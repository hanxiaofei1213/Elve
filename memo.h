/**
 * 类名：Memo
 * 作用：备忘录类
 */

#pragma once
#include <QWidget>
#include <QMap>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QSize>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

class Memo : public QWidget {
	Q_OBJECT
public:
	Memo(QWidget* parent = 0);
	~Memo();

	void setBackgroundPic(const QString&);       // 设置背景图片
	void setLabelSize(const QSize&);             // 设置label的大小   
	void setLocation(const QSize&);              // 设置部件的位置
	void showOnePageBox();                       // 展示一页复选框


	QPixmap* m_pixmap;                           // 存放图片
	QLabel* m_mainLabel;                         // 显示图片的label
	QMap<QString, QCheckBox*>* m_checkBoxMap;    // 存放复选框的容器
	QSize* m_size;                               // 控件大小
	QSize* m_location;                           // 部件的位置
	const int m_onePageBoxCount = 4;             // 一页展示多少个待做事件
	int m_pageCount;                             // 一共要多少页
	int m_nowPage;                               // 当前第几页


public slots:
	void addThoughtLineSlot(int);
	void addCheckBoxSlot(QString);               // 添加复选框 
	void deleteCheckBoxSlot();                   // 删除复选框

};
