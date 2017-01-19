/*
 * addwindow.cpp:
 *
 * St: 2016-12-15 Thu 04:16 PM
 * Up: 2016-12-15 Thu 04:33 PM
 *
 * Author: SPS
 */

#include <QtGui>
#include "addwindow.h"
#include <iostream>

// Constructor
AddWindow::AddWindow(struct expData *newExp)
{
	newExpData = newExp;

	date = new QLabel("Date: ");
	dateInp = new QLineEdit();

	item = new QLabel("Item: ");
	itemInp = new QLineEdit();

	cat = new QLabel("Cat: ");
	catInp = new QLineEdit();

	price = new QLabel("Price: ");
	priceInp = new QLineEdit();

	comment = new QLabel("Comment: ");
	commentInp = new QLineEdit();

	okButton = new QPushButton("Ok");
	closeButton = new QPushButton("Close");
	vBox = new QVBoxLayout();
	addFormWidget = new QWidget();

	vBox->addWidget(date);
	vBox->addWidget(dateInp);
	vBox->addWidget(item);
	vBox->addWidget(itemInp);
	vBox->addWidget(cat);
	vBox->addWidget(catInp);
	vBox->addWidget(price);
	vBox->addWidget(priceInp);
	vBox->addWidget(comment);
	vBox->addWidget(commentInp);
	vBox->addWidget(okButton);
	vBox->addWidget(closeButton);

	addFormWidget->setLayout(vBox);
	addFormWidget->show();

	connect(okButton, SIGNAL(clicked()), this, SLOT(fillData()));
	connect(closeButton, SIGNAL(clicked()), addFormWidget, SLOT(close()));
}

void AddWindow::fillData()
{
	QString qStr;

	qStr = dateInp->text();
	newExpData->date = qStr.toStdString();

	qStr = itemInp->text();
	newExpData->item = qStr.toStdString();

	qStr = catInp->text();
	newExpData->cat = qStr.toStdString();

	qStr = priceInp->text();
	newExpData->price = qStr.toStdString();

	qStr = commentInp->text();
	newExpData->comment = qStr.toStdString();

	emit newExpReceived(newExpData);
	addFormWidget->close();
}

