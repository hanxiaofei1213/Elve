#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>

#include <QDebug>

#include "myElve.h"
#include "memo.h"
#include "welcome.h"
#include "makeOrder.h"


// TODO：处理下这个类，太冗长了

MyElve::MyElve(QWidget* parent)
	: QWidget(parent)
{

	ui.setupUi(this);


	// 初始化
	m_btnList = new QList<QPushButton*>;
	m_picLabel = new QLabel(this);
	m_stackedWidget = new QStackedWidget(this);
	m_welcome = new Welcome(this);
	m_memo = new Memo(this);
	m_makeOrder = new MakeOrder(this);

	// 初始化布局
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QVBoxLayout* leftLayout = new QVBoxLayout(this);
	QVBoxLayout* rightLayout = new QVBoxLayout(this);
	leftLayout->addStretch();

	// 设置按钮的属性和位置
	for (int i = 0; i < m_buttonCount; ++i)
	{
		QPushButton* btn = new QPushButton(this);
		btn->setObjectName(QString('1' + i));   // 使用objectName作为区分名字
		leftLayout->addWidget(btn);
		m_btnList->append(btn);
	}

	// 设置图片的位置 
	QPixmap* pixmap = new QPixmap;
	pixmap->load(":/myElve/C:/Users/64315/Desktop/test.png");
	m_picLabel->setPixmap(*pixmap);
	m_picLabel->setAlignment(Qt::AlignCenter);

	// 设置stackedWidget属性
	m_stackedWidget->addWidget(m_welcome);  // 欢迎界面index为0
	m_stackedWidget->addWidget(m_memo);     // 备忘录界面index为1



	// 创建布局
	// 设置右边上下布局比例为1：2
	rightLayout->addWidget(m_stackedWidget);
	rightLayout->addWidget(m_picLabel);
	rightLayout->setStretchFactor(m_stackedWidget, 1);
	rightLayout->setStretchFactor(m_picLabel, 2);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	// 设置左右两个布局的比例是1：4
	mainLayout->setStretchFactor(leftLayout, 1);
	mainLayout->setStretchFactor(rightLayout, 4);
	setLayout(mainLayout);

	// 设置整体窗口属性
	setWindowFlags(Qt::FramelessWindowHint);   // 去掉窗口边框
	setAttribute(Qt::WA_TranslucentBackground);   // 将窗口全透明
	move(1600, 700);   // TODO：这里修改一下
	


	// 建立连接
	connect(m_btnList->at(0), &QPushButton::clicked, this, &MyElve::invokeOrderDialogSlot);
	connect(m_btnList->at(1), &QPushButton::clicked, this, &MyElve::switchWidgetSlot);
	connect(m_btnList->at(5), &QPushButton::clicked, this, &QApplication::quit);    // TODO：关闭之前保存到文件

}


// 按钮点击切换界面的槽
void MyElve::switchWidgetSlot()
{
	int currentIndex = m_stackedWidget->currentIndex();
	m_stackedWidget->setCurrentIndex((currentIndex + 1) % m_widgetCount);
}

// 调用下达命令类的槽函数
void MyElve::invokeOrderDialogSlot()
{
	m_makeOrder->show();
}

void MyElve::addCheckBoxSlot(QString a_text)
{
	m_memo->addCheckBoxSlot(a_text);
}
