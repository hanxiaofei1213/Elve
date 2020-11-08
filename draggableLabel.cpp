

#include "draggableLabel.h"

// 构造函数
DraggableLabel::DraggableLabel(QWidget* parent) 
	: QLabel(parent), m_mouseRawLoc(nullptr)
{
	
}

// 析构函数
DraggableLabel::~DraggableLabel()
{
	if (m_mouseRawLoc)
		delete m_mouseRawLoc;
	m_mouseRawLoc = nullptr;
}

/**
 * 函数名：mousePressEvent
 * 作用：鼠标按下事件，记录鼠标的坐标（相对
 */
void DraggableLabel::mousePressEvent(QMouseEvent* e)
{
	// 如果属性不为空
	if (m_mouseRawLoc)
	{
		delete m_mouseRawLoc;
		m_mouseRawLoc = nullptr;
	}
	m_mouseRawLoc = new QPoint(e->x(), e->y());
}


/**
 * 函数名：mouseMoveEvent
 * 作用：鼠标移动事件
 */
void DraggableLabel::mouseMoveEvent(QMouseEvent* e)
{

}

/**
 * 函数名：mouseReleaseEvent
 * 作用：鼠标放下事件
 */
void DraggableLabel::mouseReleaseEvent(QMouseEvent* e)
{
	QPoint nowPoint = e->pos();

	// 判断是什么操作
	if (nowPoint.x() - m_mouseRawLoc->x() > 20)   // 向右拖
	{
		if (e->button() == Qt::LeftButton)
			emit leftDragToRightSignal();
		else
			emit rightDragToRightSignal();
	}
	if (nowPoint.x() - m_mouseRawLoc->x() < -20) {   // 向左拖
		if (e->button() == Qt::LeftButton)
			emit leftDragToLeftSignal();
		else
			emit rightDragToLeftSignal();
	}
	if (nowPoint.y() - m_mouseRawLoc->y() > 80 && e->button() == Qt::LeftButton)
	{
		emit leftDragToDownSignal();
	}
}

/**
 * 函数名：mouseDoubleClickEvent
 * 作用：鼠标双击事件
 */
void DraggableLabel::mouseDoubleClickEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		emit leftDoubleClickedSignal();
	}
	if (e->button() == Qt::RightButton)
	{
		emit rightDoubleClickedSignal();
	}
}