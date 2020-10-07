


#include "memo.h"


// ���캯��
Memo::Memo(QWidget* parent) : QWidget(parent)
{
	// ��ʼ������
	m_pixmap = new QPixmap;
	m_mainLabel = new QLabel(this);
	m_checkBoxMap = new QMap<QString, QCheckBox*>;
	m_size = new QSize(150, 140);
	m_pageCount = 1;
	m_nowPage = 1;

	// ���ñ���
	setBackgroundPic(":/myElve/usePic/memoBackground.png");

	// ����label��С
	setLabelSize(*m_size);
}

// ��������
Memo::~Memo()
{
	qDebug() << "xigou";
	delete m_checkBoxMap;
}

/**
 * ��������setBackgroundPic
 * ���ã�������������¼�ı���ͼƬ
 */
void Memo::setBackgroundPic(const QString& a_picName)
{
	// ���ͼƬ�Ƿ�Ϸ�
	if (a_picName == nullptr || a_picName.isEmpty() || !m_pixmap->load(a_picName))
	{
		QMessageBox::warning(this, "Programe Error", " Illegal picture in Memo::setBackgroundPic(const QString&) ");
		exit(0);
	}

	// ����ͼƬ�ɹ�
	m_mainLabel->setPixmap(*m_pixmap);
}


void Memo::setLabelSize(const QSize& a_size)
{
	m_mainLabel->setFixedSize(a_size);
}


// TODO�����Ҫÿ�ζ���һ�²�����
// ���checkBox�ķ���������ĸ�����
void Memo::addCheckBoxSlot(QString a_text)
{

}

// ɾ��checkBox�ķ���
void Memo::deleteCheckBoxSlot()
{

}

// ���ɾ���ߵĲ�
// TODO:����������
void Memo::addThoughtLineSlot(int a_state)
{
	QCheckBox* box = (QCheckBox*)sender();
	if (a_state == Qt::Checked)
	{
		box->setStyleSheet("text-decoration: line-through;");
		//QSound::play(":/myElve/messionComplete.wav");
	}
	else {
		box->setStyleSheet("");
	}
}
