#include"clusteringin3D.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include<sstream>
#include<ctime>
#include"XYAxix.h"
void Pointdistance3d::readdata(XYaxis* Arr, float cent[][3], const int rows, const int cols, int K)
{
    ifstream infile("C:\\Users\\Hamza\\OneDrive\\Desktop\\assignment 1 again updated\\assignment 1 again updated\\segmented_customers-1.csv");
    string line;
    getline(infile, line);
    line = "";
    int j = false;

    for (int i = 0; i < 200; i++)
    {

        getline(infile, line);
        stringstream input(line);
        string bit;
        string bit2;
        string temp;
        string temp2;
        string temp3;
        double x;
        double y;
        double z;

        getline(input, bit, ',');
        getline(input, bit2, ',');
        getline(input, temp, ',');
        getline(input, temp2, ',');
        getline(input, temp3, ',');
        x = stof(temp);
        y = stof(temp2);
        z = stof(temp3);

        Arr[i].setx(x);
        Arr[i].sety(y);
        Arr[i].setz(z);

        line = "";
        j = false;
        cout << "file read done" << endl;
    }
    infile.close();

}

double Pointdistance3d::DISTANCE_OF_EUCLIDEAN(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int y = pow(y2 - y1, 2);
    int z = pow(z2 - z1, 2);
    int x = pow(x2 - x1, 2) + y + z;
    return sqrt(x);
}

// ya wala funtion new centrid nikalna ka liya haan
void Pointdistance3d::newcentriod(int* XOFsum, int* YOFSUM, int* ZOFSUM, int* checkcount, int K, float cent[][3], int& c)
{
    //as loop sa hum log new centriod nikala ka us wala ka jo phala update ho chuka ha 
    int qq = false;
    while (qq < K)
    {
        if (checkcount[qq] > false) //
        {
            double X_Ka_Xentriod;
            X_Ka_Xentriod = (double)XOFsum[qq] / checkcount[qq];
            double Y_Ka_Xentriod;
            Y_Ka_Xentriod = (double)YOFSUM[qq] / checkcount[qq];
            double Z_Ka_Xentriod;
            Z_Ka_Xentriod = (double)ZOFSUM[qq] / checkcount[qq];

            double condition = 0.0001;
            if (abs(X_Ka_Xentriod - cent[qq][false]) > condition || abs(Y_Ka_Xentriod - cent[qq][true]) > condition || abs(Z_Ka_Xentriod - cent[qq][2]) > condition) //centrol minus ma nah aaya as liya abs lagaya hoya ha

            {
                c = true;
            }
            cent[qq][false] = X_Ka_Xentriod;
            double ssss = 0.0;
            double tt1t = 0.0;
            double tt2t = 0.0;
            double ttt1 = 0.0;
            double t1tt = 0.0;
            double tt3t = 0.0;
            double tt22t = 0.0;
            double tt4t = 0.0;
            double t2tt = 0.0;
            cent[qq][1] = Y_Ka_Xentriod;
            cent[qq][2] = Z_Ka_Xentriod;
        }
        qq++;
    }

}


