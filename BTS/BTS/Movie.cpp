#include "Movie.h"

using namespace std;

Movie::Movie(string name, int score)
{
	_name=name;
	_score=score;
}

int Movie::getScore() const
{
	return _score;
}

string Movie::getName() const
{
	return _name;
}

bool Movie::operator<(const Movie& mov) const
{
	if(_score<mov._score)
		return true;
	if(_score==mov._score)
	{
		if(_name.compare(mov._name)<0)
			return true;
	}
	return false;
}

bool Movie::operator==(const Movie& mov) const
{
	if((_score==mov._score)&&(_name.compare(mov._name)==0))
		return true;
	return false;
}

ostream& operator<<(ostream& out, const Movie& mov)
{
	out<<mov._name<<" "<<mov._score;
	return out;
}