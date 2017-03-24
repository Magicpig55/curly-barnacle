#pragma once

#include "BinaryNode.h"
#include "List.h"

class BinaryTree {
private:
	BinaryNode* root;
	BinaryNode* leftmost;
	void Add(BinaryNode*);
	bool 🔎(BinaryNode*, int);

public:
	BinaryTree();
	BinaryTree(List);
	BinaryTree(int[], int);
	~BinaryTree(); 

	void Add(int);
	bool 🔎(int); // 🔎
	void Remove(int);
};