#include "myElve.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString qss;
	QFile qssFile(":/myElve/myQss.qss");
	qssFile.open(QFile::ReadOnly);

	if (qssFile.isOpen())
	{
		qDebug()  << "qss open success" ;
		qss = QString(qssFile.readAll());
		a.setStyleSheet(qss);
		qssFile.close();
	} else {
		qDebug() << "qss open failed";
	}

	MyElve w;
	w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);  // 设置窗口总在最前
    w.show();
    return a.exec();
}
