#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include "Node.h"

using namespace std;

template <class T> 
class Tree{
public:
	Tree():_root(NULL){};
	Tree(Node<T>* root):_root(root){};

	/*Should return the root of the tree
	* if the tree is empty should return NULL
	*/
	Node<T>* getRoot() const;

	/* Should return the node that contains the input paramter.
	* if such node does not exist, should return NULL
	*/	
	Node<T>* findNode(const T&) const;

	/*Should return the node with the maximal value
	* if the tree is empty should return NULL
	*/
	Node<T>* getMaximum() const;

	/* Should delete the node with input parameter from the tree, 
	 * if a node with this value does not exist, returns false 
	 * if the deletion succeeded returns true
	 * otherwise, returns false 
	 */
	bool deleteElement(const T&);

	/* Should delete the node todelete from the tree, 
	 * if the deletion succeeded returns true
	 * otherwise, returns false 
	 */
	bool deleteNode(Node<T>* todelete);
	
	/*Should add a node with input value to the tree
	* if a node with the same value exists, the function should return false
	* otehrwise, it should return true
	*/
	bool addElement(const T&);

	/*Should print the tree in ascending order. 
	* (first value is the smallest node in the tree)
	* if the tree is empty, it should print 'The tree is empty'
	*/
	void printTree() const;

private:
	Node<T>* _root;
	void inorder(Node<T>*) const;
};

//get root
template <class T>
Node<T>* Tree<T>::getRoot() const
{
	return _root;
}

//find node - returns the eqvivalent node or NULL
template <class T>
Node<T>* Tree<T>::findNode(const T& ele) const
{
	Node<T>* temp=_root;
	while(temp!=NULL)
	{
		if(temp->getElement()==ele)
			return temp;
		else if(temp->getElement()<ele)
			temp=temp->getRight();
		else temp=temp->getLeft();
	}
	return NULL;
}

//returns the maximum value in the tree if the tree is empty returns NULL
template <class T>
Node<T>* Tree<T>::getMaximum() const
{
	Node<T>* temp=_root;
	if(temp==NULL)
		return NULL;
	while(temp->getRight()!=NULL)
	{
		temp=temp->getRight();
	}
	return temp;
}
template <class T>
bool Tree<T>::deleteNode(Node<T>* todelete)
{
	int Fleft=0, Fright=0, isroot=0;
	if(todelete==_root)
		isroot=1;
	else if(todelete->getParent()->getLeft()==todelete)//in case todelete was a left child
		Fleft=1;
	else (todelete->getParent()->getRight()==todelete)//in case todelete was a right child
		Fright=1;
	
	//first case- no children
	if((todelete->getLeft()==NULL)&&(todelete->getRight()==NULL))
	{
		if(Fleft)//in case todelete was a left child
			todelete->getParent()->getLeft()=NULL;
		else if(Fright) 
			todelete->getParent()->getRight()=NULL;
		delete todelete;//מה זה עושה?!?!?!?!?!?!?!?!?!?!?!!!!!!!!!!!!!!!!!!!!!?!?!?!?
		return true;
	}
	//second case- one child
	/*else if((todelete->_left==NULL)&&(todelete->_right!=NULL)||(todelete->_left!=NULL)&&(todelete->_right==NULL))
	{
		if(todelete->_right!=NULL)
		{

		}
	}*/


	return false;
}

//finds the node with the input parameter, deletes it.
template <class T>
bool Tree<T>::deleteElement(const T& input)
{
	Node<T>* temp=findNode(input);
	if(temp!=NULL)
	{
		if(deleteNode(temp))
			return true;
		else
			return false;
	}
	else
		return false;
}
#endif