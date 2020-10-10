
#include "memo.h"


// 构造函数
Memo::Memo(QWidget* parent) : QWidget(parent)
{
	// 初始化属性
	m_pixmap = new QPixmap;
	m_mainLabel = new QLabel(this);
	m_bottomSpacer = new QSpacerItem(5, 5, QSizePolicy::Expanding, QSizePolicy::Expanding);    // 弹簧默认这么大
	m_draggableBoxMap = new QMap<QString, DraggableBox*>;
	m_size = new QSize(150, 140);
	m_location = new QPoint(40, 0);
	m_layout = new QVBoxLayout(this);
	m_pageCount = 1;
	m_nowPage = 1;
	m_totalBox = 0;
	m_totalCompletedBox = 0;
	m_mousePressPoint = new QPoint(0, 0);


	// 设置背景
	setBackgroundPic(":/myElve/usePic/memoBackground.png");

	// 设置label大小
	setLabelSize(*m_size);
	
	// 设置布局的属性
	m_layout->setSpacing(10);
	m_layout->addItem(m_bottomSpacer);
	setLayout(m_layout);

	// 显示所有复选框
	showOnePageBox();
}

// 析构函数
Memo::~Memo()
{
	
}

/**
 * 函数名：setBackgroundPic
 * 作用：设置整个备忘录的背景图片
 * TODO：需要调用show方法吗？
 */
void Memo::setBackgroundPic(const QString& a_picName)
{
	// 检查图片是否合法
	if (a_picName == nullptr || a_picName.isEmpty() || !m_pixmap->load(a_picName))
	{
		QMessageBox::warning(this, "Programe Error", " Illegal picture in Memo::setBackgroundPic(const QString&) ");
		exit(0);
	}

	// 加载图片成功
	m_mainLabel->setPixmap(*m_pixmap);
}

/**
 * 函数名：setLabelSize
 * 作用：设置label的大小
 */
void Memo::setLabelSize(const QSize& a_size)
{
	m_mainLabel->setFixedSize(a_size);
}


/**
 * 函数名：setLocation
 * 作用：设置组件的位置
 */
void Memo::setLocation(const QPoint& a_locationPoint)
{
	this->move(a_locationPoint);
}


/**
 * 函数名：showOnePageBox
 * 作用：根据一页最多几个复选框，来展示一页
 */
void Memo::showOnePageBox()
{
	// 将底部弹簧先从布局移出，在最后再添加上，保证底部弹簧一直在底部
	// 使用insertItem方法并且index为负数行不通
	m_layout->removeItem(m_bottomSpacer);

	// 遍历存放复选框的map
	int i = 0;
	for each (auto box in *m_draggableBoxMap)
	{
		// 如果该复选框已经添加到布局了，就什么也不做，否则添加至布局
		if (box->layout() != m_layout)
			m_layout->addWidget(box);

		// 如果当前的复选框不是当前页的内容，则隐藏，否则则展示出来
		if (i < (m_nowPage - 1) * m_onePageBoxCount || i >= m_nowPage * m_onePageBoxCount)
		{
			box->hide();
		}
		else {
			box->show();
		}

		i++;
	}

	// 最后将底部弹簧添加上
	m_layout->addItem(m_bottomSpacer);
}

/**
 * 函数名：changePageSlot
 * 作用：用来换页的槽函数
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
 * 函数名：addCheckBoxSlot
 * 作用：添加一个复选框，并且添加入map中，最后调用显示函数用来刷新界面
 */
void Memo::addCheckBoxSlot(QString a_text)
{
	// 创建复选框
	DraggableBox* box = new DraggableBox(this);
	box->setText(a_text);
	box->setObjectName(QString(m_totalBox));

	// 建立连接，每当复选框状态变化时，根据状态添加删除线
	connect(box, &DraggableBox::stateChanged, this, &Memo::addThoughtLineSlot);
	connect(box, &DraggableBox::deleteDraggableBoxSignal, this, &Memo::deleteCheckBoxSlot);

	// 添加到map中
	m_draggableBoxMap->insert(box->objectName(), box);

	// 更新个数等属性
	m_totalBox++;
	m_pageCount = m_totalBox / m_onePageBoxCount + 1;

	// 调用显示的方法
	showOnePageBox();
}



// 删除checkBox的方法
void Memo::deleteCheckBoxSlot()
{
	DraggableBox* box = (DraggableBox*)sender();
	m_draggableBoxMap->remove(box->objectName());
	delete box;

	showOnePageBox();
}


/**
 * 函数名：addThoughtLineSlot
 * 作用：用来给复选框添加删除线的槽函数
 * TODO:处理下音乐
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




// 鼠标手势模块
// ============================================================

/**
 * 函数名：mousePressEvent
 * 作用：用来记录起始点位，和最后释放点位做比较，看向上翻页还是向下翻页
 */
void Memo::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::RightButton)
		*m_mousePressPoint = e->globalPos();
}


/**
 * 函数名：mouseReleaseEvent
 * 作用：根据释放位置的鼠标y坐标，和鼠标按下位置的y坐标比较，决定翻页方向
 */
void Memo::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::RightButton)
	{
		bool isdown = e->globalPos().y() - m_mousePressPoint->y();
		changePage(isdown);
	}
		
}
