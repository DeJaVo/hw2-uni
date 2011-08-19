/***************************************************************************
 *
 * HW 2
 *
 * Author:  Dvir Segal
 *
 * Author:  Sheira Ben Haim
 **************************************************************************/

#include "Movie.h"

using namespace std;

//defualt and regular c'tor
Movie::Movie(string name, int score)
{
	_name=name;
	_score=score;
}

//get score
int Movie::getScore() const
{
	return _score;
}

//get name
string Movie::getName() const
{
	return _name;
}


//operator <
bool Movie::operator<(const Movie& mov) const
{
	if(_score<mov._score)
		return true;
	if(_score==mov._score)
	{
		if(_name.compare(mov._name)<0)//string compare func
			return true;
	}
	return false;
}

//operator ==
bool Movie::operator==(const Movie& mov) const
{
	if((_score==mov._score)&&(_name.compare(mov._name)==0))
		return true;
	return false;
}

//I/O stream operator
ostream& operator<<(ostream& out, const Movie& mov)
{
	out<<mov._name<<"("<<mov._score<<")";
	return out;
}