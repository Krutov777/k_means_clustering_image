#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include  "k_means.h"
#include "QFileDialog"
#include "QElapsedTimer"
#include "QDebug"
#include "QPixmap"

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
    void on_pushButton_clicked();

    void on_PB_choose_path_clicked();

    void on_PB_save_clicked();

private:
    Ui::MainWindow *ui;
     QImage* newImage;
     QImage image;
};
#endif // MAINWINDOW_H
