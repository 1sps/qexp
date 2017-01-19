/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/


#include <QtGui>
#include <iostream>
#include <sstream>
#include "mymodel.h"
#include "addwindow.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
	int i;
	struct expData temp;

	book.openBook();
	book.readBook();
	book.closeBook();

	dates = book.getDates();
	items = book.getItems();
	cats = book.getCats();
	prices = book.getPrices();
	comments = book.getComments();

	// TODO: This should _not_ use dates.size() - maybe a dedicated variable
	for (i = 0; i < dates.size(); i++) {
		temp.date = dates[i];
		temp.item = items[i];
		temp.cat = cats[i];
		temp.price = prices[i];
		temp.comment = comments[i];

		expenses.push_back(temp);
	}
	//sortByName();
}

//-----------------------------------------------------------------
int MyModel::rowCount(const QModelIndex & /*parent*/) const
{
	return expenses.size();
}

//-----------------------------------------------------------------
int MyModel::columnCount(const QModelIndex & /*parent*/) const
{
    return COLS;
}

//-----------------------------------------------------------------
QVariant MyModel::data(const QModelIndex &index, int role) const
{
    static std::string oldDate = "dummy";
    static QColor backColor = Qt::white;
    if (role == Qt::DisplayRole)
    {
    	if (index.column() == 0) {
		return QString::fromStdString(expenses[index.row()].date);
	} else if (index.column() == 1) {
		return QString::fromStdString(expenses[index.row()].item);
	} else if (index.column() == 2) {
		return QString::fromStdString(expenses[index.row()].cat);
	} else if (index.column() == 3) {
		return QString::fromStdString(expenses[index.row()].price);
	} else if (index.column() == 4) {
		return QString::fromStdString(expenses[index.row()].comment);
	}
    } else if (role == Qt::BackgroundRole) {
    	if (oldDate.compare(expenses[index.row()].date) != 0) {
		if (backColor == QColor(220, 220, 220))
			backColor = Qt::white;
		else
			backColor = QColor(220, 220, 220);
	}
	oldDate = expenses[index.row()].date;
	return QBrush(backColor);
    }

    return QVariant();
}

//-----------------------------------------------------------------
QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal) {
			switch (section) {
				case 0:
					return QString("Date");
				case 1:
					return QString("Item");
				case 2:
					return QString("Cat");
				case 3:
					return QString("Price");
				case 4:
					return QString("Comment");
				default:	
					break;
			}
		} else if (orientation == Qt::Vertical) {
			return section+1;
		}
	}
	return QVariant();
}

//-----------------------------------------------------------------
void MyModel::addData()
{
	struct expData *newExp = new struct expData;
	AddWindow *addWindow = new AddWindow(newExp);
	QObject::connect(addWindow, SIGNAL(newExpReceived(struct expData *)), this, SLOT(pushData(struct expData *)));
}

//-----------------------------------------------------------------
void MyModel::pushData(struct expData *newExp)
{
	struct expData temp;
	temp.date = newExp->date;
	temp.item = newExp->item ;
	temp.cat = newExp->cat ;
	temp.price = newExp->price ;
	temp.comment = newExp->comment ;

	expenses.push_back(temp);

	delete newExp;
	sortByDate();

	emit(layoutChanged());
}


//-----------------------------------------------------------------
void MyModel::writeToFile()
{
	book.openBook();
	book.writeBook(expenses);
	book.closeBook();
}

//-----------------------------------------------------------------
void MyModel::searchData()
{
	;
}

//-----------------------------------------------------------------
void MyModel::sortData()
{
	std::string sortBy;
	QStringList items;
	items << tr("Date") << tr("Item") << tr("Cat") << tr("Price");

	bool ok;
	QString item = QInputDialog::getItem(0, tr("Sort By:"),
			tr("Sort By:"), items, 0, false, &ok);
	if (ok && !item.isEmpty()) {
		sortBy = item.toStdString();
		if (sortBy.compare("Date") == 0) {
			sortByDate();
		}
#ifdef OTHER_SORTS
		else if (sortBy.compare("District") == 0) {
			sortByDistrict();
		} else if (sortBy.compare("Area") == 0) {
			sortByArea();
		} else if (sortBy.compare("Status") == 0) {
			sortByStatus();
		}
#endif /* OTHER_SORTS */
		else {
			return;
		}
		emit(layoutChanged());
	}
}

//-----------------------------------------------------------------
void MyModel::sortByDate()
{
	std::sort(expenses.begin(), expenses.end(), lessDate());
}

#ifdef EXP_INIT_DONE
//-----------------------------------------------------------------
void MyModel::sortByDistrict()
{
	std::sort(contacts.begin(), contacts.end(), lessDistrict());
}

//-----------------------------------------------------------------
void MyModel::sortByArea()
{
	std::sort(contacts.begin(), contacts.end(), lessArea());
}

//-----------------------------------------------------------------
void MyModel::sortByStatus()
{
	std::sort(contacts.begin(), contacts.end(), lessStatus());
}
#endif /* EXP_INIT_DONE */


//-----------------------------------------------------------------
Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

//-----------------------------------------------------------------
bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	QString qNewVal;
	std::string sNewVal;
	int col;
	int button;

	if (index.isValid() && role == Qt::EditRole) {

		col = index.column();
		qNewVal = value.toString();
		sNewVal = qNewVal.toStdString();
		
		button = QMessageBox::question(0,                         
                                tr("Confirm Change"),                            
                                tr("Are you sure you want to change to \"%1\"?").arg(qNewVal),
                                QMessageBox::Yes | QMessageBox::No);             
                                                                                 
                if (button == QMessageBox::No) {                                
                	return false ;
                }    

		switch (col) {
		case 0:
			expenses[index.row()].date = sNewVal;
			break;
		case 1:
			expenses[index.row()].item = sNewVal;
			break;
		case 2:
			expenses[index.row()].cat = sNewVal;
			break;
		case 3:
			expenses[index.row()].price = sNewVal;
			break;
		case 4:
			expenses[index.row()].comment = sNewVal;
			break;
		default:
			return false;
			break;
		}

		emit dataChanged(index, index);
		return true;
	}
	return false;
}

//-----------------------------------------------------------------
int MyModel::getTotal(std::string startDate, std::string endDate)
{
	int i;
	int total = 0;
	int temp;

	i = 0;
	while (i < expenses.size()) {
		if (expenses[i].date.compare(startDate) >= 0 
		    && expenses[i].date.compare(endDate) <= 0) {
			std::stringstream(expenses[i].price) >> temp;
			total += temp;
		}
		i++;
	}
	return total;
}

