#include "k_means.h"
//                                       (russian)
//Алгоритм реализован не полностью, отсутствует пересчет центроидов кластеров, то есть
//центроиды не меняются с изначальной инициализации,тем самым программа работает менее точно и быстрее
//                                      (eng)
// The algorithm is not fully implemented, there is no recalculation of cluster centroids, that is
// centroids have not changed since the initial initialization, thus the program is less accurate and faster


k_means::k_means(QObject *parent) : QObject(parent) {}

// выбор начальных центроидов кластеров
void k_means::Init_centroids() {
    for (int i = 0; i < num_clusters; i++) {
        Cluster cluster;
        QColor pixColor;
        int iteration = 0;
        do {
            int height = rand() % image->height() + 1;
            int width = rand() % image->width()+ 1;
            QPoint position(height, width);
            pixColor = image->pixelColor(height, width);
            cluster = Cluster(pixColor , position);
            iteration++;
        }while((std::find(clusters.begin(), clusters.end(), cluster) != clusters.end() || CheckClustersForRepeats(pixColor)) && iteration != 42);
        clusters.push_back(cluster);
    }
}

// проверка на сильную схожесть цветов
bool k_means::CheckClustersForRepeats(QColor cen) {
    for (auto &it : clusters) {
        int r = pow((cen.red() - it.color.red()), 2);
        int g = pow((cen.green() - it.color.green()), 2);
        int b = pow((cen.blue() - it.color.blue()), 2);
         if ((r + g + b) < 2000)
             return true;
    }
    return false;
}

//вычисляет новый цвет пикселя в зависимости от расстояния между центроидами кластеров
QColor k_means::CalcColor(QColor cen) {
    int min = 100000;
    QColor newColor;
    for (auto &it : clusters) {
        int r = pow((cen.red() - it.color.red()), 2);
        int g = pow((cen.green() - it.color.green()), 2);
        int b = pow((cen.blue() - it.color.blue()), 2);
        if((r + g + b) < min) {
            min = r+g+b;
            newColor = QColor(it.color.rgb());
        }
    }
    return newColor;
}

//изменить цвет пикселей в зависимости от их расстояния между центроидами.
void k_means::Paint() {
    for(int i = 0; i < image->width(); i++) {
        for(int j = 0; j < image->height(); j++) {
            QColor newColor = CalcColor(image->pixelColor(i, j));
            image->setPixelColor(i, j, newColor);
        }
    }
}

QImage* k_means::Clustering(QImage img, int num_clusters) {
    this->image = new QImage(img);
    this->num_clusters = num_clusters;

    Init_centroids();
    Paint();
    return image;
}
