#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <LayerShellQt/Window>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void setupLayerShell();

    void setAnchor(const QString &anchor);
    void setDockThickness(int dockThickness);
    void setDockLength(int dockLength);
    void setDockMargin(int dockMargin);

private:
    Ui::MainWindow *ui;
    LayerShellQt::Window *layerShellWindow = nullptr;  // ← was missing

    QString m_anchor = "bottom";
    int m_dockThickness = 48;
    int m_dockLength = 700;
    int m_dockMargin = 8;

protected:
    void showEvent(QShowEvent *event) override;
};
#endif // MAINWINDOW_H