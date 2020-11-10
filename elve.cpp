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


// TODO������������̫࣬�߳���

Elve::Elve(QWidget* parent)
	: QWidget(parent)
{

	ui.setupUi(this);


	// ��ʼ��
	m_picLabel = new DraggableLabel(this);
	m_stackedWidget = new QStackedWidget(this);
	m_welcome = new Welcome(this);
	m_memo = new Memo(this);
	m_makeOrder = new MakeOrder(this);

	// ��ʼ������
	QVBoxLayout* mainLayout = new QVBoxLayout(this);


	// ����ͼƬ��λ�� 
	QPixmap* pixmap = new QPixmap;
	pixmap->load(":/myElve/usePic/gril1.png");
	m_picLabel->setPixmap(*pixmap);
	m_picLabel->setAlignment(Qt::AlignCenter);


	// ����stackedWidget����
	m_stackedWidget->addWidget(m_welcome);  // ��ӭ����indexΪ0
	m_stackedWidget->addWidget(m_memo);     // ����¼����indexΪ1



	// ����������������
	mainLayout->addWidget(m_stackedWidget);
	mainLayout->addWidget(m_picLabel);
	setLayout(mainLayout);

	// �������������λ��
	m_stackedWidget->move(0, 0);
	m_picLabel->move(0, 150);

	// �������崰������
	setWindowFlags(Qt::FramelessWindowHint);   // ȥ�����ڱ߿�
	setAttribute(Qt::WA_TranslucentBackground);   // ������ȫ͸��

	move(1650, 600);   // TODO�������޸�һ��
	resize(250, 400);  // ������С
	

	// ��������
	connect(m_makeOrder, &MakeOrder::addCheckBoxSignal, m_memo, &Memo::addCheckBoxSlot);
	connect(m_picLabel, &DraggableLabel::leftDoubleClickedSignal, this, &Elve::invokeOrderDialogSlot);
	connect(m_picLabel, &DraggableLabel::rightDoubleClickedSignal, this, &Elve::hideOtherWidgetSlot);
	connect(m_picLabel, &DraggableLabel::leftDragToLeftSignal, this, &Elve::switchWidgetSlot);
	connect(m_picLabel, &DraggableLabel::leftDragToRightSignal, this, &Elve::switchWidgetSlot);
	connect(m_picLabel, &DraggableLabel::leftDragToDownSignal, this, &QApplication::quit);
	connect(m_picLabel, &DraggableLabel::rightDragToLeftSignal, this, &Elve::rightDragToLeftSlot);
	connect(m_picLabel, &DraggableLabel::rightDragToRightSignal, this, &Elve::rightDragToRightSlot);

}


// ��ť����л�����Ĳ�
void Elve::switchWidgetSlot()
{
	int currentIndex = m_stackedWidget->currentIndex();
	m_stackedWidget->setCurrentIndex((currentIndex + 1) % m_widgetCount);
}

// �����´�������Ĳۺ���
void Elve::invokeOrderDialogSlot()
{
	m_makeOrder->show();
}


// ���ػ���ʾ����label��widget
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