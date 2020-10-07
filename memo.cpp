


#include "memo.h"


// 构造函数
Memo::Memo(QWidget* parent) : QWidget(parent)
{
	// 初始化属性
	m_pixmap = new QPixmap;
	m_mainLabel = new QLabel(this);
	m_checkBoxMap = new QMap<QString, QCheckBox*>;
	m_size = new QSize(150, 140);
	m_pageCount = 1;
	m_nowPage = 1;

	// 设置背景
	setBackgroundPic(":/myElve/usePic/memoBackground.png");

	// 设置label大小
	setLabelSize(*m_size);
}

// 析构函数
Memo::~Memo()
{
	qDebug() << "xigou";
	delete m_checkBoxMap;
}

/**
 * 函数名：setBackgroundPic
 * 作用：设置整个备忘录的背景图片
 */
void Memo::setBackgroundPic(const QString& a_picName)
{
	// 检查图片是否合法
	if (a_picName == nullptr || a_picName.isEmpty() || !m_pixmap->load(a_picName))
	{
		QMessageBox::warning(this, "Programe Error", " Illegal picture in Memo::setBackgroundPic(const QString&) ");
		exit(0);
	}

	// 加载图片成功
	m_mainLabel->setPixmap(*m_pixmap);
}


void Memo::setLabelSize(const QSize& a_size)
{
	m_mainLabel->setFixedSize(a_size);
}


// TODO：真的要每次都设一下布局吗
// 添加checkBox的方法，最多四个现在
void Memo::addCheckBoxSlot(QString a_text)
{

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
