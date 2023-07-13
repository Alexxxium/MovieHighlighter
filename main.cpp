#include <QApplication>
#include <QTextStream>
#include <locale>
#include <QFile>

#include "mainwindow.h"



int main(int argc, char* argv[])
{
    std::setlocale(LC_ALL, "ru_RU.utf8");

    QApplication app(argc, argv);

    constexpr auto style_path = ":/src/style/cascade.qss";
    QFile style(style_path);

    if (style.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&style);
        app.setStyleSheet(stream.readAll());
    }
    
    mv::MainWindow::getInstanse()->show();

    return app.exec();
}
