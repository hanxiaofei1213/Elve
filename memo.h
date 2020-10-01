/************************************************************************/
/* ����¼��                                                                     */
/************************************************************************/

#pragma once

#include <QWidget>
#include <QList>

// ǰ������
class QCheckBox;
class QVBoxLayout;

class Memo : public QWidget {
	Q_OBJECT
public:
	Memo(QWidget* parent = 0);
	~Memo();

	QList<QCheckBox*>* m_checkBoxList;   // ��Ÿ�ѡ�������
	QVBoxLayout* m_mainlayout;


public slots:
	void addThoughtLine(int);
	void addCheckBox(QString);
	void deleteCheckBox();
	

};
