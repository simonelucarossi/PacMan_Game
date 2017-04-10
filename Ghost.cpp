	#include "Ghost.h"
	#include <cstdlib>
	#include <ctime>

	Ghost::Ghost(Map& m, int xpassed, int ypassed) {
		x = xpassed;
		y = ypassed;
		previous = 0;
		dead = false;
		exit = false;
		randattuale = 0;
		
		m.map[x][y] = 75;
	}
	
	//Ghost::~Ghost();
	
	int Ghost::getCoordinateX() { return x; }
	int Ghost::getCoordinateY() { return y; }
	
	string Ghost::getUrlImage() { return urlImage; }
	
	void Ghost::setUrlImage(string c) { urlImage = c; }
	
	void Ghost::setCoordinateX(int xP) { x = xP; }
	
	void Ghost::setCoordinateY(int yP) { y = yP; }

	void Ghost::setRandAttuale(int rA) { randattuale = rA; }

	void Ghost::setPrevious(int p) { previous = p; }
	
	bool Ghost::MoveLeft(Map& m) { 
		if(m.map[x][y-1] == 0 || m.map[x][y-1] == 11){
			m.map[x][y] = previous;

			if(m.map[x][y-1] != 11){ previous = m.map[x][y-1]; } else { previous = 0; }
			m.map[x][y-1] = 75;
			y = y-1;
			return true;
		}
		else if(m.map[x][y-1] == 9){
			m.map[x][y] = previous;
			previous = m.map[x][y-1]; 
			m.map[x][y-1] = 75;
			y = y-1;
			return true;
		}

		else if(m.map[x][y-1] == 7){
			m.map[x][y] = previous;
			previous = m.map[x][y-1]; 
			m.map[x][y-1] = 75;
			y = y-1;
			return true;
		}

		else if(m.map[x][y-1] == 8){
			m.map[x][y] = previous;
			previous = m.map[x][y-1]; 
			m.map[x][y-1] = 75;
			y = y-1;
			return true;
		}

		return false;

	}
	
	bool Ghost::MoveUp(Map& m){
		if(m.map[x-1][y] == 0 || m.map[x-1][y] == 11){
			m.map[x][y] = previous;
			if(m.map[x-1][y] != 11){ previous = m.map[x-1][y]; } else { previous = 0; } 
			m.map[x-1][y] = 75;
			x = x-1;
			return true;
		}

		else if(m.map[x-1][y] == 9){
			m.map[x][y] = previous; 
			previous = m.map[x-1][y];
			m.map[x-1][y] = 75;
			x = x-1;

			return true;
		}

		else if(m.map[x-1][y] == 7){
			m.map[x][y] = previous; 
			previous = m.map[x-1][y];
			m.map[x-1][y] = 75;
			this->exit = true;
			x = x-1;
			return true;
		}

		else if(m.map[x-1][y] == 8){
			m.map[x][y] = previous;
			previous = m.map[x-1][y]; 
			m.map[x-1][y] = 75;
			x = x-1;
			this->exit = true;
			return true;
		}


		return false;

	}
	
	bool Ghost::MoveDown(Map& m){
		if(m.map[x+1][y] == 0 || m.map[x+1][y] == 11){
			m.map[x][y] = previous;
			if(m.map[x][y] == 7 || m.map[x][y] == 8) { return false; }
			if(m.map[x+1][y] != 11){ previous = m.map[x+1][y]; } else { previous = 0; } 
			m.map[x+1][y] = 75;
			x = x+1;
			return true;
		}

		else if(m.map[x+1][y] == 9){
			m.map[x][y] = previous;
			previous = m.map[x+1][y]; 
			m.map[x+1][y] = 75;
			x = x+1;
			return true;
		}

		else if(m.map[x+1][y] == 7 && !(exit)){
			m.map[x][y] = previous;
			previous = m.map[x+1][y]; 
			m.map[x+1][y] = 75;
			x = x+1;
			return true;
		}

		else if(m.map[x+1][y] == 8 && !(exit)){
			m.map[x][y] = previous;
			previous = m.map[x+1][y]; 
			m.map[x+1][y] = 75;
			x = x+1;
			return true;
		}

		return false;

	}

	
	bool Ghost::MoveRight(Map& m){ 
		if(m.map[x][y+1] == 0 || m.map[x][y+1] == 11){
			m.map[x][y] = previous;
			if(m.map[x][y+1] != 11){ previous = m.map[x][y+1]; } else { previous = 0; } 
			m.map[x][y+1] = 75;
			y = y+1;
			return true;
		}
		else if(m.map[x][y+1] == 9){
			m.map[x][y] = previous;
			previous = m.map[x][y+1];  
			m.map[x][y+1] = 75;
			y = y+1;
			return true;
		}

		else if(m.map[x][y+1] == 7){
			m.map[x][y] = previous;
			previous = m.map[x][y+1];  
			m.map[x][y+1] = 75;
			y = y+1;
			return true;
		}

		else if(m.map[x][y+1] == 8){
			m.map[x][y] = previous;
			previous = m.map[x][y+1];  
			m.map[x][y+1] = 75;
			y = y+1;
			return true;
		}



		return false;

	}

	bool Ghost::checkUp(Map& m){
		if(m.map[x-1][y] != 0 && m.map[x-1][y] != 9 && m.map[x-1][y] != 11 && m.map[x-1][y] != 75 && m.map[x-1][y] != 7 && m.map[x-1][y] != 8) { return false; }
		return true;
	}

	bool Ghost::checkDown(Map& m){
		if(m.map[x+1][y] != 0 && m.map[x+1][y] != 9 && m.map[x+1][y] != 11) { return false; }
		return true;
	}

	bool Ghost::checkLeft(Map& m){
		if(m.map[x][y-1] != 0 && m.map[x-1][y-1] != 9 && m.map[x-1][y-1] != 11) { return false; }
		return true;
	}

	bool Ghost::checkRight(Map& m){
		if(m.map[x][y+1] != 0 && m.map[x][y+1] != 9 && m.map[x][y+1] != 11) { return false; }
		return true;
	}

	void Ghost::moveGhost(Map& m){
		if(randattuale == 0 && (checkUp(m))) { this->MoveUp(m);}
		else if(randattuale == 1 && (checkLeft(m))) { this->MoveLeft(m);}
		else if(randattuale == 2 && (checkRight(m))) { this->MoveRight(m);}
		else if(randattuale == 3 && (checkDown(m))) { this->MoveDown(m);}

		else {
				int v1 = rand() % 4;
				if(v1 == 0){
					this->MoveUp(m);
					randattuale = v1;
				}
				if(v1 == 1){
					this->MoveLeft(m);
					randattuale = v1;
				}
				if(v1 == 2){
					this->MoveRight(m);
					randattuale = v1;
				}
				if(v1 == 3){
					this->MoveDown(m);
					randattuale = v1;
				}
			}
	}