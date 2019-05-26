#include <iostream>

using namespace std;

double func(double x,double y){
    return -(x+y);
}

void euler(double y0, double x0, double range, double h)
{
    double y = y0;
    for (double x = x0; x <= x0 + range; x += h){
        y += h * func(x, y);
        cout<<"[ "<<x<<" , "<<y<<" ]"<<endl;
    }
}

void heun(double y0, double x0, double range, double h){
    double y = y0;
    for(double x = x0; x <= x0 + range ; x+=h ){
        double k1 = func(x,y);
        double k2 = func(x+h,y+h*k1);
        y += h*0.5*(k1+k2);
        cout<<"[ "<<x<<" , "<<y<<" ]"<<endl;
    }
}

void simpson(double y0, double x0, double range, double h){
    double y = y0;

    for(double x = x0; x <= x0 + range ; x+=h ){
        double k1=func(x,y);
        double k2=func(x + 0.5*h,y+0.5*k1);
        double k3=func(x + h,y - k1 + 2*k2);
        y += h*(k1+4*k2+k3)/6.0;
        cout<<"[ "<<x<<" , "<<y<<" ]"<<endl;
    }
}

void runnego_kutty(double y0, double x0, double range, double h){
    double y = y0;

    for(double x = x0; x <= x0 + range ; x+=h ){
        int i=1;
        double k1=func(x,y);
        double k2=func(x + 0.5*h,y+0.5*k1);
        double k3=func(x + 0.5*h,y+0.5*k2);
        double k4=func(x + h,y + k3);
        y += h*(k1+2*k2+2*k3+k4)/6.0;
        cout<<"[ "<<x<<" , "<<y<<" ]"<<endl;
        i++;
    }
}
