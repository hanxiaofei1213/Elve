
#include <QSound>

#include "memo.h"


// ���캯��
// TODO����һ�±���
Memo::Memo(QWidget* parent) : QWidget(parent)
{
	m_mainWidget = new QWidget(this);
	m_checkBoxList = new QList<QCheckBox *>;
	m_mainlayout = new QVBoxLayout(m_mainWidget);

	m_mainWidget->setFixedSize(200, 100);
	m_mainWidget->setStyleSheet("background:yellow");

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
	QCheckBox* box = new QCheckBox(a_text, m_mainWidget);
	m_checkBoxList->append(box);
	connect(box, &QCheckBox::stateChanged, this, &Memo::addThoughtLineSlot);
	m_mainlayout->addWidget(box);
	m_mainWidget->setLayout(m_mainlayout);
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
		delete box;
	}
	else {
		box->setStyleSheet("");
	}
}
