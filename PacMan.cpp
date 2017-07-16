#include "PacMan.h"

PacMan::PacMan(Map& m) {
    x = 22;
    y = 13;

    previous = 0;
    score = 0;
    lifes = 3;
    frame = 0;
    eated = 0;
    Pills = m.getNumberOfPills()-1;
    direction = 1; // left
    deathPacman = false;
    frameDeath = 0;

    m.map[x][y] = 11;
    ghostCollision = NULL;
}

//PacMan::~PacMan();
int PacMan::getPills() { return Pills; }

int PacMan::getCoordinateX() { return x; }
int PacMan::getCoordinateY() { return y; }

string PacMan::getUrlImage() { return urlImage; }
void    PacMan::setUrlImage(string c) { urlImage = c; }

void PacMan::setCoordinateX(int xP) { x = xP; }
void PacMan::setCoordinateY(int yP) { y = yP; }

void PacMan::setDirection(int direction) { this->direction = direction; }
int  PacMan::getDirection() { return this->direction; }

int PacMan::getScore() { return this->score; }
int PacMan::getLifes() { return this->lifes; }
void PacMan::setLifes(int q) { this->lifes = q; }

void PacMan::nextStep(Map& map) {
    switch(this->direction) {
        case 0:
            this->MoveUp(map);
            break;
        case 1:
            this->MoveLeft(map);
            break;
        case 2:
            this->MoveRight(map);
            break;
        case 3:
            this->MoveDown(map);
            break;
    }
}

bool PacMan::MoveLeft(Map& m) {
    if(m.map[x][y-1] == 0 || m.map[x][y-1] == 75 || m.map[x][y-1] == 77 || m.map[x][y-1] == 78 || m.map[x][y-1] == 79 || m.map[x][y-1] == 15){
        if(x == 15 && (y-1) == 0 ){
            m.map[x][y] = 0;
            y = 29;
        }
        m.map[x][y] = 0;
        previous = m.map[x][y-1];
        m.map[x][y-1] = 11;
        y = y-1;
        return true;
    }
    else if(m.map[x][y-1] == 9){
        score = score + 10;
        Pills--;
        m.map[x][y] = 0;
        previous = m.map[x][y-1];
        m.map[x][y-1] = 11;
        y = y-1;
        return true;
    }

    else if(m.map[x][y-1] == 15){
      Pills--;
      return true;  
    }



    return false;

}

bool PacMan::MoveUp(Map& m){
    if(m.map[x-1][y] == 0 || m.map[x-1][y] == 75 || m.map[x-1][y] == 77 || m.map[x-1][y] == 78 || m.map[x-1][y] == 79 || m.map[x-1][y] == 15){
        m.map[x][y] = 0;
        previous = m.map[x-1][y];
        m.map[x-1][y] = 11;
        x = x-1;
        return true;
    }

    else if(m.map[x-1][y] == 9){
        score = score + 10;
        Pills--;
        m.map[x][y] = 0;
        previous = m.map[x-1][y];
        m.map[x-1][y] = 11;
        x = x-1;

        return true;
    }

    else if(m.map[x-1][y] == 15){
      Pills--;
      return true;  
    }


    return false;

}

bool PacMan::MoveDown(Map& m){
    if(m.map[x+1][y] == 0 || m.map[x+1][y] == 75 || m.map[x+1][y] == 77 || m.map[x+1][y] == 78 || m.map[x+1][y] == 79 || m.map[x+1][y] == 15){
        m.map[x][y] = 0;
        previous = m.map[x+1][y];
        m.map[x+1][y] = 11;
        x = x+1;
        return true;
    }

    else if(m.map[x+1][y] == 9){
        score = score + 10;
        Pills--;
        m.map[x][y] = 0;
        previous = m.map[x+1][y];
        m.map[x+1][y] = 11;
        x = x+1;
        return true;
    }
    else if(m.map[x+1][y] == 15){
      Pills--;
      return true;  
    }

    return false;

}


