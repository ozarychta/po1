#ifndef _Assoctab_H
#define _Assoctab_H

char* toLow(const char *word);

class AssocTab{
protected:
	class node;
	node *head;

	virtual void insert(const char *key, int val);
	void clear();
	virtual node* find(const char *key);
	void swap(AssocTab &a);
public:	
	AssocTab();
	AssocTab(const AssocTab &a);
	~AssocTab();	
	AssocTab& operator=(const AssocTab &a);
	int& operator[](const char* k);

};

class AssocTab2: public AssocTab{
	void insert(const char *key, int val);
    node* find(const char *key);
public:
    AssocTab2();
    AssocTab2(const AssocTab2 &a);
	char* toLow(const char *word);
};

class AssocTab::node{
public:
	node *next;
	char *key;
	int value;
	node(const char *k);
	node(const node &n);
	~node();

};

#endif
