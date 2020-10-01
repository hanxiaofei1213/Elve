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


// TODO������������̫࣬�߳���

MyElve::MyElve(QWidget* parent)
	: QWidget(parent)
{

	ui.setupUi(this);


	// ��ʼ��
	m_btnList = new QList<QPushButton*>;
	m_picLabel = new QLabel(this);
	m_stackedWidget = new QStackedWidget(this);
	m_welcome = new Welcome(this);
	m_memo = new Memo(this);
	m_makeOrder = new MakeOrder(this);

	// ��ʼ������
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QVBoxLayout* leftLayout = new QVBoxLayout(this);
	QVBoxLayout* rightLayout = new QVBoxLayout(this);
	leftLayout->addStretch();

	// ���ð�ť�����Ժ�λ��
	for (int i = 0; i < m_buttonCount; ++i)
	{
		QPushButton* btn = new QPushButton(this);
		btn->setObjectName(QString('1' + i));   // ʹ��objectName��Ϊ��������
		leftLayout->addWidget(btn);
		m_btnList->append(btn);
	}

	// ����ͼƬ��λ�� 
	QPixmap* pixmap = new QPixmap;
	pixmap->load(":/myElve/C:/Users/64315/Desktop/test.png");
	m_picLabel->setPixmap(*pixmap);
	m_picLabel->setAlignment(Qt::AlignCenter);

	// ����stackedWidget����
	m_stackedWidget->addWidget(m_welcome);  // ��ӭ����indexΪ0
	m_stackedWidget->addWidget(m_memo);     // ����¼����indexΪ1



	// ��������
	// �����ұ����²��ֱ���Ϊ1��2
	rightLayout->addWidget(m_stackedWidget);
	rightLayout->addWidget(m_picLabel);
	rightLayout->setStretchFactor(m_stackedWidget, 1);
	rightLayout->setStretchFactor(m_picLabel, 2);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	// ���������������ֵı�����1��4
	mainLayout->setStretchFactor(leftLayout, 1);
	mainLayout->setStretchFactor(rightLayout, 4);
	setLayout(mainLayout);

	// �������崰������
	setWindowFlags(Qt::FramelessWindowHint);   // ȥ�����ڱ߿�
	setAttribute(Qt::WA_TranslucentBackground);   // ������ȫ͸��
	move(1600, 700);   // TODO�������޸�һ��
	


	// ��������
	connect(m_btnList->at(0), &QPushButton::clicked, this, &MyElve::invokeOrderDialogSlot);
	connect(m_btnList->at(1), &QPushButton::clicked, this, &MyElve::switchWidgetSlot);
	connect(m_btnList->at(5), &QPushButton::clicked, this, &QApplication::quit);    // TODO���ر�֮ǰ���浽�ļ�

}


// ��ť����л�����Ĳ�
void MyElve::switchWidgetSlot()
{
	int currentIndex = m_stackedWidget->currentIndex();
	m_stackedWidget->setCurrentIndex((currentIndex + 1) % m_widgetCount);
}

// �����´�������Ĳۺ���
void MyElve::invokeOrderDialogSlot()
{
	m_makeOrder->show();
}

void MyElve::addCheckBoxSlot(QString a_text)
{
	m_memo->addCheckBoxSlot(a_text);
}
