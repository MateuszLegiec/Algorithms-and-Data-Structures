#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int x;
	int y;
};
float lagrangeInterpolation(Node node[] ,float val,int n){
    float result = 0.0;
    float temp=1.0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(j!=i)
                temp*=(val-node[j].x)/(node[i].x-node[j].x);
        result+=node[i].y*temp;
        temp=1.0;
    }
    return result;
}
bool compareByX(Node a,Node b){
    return a.x<b.x;
}
