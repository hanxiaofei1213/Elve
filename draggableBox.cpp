

#include "draggableBox.h"

// 构造函数
DraggableBox::DraggableBox(QWidget* parent)
	: QCheckBox(parent)
{
	m_boxRawLoc = new QPoint(0, 0);
	m_mouseRawGlobalLoc = new QPoint(0, 0);

}

/**
 * 函数名：mousePressEvent
 * 作用：记录当下复选框和鼠标的坐标，供以后移动使用
 */
void DraggableBox::mousePressEvent(QMouseEvent* e)
{
	// 记录当前复选框的相对坐标
	*m_boxRawLoc = this->pos();

	// 记录当前复选框全局坐标
	*m_mouseRawGlobalLoc = e->globalPos();

	// 调用父类的按下事件
	QCheckBox::mousePressEvent(e);
}

/**
 * 函数名：mouseMoveEvent
 * 作用：根据鼠标移动的距离，来重新设置部件的位置，以此来实现鼠标拖动部件
 */
void DraggableBox::mouseMoveEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		this->move((e->globalPos() - *m_mouseRawGlobalLoc) + *m_boxRawLoc);
	}
	QCheckBox::mouseMoveEvent(e);
}

/**
 * 函数名：mouseReleaseEvent
 * 作用：进行判断，看复选框是否出边框
 */
void DraggableBox::mouseReleaseEvent(QMouseEvent* e)
{
	QCheckBox::mouseReleaseEvent(e);
	if (this->pos().x() < 0 || this->pos().y() < 0)
		emit deleteDraggableBoxSignal();
	else
		this->move(*m_boxRawLoc);
}


