#include "mainwindow.h"
#include <QApplication>

#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription("hypr_dock - A Hyprland dock");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption anchorOption(
        QStringList() << "a" << "anchor",
        "Anchor position: top, bottom, left, right",
        "anchor",
        "bottom"   // default value
        );

    parser.addOption(anchorOption);

    parser.process(a);

    QString anchor = parser.value(anchorOption).toLower();

    MainWindow w;
    w.show();
    return QCoreApplication::exec();
}
