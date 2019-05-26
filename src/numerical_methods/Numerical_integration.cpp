#include <iostream>
#include <windows.h>
#include <math.h>
#include <vector>
#include <iomanip>
#define A -1
#define B 1

using namespace std;

double funcLn(double arg){
    return 1/arg;
}

double funcPi(double arg){
    return 2/(pow(arg,2)+1);
}

typedef double(* funct)(double);

vector<double> setVector(double start,double h,int steps,funct func){
    vector<double> vec;
    for(int i=0;i<=steps;i++)
        vec.push_back(func(start+i*h));
    return vec;
}

vector<double> setVectorLn(double h,int steps,double arg){
    return (arg>1)?setVector(1,h,steps,funcLn):setVector(arg,h,steps,funcLn);
}

double simpson(int steps){
    double h=(B-A)/(double)(steps);
    vector<double> vec=setVector(A,h,steps,funcPi);

    double result = vec.at(0) + vec.at(steps);
    double temp=0;
    for(int i=1;i<steps;i+=2)
        temp+=vec.at(i);
    result+=4*temp;
    temp=0;
    for(int i=2;i<steps;i+=2)
        temp+=vec.at(i);
    result+=2*temp;

    return h*result/3.0;
}

double trapezoidal(int steps,double arg){
    double h=abs(arg-1)/(double)steps;

    vector<double> vec = setVectorLn(h,steps,arg);

    double result=(vec.at(0)+vec.at(vec.size()-1))*0.5;
    for(int i=1;i<vec.size()-1;i++)
        result+=vec.at(i);

    return (arg>=1)?(h*result):((-1)*h*result);
}

