#include "PacMan.h"

PacMan::PacMan(Map& m) {
		x = 22;
		y = 13;
		previous = 0;
		
		m.map[x][y] = 11;
	}
	
	//PacMan::~PacMan();
	
	int PacMan::getCoordinateX() { return x; }
	int PacMan::getCoordinateY() { return y; }
	
	string PacMan::getUrlImage() { return urlImage; }
	
	void PacMan::setUrlImage(string c) { urlImage = c; }
	
	void PacMan::setCoordinateX(int xP) { x = xP; }
	
	void PacMan::setCoordinateY(int yP) { y = yP; }
	
	bool PacMan::MoveLeft(Map& m) { 
		if(m.map[x][y-1] == 0 || m.map[x][y-1] == 75){
			if(x == 15 && (y-1) == 0 ){
				m.map[x][y] = 0;
				y = 29;
			}
			m.map[x][y] = 0;
			m.map[x][y-1] = 11;
			y = y-1;
			return true;
		}
		else if(m.map[x][y-1] == 9){
			score = score + 10;
			m.map[x][y] = 0; 
			m.map[x][y-1] = 11;
			y = y-1;
			return true;
		}

		return false;

	}
	
	bool PacMan::MoveUp(Map& m){
		if(m.map[x-1][y] == 0 || m.map[x-1][y] == 75){
			m.map[x][y] = 0; 
			m.map[x-1][y] = 11;
			x = x-1;
			return true;
		}

		else if(m.map[x-1][y] == 9){
			score = score + 10;
			m.map[x][y] = 0; 
			m.map[x-1][y] = 11;
			x = x-1;

			return true;
		}

		
		return false;

	}
	
	bool PacMan::MoveDown(Map& m){
		if(m.map[x+1][y] == 0 || m.map[x+1][y] == 75){
			m.map[x][y] = 0; 
			m.map[x+1][y] = 11;
			x = x+1;
			return true;
		}

		else if(m.map[x+1][y] == 9){
			score = score + 10;
			m.map[x][y] = 0; 
			m.map[x+1][y] = 11;
			x = x+1;
			return true;
		}


		return false;

	}

	
	bool PacMan::MoveRight(Map& m){ 
		if(m.map[x][y+1] == 0 || m.map[x][y+1] == 75){
			if(x == 15 && (y+1) == 29){
				m.map[x][y] = 0;
				y = 0;
			}
			m.map[x][y] = 0; 
			m.map[x][y+1] = 11;
			y = y+1;
			return true;
		}
		else if(m.map[x][y+1] == 9){
			score = score + 10;
			m.map[x][y] = 0;  
			m.map[x][y+1] = 11;
			y = y+1;
			return true;
		}

		return false;

	}

	void PacMan::printScore() {
		if(lifes == 3){
			cout << "       SCORE: " << score << "          " << "LIFES: " << "ᴥ ᴥ ᴥ"<< endl;
		}
		if(lifes == 2){
			cout << "       SCORE: " << score << "          " << "LIFES: " << "ᴥ ᴥ"<< endl;
		}
		if(lifes == 1){
			cout << "       SCORE: " << score << "          " << "LIFES: " << "ᴥ"<< endl;
		}
	}

	bool PacMan::CheckCollision(Ghost g1, Ghost g2, Ghost g3,Ghost g4) {
		if(x == g1.getCoordinateX() && y == g1.getCoordinateY()) { lifes--; return true; }
		if(x == g2.getCoordinateX() && y == g2.getCoordinateY()) { lifes--; return true; }
		if(x == g3.getCoordinateX() && y == g3.getCoordinateY()) { lifes--; return true; }
		if(x == g4.getCoordinateX() && y == g4.getCoordinateY()) { lifes--; return true; }
	}