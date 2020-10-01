#include "myElve.h"
#include <QtWidgets/QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString qss;
	QFile qssFile(":/Elve/myQss.qss");
	qssFile.open(QFile::ReadOnly);

	if (qssFile.isOpen())
	{
		qss = QString(qssFile.readAll());
		a.setStyleSheet(qss);
		qssFile.close();
	}

	MyElve w;
	w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);  // 设置窗口总在最前
    w.show();
    return a.exec();
}
