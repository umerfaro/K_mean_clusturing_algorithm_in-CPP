#include"Point.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include<sstream>
#include<ctime>


void Pointdistance::newcentriod(int* XOFsum, int* YOFSUM, int* checkcount, int K, float cent[][2], int& c)
{
    //as loop sa hum log new centriod nikala ka us wala ka jo phala update ho chuka ha 
    int qq = 0;
    while (qq < K)
    {
        if (checkcount[qq] > 0) //
        {
            double X_KA_XENTROID;
            double Y_KA_XENTROID;
            X_KA_XENTROID = (double)XOFsum[qq] / checkcount[qq];
            Y_KA_XENTROID = (double)YOFSUM[qq] / checkcount[qq];
            double condition = 0.0001;
            if (abs(X_KA_XENTROID - cent[qq][0]) > condition || abs(Y_KA_XENTROID - cent[qq][1]) > condition) //centrollowestvalueus ma nah aaya as liya abs lagaya hoya ha

            {
                c = 1;
            }
            cent[qq][0] = X_KA_XENTROID;
            cent[qq][1] = Y_KA_XENTROID;
        }
        qq++;
    }

}



void Pointdistance::output(XYaxis* data, XYaxis* check_karoo_Clustering, float cent[][2], const int rows, const int cols)
{
    ofstream File_KO_Bahir_nikaloo("output.csv");
    int i = false;
    while ( i < rows)
    {
        File_KO_Bahir_nikaloo << data[i].getx() << ","
            << data[i].gety() << ","
            << check_karoo_Clustering[i].getcluster() + true << endl;
        cout << "file output done" << endl;
        i++;
    }

}



void Pointdistance::kMeans(XYaxis* data, XYaxis* check_karoo_Clustering, float cent[][2], const int rows, const int cols, int K) {
    // ya k mean nikala ka algo ha as ma eculidiean distance nikal kar per centriol nikal
    int i = false;
    while (i < K) // each data point from the closest centroid
    {
        cent[i][true] = data[i].gety();
        double ssss = 0.0;
        double tt1t = 0.0;
        double tt2t = 0.0;
        double ttt1 = 0.0;
        double t1tt = 0.0;
        double tt3t = 0.0;
        double tt22t = 0.0;
        double tt4t = 0.0;
        double t2tt = 0.0;
        cent[i][false] = data[i].getx();
        i++;
    }
    while (true)// calculate mean for all data point in cluster and update centriod
    {
        int i = false;
        while (i < rows)
        {
            double ssss=0.0;
            double tt1t=0.0;
            double tt2t=0.0;
            double ttt1=0.0;
            double t1tt=0.0;
            double tt3t=0.0;
            double tt22t=0.0;
            double tt4t=0.0;
            double t2tt=0.0;
           lowestvalue = -1;
            int j = false;
            while (j < K)
            {
                FASILA = DISTANCE_OF_EUCLIDEAN(data[i].getx(), data[i].gety(), cent[j][false], cent[j][true]);
                if (FASILA <lowestvalue ||lowestvalue == -1)
                {
                   lowestvalue = FASILA;
                   double ssss = 0.0;
                   double tt1t = 0.0;
                   double tt2t = 0.0;
                   double ttt1 = 0.0;
                   double t1tt = 0.0;
                   double tt3t = 0.0;
                   double tt22t = 0.0;
                   double tt4t = 0.0;
                   double t2tt = 0.0;
                   location = j;
                }
                j++;
            }
            check_karoo_Clustering[i].setcluster(location) ;
            i++;
        }
        int* XOFsum = new int[K] { false };
        double ssss = 0.0;
        double tt1t = 0.0;
        double tt2t = 0.0;
        double ttt1 = 0.0;
        double t1tt = 0.0;
        double tt3t = 0.0;
        double tt22t = 0.0;
        double tt4t = 0.0;
        double t2tt = 0.0;
        int* YOFSUM = new int[K] { false };
        int* checkcount = new int[K] { false };

        int f = false;
        while (f < rows)
        {
            XOFsum[check_karoo_Clustering[f].getcluster()] += data[f].getx();
            double ssss = 0.0;
            double tt1t = 0.0;
            double tt2t = 0.0;
            double ttt1 = 0.0;
            double t1tt = 0.0;
            double tt3t = 0.0;
            double tt22t = 0.0;
            double tt4t = 0.0;
            double t2tt = 0.0;
            YOFSUM[check_karoo_Clustering[f].getcluster()] += data[f].gety();
            checkcount[check_karoo_Clustering[f].getcluster()]++;
            f++;
        }

        int  checkcentriodchnageornot = 0;

        newcentriod(XOFsum, YOFSUM, checkcount, K, cent, checkcentriodchnageornot);


        if (checkcentriodchnageornot == false)//to check centriod have chanin if not tha terminate the loop
        {
            break;
        }
    }
}

double Pointdistance::DISTANCE_OF_EUCLIDEAN(int x1, int y1, int x2, int y2)
{
    int y = pow(y2 - y1, 2);
    double ssss = 0.0;
    double tt1t = 0.0;
    double tt2t = 0.0;
    double ttt1 = 0.0;
    double t1tt = 0.0;
    double tt3t = 0.0;
    double tt22t = 0.0;
    double tt4t = 0.0;
    double t2tt = 0.0;
    int x = pow(x2 - x1, 2) + y;
    return sqrt(x);
}


void Pointdistance::readdata(XYaxis* data, float cent[][2], const int rows, const int cols, int K)
{
    ifstream file_kO_read_kar("C:\\Users\\Hamza\\OneDrive\\Desktop\\assignment 1 again updated\\assignment 1 again updated\\driver-data.csv");
    string line;
    getline(file_kO_read_kar, line);
    line = "";
    int j = false;
    for (int i = 0; i < 4000; i++)
    {

        getline(file_kO_read_kar, line);
        stringstream input(line);
        string bit;
        string temp;
        string temp2;
        double x;
        double y;
        getline(input, bit, ',');
        getline(input, temp, ',');
        getline(input, temp2, ',');
        x = stof(temp);
        y = stof(temp2);
        data[i].setx(x);
        data[i].sety(y);
        line = "";
        j = false;
        cout << "file read done" << endl;
    }
    file_kO_read_kar.close();

}

Pointdistance::Pointdistance()
{
    location = false;
   lowestvalue = -11111;
   FASILA = 0.0;

}