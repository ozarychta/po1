#include <iostream>
#include <cstring>
#include <cctype>
#include "assoctab.h"

using namespace std;



//node
AssocTab::node::node(const char *k): next(NULL){
	key = new char[strlen(k)+1];
    strcpy(key,k);
	value=0;
}

AssocTab::node::node(const node &n): next(NULL){
	key = new char[strlen(n.key)+1];
	strcpy(key,n.key);
	value=n.value;
}

AssocTab::node::~node(){
	delete[] key;
}

//assoctab
 void AssocTab::insert(const char *key, int val){
	node *n = new node(key);
	n->next = head;
	head = n;
	head->value = val;
}

void AssocTab::clear(){
	while (head){
		node *n = head->next;
		delete head;
		head=n;
	}
}

AssocTab::node* AssocTab::find(const char *key){
	node *n = head;
	while(n){
		if(!strcmp(n->key, key)) return n;
		else n=n->next;
	}
	return NULL;
}

void AssocTab::swap(AssocTab &a){
	node *n = head;
	head = a.head;
	a.head = n;
}

AssocTab::AssocTab(){
	head = NULL;
}

AssocTab::AssocTab(const AssocTab &a){
	head = NULL;
	node *src;
	src = a.head;
	try{
	while(src){
		insert(src->key,src->value);
		src = src->next;
	}
	} catch(...){
		clear();
		cout << "Oh no! something terrible happened in AssocTab constructor! :("<<endl;
	}
}

AssocTab::~AssocTab(){
	clear();
}

AssocTab& AssocTab::operator=(const AssocTab &a){
	if(&a == this) return *this;
	AssocTab t(a);
	swap(t);
	t.clear();
	return *this;
}

int& AssocTab::operator[](const char *k){
	node *n = find(k);
	if(!n){
		insert(k, 0);
		n=head;	
	}
	return n->value;
}

//assoctab2
AssocTab2::AssocTab2():AssocTab(){
}

AssocTab2::AssocTab2(const AssocTab2 &a):AssocTab(a){
}

char* AssocTab2::toLow(const char *word){
    char *newWord=new char[strlen(word)+1];
    strcpy(newWord,word);
    for(int i=0; word[i]; i++){
        newWord[i]=(char)tolower(word[i]);
    }
    return newWord;
}

void AssocTab2::insert(const char *key, int val){
	const char *temp =(const char*)toLow(key);
	AssocTab::insert(temp, val);
	delete[]temp;
}

AssocTab2::node* AssocTab2::find(const char *key){
    	char *temp = toLow(key);
	node *n = AssocTab::find(temp);
	delete[]temp;
    return n;
}














