#include "Map.h"
#include "Ghost.h"

class PacMan{
	private:
	string urlImage;
	int x,y;
	int previous;
	int score;
	int lifes;
	int eated;

	
public:
	PacMan(Map&);
	//~PacMan();
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
	void printScore();
	bool CheckCollision(Ghost, Ghost, Ghost,Ghost);
	bool eatGhost(Ghost&, Ghost&, Ghost&, Ghost&, Map&);
	bool eatPill();
	inline int getLifes(){ return lifes; }
};