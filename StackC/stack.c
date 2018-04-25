#include <stdbool.h> /*typ bool*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define INITIAL_SIZE 4

void init(Stack* s)
{
	s->top=0;
	s->size=INITIAL_SIZE;
	if((s->data = (int*)calloc(s->size, sizeof(int)))==NULL)
	{
		printf("\nStack allocation error!");
		abort();
	}
}

void destroy(Stack* s)
{
	free(s->data);
}

void push(Stack* s, int element)
{
	if(s->top>=s->size){
		int newSize = s->size*2;
		int* newData;
		if((newData = (int*)realloc(s->data,newSize*sizeof(int)))==NULL)
		{	
			printf("\nStack allocation error!");
			free(s->data);
			abort();
		}
		s->data=NULL;
		s->data=newData;
		s->size=newSize;
	}
	s->data[s->top++]=element;
}

int pop(Stack* s)
{
	if(isEmpty(s))
	{
	printf("Stack is empty. Nothing to pop.\n");
	return 0;
	}
	s->top--;
	return s->data[s->top];
}

void clear(Stack* s)
{
	/*for (; s->top>0; s->top--)
	{
	s->data[s->top-1]=0;
	}*/
	s->top=0;
}

bool isEmpty(Stack* s)
{
	if(s->top==0) return true;
	else return false;
}

void printMenu()
{
	printf("\n\t\tMENU\n\t____________________________\n");
	printf("\t1 - Push value \n\t2 - Pop value \n\t3 - Clear stack\n");
	printf("\t4 - Check if stack is empty \n\t5 - Print stack \n\t6 - Exit\n");
}

void printStack(Stack* s)
{	int i;
	printf("\n\n\tSTACK:\n\t__________\n\n");
	if(isEmpty(s)) printf("\tEmpty\n");
	else{
		for(i=s->top; i>0; i--)
		{
		printf("\t%d\n", s->data[i-1]);
		}
	}
	printf("\t__________\n\n");
}
