# k-means clustering of image
-----------------------------

Clustering of image by k-means algorithm

The source image is selected when `Main.kt` is starting

To display the image is used `JPanel` and `BufferedImage` in `Image.kt`

Clustered image is saved in root of project

-----------------------------

`IClusterizer.kt` allows you to add others implementations of clustering

`Cluster.kt` and `Pixel.kt` just (nearly) data classes for clustering

`KMeansClusterizer.kt` - my implementation of k-means. Details of implementation are described in comments in class file.


# Results:


| **Source Image**  | **2-Clusters** |
| :---:  | :---:  |
|![1a](https://github.com/Krutov777/k_means_clustering_image/blob/main/images/woman.jpg)|![clusteredImage(k = 2)](https://github.com/Krutov777/k_means_clustering_image/blob/main/images/woman2clusters.jpg)|
| **5-Clusters**  | **10-Clusters** |
|![clusteredImage(k = 5)](https://github.com/Krutov777/k_means_clustering_image/blob/main/images/woman5clusters.jpg)|![clusteredImage(k = 10)](https://github.com/Krutov777/k_means_clustering_image/blob/main/images/woman10clusters.jpg)|
