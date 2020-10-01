
#include <QSound>

#include "memo.h"


// 构造函数
// TODO：搞一下背景
Memo::Memo(QWidget* parent) : QWidget(parent)
{
	m_mainWidget = new QWidget(this);
	m_checkBoxList = new QList<QCheckBox *>;
	m_mainlayout = new QVBoxLayout(m_mainWidget);

	m_mainWidget->setFixedSize(200, 100);
	m_mainWidget->setStyleSheet("background:yellow");

	addCheckBoxSlot("for test");
	
}

// 析构函数
Memo::~Memo()
{
	delete m_checkBoxList;
}

// TODO：真的要每次都设一下布局吗
// 添加checkBox的方法，最多四个现在
void Memo::addCheckBoxSlot(QString a_text)
{
	QCheckBox* box = new QCheckBox(a_text, m_mainWidget);
	m_checkBoxList->append(box);
	connect(box, &QCheckBox::stateChanged, this, &Memo::addThoughtLineSlot);
	m_mainlayout->addWidget(box);
	m_mainWidget->setLayout(m_mainlayout);
}

// 删除checkBox的方法
void Memo::deleteCheckBoxSlot()
{

}

// 添加删除线的槽
// TODO:处理下音乐
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
