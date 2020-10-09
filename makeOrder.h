/**
 * 下达命令类
 */

#pragma once
#include <QDialog>

// 前向声明
class QLineEdit;
class QLabel;
class QPushButton;
class Elve;

// 类声明
class MakeOrder : public QDialog {
	Q_OBJECT

public:
	MakeOrder(Elve* myElve, QWidget* parent = 0);

	// 界面属性
	QLineEdit* m_orderLineEdit;
	QPushButton* m_yesButton;
	QPushButton* m_noButton;
	QLabel* m_hintMessage;
	QLabel* m_picLabel;

public slots:
	void dealOrder();   // 处理命令的槽函数
	void exitDialog();  // 无需处理，退出对话框的槽函数

signals:
	void addCheckBoxSignal(QString);

};


