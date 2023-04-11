#pragma
#ifndef POINTDISTANCE_H
#define POINTDISTANCE_H
#include<iostream>
#include"XYAxix.h"
using namespace std;

class  Pointdistance 
{
private:
    int location ;
    double lowestvalue;
    double FASILA;
public:
    

    void readdata(XYaxis* data,  float centroids[][2], const int rows, const int cols, int K);
    Pointdistance();
    double DISTANCE_OF_EUCLIDEAN(int x1, int y1, int x2, int y2);
    // ya wala funtion new centrid nikalna ka liya haan
    void newcentriod(int* XOFsum, int* YOFSUM, int* checkcount, int K, float centroids[][2], int& c);
    void kMeans(XYaxis* data, XYaxis* clusters, float centroids[][2], const int rows, const int cols, int K);
    void output(XYaxis* data, XYaxis* clusters, float centroids[][2], const int rows, const int cols);

};








#endif // !POINT_H
