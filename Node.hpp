/*
 * Node.hpp
 *
 *  Created on: May 25, 2024
 *      Author: markdillman
 */

#ifndef NODE_HPP_
#define NODE_HPP_

class Node {

private:
	int val;
	int height;//subtree properties
	Node * parent;
	Node * leftChild;
	Node * rightChild;

public:
	void setVal(int _i){val=_i;};
	int getVal()const{return val;};
	int getHeight()const{return height;};
	void setParent(Node * _parent){parent=_parent;};
	Node* getParent()const{return parent;};
	void setLeftChild(Node * _leftChild){leftChild=_leftChild;};
	Node* getLeftChild()const{return leftChild;};
	void setRightChild(Node* _rightChild){rightChild=_rightChild;};
	Node* getRightChild()const{return rightChild;};
	int calculateHeight();//returns and internally adjusts height
	Node * firstInSubtree();
	Node * lastInSubtree();
	Node * getPredecessor();
	Node * getSuccessor();
	void printSubtree(Node *);
	//constructors
	Node():val(0),height(0),parent(nullptr),leftChild(nullptr),rightChild(nullptr){};
	Node(int _val):val(_val),height(0),parent(nullptr),leftChild(nullptr),rightChild(nullptr){};
	Node(int _val,Node*_parent,Node*_leftChild,Node*_rightChild):
		val(_val),height(0),parent(_parent),leftChild(_leftChild),rightChild(_rightChild){};
	Node(Node& n):val(n.val),height(n.height),parent(n.parent),leftChild(n.leftChild),rightChild(n.rightChild){};//copy constructor
};



#endif /* NODE_HPP_ */
