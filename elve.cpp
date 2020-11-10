#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>

#include <QDebug>

#include "elve.h"
#include "memo.h"
#include "welcome.h"
#include "makeOrder.h"
#include "draggableLabel.h"


// TODO：处理下这个类，太冗长了

Elve::Elve(QWidget* parent)
	: QWidget(parent)
{

	ui.setupUi(this);


	// 初始化
	m_picLabel = new DraggableLabel(this);
	m_stackedWidget = new QStackedWidget(this);
	m_welcome = new Welcome(this);
	m_memo = new Memo(this);
	m_makeOrder = new MakeOrder(this);

	// 初始化布局
	QVBoxLayout* mainLayout = new QVBoxLayout(this);


	// 设置图片的位置 
	QPixmap* pixmap = new QPixmap;
	pixmap->load(":/myElve/usePic/gril1.png");
	m_picLabel->setPixmap(*pixmap);
	m_picLabel->setAlignment(Qt::AlignCenter);


	// 设置stackedWidget属性
	m_stackedWidget->addWidget(m_welcome);  // 欢迎界面index为0
	m_stackedWidget->addWidget(m_memo);     // 备忘录界面index为1



	// 布局中添加两个组件
	mainLayout->addWidget(m_stackedWidget);
	mainLayout->addWidget(m_picLabel);
	setLayout(mainLayout);

	// 设置两个组件的位置
	m_stackedWidget->move(0, 0);
	m_picLabel->move(0, 150);

	// 设置整体窗口属性
	setWindowFlags(Qt::FramelessWindowHint);   // 去掉窗口边框
	setAttribute(Qt::WA_TranslucentBackground);   // 将窗口全透明

	move(1650, 600);   // TODO：这里修改一下
	resize(250, 400);  // 调整大小
	

	// 建立连接
	connect(m_makeOrder, &MakeOrder::addCheckBoxSignal, m_memo, &Memo::addCheckBoxSlot);
	connect(m_picLabel, &DraggableLabel::leftDoubleClickedSignal, this, &Elve::invokeOrderDialogSlot);
	connect(m_picLabel, &DraggableLabel::rightDoubleClickedSignal, this, &Elve::hideOtherWidgetSlot);
	connect(m_picLabel, &DraggableLabel::leftDragToLeftSignal, this, &Elve::switchWidgetSlot);
	connect(m_picLabel, &DraggableLabel::leftDragToRightSignal, this, &Elve::switchWidgetSlot);
	connect(m_picLabel, &DraggableLabel::leftDragToDownSignal, this, &QApplication::quit);
	connect(m_picLabel, &DraggableLabel::rightDragToLeftSignal, this, &Elve::rightDragToLeftSlot);
	connect(m_picLabel, &DraggableLabel::rightDragToRightSignal, this, &Elve::rightDragToRightSlot);

}


// 按钮点击切换界面的槽
void Elve::switchWidgetSlot()
{
	int currentIndex = m_stackedWidget->currentIndex();
	m_stackedWidget->setCurrentIndex((currentIndex + 1) % m_widgetCount);
}

// 调用下达命令类的槽函数
void Elve::invokeOrderDialogSlot()
{
	m_makeOrder->show();
}


// 隐藏或显示除了label的widget
void Elve::hideOtherWidgetSlot()
{
	if (m_stackedWidget->isHidden())
		m_stackedWidget->show();
	else
		m_stackedWidget->hide();
}


void Elve::rightDragToLeftSlot()
{
	qDebug() << "rightDragToLeftSlot";
}
void Elve::rightDragToRightSlot()
{
	qDebug() << "rightDragToRightSlot";
}