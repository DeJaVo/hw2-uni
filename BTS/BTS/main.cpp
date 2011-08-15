#include <iostream>
#include "Tree.h"
#include "Movie.h"

int main(){
	//create a tree for ints
	Tree<int> intee; 
	//add new nodes to the tree
	intee.addElement(12);
	intee.addElement(17);
	intee.addElement(23);
	intee.addElement(20);
	intee.addElement(10);
	intee.addElement(6);
	intee.addElement(14);
	intee.addElement(11);
	intee.addElement(9);
	intee.addElement(22);
	intee.addElement(7);
	if(intee.addElement(14))
	{
		cout << "Error: entered 14 twice!!" << endl;
	}
	//print the nodes in ascending order
	intee.printTree();
	cout << "6 7 9 10 11 12 14 17 20 22 23 **********" << endl;

	//delete a node with only right child
	intee.deleteElement(6);
	intee.printTree();
	cout << "7 9 10 11 12 14 17 20 22 23 **********" << endl;

	//delete a node with only left child
	intee.deleteElement(23);
	//delete leaf that is a right child
	intee.deleteElement(22);
	intee.printTree();
	cout << "7 9 10 11 12 14 17 20 **********" << endl;

	//delete leaf that is a left child
	intee.deleteElement(14);

	//delete node with two children
	if (!intee.deleteElement(10))
	{
		cout << "Error: delete an element failed!!" << endl;
	}
	intee.printTree();
	cout << "7 9 11 12 17 20 **********" << endl;

	//delete node that does not exist
	if (intee.deleteElement(10))
	{
		cout << "Error: Delete an element that does not exist returns true!!" << endl;
	}

	//print the nodes in ascending order
	intee.printTree();
	cout << "7 9 11 12 17 20 **********" << endl;

	//delete the root
	intee.deleteElement(12);
	intee.addElement(3);
	intee.addElement(700);
	intee.printTree();
	cout << "3 7 9 11 17 20 700 **********" << endl;

	//create a tree for movies
	Movie mymovie("Great Movie",9);
	Tree<Movie> movies;
	movies.addElement(mymovie);

	//add new movies
	movies.addElement(Movie("Good Movie",8));
	movies.addElement(Movie("The Greatest Movie",9));
	movies.addElement(Movie("Medium Minus Movie",6));
	movies.addElement(Movie("Bad Movie",3));

	//print the nodes in ascending order
	cout << "Best Movie ever: " << *movies.getMaximum() << endl;
	cout << "Best Movie ever: The Greatest Movie(9) *******" << endl;
	movies.printTree();
	cout << "Bad Movie(3) Medium Minus Movie(6) Good Movie(8) Great Movie(9) The Greatest Movie(9) *******" << endl;

	cout << "found a good one: " << *movies.findNode(Movie("Good Movie",8)) << endl;
	cout << "found a good one: Good Movie(8) *******" << endl;

	cout << "Good Luck!" << endl;

	return 0;
}
