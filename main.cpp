#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator translator;
    if(translator.load(QLocale::system(), "Annotations", "_", app.applicationDirPath(), ".qm")) {
        app.installTranslator(&translator);
    }
    MainWindow w;
    w.setWindowTitle("Quatro");
    w.setWindowIcon(QIcon("Bureau/projet/images/Quarto.jpg"));
    w.show();

    return app.exec();
}
