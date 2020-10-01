/************************************************************************/
/* 备忘录类                                                                     */
/************************************************************************/

#pragma once

#include <QWidget>
#include <QList>

// 前向声明
class QCheckBox;
class QVBoxLayout;

class Memo : public QWidget {
	Q_OBJECT
public:
	Memo(QWidget* parent = 0);
	~Memo();

	QList<QCheckBox*>* m_checkBoxList;   // 存放复选框的数组
	QVBoxLayout* m_mainlayout;


public slots:
	void addThoughtLine(int);
	void addCheckBox(QString);
	void deleteCheckBox();
	

};
