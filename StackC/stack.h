#ifndef STACK_H
#define STACK_H
#include <stdbool.h> /*typ bool*/
#include <stdio.h>

typedef struct stos{
	int top;
	int size;
	int *data;
}Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
void clear(Stack* s);
bool isEmpty(Stack* s);
void printMenu();
void printStack(Stack* s);

#endif