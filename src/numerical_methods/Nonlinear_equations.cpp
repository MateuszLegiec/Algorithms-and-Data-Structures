#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;


double func(double x){
    return pow(x,3)+x-1;
}

double derivative(double x){
    return 3*pow(x,2)+1;
}

double bisection(double leftLimit,double rightLimit,double epsilon){
    assert((func(a)*func(b)<=0) && "Niepoprawne dane wejsciowe");
    for(double x=(a+b)/2;true;(func(x)*func(a)<0)?(b=x):(a=x),x=(a+b)/2)
        if( abs(func(x))<=e  ||  b-a<=e)
            return x;
}

double newtonRaphonson(double x0,double epsilon,int iterationLimit){
    double xn;
    for(int i=0;i<iterationLimit;i++,x0=xn){
        if(abs(func(x0)<e))
            return x0;
        xn = x0 - func(x0)/derivative(x0);
        if(abs(xn-x0)<=e)
            return xn;
    }
    cout<<"Niewlasciwie dobrany punkt startowy"<<endl;
    return NAN;
}