bool PacMan::MoveRight(Map& m){
    if(m.map[x][y+1] == 0 || m.map[x][y+1] == 75 || m.map[x][y+1] == 77 || m.map[x][y+1] == 78 || m.map[x][y+1] == 79 || m.map[x][y+1] == 15){
        if(x == 15 && (y+1) == 29){
            m.map[x][y] = 0;
            y = 0;
        }
        m.map[x][y] = 0;
        previous = m.map[x][y+1];
        m.map[x][y+1] = 11;
        y = y+1;
        return true;
    }
    else if(m.map[x][y+1] == 9){
        score = score + 10;
        Pills--;
        m.map[x][y] = 0;
        previous = m.map[x][y+1];
        m.map[x][y+1] = 11;
        y = y+1;
        return true;
    }
    else if(m.map[x][y+1] == 15){
      Pills--;
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
    if(x == g1.getCoordinateX() && y == g1.getCoordinateY() && !(g1.getEatable())) { ghostCollision = &g1; lifes--; return true; }
    if(x == g2.getCoordinateX() && y == g2.getCoordinateY() && !(g2.getEatable())) { ghostCollision = &g2; lifes--; return true; }
    if(x == g3.getCoordinateX() && y == g3.getCoordinateY() && !(g3.getEatable())) { ghostCollision = &g3; lifes--; return true; }
    if(x == g4.getCoordinateX() && y == g4.getCoordinateY() && !(g4.getEatable())) { ghostCollision = &g4; lifes--; return true; }

    if(x == g1.getCoordinateX() && y == g1.getCoordinateY() && (g1.getEatable())) { 
        ghostCollision = &g1; 
        if(ghostCollision->getPrevious() == 9 || ghostCollision->getPrevious() == 15) { Pills--; }
        return true; 
    }
    if(x == g2.getCoordinateX() && y == g2.getCoordinateY() && (g2.getEatable())) { 
        ghostCollision = &g2; 
        if(ghostCollision->getPrevious() == 9 || ghostCollision->getPrevious() == 15) { Pills--; }
        return true; 
    }
    if(x == g3.getCoordinateX() && y == g3.getCoordinateY() && (g3.getEatable())) { 
        ghostCollision = &g3; 
        if(ghostCollision->getPrevious() == 9 || ghostCollision->getPrevious() == 15) { Pills--; }
        return true; 
    }
    if(x == g4.getCoordinateX() && y == g4.getCoordinateY() && (g4.getEatable())) { 
        ghostCollision = &g4; 
        if(ghostCollision->getPrevious() == 9 || ghostCollision->getPrevious() == 15) { Pills--; }
        return true; 
    }
}

bool PacMan::eatGhost(Ghost& g1, Ghost& g2, Ghost& g3, Ghost& g4, Map& m) {
    if(x == g1.getCoordinateX() && y == g1.getCoordinateY() && g1.getEatable()) {
        eated++;
        score += (eated*200);
        g1.restartGhost(m);
        ghostCollision = NULL;
        return true;
    }
    if(x == g2.getCoordinateX() && y == g2.getCoordinateY() && g2.getEatable()) {
        eated++;
        score += (eated*200);
        g2.restartGhost(m);
        ghostCollision = NULL;
        return true;
    }
    if(x == g3.getCoordinateX() && y == g3.getCoordinateY() && g3.getEatable()) {
        eated++;
        score += (eated*200);
        g3.restartGhost(m);
        ghostCollision = NULL;
        return true;
    }
    if(x == g4.getCoordinateX() && y == g4.getCoordinateY() && g4.getEatable()) {
        eated++;
        score += (eated*200);
        g4.restartGhost(m);
        ghostCollision = NULL;
        return true;
    }
}

bool PacMan::eatPill() {
    if(previous == 15){
        Pills--;
        return true;
    }
    return false;
}

int PacMan::nextFrame() {
    return (this->frame++%3);
}
