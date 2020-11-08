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
	// 左键双击、左键按住向左拖、左键按住向右拖、左键向下拖、右键双击、右键按住向左拖、右键按住向右拖 
	void leftDoubleClickedSignal();
	void leftDragToLeftSignal();
	void leftDragToRightSignal();
	void leftDragToDownSignal();
	void rightDoubleClickedSignal();
	void rightDragToLeftSignal();
	void rightDragToRightSignal();
};


