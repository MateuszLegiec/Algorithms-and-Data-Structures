#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;


bool symetricalVerification(float **matrix, int rozmiar)
{
    for (int i=0; i<rozmiar; i++)
        for (int j=i; j<rozmiar; j++)
            if (matrix[i][j] != matrix[j][i])
                return false;
    return true;
}

bool positiveMatrixDefVerification(float **matrix, int rozmiar)
{
    for (int k=0; k<rozmiar; k++)
    {
        float sum=0;
        if (k >0)
            for (int j=0; j<k; j++)
                sum+=pow(matrix[k][j],2);

        if (matrix[k][k] - sum < 0)
            return false;

        matrix[k][k]=sqrt(matrix[k][k] - sum);

        for (int i=0; i<rozmiar; i++)
        {
            sum=0;
            if (k >0)
            {
                for (int j=0; j<k; j++)
                    sum+= matrix[i][j] * matrix[k][j];
                if (i != k)
                    matrix[i][k] = (matrix[i][k] - sum)/matrix[k][k];
            }
        }
    }
    return true;
}

void reverseProceedingY(float **matrix, int rozmiar)
{
    float result[rozmiar];
    result[0]= matrix[0][rozmiar] / matrix[0][0];

    for (int i=1; i<rozmiar; i++)
    {
        float sum = 0;
        for (int j=0; j<rozmiar; j++)
            sum+= result[j] * matrix[i][j];

        result[i] = (matrix[i][rozmiar] - sum) / matrix[i][i];
    }

    cout<<endl<<"-------------------------------------"<<endl;
    cout<<"y = [";
    for (int i=0; i<rozmiar; i++)
    {
        matrix[i][rozmiar]=result[i];
        cout<<result[i];
        if (i != rozmiar-1)
            cout<<", ";
    }
    cout<<"]";
    cout<<endl<<"-------------------------------------"<<endl;
}

void reverseProceedingX(float **matrix, int rozmiar)
{
    float result[rozmiar];

    result[rozmiar-1]= matrix[rozmiar-1][rozmiar] / matrix[rozmiar-1][rozmiar-1];

    for (int i=rozmiar-2; i>=0; i--)
    {
        float sum =0;
        for (int j=i+1; j<rozmiar; j++)
            sum+= result[j] * matrix[i][j];
        result[i] = (matrix[i][rozmiar] - sum) / matrix[i][i];
    }
    cout<<endl<<"-------------------------------------"<<endl;
    cout<<"x = [";
    for (int i=0; i<rozmiar; i++)
    {
        cout<<result[i];
        if (i != rozmiar-1)
            cout<<", ";
    }
    cout<<"]";
    cout<<endl<<"-------------------------------------"<<endl;

}

void transposeMatrix(float **matrix, int rozmiar)
{
    for (int i=0; i<rozmiar; i++)
        for (int j=i+1; j<rozmiar; j++)
            swap(matrix[j][i],matrix[i][j]);
}