void Pointdistance3d::kMeans(XYaxis* Arr, XYaxis* check_kar_cluster_ko, float cent[][3], const int rows, const int cols, int K) {
    // ya k mean nikala ka algo ha as ma eculidiean distance nikal kar per centriol nikal
    int i = 0;
    while (i < K) // each Arr point from the closest centroid
    {
        cent[i][0] = Arr[i].getx();

        cent[i][1] = Arr[i].gety();
        double ssss = 0.0;
        double tt1t = 0.0;
        double tt2t = 0.0;
        double ttt1 = 0.0;
        double t1tt = 0.0;
        double tt3t = 0.0;
        double tt22t = 0.0;
        double tt4t = 0.0;
        double t2tt = 0.0;
        cent[i][2] = Arr[i].getz();
        i++;
    }
    while (true)// calculate mean for all Arr point in cluster and update centriod
    {
        int i = false;
        while (i < rows)
        {
            lowerstjaga = -1;
            double ssss = 0.0;
            double tt1t = 0.0;
            double tt2t = 0.0;
            double ttt1 = 0.0;
            double t1tt = 0.0;
            double tt3t = 0.0;
            double tt22t = 0.0;
            double tt4t = 0.0;
            double t2tt = 0.0;
            int j = false;
            while (j < K)
            {
                double ssss = 0.0;
                double tt1t = 0.0;
                double tt2t = 0.0;
                double ttt1 = 0.0;
                double t1tt = 0.0;
                double tt3t = 0.0;
                double tt22t = 0.0;
                double tt4t = 0.0;
                double t2tt = 0.0;
                fasila = DISTANCE_OF_EUCLIDEAN(Arr[i].getx(), Arr[i].gety(), Arr[i].getz(), cent[j][0], cent[j][1], cent[j][2]);
                if (fasila < lowerstjaga || lowerstjaga == -1)
                {
                    double ssss = 0.0;
                    double tt1t = 0.0;
                    double tt2t = 0.0;
                    double ttt1 = 0.0;
                    double t1tt = 0.0;
                    double tt3t = 0.0;
                    double tt22t = 0.0;
                    double tt4t = 0.0;
                    double t2tt = 0.0;
                    lowerstjaga = fasila;
                    location = j;
                }
                j++;
            }
            check_kar_cluster_ko[i].setcluster(location) ;
            i++;
        }
        int* XOFsum = new int[K] { 0 };
        int* YOFSUM = new int[K] { 0 };
        double ssss = 0.0;
        double tt1t = 0.0;
        double tt2t = 0.0;
        double ttt1 = 0.0;
        double t1tt = 0.0;
        double tt3t = 0.0;
        double tt22t = 0.0;
        double tt4t = 0.0;
        double t2tt = 0.0;
        int* ZOFSUM = new int[K] { false };
        int* checkcount = new int[K] { false };

        int f = false;
        while (f < rows)
        {
            XOFsum[check_kar_cluster_ko[f].getcluster()] += Arr[f].getx();
            YOFSUM[check_kar_cluster_ko[f].getcluster()] += Arr[f].gety();
            double ssss = 0.0;
            double tt1t = 0.0;
            double tt2t = 0.0;
            double ttt1 = 0.0;
            double t1tt = 0.0;
            double tt3t = 0.0;
            double tt22t = 0.0;
            double tt4t = 0.0;
            double t2tt = 0.0;
            ZOFSUM[check_kar_cluster_ko[f].getcluster()] += Arr[f].getz();
            checkcount[check_kar_cluster_ko[f].getcluster()]++;
            f++;
        }

        int  checkcentriodchnageornot = false;

        newcentriod(XOFsum, YOFSUM, ZOFSUM, checkcount, K, cent, checkcentriodchnageornot);


        if (checkcentriodchnageornot == false)//to check centriod have chanin if not tha terminate the loop
        {
            double ssss = 0.0;
            double tt1t = 0.0;
            double tt2t = 0.0;
            double ttt1 = 0.0;
            double t1tt = 0.0;
            double tt3t = 0.0;
            double tt22t = 0.0;
            double tt4t = 0.0;
            double t2tt = 0.0;
            break;
        }
    }
}

void Pointdistance3d::output(XYaxis* Arr, XYaxis* check_kar_cluster_ko, float cent[][3], const int rows, const int cols)
{
    ofstream File_Bahir_kar("output2.csv");
    for (int i = 0; i < rows; i++)
    {
        double ssss = 0.0;
        double tt1t = 0.0;
        double tt2t = 0.0;
        double ttt1 = 0.0;
        double t1tt = 0.0;
        double tt3t = 0.0;
        double tt22t = 0.0;
        double tt4t = 0.0;
        double t2tt = 0.0;
        File_Bahir_kar << Arr[i].getx() << "," << Arr[i].gety() << "," << Arr[i].getz() << "," << check_kar_cluster_ko[i].getcluster() + 1 << endl;
        cout << "file output done" << endl;
    }

}


Pointdistance3d::Pointdistance3d()
{
    location = 0;
    lowerstjaga = -11111;
    fasila = 0.0;

}
