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

private:
    Ui::MainWindow *ui;
    LayerShellQt::Window *layerShellWindow = nullptr;  // ← was missing

protected:
    void showEvent(QShowEvent *event) override;
};
#endif // MAINWINDOW_H