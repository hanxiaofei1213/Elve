#include <QCheckBox>
#include <QVBoxLayout>

#include "memo.h"


// ���캯��
Memo::Memo(QWidget* parent) : QWidget(parent)
{

	m_checkBoxList = new QList<QCheckBox *>;
	m_mainlayout = new QVBoxLayout(this);
	m_mainlayout->addStretch(-1);
	addCheckBox("to do");

	
}

// ��������
Memo::~Memo()
{
	delete m_checkBoxList;
}

// TODO�����Ҫÿ�ζ���һ�²�����
// ���checkBox�ķ���
void Memo::addCheckBox(QString a_text)
{
	QCheckBox* box = new QCheckBox(a_text, this);
	m_checkBoxList->append(box);
	connect(box, &QCheckBox::stateChanged, this, &Memo::addThoughtLine);
	m_mainlayout->addWidget(box);
	setLayout(m_mainlayout);
}

// ɾ��checkBox�ķ���
void Memo::deleteCheckBox()
{

}

// ���ɾ���ߵĲ�
void Memo::addThoughtLine(int a_state)
{
	QCheckBox* box = (QCheckBox*)sender();
	if (a_state == Qt::Checked)
	{
		box->setStyleSheet("text-decoration: line-through;");
	}
	else {
		box->setStyleSheet("");
	}
}
