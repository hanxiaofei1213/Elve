#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>

class DraggableLabel : public QLabel {
	Q_OBJECT

public:
	DraggableLabel(QWidget* parent = NULL);
	~DraggableLabel();


protected:
	void mousePressEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void mouseDoubleClickEvent(QMouseEvent*);

private:
	QPoint* m_mouseRawLoc;

signals:
	// ���˫���������ס�����ϡ������ס�����ϡ���������ϡ��Ҽ�˫�����Ҽ���ס�����ϡ��Ҽ���ס������ 
	void leftDoubleClickedSignal();
	void leftDragToLeftSignal();
	void leftDragToRightSignal();
	void leftDragToDownSignal();
	void rightDoubleClickedSignal();
	void rightDragToLeftSignal();
	void rightDragToRightSignal();
};


