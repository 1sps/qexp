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

#ifndef MYMODEL_H
#define MYMODEL_H

//! [Quoting ModelView Tutorial]
// mymodel.h
#include <QtGui>
#include <QAbstractTableModel>
#include <QString>
#include <vector>
#include <string>
#include "coreds.h"
#include "book.h"

const int COLS= 5;
// Not used anyways
const int ROWS= 2;

class MyModel : public QAbstractTableModel
{
	Q_OBJECT
	public:
	MyModel(QObject *parent);
	int rowCount(const QModelIndex &parent = QModelIndex()) const ;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	//For editing
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value,
		     int role = Qt::EditRole);
	void sortByDate();
#ifdef INIT_EXP_DONE
	void sortByDistrict();
	void sortByArea();
	void sortByStatus();
#endif /* INIT_EXP_DONE */
	int getTotal(std::string startDate, std::string endDate);

	QPushButton *aButton;
	QPushButton *qButton;

	private slots:
	void addData();
	void pushData(struct expData *newExp);
	void writeToFile();
	void sortData();
	void searchData();

	private:
	int rows;
	int columns;
	// Below vectors hold core data
	std::vector<std::string> dates;
	std::vector<std::string> items;
	std::vector<std::string> cats;
	std::vector<std::string> prices;
	std::vector<std::string> comments;
	std::vector<struct expData> expenses;
	Book book;

	signals:
};

struct lessDate
{
	inline bool operator() (const struct expData& exp1, const struct expData& exp2)
	{
		std::string st1;
		std::string st2;

		st1 = exp1.date;
		std::transform(st1.begin(), st1.end(), st1.begin(), ::tolower);

		st2 = exp2.date;
		std::transform(st2.begin(), st2.end(), st2.begin(), ::tolower);

		if (st1.compare(st2) < 0)
			return true;
		else
			return false;
	}
};

#ifdef INIT_EXP_DONE
struct lessDistrict
{
	inline bool operator() (const struct ctData& ct1, const struct ctData& ct2)
	{
		std::string st1;
		std::string st2;

		st1 = ct1.district;
		std::transform(st1.begin(), st1.end(), st1.begin(), ::tolower);

		st2 = ct2.district;
		std::transform(st2.begin(), st2.end(), st2.begin(), ::tolower);

		if (st1.compare(st2) < 0)
			return true;
		else
			return false;
	}
};
struct lessArea
{
	inline bool operator() (const struct ctData& ct1, const struct ctData& ct2)
	{
		std::string st1;
		std::string st2;

		st1 = ct1.area;
		std::transform(st1.begin(), st1.end(), st1.begin(), ::tolower);

		st2 = ct2.area;
		std::transform(st2.begin(), st2.end(), st2.begin(), ::tolower);

		if (st1.compare(st2) < 0)
			return true;
		else
			return false;
	}
};
struct lessStatus
{
	inline bool operator() (const struct ctData& ct1, const struct ctData& ct2)
	{
		std::string st1;
		std::string st2;

		st1 = ct1.status;
		std::transform(st1.begin(), st1.end(), st1.begin(), ::tolower);

		st2 = ct2.status;
		std::transform(st2.begin(), st2.end(), st2.begin(), ::tolower);

		if (st1.compare(st2) < 0)
			return true;
		else
			return false;
	}
};

#endif /* INIT_EXP_DONE */

#endif // MYMODEL_H

