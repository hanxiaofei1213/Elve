
#include "memo.h"


// ���캯��
Memo::Memo(QWidget* parent) : QWidget(parent)
{
	// ��ʼ������
	m_pixmap = new QPixmap;
	m_mainLabel = new QLabel(this);
	m_bottomSpacer = new QSpacerItem(5, 5, QSizePolicy::Expanding, QSizePolicy::Expanding);    // ����Ĭ����ô��
	m_draggableBoxMap = new QMap<QString, DraggableBox*>;
	m_size = new QSize(150, 140);
	m_location = new QPoint(40, 0);
	m_layout = new QVBoxLayout(this);
	m_pageCount = 1;
	m_nowPage = 1;
	m_totalBox = 0;
	m_totalCompletedBox = 0;
	m_mousePressPoint = new QPoint(0, 0);


	// ���ñ���
	setBackgroundPic(":/myElve/usePic/memoBackground.png");

	// ����label��С
	setLabelSize(*m_size);
	
	// ���ò��ֵ�����
	m_layout->setSpacing(10);
	m_layout->addItem(m_bottomSpacer);
	setLayout(m_layout);

	// ��ʾ���и�ѡ��
	showOnePageBox();
}

// ��������
Memo::~Memo()
{
	
}

/**
 * ��������setBackgroundPic
 * ���ã�������������¼�ı���ͼƬ
 * TODO����Ҫ����show������
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

/**
 * ��������setLabelSize
 * ���ã�����label�Ĵ�С
 */
void Memo::setLabelSize(const QSize& a_size)
{
	m_mainLabel->setFixedSize(a_size);
}


/**
 * ��������setLocation
 * ���ã����������λ��
 */
void Memo::setLocation(const QPoint& a_locationPoint)
{
	this->move(a_locationPoint);
}


/**
 * ��������showOnePageBox
 * ���ã�����һҳ��༸����ѡ����չʾһҳ
 */
void Memo::showOnePageBox()
{
	// ���ײ������ȴӲ����Ƴ��������������ϣ���֤�ײ�����һֱ�ڵײ�
	// ʹ��insertItem��������indexΪ�����в�ͨ
	m_layout->removeItem(m_bottomSpacer);

	// ������Ÿ�ѡ���map
	int i = 0;
	for each (auto box in *m_draggableBoxMap)
	{
		// ����ø�ѡ���Ѿ���ӵ������ˣ���ʲôҲ�������������������
		if (box->layout() != m_layout)
			m_layout->addWidget(box);

		// �����ǰ�ĸ�ѡ���ǵ�ǰҳ�����ݣ������أ�������չʾ����
		if (i < (m_nowPage - 1) * m_onePageBoxCount || i >= m_nowPage * m_onePageBoxCount)
		{
			box->hide();
		}
		else {
			box->show();
		}

		i++;
	}

	// ��󽫵ײ����������
	m_layout->addItem(m_bottomSpacer);
}

/**
 * ��������changePageSlot
 * ���ã�������ҳ�Ĳۺ���
 */
void Memo::changePage(bool a_isdown)
{
	if (a_isdown)
	{
		m_nowPage = (m_nowPage >= m_pageCount) ? (m_nowPage + 1 - m_pageCount) : m_nowPage + 1;
	} else {
		m_nowPage = (m_nowPage <= 1) ? (m_nowPage - 1 + m_pageCount) : m_nowPage - 1;
	}
		

	showOnePageBox();
}

/**
 * ��������addCheckBoxSlot
 * ���ã����һ����ѡ�򣬲��������map�У���������ʾ��������ˢ�½���
 */
void Memo::addCheckBoxSlot(QString a_text)
{
	// ������ѡ��
	DraggableBox* box = new DraggableBox(this);
	box->setText(a_text);
	box->setObjectName(QString(m_totalBox));

	// �������ӣ�ÿ����ѡ��״̬�仯ʱ������״̬���ɾ����
	connect(box, &DraggableBox::stateChanged, this, &Memo::addThoughtLineSlot);
	connect(box, &DraggableBox::deleteDraggableBoxSignal, this, &Memo::deleteCheckBoxSlot);

	// ��ӵ�map��
	m_draggableBoxMap->insert(box->objectName(), box);

	// ���¸���������
	m_totalBox++;
	m_pageCount = m_totalBox / m_onePageBoxCount + 1;

	// ������ʾ�ķ���
	showOnePageBox();
}



// ɾ��checkBox�ķ���
void Memo::deleteCheckBoxSlot()
{
	DraggableBox* box = (DraggableBox*)sender();
	m_draggableBoxMap->remove(box->objectName());
	delete box;

	showOnePageBox();
}


/**
 * ��������addThoughtLineSlot
 * ���ã���������ѡ�����ɾ���ߵĲۺ���
 * TODO:����������
 */
void Memo::addThoughtLineSlot(int a_state)
{
	DraggableBox* box = (DraggableBox*)sender();
	if (a_state == Qt::Checked)
	{
		box->setStyleSheet("text-decoration: line-through;");
		//QSound::play(":/myElve/messionComplete.wav");
	}
	else {
		box->setStyleSheet("");
	}
}




// �������ģ��
// ============================================================

/**
 * ��������mousePressEvent
 * ���ã�������¼��ʼ��λ��������ͷŵ�λ���Ƚϣ������Ϸ�ҳ�������·�ҳ
 */
void Memo::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::RightButton)
		*m_mousePressPoint = e->globalPos();
}


/**
 * ��������mouseReleaseEvent
 * ���ã������ͷ�λ�õ����y���꣬����갴��λ�õ�y����Ƚϣ�������ҳ����
 */
void Memo::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::RightButton)
	{
		bool isdown = e->globalPos().y() - m_mousePressPoint->y();
		changePage(isdown);
	}
		
}
