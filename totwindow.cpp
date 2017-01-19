/*
 * totwindow.cpp:
 *
 * St: 2017-01-17 Tue 07:47 PM
 * Up: 2017-01-17 Tue 07:47 PM
 *
 * Author: SPS
 */

#include<iostream>
#include<sstream>
#include"totwindow.h"

TotWindow::TotWindow(MyModel *myModel, MainWindow *mainWindow)
{
	expModel = myModel;
	ptrMainWindow = mainWindow;
	totMainWidget = new QWidget;
	vBox = new QVBoxLayout(totMainWidget);
	startDate = new QLabel("Start Date:");
	startLine = new QLineEdit;
	endDate = new QLabel("End Date:");
	endLine = new QLineEdit;
	okButton = new QPushButton("Ok");
	doneButton = new QPushButton("Done");

	vBox->addWidget(startDate);
	vBox->addWidget(startLine);
	vBox->addWidget(endDate);
	vBox->addWidget(endLine);
	vBox->addWidget(okButton);
	vBox->addWidget(doneButton);
	vBox->addStretch();

	totMainWidget->show();
	connect(okButton, SIGNAL(clicked()), this, SLOT(getTotal()));
	// connect(doneButton, SIGNAL(clicked()), totMainWidget, SLOT(close()));
	connect(doneButton, SIGNAL(clicked()), this, SLOT(finishOneself()));
}

TotWindow::~TotWindow()
{
	/*
	 * FIXME: Seg fault if totMainWidget is being deleted here
	 * Note:  vBox deletion seems NOT to be an issue, although commented here
	 */

	//delete vBox;
	// delete totMainWidget;
	delete startDate;
	delete startLine;
	delete endDate;
	delete endLine;
	delete okButton;
	delete doneButton;
}

void TotWindow::getTotal()
{
	int total;
	std::stringstream ss;
	std::string totStr;

	total = expModel->getTotal(startLine->text().toStdString(), endLine->text().toStdString());
	ss << total;
	totStr = ss.str();
	totStr.insert(0, "Total: ");
	QLabel *totLabel = new QLabel(QString::fromStdString(totStr));
	vBox->addWidget(totLabel);
}

void TotWindow::finishOneself()
{
	totMainWidget->close();
	emit totDone(this);
}

