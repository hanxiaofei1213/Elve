#pragma once

#include <QtWidgets/QWidget>
#include <QCheckBox>
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>

class DraggableBox : public QCheckBox
{
	Q_OBJECT

public:
	DraggableBox(QWidget* parent = nullptr);

protected:
	void mousePressEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);

signals:
	void deleteDraggableBoxSignal();

private:
	// ��ѡ��ԭʼ���������
	QPoint* m_boxRawLoc;
	// ���ԭʼ��ȫ������
	QPoint* m_mouseRawGlobalLoc;


};
