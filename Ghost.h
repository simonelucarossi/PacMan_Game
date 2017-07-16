#ifndef GHOST_H_
#define GHOST_H_

#include <string>
#include <iostream>
#include "Map.h"
using namespace std;

class Ghost {
private:
	string urlImage;
	int x,y, xinit, yinit;
	int previous;
	bool exit;
	bool dead;
	int frame;
	int randattuale;
	bool eatable;
	int image;
	int movementFrame;
	int ImageInit;
public:
	Ghost(Map&, int, int, int);
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
	void moveGhost(Map&, int, int);
	bool checkUp(Map&);
	bool checkDown(Map&);
	bool checkLeft(Map&);
	bool checkRight(Map&);
	bool checkPacmanUp(Map&);
	bool checkPacmanDown(Map&);
	bool checkPacmanLeft(Map&);
	bool checkPacmanRight(Map&);
	void setRandAttuale(int);
	void setPrevious(int);
	bool getEatable() { return eatable; }
	void setEatable(bool x) { eatable = x; }
	void setImage(int q) { image = q; }
	bool restartGhost(Map&);
	inline int getPrevious(){ return previous; }
	int nextFrame();
	int getFrame();
	int getRandAttuale();
	inline int getMovementFrame() { return movementFrame; }
	void changeEatableFrame();
	void changeMovementFrame();
};

#endif
