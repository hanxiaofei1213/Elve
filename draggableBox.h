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
	// 复选框原始的相对坐标
	QPoint* m_boxRawLoc;
	// 鼠标原始的全局坐标
	QPoint* m_mouseRawGlobalLoc;


};
