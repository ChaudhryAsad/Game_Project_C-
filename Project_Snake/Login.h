#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game_screen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_openGLWidget_aboutToCompose();

    void on_frame_customContextMenuRequested(const QPoint &pos);

    void on_label_pic_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
    game_screen *game_screen;
};
#endif // MAINWINDOW_H
