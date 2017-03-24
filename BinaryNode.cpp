#include "BinaryNode.h"

BinaryNode::BinaryNode() {
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	value = 0;
}
BinaryNode::BinaryNode(int _val) {
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	value = _val;
}
BinaryNode::~BinaryNode() {}

int BinaryNode::getValue() {
	return value;
}
void BinaryNode::setValue(int _val) {
	value = _val;
}

BinaryNode* BinaryNode::getLeft() {
	return left;
}
BinaryNode* BinaryNode::getRight() {
	return right;
}
BinaryNode* BinaryNode::getParent() {
	return parent;
}

void BinaryNode::setLeft(BinaryNode* _node) {
	left = _node;
}
void BinaryNode::setRight(BinaryNode* _node) {
	right = _node;
}
void BinaryNode::setParent(BinaryNode* _node) {
	parent = _node;
}