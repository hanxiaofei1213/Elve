#include <QTextBrowser>
#include <QPixmap>
#include "welcome.h"


Welcome::Welcome(QWidget* parent)
	:QWidget(parent)
{
	m_welcomeBrowser = new QTextBrowser(this);
	m_welcomeBrowser->setText("Welcome!");
}