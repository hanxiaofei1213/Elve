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
	// �����ı�
	// TODO���������ͼƬ
	m_picLabel->setText("here will be a pic");
	m_hintMessage->setText("Any orders I need to do?");
	m_yesButton->setText("yes, please");
	m_noButton->setText("no, thanks");

	// ���ÿ�ݼ�
	m_yesButton->setShortcut(Qt::Key_Enter);
	m_yesButton->setShortcut(Qt::Key::Key_Return);

	// ��������
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QVBoxLayout* rightLayout = new QVBoxLayout(this);
	QHBoxLayout* rightDownLayout = new QHBoxLayout(this);

	// ��ӽ�����
	rightDownLayout->addWidget(m_yesButton);
	rightDownLayout->addWidget(m_noButton);
	rightLayout->addWidget(m_hintMessage);
	rightLayout->addWidget(m_orderLineEdit);
	rightLayout->addItem(rightDownLayout);
	mainLayout->addWidget(m_picLabel);
	mainLayout->addItem(rightLayout);

	setLayout(mainLayout);

	// ��������
	connect(m_yesButton, &QPushButton::clicked, this, &MakeOrder::dealOrder);
	connect(m_noButton, &QPushButton::clicked, this, &MakeOrder::exitDialog);
	connect(this, &MakeOrder::addCheckBoxSignal, myElve, &Elve::addCheckBoxSlot);
}

// ��������Ĳۺ���
void MakeOrder::dealOrder()
{
	QString order = m_orderLineEdit->text();

	// memo����
	QRegExp memoRegexp("(^memo)(\\s*)(.*)");
	int memoPos = memoRegexp.indexIn(order);
	if (memoPos != -1) 
	{
		// TODO��here ����Ҫ��㣬û������ɸѡ
		emit addCheckBoxSignal(memoRegexp.cap(3));   
		//qDebug() << memoRegexp.cap(3);
	}
	


	// ��ձ༭�����ݣ����Ի�������
	m_orderLineEdit->setText("");
	this->hide();
}

// ���ضԻ���Ĳۺ���
void MakeOrder::exitDialog()
{
	this->hide();
}