#include "mainwindow.h"
#include <QApplication>
#include<QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QLabel *label=new QLabel();
    label->setWindowTitle("Notepad");
    label->resize(500,500);
//    label->setWindowIcon("");
    w.show();
    return a.exec();
}
