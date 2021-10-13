#include <QApplication>
#include "widget.h"
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow mainWin;
    mainWin.setWindowTitle(QObject::tr("Qt SQL Browser"));

    Widget w(&mainWin);

    mainWin.setCentralWidget(&w);
    mainWin.show();

    return a.exec(); //&#40;&#41;;
}
