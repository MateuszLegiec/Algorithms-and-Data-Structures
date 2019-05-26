#include <iostream>
#include <windows.h>

using namespace std;

class stack
{
	int *arr;
	int head;
	int maxLength;

public:
	stack(int size = SIZE){
       arr = new int[size];
       maxLength = size;
       head = -1;
    };

    void push(int x){
    	if (isFull()){
    		cout << "Stack is full";
    	}else{
            arr[++head] = x;
    	}
    }

	int pop(){
    	if (isEmpty())
    		cout << "Stack is empty";
    	else{
        	return arr[head--];
    	}
    }

	int peek(){
    	if (isEmpty())
    		cout << "Stack is empty";
        else
    		return arr[head];
    }

	int size(){
	    return head+1;
	};

	bool isEmpty(){
	    return this.size() == 0
	};

	bool isFull(){
	    return head == maxLength-1;
	};
};