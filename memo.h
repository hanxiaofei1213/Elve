/**
 * ������Memo
 * ���ã�����¼��
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

	void setBackgroundPic(const QString&);       // ���ñ���ͼƬ
	void setLabelSize(const QSize&);             // ����label�Ĵ�С   
	void setLocation(const QPoint&);             // ���ò�����λ��
	void showOnePageBox();                       // չʾһҳ��ѡ��
	void changePage(bool);                       // �����ı�չʾ�ڼ�ҳ�Ĳۺ���

	QPixmap* m_pixmap;                           // ���ͼƬ
	QLabel* m_mainLabel;                         // ��ʾͼƬ��label
	QSpacerItem* m_bottomSpacer;                 // ���������棬�Ѹ�ѡ�������ĵ���
	QMap<QString, DraggableBox*>* m_draggableBoxMap; // ��Ÿ�ѡ�������
	QSize* m_size;                               // �ؼ���С
	QPoint* m_location;                          // ������λ��
	QVBoxLayout* m_layout;                       // ���� 
	const int m_onePageBoxCount = 4;             // һҳչʾ���ٸ������¼�
	int m_pageCount;                             // һ��Ҫ����ҳ
	int m_nowPage;                               // ��ǰ�ڼ�ҳ
	int m_totalBox;                              // һ������box���Ѿ�
	int m_totalCompletedBox;                     // һ����ɶ�����
	QPoint* m_mousePressPoint;                   // ����Ҽ����µ�λ��

public slots:
	void addThoughtLineSlot(int);                // Ϊ��ѡ�����ɾ����   
	void addCheckBoxSlot(QString);               // ��Ӹ�ѡ�� 
	void deleteCheckBoxSlot();                   // ɾ����ѡ��
	

protected:
	// �������ģ�飬ʹ�ÿ��������Ʊ�ݵĲ���
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
};
