/************************************************************************/
/* 界面类，用来显示界面以及传递信号至逻辑类                                                                   */
/************************************************************************/

#pragma once

#include <QtWidgets/QWidget>
#include <QList>

#include "ui_myElve.h"


// 前向声明
class QStackedWidget;
class Memo;
class Welcome;
class MakeOrder;
class DraggableLabel;

// 类
class Elve : public QWidget
{
	Q_OBJECT

public:
	// 构造函数
	Elve(QWidget* parent = Q_NULLPTR);

	DraggableLabel* m_picLabel;   	            // 放置图的label
	QStackedWidget* m_stackedWidget;	// 存放不同界面的stackWidget

public slots:
	void switchWidgetSlot();           // 切换stackedWidget中组件的槽函数
	void invokeOrderDialogSlot();      // 调用命令窗口槽函数
	void hideOtherWidgetSlot();        // 隐藏或显示除了label的其它组件
	// 响应鼠标的槽函数
	void rightDragToLeftSlot();
	void rightDragToRightSlot();

private:
	Ui::myElveClass ui;

	const int m_buttonCount = 6;   // 按钮的数量
	const int m_widgetCount = 2;   // 切换界面的数量
	Welcome* m_welcome;
	Memo* m_memo;
	MakeOrder* m_makeOrder;

};
