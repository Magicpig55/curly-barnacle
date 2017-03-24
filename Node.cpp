#include "Node.h"
Node::Node() {
	next = nullptr;
	value = 0;
}
Node::Node(int _val) {
	next = nullptr;
	value = _val;
}
Node::~Node() {}

Node* Node::getNext() {
	return next;
}
void Node::setNext(Node* _node) {
	next = _node;
}


Node* Node::getPrevious() {
	return previous;
}
void Node::setPrevious(Node* _node) {
	previous = _node;
}

int Node::getValue() {
	return value;
}
void Node::setValue(int _val) {
	value = _val;
}