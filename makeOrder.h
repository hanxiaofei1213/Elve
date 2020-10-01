/**
 * �´�������
 */

#pragma once
#include <QDialog>

// ǰ������
class QLineEdit;
class QLabel;
class QPushButton;
class MyElve;

// ������
class MakeOrder : public QDialog {
	Q_OBJECT

public:
	MakeOrder(MyElve* myElve, QWidget* parent = 0);

	// ��������
	QLineEdit* m_orderLineEdit;
	QPushButton* m_yesButton;
	QPushButton* m_noButton;
	QLabel* m_hintMessage;
	QLabel* m_picLabel;

public slots:
	void dealOrder();   // ��������Ĳۺ���
	void exitDialog();  // ���账���˳��Ի���Ĳۺ���

signals:
	void addCheckBoxSignal(QString);

};


