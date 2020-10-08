/**
 * 类名：Memo
 * 作用：备忘录类
 */

#pragma once
#include <QtWidgets/QWidget>
#include <QMap>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QSize>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QPoint>
#include <QMapIterator>
#include <QSpacerItem>
#include <QMouseEvent>

#include "draggableBox.h"

class Memo : public QWidget {
	Q_OBJECT
public:
	Memo(QWidget* parent = 0);
	~Memo();

	void setBackgroundPic(const QString&);       // 设置背景图片
	void setLabelSize(const QSize&);             // 设置label的大小   
	void setLocation(const QPoint&);             // 设置部件的位置
	void showOnePageBox();                       // 展示一页复选框
	void changePage(bool);                       // 用来改变展示第几页的槽函数

	QPixmap* m_pixmap;                           // 存放图片
	QLabel* m_mainLabel;                         // 显示图片的label
	QSpacerItem* m_bottomSpacer;                 // 放在最下面，把复选框顶起来的弹簧
	QMap<QString, DraggableBox*>* m_draggableBoxMap; // 存放复选框的容器
	QSize* m_size;                               // 控件大小
	QPoint* m_location;                          // 部件的位置
	QVBoxLayout* m_layout;                       // 布局 
	const int m_onePageBoxCount = 4;             // 一页展示多少个待做事件
	int m_pageCount;                             // 一共要多少页
	int m_nowPage;                               // 当前第几页
	int m_totalBox;                              // 一共多少box了已经
	int m_totalCompletedBox;                     // 一共完成多少了
	QPoint* m_mousePressPoint;                   // 鼠标右键按下的位置

public slots:
	void addThoughtLineSlot(int);                // 为复选框添加删除线   
	void addCheckBoxSlot(QString);               // 添加复选框 
	void deleteCheckBoxSlot();                   // 删除复选框
	

protected:
	// 鼠标手势模块，使得可以用手势便捷的操作
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
};
