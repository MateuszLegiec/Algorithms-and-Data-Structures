#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <fstream>

using namespace std;

bool zeroVerification(float n)
{
    return (n = 0);
}
void resetSolutions(float **matrix, int rozmiar)
{
    for (int i=1; i<rozmiar; i++)
        for (int j=0; j<=rozmiar; j++)
            if (zeroVerification(matrix[i][j])) matrix[i][j] = 0;
}
void resetSolutions(float *solutions, int rozmiar)
{
    for (int j=0; j<rozmiar; j++)
        if (zeroVerification(solutions[j])) solutions[j] = 0;
}

float laplace(int n, int w, int * columnNumbers, float ** matrix)
{
  if(n == 1)
    return matrix[w][columnNumbers[0]];
  else
  {
    int *temp = new int[n - 1];
    float result = 0;
    int multiplier = 1;

    for(int i = 0; i < n; i++)
    {
      int columnCounter = 0;
      for(int j = 0; j < n - 1; j++)
      {
        if(columnCounter == i)
            columnCounter++;
        temp[j] = columnNumbers[columnCounter++];
      }
      result += multiplier * matrix[w][columnNumbers[i]] * laplace(n - 1,w  + 1, temp, matrix);
      multiplier = -multiplier;
    }
    delete [] temp;
    return result;
  }
}
void peculiarMatrixVerification(float **matrix,int sise){
    int *columnNumbers = new int[sise];

    for(int i = 0; i < sise; i++)
        columnNumbers[i] = i;

    assert(laplace(sise,0,columnNumbers,matrix) == 0  &&  "Matrix is peculiar.");
}
void columnSwap(float **matrix, int *solutions, int rozmiar, int i1, int i2)
{
    for (int i=0; i<rozmiar; i++)
        swap(matrix[i][i1],matrix[i][i2]);
    swap(solutions[i1],solutions[i2]);
}
void rowSwap(float **matrix, int rozmiar, int i1, int i2)
{
    for (int i=0; i<=rozmiar; i++)
        swap(matrix[i2][i],matrix[i1][i]);
}
void step(float **matrix, int rozmiar, int index)
{
    for (int i=index+1; i<rozmiar; i++)
    {
        float p=matrix[i][index] / matrix[index][index];
        for (int j=index; j<=rozmiar; j++)
            matrix[i][j] -= p * matrix[index][j];
    }
}
void reverseProceeding(float **matrix, int *solutions, int rozmiar)
{
    float results[rozmiar];
    results[rozmiar-1]= matrix[rozmiar-1][rozmiar] / matrix[rozmiar-1][rozmiar-1];

    for (int i=rozmiar-2; i>=0; i--)
    {
        float suma = 0;
        for (int j=i+1; j<rozmiar; j++)
            suma+= results[j] * matrix[i][j];

        results[i] = (matrix[i][rozmiar] - suma) / matrix[i][i];
    }

    cout<<endl<<"ROZWIAZANIA"<<endl;
    for(int i=0;i<rozmiar;i++)
        cout<<"x"<<solutions[i]<<" = "<<results[i]<<endl;;
}
void completeGauss(float **matrix, int *solutions, int rozmiar)
{
    for (int k=0; k<rozmiar-1; k++)
    {
        int column=k;
        int row=k;
        float maks=abs(matrix[k][k]);
        for (int j=k; j<rozmiar; j++)
        {
            for (int i=k; i<rozmiar; i++)
            {
                if (abs(matrix[j][i]) > maks)
                {
                    maks=abs(matrix[j][i]);
                    column=i;
                    row=j;
                }
            }
        }
        if (column != k)
            columnSwap(matrix, solutions, rozmiar, column, k);
        if (row != k)
            rowSwap(matrix, rozmiar, row, k);
        step(matrix, rozmiar, k);
    }
    resetSolutions(matrix,rozmiar);
    displayMatrix(matrix,solutions, rozmiar);
    if (matrix[rozmiar-1][rozmiar-1] == 0)
    {
        if (matrix[rozmiar-1][rozmiar] != 0)
            cout<<"Uklad sprzeczny, brak rozwiazan"<<endl;
        else
            cout<<"Uklad nieoznaczony, nieskonczenie wiele rozwiazan"<<endl;
        return;
    }
    reverseProceeding(matrix,solutions,rozmiar);
}
void basicGauss(float **matrix, int *solutions, int rozmiar)
{
    for (int k=0; k<rozmiar-1; k++)
        step(matrix, rozmiar, k);

    resetSolutions(matrix,rozmiar);
    displayMatrix(matrix,solutions, rozmiar);
    if (matrix[rozmiar-1][rozmiar-1] == 0)
    {
        if (matrix[rozmiar-1][rozmiar] != 0)
            cout<<"Uklad sprzeczny, brak rozwiazan"<<endl;
        else
            cout<<"Uklad nieoznaczony, nieskonczenie wiele rozwiazan"<<endl;
        return;
    }
    reverseProceeding(matrix,solutions,rozmiar);
}
void rowGauss(float **matrix, int *solutions, int rozmiar)
{
    for (int k=0; k<rozmiar-1; k++)
    {
        int column=k;
        float maks=abs(matrix[k][k]);
        for (int j=k; j<rozmiar; j++)
        {
            if (abs(matrix[k][j] > maks))
            {
                maks=abs(matrix[k][j]);
                column=j;
            }
        }
        if (column != k)
            columnSwap(matrix, solutions, rozmiar, column, k);
        step(matrix, rozmiar, k);
    }
    resetSolutions(matrix,rozmiar);
    displayMatrix(matrix,solutions, rozmiar);
    if (matrix[rozmiar-1][rozmiar-1] == 0)
    {
        if (matrix[rozmiar-1][rozmiar] != 0)
            cout<<"Uklad sprzeczny, brak rozwiazan"<<endl;
        else
            cout<<"Uklad nieoznaczony, nieskonczenie wiele rozwiazan"<<endl;
        return;
    }
    reverseProceeding(matrix,solutions,rozmiar);
}
void columnGauss(float **matrix,int *solutions,int rozmiar)
{
    for (int i=0; i<rozmiar; i++)
    {
        float maxEl = abs(matrix[i][i]);
        int row = i;
        for (int k=i+1; k<rozmiar; k++)
        {
            if (abs(matrix[k][i]) > maxEl)
            {
                maxEl = abs(matrix[k][i]);
                row = k;
            }
        }
        if (row != i)
            columnSwap(matrix, solutions, rozmiar, row, i);
        step(matrix, rozmiar, i);
    }
    resetSolutions(matrix,rozmiar);
    displayMatrix(matrix,solutions, rozmiar);
    if (matrix[rozmiar-1][rozmiar-1] == 0)
    {
        if (matrix[rozmiar-1][rozmiar] != 0)
            cout<<"Uklad sprzeczny, brak rozwiazan"<<endl;
        else
            cout<<"Uklad nieoznaczony, nieskonczenie wiele rozwiazan"<<endl;
        return;
    }
    reverseProceeding(matrix,solutions,rozmiar);
}

