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

void MainWindow::setAnchor(const QString &anchor)
{
    m_anchor = anchor;
}

void MainWindow::setDockLength(int dockLength)
{
    m_dockLength = dockLength;
}

void MainWindow::setDockThickness(int dockThickness)
{
    m_dockThickness = dockThickness;
}

void MainWindow::setupLayerShell()
{
    layerShellWindow = LayerShellQt::Window::get(this->windowHandle());
    if (!layerShellWindow) {
        qWarning() << "Failed to get LayerShellQt::Window";
        return;
    }

    layerShellWindow->setLayer(LayerShellQt::Window::LayerBottom);
    layerShellWindow->setMargins(QMargins(0, 0, 0, 0));


    if (m_anchor == "bottom") {
        layerShellWindow->setAnchors(LayerShellQt::Window::Anchors(
            LayerShellQt::Window::AnchorBottom
            ));
        layerShellWindow->setExclusiveZone(m_dockThickness);
        this->resize(m_dockLength, m_dockThickness);

    } else if (m_anchor == "top") {
        layerShellWindow->setAnchors(LayerShellQt::Window::Anchors(
            LayerShellQt::Window::AnchorTop
            ));
        layerShellWindow->setExclusiveZone(m_dockThickness);
        this->resize(m_dockLength, m_dockThickness);

    } else if (m_anchor == "left") {
        layerShellWindow->setAnchors(LayerShellQt::Window::Anchors(
            LayerShellQt::Window::AnchorLeft
            ));
        layerShellWindow->setExclusiveZone(m_dockThickness);
        this->resize(m_dockThickness, m_dockLength);  // ← swapped

    } else if (m_anchor == "right") {
        layerShellWindow->setAnchors(LayerShellQt::Window::Anchors(
            LayerShellQt::Window::AnchorRight
            ));
        layerShellWindow->setExclusiveZone(m_dockThickness);
        this->resize(m_dockThickness, m_dockLength);  // ← swapped
    }
}