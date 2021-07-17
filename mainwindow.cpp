#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete newImage;
}

//clustering
void MainWindow::on_pushButton_clicked()
{
    int num_clusters = ui->spinBox->value();
    k_means clusterizer;
    QElapsedTimer timer;
    timer.start();
    newImage = clusterizer.Clustering(image, num_clusters);
    ui->lb_time->setText(QString::number(timer.elapsed())+ " ms");
    qDebug() << "Clustering took" << timer.elapsed() << "ms";
    ui->lb_after->setPixmap(QPixmap::fromImage(newImage->scaled(ui->lb_after->width(), ui->lb_after->height())));
}

void MainWindow::on_PB_choose_path_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    image.load(path);
    ui->lb_before->setPixmap(QPixmap::fromImage(image.scaled(ui->lb_before->width(), ui->lb_before->height())));
}

void MainWindow::on_PB_save_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Сохранить как"), "", tr("JPG (*.jpg);;PNG (*.png);; All Files(*)"));
    newImage->save(path);
}
