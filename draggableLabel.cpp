

#include "draggableLabel.h"

// ���캯��
DraggableLabel::DraggableLabel(QWidget* parent) 
	: QLabel(parent), m_mouseRawLoc(nullptr)
{
	
}

// ��������
DraggableLabel::~DraggableLabel()
{
	if (m_mouseRawLoc)
		delete m_mouseRawLoc;
	m_mouseRawLoc = nullptr;
}

/**
 * ��������mousePressEvent
 * ���ã���갴���¼�����¼�������꣨���
 */
void DraggableLabel::mousePressEvent(QMouseEvent* e)
{
	// ������Բ�Ϊ��
	if (m_mouseRawLoc)
	{
		delete m_mouseRawLoc;
		m_mouseRawLoc = nullptr;
	}
	m_mouseRawLoc = new QPoint(e->x(), e->y());
}


/**
 * ��������mouseMoveEvent
 * ���ã�����ƶ��¼�
 */
void DraggableLabel::mouseMoveEvent(QMouseEvent* e)
{

}

/**
 * ��������mouseReleaseEvent
 * ���ã��������¼�
 */
void DraggableLabel::mouseReleaseEvent(QMouseEvent* e)
{
	QPoint nowPoint = e->pos();

	// �ж���ʲô����
	if (nowPoint.x() - m_mouseRawLoc->x() > 20)   // ������
	{
		if (e->button() == Qt::LeftButton)
			emit leftDragToRightSignal();
		else
			emit rightDragToRightSignal();
	}
	if (nowPoint.x() - m_mouseRawLoc->x() < -20) {   // ������
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
 * ��������mouseDoubleClickEvent
 * ���ã����˫���¼�
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