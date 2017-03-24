#pragma once

class BinaryNode {
private:
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode* parent;
	int value;

public:
	BinaryNode();
	BinaryNode(int);
	~BinaryNode();

	int getValue();
	void setValue(int);

	BinaryNode* getLeft();
	BinaryNode* getRight();
	BinaryNode* getParent();

	void setLeft(BinaryNode*);
	void setRight(BinaryNode*);
	void setParent(BinaryNode*);
};