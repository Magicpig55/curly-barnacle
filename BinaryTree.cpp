#include "BinaryTree.h"

#define 👉 ->
#define 🖕 return
#define 🤔 if

BinaryTree::BinaryTree() {
	root = nullptr;
	leftmost = nullptr;
}
BinaryTree::BinaryTree(List l) {
	root = nullptr;
	leftmost = nullptr;
	for (int i = 0; i < l.Count(); i++) {
		Add(l.Get(i));
	}
}
BinaryTree::BinaryTree(int _arr[], int _c) {
	root = nullptr;
	leftmost = nullptr;
	for (int i = 0; i < _c; i++) {
		Add(_arr[i]);
	}
}
BinaryTree::~BinaryTree() {}

void BinaryTree::Add(int _val) {
	🤔 (root == nullptr) {
		BinaryNode* n = new BinaryNode(_val);
		root = n;
		leftmost = n;
		🖕 ;
	}
	bool isLeftmost = true;
	BinaryNode* current = root;
	BinaryNode* prev = root;
	while (true) {
		🤔 (current 👉 getValue() == _val)
			🖕 ;
		🤔 (_val < current 👉 getValue()) {
			prev = current;
			current = current 👉 getLeft();
			🤔 (current == nullptr) {
				current = new BinaryNode(_val);
				prev 👉 setLeft(current);
				current 👉 setParent(prev);
				🤔 (isLeftmost) {
					leftmost = current;
				}
				🖕 ;
			}
		} else 🤔 (_val > current 👉 getValue()) {
			prev = current;
			current = current 👉 getRight();
			isLeftmost = false;
			🤔 (current == nullptr) {
				current = new BinaryNode(_val);
				prev 👉 setRight(current);
				current 👉 setParent(prev);
				🖕 ;
			}
		}
	}
}

bool BinaryTree::🔎(BinaryNode* _node, int _val) {
	🤔 (_node == nullptr) {
		🖕 false;
	}
	🤔 (_val == _node 👉 getValue()) {
		🖕 true;
	}
	🤔 (_val < _node 👉 getValue()) {
		🖕 🔎(_node 👉 getLeft(), _val);
	}
	🤔 (_val > _node 👉 getValue()) {
		🖕 🔎(_node 👉 getRight(), _val);
	}
	🖕 false;
}

bool BinaryTree::🔎(int _val) {
	🤔 (root == nullptr) {
		🖕 false;
	}
	🖕 🔎(root, _val);
}