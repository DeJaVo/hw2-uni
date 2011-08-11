#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>
#include <ostream>

using namespace std;

class Movie {
public:
	Movie(string name, int score);

	int getScore() const;
	string getName() const;
	
	/* movie1 is smaller than  movie2,
	*  if its score is smaller. 
	*  If the scores are the same, their names should be lexicographic compared*/
	bool operator<(const Movie&) const;
	
	/* movie1 equals movie2 if their scores and names are the same */
	bool operator==(const Movie&) const;

	/* Should output the movie name and movie score */
	friend ostream& operator<<(ostream&, const Movie&);
private:
	int _score;
	string _name;
};

#endif