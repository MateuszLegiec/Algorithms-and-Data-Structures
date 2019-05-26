#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

struct Point
{
    float x;
    float y;
};

bool compareByX(Point a,Point b)
{
    return a.x<b.x;
}

vector<vector<float>> augmentedMatrix(int polynomicalDegree,vector<Point> points)
{
    float X[2*polynomicalDegree+1];
    for(int i=0; i<2*polynomicalDegree+1; i++)
    {
        X[i]=0;
        for(int j=0; j<points.size(); j++)
            X[i]+=pow(points.at(j).x,i);
    }
    vector<float> line(polynomicalDegree+2,0);
    vector< vector<float> > Matrix(polynomicalDegree+1,line);
    for(int i=0; i<=polynomicalDegree; i++)
        for(int j=0; j<=polynomicalDegree; j++)
            Matrix[i][j]=X[i+j];
    float Y[polynomicalDegree+1];
    for(int i=0; i<polynomicalDegree+1; i++)
    {
        Y[i]=0;
        for(int j=0; j<points.size(); j++)
            Y[i]+=pow(points.at(j).x,i)*points.at(j).y;
    }
    for(int i=0; i<=polynomicalDegree; i++)
        Matrix[i][polynomicalDegree+1]=Y[i];
    return Matrix;
}

vector<float> gauss(vector< vector<float> > augmentedMatrix)
{
    int n = vec.size();

    for (int i=0; i<n; i++)
    {
        float maxEl = abs(vec[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++)
        {
            if (abs(vec[k][i]) > maxEl)
            {
                maxEl = abs(vec[k][i]);
                maxRow = k;
            }
        }
        for (int k=i; k<n+1; k++)
            swap(vec[maxRow][k],vec[i][k]);

        for (int k=i+1; k<n; k++)
        {
            float temp = -vec[k][i]/vec[i][i];
            for (int j=i; j<n+1; j++)
                if (i==j)
                    vec[k][j] = 0;
                else
                    vec[k][j] += temp * vec[i][j];
        }
    }
    vector<float> result(n);
    for (int i=n-1; i>=0; i--)
    {
        result[i] = vec[i][n]/vec[i][i];
        for (int k=i-1; k>=0; k--)
        {
            vec[k][n] -= vec[k][i] * result[i];
        }
    }
    return result;
}


float approximationResult(vector<float> gauss,float arg)
{
    float sum=0;
    for(int i=0; i<vec.size(); i++)
    {
        sum+=vec.at(i)+pow(arg,i);
    }
    return sum;
}



