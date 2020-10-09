/************************************************************************/
/* �����࣬������ʾ�����Լ������ź����߼���                                                                   */
/************************************************************************/

#pragma once

#include <QtWidgets/QWidget>
#include <QList>

#include "ui_myElve.h"


// ǰ������
class QPushButton;
class QLabel;
class QStackedWidget;
class Memo;
class Welcome;
class MakeOrder;

// ��
class Elve : public QWidget
{
	Q_OBJECT

public:
	// ���캯��
	Elve(QWidget* parent = Q_NULLPTR);

	QList<QPushButton*>* m_btnList;   	// ��Ű�ť������
	QLabel* m_picLabel;   	// ����ͼ��label
	QStackedWidget* m_stackedWidget;	// ��Ų�ͬ�����stackWidget

public slots:
	void switchWidgetSlot();   // �л�stackedWidget������Ĳۺ���
	void invokeOrderDialogSlot();   // ��������ڲۺ���
	void addCheckBoxSlot(QString);   // ���һ����ѡ��


private:
	Ui::myElveClass ui;

	const int m_buttonCount = 6;   // ��ť������
	const int m_widgetCount = 2;   // �л����������
	Welcome* m_welcome;
	Memo* m_memo;
	MakeOrder* m_makeOrder;

};
