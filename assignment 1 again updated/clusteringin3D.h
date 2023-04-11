#pragma once
#ifndef CLUSTERINGIN3D_H
#define CLUSTERINGIN3D_H

#include"XYAxix.h"
#include<iostream>
using namespace std;

class  Pointdistance3d
{
private:
    int location;
    double lowerstjaga;
    double fasila;
public:


    void readdata(XYaxis* data,  float centroids[][3], const int rows, const int cols, int K);
    Pointdistance3d();
    double DISTANCE_OF_EUCLIDEAN(int x1, int y1, int z1, int x2, int y2, int z2);
    // ya wala funtion new centrid nikalna ka liya haan
    void newcentriod(int* XOFsum, int* YOFSUM, int* ZOFSUM, int* checkcount, int K, float centroids[][3], int& c);
    void kMeans(XYaxis* data, XYaxis* clusters, float centroids[][3], const int rows, const int cols, int K);
    void output(XYaxis* data, XYaxis* clusters, float centroids[][3], const int rows, const int cols);


};







#endif // !CLUSTERINGIN3D
