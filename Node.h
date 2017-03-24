#pragma once

class Node {
private:
	Node* next;
	Node* previous;
	int value;

public:
	Node();
	Node(int);
	~Node();

	Node* getNext();
	void setNext(Node*);

	Node* getPrevious();
	void setPrevious(Node*);

	int getValue();
	void setValue(int);
};