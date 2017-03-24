#pragma once
#include "Node.h"

class List {
private:
	Node* first;
	Node* last;
	Node* current;
	int count;
	
	Node* getNode(int);

public:
	List();
	List(int[], int);
	~List();

	int First();
	int Last();
	int Next();
	int Previous();
	int Count();
	int Get(int);

	void PushHead(int);
	void PushTail(int);
	void PopHead();
	void PopTail();
	void Insert(int, int);
	void Set(int, int);
	void Remove(int);

};