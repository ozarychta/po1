#include "stack.h"
#include <stdio.h>

int main(){
	int chosenOption, isCorrect, newElement;
	Stack stos;
	init(&stos);
	do
	{
	printMenu();

	do
	{
		fflush(stdin);
		printf("\nChoose an option: ");
		isCorrect=scanf("%d",&chosenOption);
		if(!isCorrect || chosenOption<1 || chosenOption>6)
			printf("\nThere is no option with that number! Try again.");
	}while (!isCorrect || chosenOption<1 || chosenOption>6);
	
	switch(chosenOption){
	case 1: { 
		printf("Enter a number you want to add: ");
		scanf("%d", &newElement);
		push(&stos, newElement);
		printf("\nAdded.");
		break;
		}
	case 2: { 
		if(isEmpty(&stos)) pop(&stos);
		else printf("\nPopped number: %d\n",pop(&stos));
		break;
		}
	case 3: { 
		clear(&stos);
		printf("\nStack cleared.");
		break;
		}
	case 4: { 
		if(isEmpty(&stos)) printf("\nStack is empty.");
		else printf("\nStack is not empty.");
		break;
		}
	case 5: { 
		printStack(&stos);
		break;
		}
	}
	}while(chosenOption!=6);
	destroy(&stos);
	getchar();
	return 0;
}
