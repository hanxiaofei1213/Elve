/**
 * ������Memo
 * ���ã�����¼��
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

	void setBackgroundPic(const QString&);       // ���ñ���ͼƬ
	void setLabelSize(const QSize&);             // ����label�Ĵ�С   
	void setLocation(const QSize&);              // ���ò�����λ��
	void showOnePageBox();                       // չʾһҳ��ѡ��


	QPixmap* m_pixmap;                           // ���ͼƬ
	QLabel* m_mainLabel;                         // ��ʾͼƬ��label
	QMap<QString, QCheckBox*>* m_checkBoxMap;    // ��Ÿ�ѡ�������
	QSize* m_size;                               // �ؼ���С
	QSize* m_location;                           // ������λ��
	const int m_onePageBoxCount = 4;             // һҳչʾ���ٸ������¼�
	int m_pageCount;                             // һ��Ҫ����ҳ
	int m_nowPage;                               // ��ǰ�ڼ�ҳ


public slots:
	void addThoughtLineSlot(int);
	void addCheckBoxSlot(QString);               // ��Ӹ�ѡ�� 
	void deleteCheckBoxSlot();                   // ɾ����ѡ��

};
