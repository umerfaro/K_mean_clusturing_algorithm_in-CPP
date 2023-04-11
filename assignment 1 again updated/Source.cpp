#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include<sstream>
#include"Point.h"
#include<ctime>
#include"clusteringin3D.h"
#include"XYAxix.h"


using namespace std;


int main() 
{
    srand(time(0));
    Pointdistance p;

    const int rows = 4000;
    const int cols = 2;
     const int K = 5;

     XYaxis* data = new XYaxis[4000];

     XYaxis* clusters=new  XYaxis  [4000];

    float centroids[K][2]{ 0.0 };
    
    p.readdata(data,  centroids, rows, cols, K);

   p. kMeans(data, clusters, centroids, rows, cols, K);
   
   p.output(data, clusters, centroids, rows, cols);
    
    delete[] data;
    delete []clusters;
//.......................................................................................................................//
    //Tast 2
////
//    Pointdistance3d q;
//    srand(time(0));
//
//
//    const int rows = 200;
//    const int columensize = 3;
//    const int K = 5;
//
//    XYaxis* datas = new XYaxis[200];
//    
//    XYaxis* cluster = new XYaxis[200];
//
//    float centroid[K][3]{ 0.0 };
//
//    q.readdata(datas,  centroid, rows, columensize, K);
//    q.kMeans(datas, cluster, centroid, rows, columensize, K);
//    q.output(datas, cluster, centroid, rows, columensize);
//
//    
//    delete[] datas;
//
//    
//        delete[] cluster;
 
    return 0;
}

