#include <QPixmap>
#include <QSound>

#include "memo.h"


// ���캯��
// TODO����һ�±���
Memo::Memo(QWidget* parent) : QWidget(parent)
{
	// ��ʼ������
	m_mainLabel = new QLabel(this);
	m_checkBoxList = new QList<QCheckBox *>;
	m_mainlayout = new QVBoxLayout(m_mainLabel);

	m_mainLabel->setFixedSize(150, 140);
	

	// ���ñ���
	QPixmap pix(":/myElve/usePic/memoBackground.png");
	m_mainLabel->setPixmap(pix);
	addCheckBoxSlot("for test");
	
}

// ��������
Memo::~Memo()
{
	delete m_checkBoxList;
}

// TODO�����Ҫÿ�ζ���һ�²�����
// ���checkBox�ķ���������ĸ�����
void Memo::addCheckBoxSlot(QString a_text)
{
	QCheckBox* box = new QCheckBox(a_text, m_mainLabel);
	m_checkBoxList->append(box);
	connect(box, &QCheckBox::stateChanged, this, &Memo::addThoughtLineSlot);
	m_mainlayout->addWidget(box);
	m_mainLabel->setLayout(m_mainlayout);
}

// ɾ��checkBox�ķ���
void Memo::deleteCheckBoxSlot()
{

}

// ���ɾ���ߵĲ�
// TODO:����������
void Memo::addThoughtLineSlot(int a_state)
{
	QCheckBox* box = (QCheckBox*)sender();
	if (a_state == Qt::Checked)
	{
		box->setStyleSheet("text-decoration: line-through;");
		//QSound::play(":/myElve/messionComplete.wav");
	}
	else {
		box->setStyleSheet("");
	}
}
