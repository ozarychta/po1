#ifndef _STACKCPP_H
#define _STACKCPP_H

class Stack
{
		int top;
		int *data;
		int size;
	public:
		Stack();
		void push(int element);	
		int pop();
		void clear();
		bool isEmpty();	
		void printStack();
		~Stack();	
};

void printMenu();

#endif

