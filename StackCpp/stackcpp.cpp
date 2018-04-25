#include <iostream>
#include <cstdlib>
#include "stackcpp.h"
#define INITIAL_SIZE 4

using namespace std;

Stack::Stack()
{
	top = 0;
	size = INITIAL_SIZE;
	if((data = new int[size])==NULL)
		{
		cout << "\nAllocate error!\n";
		abort();
		}
	cout <<"Constructor called.\n";
}

void Stack::push(int newElement)
{
	if(top>=size){
		int *newData;
		if((newData = new int[size*2])==NULL)
		{
			cout << "\nAllocate error!\n";
			delete[] data;
			abort();
		}
		for (int i=0; i<top; i++)
		{
			newData[i]=data[i];
		}
		size=size*2;
		delete [] data;
		data=newData;
	}
	data[top++]=newElement;
}
	
int Stack::pop()
{
	if(isEmpty())
	{
		cout << "Stack is empty. Nothing to pop.\n";
    		return 0;
	}
	top--;
	return data[top];
}

void Stack::clear()
{
	//for (; top>0; top--)
	//{
	//data[top-1]=0;
	//}
	top=0;
}

bool Stack::isEmpty()
{
	if(top==0) return true;
	else return false;
}	

Stack::~Stack()
{
	delete[] data;
	cout << "Destructor called\n";
}

void Stack::printStack()
{
	cout << "\n\n\tSTACK:\n\t__________\n\n";
    if(Stack::isEmpty()) cout<<"\tEmpty\n";
	else{
		for(int i=top; i>0; i--)
		{
		cout << "\t"  << data[i-1] <<"\n";
		}
	}
	cout << "\n\n";
}

void printMenu()
{
	cout << "\n\t\tMENU\n\t____________________________\n" <<
		"\t1 - Push value \n\t2 - Pop value \n\t3 - Clear stack\n"<<
		"\t4 - Check if stack is empty \n\t5 - Print stack \n\t6 - Exit\n";
}	
