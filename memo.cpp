#include <QPixmap>
#include <QSound>

#include "memo.h"


// 构造函数
// TODO：搞一下背景
Memo::Memo(QWidget* parent) : QWidget(parent)
{
	// 初始化属性
	m_mainLabel = new QLabel(this);
	m_checkBoxList = new QList<QCheckBox *>;
	m_mainlayout = new QVBoxLayout(m_mainLabel);

	m_mainLabel->setFixedSize(150, 140);
	

	// 设置背景
	QPixmap pix(":/myElve/usePic/memoBackground.png");
	m_mainLabel->setPixmap(pix);
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
	QCheckBox* box = new QCheckBox(a_text, m_mainLabel);
	m_checkBoxList->append(box);
	connect(box, &QCheckBox::stateChanged, this, &Memo::addThoughtLineSlot);
	m_mainlayout->addWidget(box);
	m_mainLabel->setLayout(m_mainlayout);
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
	}
	else {
		box->setStyleSheet("");
	}
}
