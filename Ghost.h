#include <string>
#include <iostream>
#include "Map.h"
using namespace std;

class Ghost {
private:
	string urlImage;
	int x,y;
	int previous;
	bool exit;
	bool dead;
	int randattuale;
	
public:
	Ghost(Map&, int, int);
	int getCoordinateX();
	int getCoordinateY();
	string getUrlImage();
	void setUrlImage(string);
	void setCoordinateX(int);
	void setCoordinateY(int);
	bool MoveLeft(Map&);
	bool MoveUp(Map&);
	bool MoveDown(Map&);
	bool MoveRight(Map&);
	void moveGhost(Map&);
	bool checkUp(Map&);
	bool checkDown(Map&);
	bool checkLeft(Map&);
	bool checkRight(Map&);
	void setRandAttuale(int);
	void setPrevious(int);

	inline int getPrevious(){ return previous; }
};