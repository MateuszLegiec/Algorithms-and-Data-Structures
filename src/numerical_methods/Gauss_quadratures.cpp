#include <vector>
#include <math.h>
#include <windows.h>

using namespace std;

struct Node{
    double x;
    double A;
};

vector<Node> setNodes(int n){
    vector<Node> vec;
    switch(n-1){
        case 1:
            vec.push_back(createNode(-0.577350,1));
            vec.push_back(createNode(0.577350,1));
            break;
        case 2:
            vec.push_back(createNode(-0.774597,0.555556));
            vec.push_back(createNode(0,0.888889));
            vec.push_back(createNode(0.774597,0.555556));
            break;
        case 3:
            vec.push_back(createNode(-0.861136,0.347855));
            vec.push_back(createNode(-0.339981,0.652145));
            vec.push_back(createNode(0.339981,0.652145));
            vec.push_back(createNode(0.861136,0.347855));
            break;
        case 4:
            vec.push_back(createNode(-0.906180,0.236927));
            vec.push_back(createNode(-0.538469,0.478629));
            vec.push_back(createNode(0,0.568889));
            vec.push_back(createNode(0.538469,0.478629));
            vec.push_back(createNode(0.906180,0.236927));
            break;
    }
    return vec;
}

double LN_Gauss(double arg, int n){
    vector<Node> vec = setNodes(n);
    double temp1=(arg-1)/2;
    double temp2=(arg+1)/2;
    double sum=0;

    for(int i=0;i<n;i++)
        sum+=(((1.0)/(temp1*vec.at(i).x+temp2))*vec.at(i).A);

    return sum*temp1;
}

double LN_Gauss_Czebyszew(double arg, int n){
    double tempA = 3.141592/(n-1);
    double temp = ((arg-1)/2);
    double sum=0;
    double tempX;

    for(int i=0;i<=n-1;i++){
        tempX = cos( ((2*i -1)*3.141592)/(2*(n-1)) );
        sum+=(((sqrt(1-pow(tempX,2)))/( temp*tempX+((arg+1)/2)))*tempA);
    }
    return sum*temp;
}


