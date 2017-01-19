#ifndef ADD_WINDOW_H
#define ADD_WINDOW_H

#include "mymodel.h"

class AddWindow : public QObject
{
	Q_OBJECT

	private:
	struct expData *newExpData;
	QLabel *date;
	QLabel *item;
	QLabel *cat;
	QLabel *price;
	QLabel *comment;

	QLineEdit *dateInp;
	QLineEdit *itemInp;
	QLineEdit *catInp;
	QLineEdit *priceInp;
	QLineEdit *commentInp;

	QPushButton *okButton;
	QPushButton *closeButton;
	QVBoxLayout *vBox;
	QWidget     *addFormWidget;

	public slots:
	void fillData();

	public:
	AddWindow(struct expData *newCt);

	signals:
	void newExpReceived(struct expData *newExp);
};

#endif /* ADD_WINDOW_H */

