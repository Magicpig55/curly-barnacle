#include "List.h"

List::List() {
	first = nullptr;
	last = nullptr;
	current = nullptr;
	count = 0;
}
List::List(int _arr[], int _len) {
	for (int i = 0; i < _len; ++i) {
		PushTail(_arr[i]);
	}
}
List::~List() {}

Node* List::getNode(int _index) {
	if (_index > count - 1)
		return nullptr;
	if (first == nullptr)
		return nullptr;

	Node* tmp = first;
	for (int i = 0; i < _index; ++i) {
		tmp = tmp->getNext();
	}
	return tmp;
}

int List::First() {
	current = first;
	return first->getValue();
}
int List::Last() {
	current = last;
	return last->getValue();
}
int List::Next() {
	current = current->getNext();
	return current->getValue();
}
int List::Previous() {
	current = current->getPrevious();
	return current->getValue();
}
int List::Count() {
	return count;
}
int List::Get(int _index) {
	return getNode(_index)->getValue();
}

void List::PushHead(int _val) {
	Node* newNode = new Node(_val);
	if (first == nullptr) {
		first = newNode;
		last = newNode;
		count = 1;
		return;
	}
	first->setPrevious(newNode);
	newNode->setNext(first);
	first = newNode;
	count++;
}
void List::PushTail(int _val) {
	Node* newNode = new Node(_val);
	if (last == nullptr) {
		first = newNode;
		last = newNode;
		count = 1;
		return;
	}
	last->setNext(newNode);
	newNode->setPrevious(last);
	last = newNode;
	count++;
}
void List::PopHead() {
	first = first->getNext();
	first->setPrevious(nullptr);
	count--;
}
void List::PopTail() {
	last = last->getPrevious();
	last->setNext(nullptr);
	count--;
}
void List::Insert(int _ind, int _val) {
	Node* tmp = getNode(_ind);
	Node* prev = tmp->getPrevious();
	Node* newNode = new Node(_val);
	prev->setNext(newNode);
	newNode->setPrevious(prev);
	tmp->setPrevious(newNode);
	newNode->setNext(tmp);
	count++;
}
void List::Set(int _ind, int _val) {
	getNode(_ind)->setValue(_val);
}
void List::Remove(int _ind) {
	Node* b = getNode(_ind);
	Node* a = b->getPrevious();
	Node* c = b->getNext();
	a->setNext(c);
	c->setPrevious(a);
	count--;
}