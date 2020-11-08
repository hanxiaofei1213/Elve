/************************************************************************/
/* �����࣬������ʾ�����Լ������ź����߼���                                                                   */
/************************************************************************/

#pragma once

#include <QtWidgets/QWidget>
#include <QList>

#include "ui_myElve.h"


// ǰ������
class QStackedWidget;
class Memo;
class Welcome;
class MakeOrder;
class DraggableLabel;

// ��
class Elve : public QWidget
{
	Q_OBJECT

public:
	// ���캯��
	Elve(QWidget* parent = Q_NULLPTR);

	DraggableLabel* m_picLabel;   	            // ����ͼ��label
	QStackedWidget* m_stackedWidget;	// ��Ų�ͬ�����stackWidget

public slots:
	void switchWidgetSlot();           // �л�stackedWidget������Ĳۺ���
	void invokeOrderDialogSlot();      // ��������ڲۺ���
	void hideOtherWidgetSlot();        // ���ػ���ʾ����label���������
	// ��Ӧ���Ĳۺ���
	void rightDragToLeftSlot();
	void rightDragToRightSlot();

private:
	Ui::myElveClass ui;

	const int m_buttonCount = 6;   // ��ť������
	const int m_widgetCount = 2;   // �л����������
	Welcome* m_welcome;
	Memo* m_memo;
	MakeOrder* m_makeOrder;

};
