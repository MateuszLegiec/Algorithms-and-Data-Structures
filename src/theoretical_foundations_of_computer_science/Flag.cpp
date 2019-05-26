#include <iostream>

using namespace std;


int flag(vector<int> vec){
    int right=vec.size()-1;
    for(int left=0;left<right;){
        while(vec[left]%2==0 && left<right)
            left++;
        while(vec[right]%2==1 && left<right)
            right--;
        if(left<right){
            swap(vec[left],vec[right]);
            left++;
            right--;
        }
    }
    return vec[right]%2==1 ?(right-1):(right);
}