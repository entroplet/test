/*
 * BinaryTree.cpp
 *
 *  Created on: May 25, 2024
 *      Author: markdillman
 */

#include "Node.hpp"
#include "BinaryTree.hpp"
#include <stack>
#include <deque>
#include <iostream>

int main(){
	Node * tempNode,successor;
	std::vector<int> v;
	v = {1, 3, 16, 5, 12, 9, 8, 19, 4};
	BinaryTree b;
	b.buildTree(v);
	b.inOrderPrint(b.getRoot());
	tempNode = b.BFS(9);
	std::cout << std::endl <<  "Current node: " << tempNode->getVal() <<std::endl;
	std::cout << "Successor to node" << tempNode->getVal() << " = "
			  << (tempNode->getSuccessor())->getVal() << std::endl;
	std::cout << "Predecessor of 4 is: " <<
			b.BFS(4)->getPredecessor()->getVal() << std::endl;
	return 0;
}

void BinaryTree::buildTree(const std::vector<int>& data){
	int dataSize = data.size();
	if (dataSize==0){
		std::cout << "No tree initialization array. Exiting construct function.\n";
		return;
	}
	this->setRoot(new Node(data[0]));
	std::deque<Node *> nodeQueue;
	nodeQueue.push_back(this->getRoot());
	//will be used to receive value from queue in the build loop body
	Node * currentNode;

	auto it=(data.begin()+1);
	//breadth first search but add to next vacant spot
	while (distance(data.begin(),it)<dataSize){
		//it will be incremented in loop body, so use distance as opposed to binary end()
		//there will always be at least one element of uninstantiated data here because
		//of loop condition
		currentNode = nodeQueue.front();
		nodeQueue.pop_front();
		currentNode->setLeftChild(new Node(*it));//currentNode->leftChild = new Node(*it);
		currentNode->getLeftChild()->setParent(currentNode);
		nodeQueue.push_back(currentNode->getLeftChild());
		it++;
		if (distance(data.begin(),it)<dataSize){
			//currentNode->rightChild = new Node(*it);
			currentNode->setRightChild(new Node(*it));
			nodeQueue.push_back(currentNode->getRightChild());
			//currentNode->rightChild->setParent(currentNode);
			(currentNode->getRightChild())->setParent(currentNode);
			it++;
		}
	}
}

//this is DFS recursive delete
BinaryTree::~BinaryTree(){
	this->deleteSubtree(root);
}


Node * BinaryTree::deleteSubtree(Node * n){
	if (n->getLeftChild()){
		n->setLeftChild(deleteSubtree(n->getLeftChild()));
	}
	if (n->getRightChild()){
		n->setRightChild(deleteSubtree(n->getRightChild()));
	}
	delete n;
	return nullptr;
}

void BinaryTree::inOrderPrint(Node * n){
	if (n->getLeftChild()){
		this->inOrderPrint(n->getLeftChild());
	}
	std::cout << n->getVal() << " ";
	if (n->getRightChild()){
		this->inOrderPrint(n->getRightChild());
	}
}

Node * BinaryTree::BFS(int searchkey){
	std::deque<Node*> nodeQueue;
	nodeQueue.push_back(this->root);
	Node * tempNode;
	while(!nodeQueue.empty()){
		tempNode = nodeQueue.front();
		nodeQueue.pop_front();
		if (tempNode->getVal()==searchkey){
			return tempNode;
		}
		if (tempNode->getLeftChild()){
			nodeQueue.push_back(tempNode->getLeftChild());
		}
		if (tempNode->getRightChild()){
			nodeQueue.push_back(tempNode->getRightChild());
		}
	}
	return nullptr;
}
