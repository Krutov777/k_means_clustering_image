#ifndef K_MEANS_H
#define K_MEANS_H

#include <QObject>
#include <QImage>
#include <cmath>

class Cluster {
public:
    QColor color;
    QPoint position;
    Cluster() {};
    Cluster(QColor col, QPoint pos) {color = col; position = pos;};
    bool operator ==(Cluster obj) {
        return this->color == obj.color && this->position == obj.position;
    }
};

class k_means : public QObject
{
    Q_OBJECT
public:
    explicit k_means(QObject *parent = nullptr);

    QImage* Clustering(QImage img, int num_clusters);

private:
        void Init_centroids();
        bool CheckClustersForRepeats(QColor cen); //функция вычисляет цветовое расстояние между случайными пикселями
        QColor CalcColor(QColor cen);                        //вычисляет новый цвет пикселя в зависимости от расстояния между центроидами кластеров
        void Paint();
private:
        int num_clusters;
        std::vector<Cluster> clusters;
        QImage* image;
};

#endif // K_MEANS_H
