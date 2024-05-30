/*
 * BinaryTree.hpp
 *
 *  Created on: May 25, 2024
 *      Author: markdillman
 */

#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

#include "Node.hpp"
#include<vector>

class BinaryTree{
private:

	Node * root;

public:

	Node * getRoot(){return root;};
	void setRoot(Node * _root){root=_root;};
	void buildTree(const std::vector<int>&);
	BinaryTree():root(nullptr){};
	~BinaryTree();
	BinaryTree(Node * _root):root(_root){};
	Node * deleteSubtree(Node *);
	void inOrderPrint(Node *);
};

#endif /* BINARYTREE_HPP_ */
