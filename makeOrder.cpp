#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QRegExp>

#include "makeOrder.h"
#include "elve.h"


MakeOrder::MakeOrder(Elve* myElve, QWidget* parent)
	: QDialog(parent),
	m_orderLineEdit(new QLineEdit(this)),
	m_yesButton(new QPushButton(this)), m_noButton(new QPushButton(this)),
	m_hintMessage(new QLabel(this)), m_picLabel(new QLabel(this))
{
	// 设置文本
	// TODO：这里放置图片
	m_picLabel->setText("here will be a pic");
	m_hintMessage->setText("Any orders I need to do?");
	m_yesButton->setText("yes, please");
	m_noButton->setText("no, thanks");

	// 设置快捷键
	m_yesButton->setShortcut(Qt::Key_Enter);
	m_yesButton->setShortcut(Qt::Key::Key_Return);

	// 创建布局
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QVBoxLayout* rightLayout = new QVBoxLayout(this);
	QHBoxLayout* rightDownLayout = new QHBoxLayout(this);

	// 添加进布局
	rightDownLayout->addWidget(m_yesButton);
	rightDownLayout->addWidget(m_noButton);
	rightLayout->addWidget(m_hintMessage);
	rightLayout->addWidget(m_orderLineEdit);
	rightLayout->addItem(rightDownLayout);
	mainLayout->addWidget(m_picLabel);
	mainLayout->addItem(rightLayout);

	setLayout(mainLayout);

	// 建立连接
	connect(m_yesButton, &QPushButton::clicked, this, &MakeOrder::dealOrder);
	connect(m_noButton, &QPushButton::clicked, this, &MakeOrder::exitDialog);
	connect(this, &MakeOrder::addCheckBoxSignal, myElve, &Elve::addCheckBoxSlot);
}

// 处理命令的槽函数
void MakeOrder::dealOrder()
{
	QString order = m_orderLineEdit->text();

	// memo处理
	QRegExp memoRegexp("(^memo)(\\s*)(.*)");
	int memoPos = memoRegexp.indexIn(order);
	if (memoPos != -1) 
	{
		// TODO：here 这里要搞搞，没加条件筛选
		emit addCheckBoxSignal(memoRegexp.cap(3));   
		//qDebug() << memoRegexp.cap(3);
	}
	


	// 清空编辑框内容，将对话框隐藏
	m_orderLineEdit->setText("");
	this->hide();
}

// 隐藏对话框的槽函数
void MakeOrder::exitDialog()
{
	this->hide();
}