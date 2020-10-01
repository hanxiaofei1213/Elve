#include <QCheckBox>
#include <QVBoxLayout>

#include "memo.h"


// 构造函数
Memo::Memo(QWidget* parent) : QWidget(parent)
{

	m_checkBoxList = new QList<QCheckBox *>;
	m_mainlayout = new QVBoxLayout(this);
	m_mainlayout->addStretch(-1);
	addCheckBox("to do");

	
}

// 析构函数
Memo::~Memo()
{
	delete m_checkBoxList;
}

// TODO：真的要每次都设一下布局吗
// 添加checkBox的方法
void Memo::addCheckBox(QString a_text)
{
	QCheckBox* box = new QCheckBox(a_text, this);
	m_checkBoxList->append(box);
	connect(box, &QCheckBox::stateChanged, this, &Memo::addThoughtLine);
	m_mainlayout->addWidget(box);
	setLayout(m_mainlayout);
}

// 删除checkBox的方法
void Memo::deleteCheckBox()
{

}

// 添加删除线的槽
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
