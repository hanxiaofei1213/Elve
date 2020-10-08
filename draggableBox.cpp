

#include "draggableBox.h"

// ���캯��
DraggableBox::DraggableBox(QWidget* parent)
	: QCheckBox(parent)
{
	m_boxRawLoc = new QPoint(0, 0);
	m_mouseRawGlobalLoc = new QPoint(0, 0);

}

/**
 * ��������mousePressEvent
 * ���ã���¼���¸�ѡ����������꣬���Ժ��ƶ�ʹ��
 */
void DraggableBox::mousePressEvent(QMouseEvent* e)
{
	// ��¼��ǰ��ѡ����������
	*m_boxRawLoc = this->pos();

	// ��¼��ǰ��ѡ��ȫ������
	*m_mouseRawGlobalLoc = e->globalPos();

	// ���ø���İ����¼�
	QCheckBox::mousePressEvent(e);
}

/**
 * ��������mouseMoveEvent
 * ���ã���������ƶ��ľ��룬���������ò�����λ�ã��Դ���ʵ������϶�����
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
 * ��������mouseReleaseEvent
 * ���ã������жϣ�����ѡ���Ƿ���߿�
 */
void DraggableBox::mouseReleaseEvent(QMouseEvent* e)
{
	QCheckBox::mouseReleaseEvent(e);
	if (this->pos().x() < 0 || this->pos().y() < 0)
		emit deleteDraggableBoxSignal();
	else
		this->move(*m_boxRawLoc);
}


