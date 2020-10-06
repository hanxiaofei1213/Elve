/**
 * ������Memo
 * ���ã�����¼��
 */

#pragma once
#include <QWidget>
#include <QList>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>

class Memo : public QWidget {
	Q_OBJECT
public:
	Memo(QWidget* parent = 0);
	~Memo();

	QLabel* m_mainLabel;
	QList<QCheckBox*>* m_checkBoxList;   // ��Ÿ�ѡ�������
	QVBoxLayout* m_mainlayout;


public slots:
	void addThoughtLineSlot(int);
	void addCheckBoxSlot(QString);
	void deleteCheckBoxSlot();

};
