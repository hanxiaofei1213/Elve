/************************************************************************/
/* �ʼ�Ļ�ӭ����                                                                     */
/************************************************************************/
#pragma once

#include <QWidget>

class QTextBrowser;

class Welcome : public QWidget {
	Q_OBJECT
public:
	Welcome(QWidget* parent = 0);
	QTextBrowser* m_welcomeBrowser;
};