#include <iostream>
#include "stackcpp.h"

using namespace std;

int main()
{		
	int chosenOption, element;
	Stack stos = Stack();
	do{
	printMenu();
	do{
		cin.clear();
		cin.sync();
		cin >> chosenOption;
		if(cin.fail() || chosenOption<1 || chosenOption>6)
			cout << "\nThere is no option with that number! Try again.\n";
	}while (cin.fail() || chosenOption<1 || chosenOption>6);

	switch(chosenOption){
	case 1: { 
		cout << "Enter a number you want to add: ";
		cin >>element;
		stos.push(element);
		cout <<"\nAdded.";
		break;
		}
	case 2: { 
		if(!stos.isEmpty()) cout<<"\nPopped number: "<<stos.pop();
		else stos.pop();
		break;
		}
	case 3: { 
		stos.clear();
		cout<<"\nStack cleared.";
		break;
		}
	case 4: { 
		if(stos.isEmpty()) cout<<"\nStack is empty.";
		else cout<<"\nStack is not empty.";
		break;
		}
	case 5: { 
		stos.printStack();
		break;
		}
	}
	}while(chosenOption!=6);
	cin.get();
	return 0;
}
