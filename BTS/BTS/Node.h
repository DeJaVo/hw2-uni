/***************************************************************************
 *
 * HW 2
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <list>

using namespace std;

template <class T> 
class Node{
public:
	Node();
	Node(T element):_parent(NULL),_right(NULL),_left(NULL),_element(element){};

	Node& operator=(const Node& node);

	bool operator<(const Node&) const;
	
	bool operator==(const Node&) const;

	/*This function should call the operator<< of the node's element*/
	template <class T> friend ostream& operator<<(ostream&, const Node<T>&);

	Node* getParent() const; 
	void setParent(Node* node);

	Node* getRight() const;
	void setRight(Node* node);

	Node* getLeft() const;
	void setLeft(Node* node);

	T getElement() const;
	void setElement(T ele);

private:
	Node* _parent;
	Node* _right;
	Node* _left;
	T _element;
};

//defualt c'tor
template <class T> 
Node<T>::Node()
{
	_parent=NULL;
	_right=NULL;
	_left=NULL;
}

//assignment operator
template <class T>
Node<T>& Node<T>::operator=(const Node& node)
{
	if(this==&node)
		return *this;
	_element=node.getElement();
	return *this;
}

//operator <
template <class T> 
bool Node<T>::operator<(const Node& node) const
{
	return _element<node.getElement()?true:false;
}

//operator ==
template <class T>
bool Node<T>::operator==(const Node& node) const
{
	return _element==node.getElement()?true:false;
}

//operator << - friend function
template<class T>
ostream& operator<<(ostream& out, const Node<T>& node)
{
	out<<node._element;
	return out;
}

//get parent
template <class T>
Node<T>* Node<T>::getParent() const
{
	return _parent;
}

//set parent
template<class T>
void Node<T>::setParent(Node* node)
{
	_parent=node;
}

//get right node
template<class T>
Node<T>* Node<T>::getRight() const 
{
	return _right;
}

//set right node
template<class T>
void Node<T>::setRight(Node* node)
{
	_right=node;
}

//get left node
template<class T>
Node<T>* Node<T>::getLeft() const
{
	return _left;
}

//set left node
template<class T>
void Node<T>::setLeft(Node* node)
{
	_left=node;
}

//get this->element
template<class T>
T Node<T>::getElement() const
{
	return _element;
}

//set this->element
template<class T>
void Node<T>::setElement(T ele)
{
	_element=ele;
}

#endif