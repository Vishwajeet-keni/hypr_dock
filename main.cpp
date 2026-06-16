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


    QCommandLineOption dockThicknessOption(
        QStringList() << "t" << "dock-thickness",
        "Default dock-thickness :  48px",
        "dock-thickness",
        "48"      // default value
        );
    parser.addOption(dockThicknessOption);

    QCommandLineOption dockLengthOption(
        QStringList() << "l" << "dock-length",
        "Default dock length    : 700px",
        "dock-length",
        "700"      // default value
        );
    parser.addOption(dockLengthOption);

    QCommandLineOption dockMarginOption(
        QStringList() << "m" << "dock-margin",
        "Default dock margin    :   8px",
        "dock-margin",
        "8"      // default value
        );
    parser.addOption(dockMarginOption);

    parser.process(a);
    QString anchor = parser.value(anchorOption).toLower();
    int dockThickness = parser.value(dockThicknessOption).toInt();
    int dockLength = parser.value(dockLengthOption).toInt();
    int dockMargin = parser.value(dockMarginOption).toInt();




    MainWindow w;
    w.setAnchor(anchor);
    w.setDockThickness(dockThickness);
    w.setDockLength(dockLength);
    w.setDockMargin(dockMargin);

    w.show();
    return QCoreApplication::exec();
}
