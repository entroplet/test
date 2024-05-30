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

