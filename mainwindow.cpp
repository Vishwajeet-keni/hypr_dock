#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QShowEvent>
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include <LayerShellQt/Window>

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    static bool once = false;
    if (!once) {
        once = true;
        setupLayerShell();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupLayerShell()
{
    // useLayerShell() is deprecated since Qt 6.5 — no longer needed

    layerShellWindow = LayerShellQt::Window::get(this->windowHandle());
    if (!layerShellWindow) {
        qWarning() << "Failed to get LayerShellQt::Window";
        return;
    }

    layerShellWindow->setLayer(LayerShellQt::Window::LayerBottom);

    layerShellWindow->setAnchors(
        LayerShellQt::Window::Anchors(
            LayerShellQt::Window::AnchorBottom |
            LayerShellQt::Window::AnchorLeft   |
            LayerShellQt::Window::AnchorRight
            )
        );

    const int dockHeight = 48;
    layerShellWindow->setExclusiveZone(dockHeight);
    layerShellWindow->setMargins(QMargins(0, 0, 0, 0));

    QScreen *screen = QGuiApplication::primaryScreen();
    this->resize(screen->availableGeometry().width(), dockHeight);
}