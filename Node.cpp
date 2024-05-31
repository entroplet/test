/*
 * Node.cpp
 *
 *  Created on: May 25, 2024
 *      Author: markdillman
 */

#include <iostream>
#include <cstddef>
#include <algorithm>
#include "Node.hpp"

int Node::calculateHeight(){

	int heightTracker = 0;
	//check if leaf
	if (!(leftChild && rightChild)){;}

	else if (!rightChild){
		heightTracker = leftChild->calculateHeight()+1;
	}
	else if (!leftChild){
		heightTracker = rightChild->calculateHeight()+1;
	}
	else {
		heightTracker = std::max(leftChild->calculateHeight(),
				                 rightChild->calculateHeight())+1;
	}
	this->height = heightTracker;

	return heightTracker;
}

Node * Node::firstInSubtree(){
	//follow all the way to the left
	Node * currentNode = this;
	while(currentNode->leftChild){
		currentNode = currentNode->leftChild;
	}
	return currentNode;
}

Node * Node::lastInSubtree(){
	//follow all the way to the right
		Node * currentNode = this;
		while(currentNode->rightChild){
			currentNode = currentNode->rightChild;
		}
		return currentNode;
}

Node * Node::getSuccessor(){
	//two cases, right child and no right child
	if (this->rightChild){
		return this->rightChild->firstInSubtree();
	}
	//if no right child, go up til reverse direct is left pathway
	Node * currentNode = this;
	while (currentNode->parent != nullptr){
		if (currentNode == currentNode->parent->getLeftChild())
			return currentNode->parent;
		currentNode = currentNode->parent;
	}
	return nullptr;//IMPLEMENT throw a no-successor
}

Node * Node::getPredecessor(){
	if (!this->parent){
		if (this->leftChild){
			return this->leftChild->lastInSubtree();
		}
	}
	if ((this->getParent())->getRightChild()==this){
		return this->getParent();
	}
	else {
		//up the tree, following until the node is a right node, then get
		//last node of the left sibling
		Node * currentNode = this;
		while (currentNode->parent &&
			   currentNode == currentNode->parent->leftChild){
			   currentNode=currentNode->parent;
		}
		//current node is either root or the right child of a node
		if (this->parent){//this means that current node is a right child
			return this->parent;
		}
		return nullptr;
	}
}


