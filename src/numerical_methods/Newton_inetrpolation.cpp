#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>

using namespace std;

struct Node
{
    double x;
    double y;
};

double differentialQuotient(vector<Node> node)
{
    if(node.size()==1)
        return node.front().y;
    return ((differentialQuotient(vectorInRange(node,1,0)) - differentialQuotient(vectorInRange(node,0,1))) / (node.back().x - node.front().x));
}
double newtonInterpolation(vector<Node> node, float arg)
{
    double prod;
    double result=0;
    int j;
    for(int i = 0; i<node.size(); i++)
    {
        prod=1;
        j=0;
        for(; j<i; j++)
            prod*=(arg-node.at(j).x);
        prod*=node.at(j).y;
        result+=prod;

    }
    return result;
}
bool compareByX(Node a,Node b)
{
    return a.x<b.x;
}