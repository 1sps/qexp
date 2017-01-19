#ifndef TOT_WINDOW_H
#define TOT_WINDOW_H

#include "mymodel.h"

class MainWindow;

class TotWindow : public QObject
{
	Q_OBJECT

	private:
	MyModel *expModel;
	MainWindow *ptrMainWindow;
	QWidget *totMainWidget;
	QVBoxLayout *vBox;
	QLabel *startDate;
	QLineEdit *startLine;
	QLabel *endDate;
	QLineEdit *endLine;
	QPushButton *okButton;
	QPushButton *doneButton;

	public slots:
	void getTotal();
	void finishOneself();

	public:
	TotWindow(MyModel *myModel, MainWindow *mainWindow);
	~TotWindow();

	signals:
	void totDone(TotWindow *tw);
};

#endif /* TOT_WINDOW_H */

