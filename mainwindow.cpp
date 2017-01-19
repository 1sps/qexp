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

#include <QTableView>
#include <iostream>
#include "mainwindow.h"
#include "mymodel.h"
#include "totwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	tableView = new QTableView(this);
	myModel = new MyModel(this);
	tableView->setModel(myModel);

	/* Create buttons */
	aButton = new QPushButton("Add");
	saveButton = new QPushButton("Save");
	searchButton = new QPushButton("Search");
	sortButton = new QPushButton("Sort");
	analyseButton = new QPushButton("Analyse");
	totalButton = new QPushButton("Total");
	qButton = new QPushButton("Quit");

	/* Create boxes */
	vbox1 = new QVBoxLayout();
	vbox2 = new QVBoxLayout();
	hbox = new QHBoxLayout();

	/* Create central widget */
	cWidget = new QWidget();

	/* Pack into boxes */
	vbox1->addWidget(tableView);

	vbox2->addWidget(aButton);
	vbox2->addWidget(sortButton);
	vbox2->addWidget(searchButton);
	vbox2->addWidget(saveButton);
	vbox2->addWidget(analyseButton);
	vbox2->addWidget(totalButton);
	vbox2->addWidget(qButton);
	vbox2->addStretch();

	hbox->addLayout(vbox1);
	hbox->addLayout(vbox2);

	/* Put main box inside widget */
	cWidget->setLayout(hbox);

	/* Make this widget the central one */
	setCentralWidget(cWidget);

	/* Connect buttons to methods */
	connect(aButton, SIGNAL(clicked()), myModel, SLOT(addData()));
	connect(saveButton, SIGNAL(clicked()), myModel, SLOT(writeToFile()));
	connect(qButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(totalButton, SIGNAL(clicked()), this, SLOT(getTotal()));
#ifdef EXP_INIT_DONE
	connect(searchButton, SIGNAL(clicked()), myModel, SLOT(searchData()));
	connect(sortButton, SIGNAL(clicked()), myModel, SLOT(sortData()));
#endif /* EXP_INIT_DONE */

	/* Disable search and sort buttons */
	searchButton->setEnabled(false);
}

void MainWindow::getTotal()
{
	TotWindow *totWindow = new TotWindow(myModel, this);
	connect(totWindow, SIGNAL(totDone(TotWindow *)), this, SLOT(destroyTotWindow(TotWindow *)));
}

void MainWindow::destroyTotWindow(TotWindow *tw)
{
	delete tw;
}

