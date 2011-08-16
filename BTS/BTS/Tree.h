/***************************************************************************
 *
 * HW 2
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include "Node.h"

using namespace std;

template <class T> 
class Tree{
public:
	Tree():_root(NULL){};
	
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

	//Free Tree
	void free_tree(Node<T>* node);
	//d'tor
	~Tree();
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
		if(*temp==ele)
			return temp;
		else if(*temp<ele)
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

//deletes a node, if the deletion succeeded returns true otherwise, returns false  
template <class T>
bool Tree<T>::deleteNode(Node<T>* todelete)
{
	int Fleft=0, Fright=0, isroot=0, numOfChilds=0;
	if(todelete==_root)
		isroot=1;
	else if(*todelete<*(todelete->getParent()))//in case todelete was a left child
		Fleft=1;
	else //in case todelete was a right child
		Fright=1;

	//finds number of children of todelete
	if((todelete->getLeft()==NULL)&&(todelete->getRight()==NULL))
		numOfChilds=0;
	else if((todelete->getLeft()!=NULL)&&(todelete->getRight()!=NULL))
		numOfChilds=2;
	else 
		numOfChilds=1;
	
	//first case- no children
	if(!numOfChilds)
	{
		if(Fleft)//in case todelete was a left child
			todelete->getParent()->setLeft(NULL);
		else if(Fright) 
			todelete->getParent()->setRight(NULL);
		delete todelete;
		return true;
	}
	//second case- one child
	else if(numOfChilds==1)
	{
		if(Fleft)//in case todelete was a left child
		{
			if(todelete->getRight()!=NULL)//in case the only son was a right child
			{
				todelete->getParent()->setLeft(todelete->getRight());
				todelete->getRight()->setParent(todelete->getParent());
			}
			else//in case the only son was a left child
			{
				todelete->getParent()->setLeft(todelete->getLeft());
				todelete->getLeft()->setParent(todelete->getParent());
			}
		}
		else// in case todelete was a right child
		{
			if(todelete->getRight()!=NULL)//in case the only son was a right child
			{
				todelete->getParent()->setRight(todelete->getRight());
				todelete->getRight()->setParent(todelete->getParent());
			}
			else//in case the only son was a left child
			{
				todelete->getParent()->setRight(todelete->getLeft());
				todelete->getLeft()->setParent(todelete->getParent());
			}
		}
		delete todelete;
		return true;
	}

	else if(numOfChilds==2)
	{
		Node<T>* successor;
		successor=todelete->getRight();
		while((successor->getLeft())!=NULL)
			successor=successor->getLeft();
		*todelete=*successor;
		return deleteNode(successor);
	}
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

//adds element to the tree,if a node with the same value exists, the function should return false otehrwise, it should return true
template<class T>
bool Tree<T>::addElement(const T& ele)
{
	Node<T>* temp=findNode(ele);//checks if element exists in the tree 
	if(_root==NULL)//in case tree is empty
		{
			_root=new Node<T>(ele);
			return true;
		}
	Node<T>* tempRoot=_root;
	if(!temp)//in case element doesn't exist in tree adds it to the tree
	{
		temp=new Node<T>(ele);//calling c'tor
		while(tempRoot!=NULL)
		{
			if(*temp<*tempRoot)
			{
				if(tempRoot->getLeft()!=NULL)
					tempRoot=tempRoot->getLeft();
				else//adds the node to the tree
				{
					tempRoot->setLeft(temp);
					temp->setParent(tempRoot);
					return true;
				}
			}
			else 
			{
				if(tempRoot->getRight()!=NULL)
					tempRoot=tempRoot->getRight();
				else//adds the node to the tree
				{
					tempRoot->setRight(temp);
					temp->setParent(tempRoot);
					return true;
				}
			}
		}
	}
	return false;
}

//recursive func, prints all elements in an inorder walk
template<class T>
void Tree<T>::inorder(Node<T>* temp) const
{
	if((temp->getLeft())!=NULL)
		inorder(temp->getLeft());
	cout<<*temp<<" ";
	if((temp->getRight())!=NULL)
		inorder(temp->getRight());
	return;
}

//calls the inorder func
template<class T>
void Tree<T>::printTree() const
{
	inorder(_root);
	cout<<endl;
	return;

}

//Free tree
template<class T>
void Tree<T>::free_tree(Node<T>* node)
{
	Node<T>* temp=node;
	if((temp->getLeft()==NULL)&&(temp->getRight()==NULL))
	{
		delete temp;
		return;
	}
	if(temp->getLeft()!=NULL)
		free_tree(temp->getLeft());
	if(temp->getRight()!=NULL)
		free_tree(temp->getRight());
	delete temp;
	return;


}

//d'tor
template<class T>
Tree<T>::~Tree()
{
	free_tree(_root);
}
#endif