#include "Ghost.h"
#include <cstdlib>
#include <ctime>

Ghost::Ghost(Map& m, int xpassed, int ypassed, int imageP) {
    x = xpassed;
    y = ypassed;
    xinit = xpassed;
    yinit  = ypassed;
    previous = 0;
    dead = false;
    exit = false;
    randattuale = 0;
    image = imageP;
    eatable = false;
    frame = 0;
    
    movementFrame = 0;
    ImageInit = imageP;

    m.map[x][y] = image;
}

//Ghost::~Ghost();

int Ghost::getCoordinateX() { return x; }
int Ghost::getCoordinateY() { return y; }

int Ghost::getFrame() { return frame; }

string Ghost::getUrlImage() { return urlImage; }

void Ghost::setUrlImage(string c) { urlImage = c; }

void Ghost::setCoordinateX(int xP) { x = xP; }

void Ghost::setCoordinateY(int yP) { y = yP; }

void Ghost::setRandAttuale(int rA) { randattuale = rA; }

int Ghost::getRandAttuale() { return randattuale; }

void Ghost::setPrevious(int p) { previous = p; }

bool Ghost::MoveLeft(Map& m) {
    if(m.map[x][y-1] == 0 || m.map[x][y-1] == 11 || m.map[x][y-1] == 75 || m.map[x][y-1] == 76 || m.map[x][y-1] == 77 || m.map[x][y-1] == 78 || m.map[x][y-1] == 79 ||  m.map[x][y-1] == 15 ){
        m.map[x][y] = previous;

        if(x == 15 && (y-1) == 0 ){
            m.map[x][y] = 0;
            y = 29;
        }

        if(m.map[x][y-1] != 11  && m.map[x][y-1] != 75 && m.map[x][y-1] != 76 && m.map[x][y-1] != 77 && m.map[x][y-1] != 78 && m.map[x][y-1] != 79){ previous = m.map[x][y-1]; }
        m.map[x][y-1] = image;
        y = y-1;



        return true;
    }
    else if(m.map[x][y-1] == 9){
        m.map[x][y] = previous;
        previous = m.map[x][y-1];
        m.map[x][y-1] = image;
        y = y-1;
        return true;
    }

    else if(m.map[x][y-1] == 7){
        m.map[x][y] = previous;
        previous = m.map[x][y-1];
        m.map[x][y-1] = image;
        y = y-1;
        return true;
    }

    else if(m.map[x][y-1] == 8){
        m.map[x][y] = previous;
        previous = m.map[x][y-1];
        m.map[x][y-1] = image;
        y = y-1;
        return true;
    }

    return false;

}

bool Ghost::MoveUp(Map& m){
    if(m.map[x-1][y] == 0 || m.map[x-1][y] == 11 || m.map[x-1][y] == 75 || m.map[x-1][y] == 76 || m.map[x-1][y] == 77 || m.map[x-1][y] == 78 || m.map[x-1][y] == 79  || m.map[x-1][y] == 15){
        m.map[x][y] = previous;
        if(m.map[x-1][y] != 11  && m.map[x-1][y] != 75 && m.map[x-1][y] != 76 && m.map[x-1][y] != 77 && m.map[x-1][y] != 78 && m.map[x-1][y] != 79){ previous = m.map[x-1][y]; }
        else if((m.map[x-1][y] == 76 || m.map[x-1][y] == 77 || m.map[x-1][y] == 78 || m.map[x-1][y] == 79) && previous == 15){ previous = 9; }
        m.map[x-1][y] = image;
        x = x-1;
        return true;
    }

    else if(m.map[x-1][y] == 9){
        m.map[x][y] = previous;
        previous = m.map[x-1][y];
        m.map[x-1][y] = image;
        x = x-1;

        return true;
    }

    else if(m.map[x-1][y] == 7){
        m.map[x][y] = previous;
        previous = m.map[x-1][y];
        m.map[x-1][y] = image;
        this->exit = true;
        x = x-1;
        return true;
    }

    else if(m.map[x-1][y] == 8){
        m.map[x][y] = previous;
        previous = m.map[x-1][y];
        m.map[x-1][y] = image;
        x = x-1;
        this->exit = true;
        return true;
    }


    return false;

}

bool Ghost::MoveDown(Map& m){
    if(m.map[x+1][y] == 0 || m.map[x+1][y] == 11 || m.map[x+1][y] == 75 || m.map[x+1][y] == 76 || m.map[x+1][y] == 77 || m.map[x+1][y] == 78 || m.map[x+1][y] == 79  || m.map[x+1][y] == 15){
        m.map[x][y] = previous;
        if(m.map[x][y] == 7 || m.map[x][y] == 8) { return false; }
        if(m.map[x+1][y] != 11  && m.map[x+1][y] != 75 && m.map[x+1][y] != 76 && m.map[x+1][y] != 77 && m.map[x+1][y] != 78 && m.map[x+1][y] != 79){ previous = m.map[x+1][y]; }
        else if((m.map[x+1][y] == 76 || m.map[x+1][y] == 77 || m.map[x+1][y] == 78 || m.map[x+1][y] == 79) && previous == 15){ previous = 9; }
        m.map[x+1][y] = image;
        x = x+1;
        return true;
    }

    else if(m.map[x+1][y] == 9){
        m.map[x][y] = previous;
        previous = m.map[x+1][y];
        m.map[x+1][y] = image;
        x = x+1;
        return true;
    }

    else if(m.map[x+1][y] == 7 && !(exit)){
        m.map[x][y] = previous;
        previous = m.map[x+1][y];
        m.map[x+1][y] = image;
        x = x+1;
        return true;
    }

    else if(m.map[x+1][y] == 8 && !(exit)){
        m.map[x][y] = previous;
        previous = m.map[x+1][y];
        m.map[x+1][y] = image;
        x = x+1;
        return true;
    }

    return false;

}


bool Ghost::MoveRight(Map& m){
    if(m.map[x][y+1] == 0 || m.map[x][y+1] == 11 ||  m.map[x][y+1] == 75 || m.map[x][y+1] == 76 || m.map[x][y+1] == 77 || m.map[x][y+1] == 78 || m.map[x][y+1] == 79  || m.map[x][y+1] == 15){
        m.map[x][y] = previous;

        if(x == 15 && (y+1) == 29 ){
            m.map[x][y] = 0;
            y = 0;
        }

        if(m.map[x][y+1] != 11 && m.map[x][y+1] != 75 && m.map[x][y+1] != 76 && m.map[x][y+1] != 77 && m.map[x][y+1] != 78 && m.map[x][y+1] != 79){ previous = m.map[x][y+1]; }
        m.map[x][y+1] = image;
        y = y+1;



        return true;
    }
    else if(m.map[x][y+1] == 9){
        m.map[x][y] = previous;
        previous = m.map[x][y+1];
        m.map[x][y+1] = image;
        y = y+1;
        return true;
    }

    else if(m.map[x][y+1] == 7){
        m.map[x][y] = previous;
        previous = m.map[x][y+1];
        m.map[x][y+1] = image;
        y = y+1;
        return true;
    }

    else if(m.map[x][y+1] == 8){
        m.map[x][y] = previous;
        previous = m.map[x][y+1];
        m.map[x][y+1] = image;
        y = y+1;
        return true;
    }



    return false;

}

bool Ghost::checkUp(Map& m){
    if(m.map[x-1][y] != 0 && m.map[x-1][y] != 9 && m.map[x-1][y] != 11 && m.map[x-1][y] != image && m.map[x-1][y] != 7 && m.map[x-1][y] != 8 && m.map[x-1][y] != 15) { return false; }
    return true;
}

bool Ghost::checkDown(Map& m){
    if(m.map[x+1][y] != 0 && m.map[x+1][y] != 9 && m.map[x+1][y] != 11 && m.map[x+1][y] != 15 ) { return false; }
    return true;
}

bool Ghost::checkLeft(Map& m){
    if(m.map[x][y-1] != 0 && m.map[x][y-1] != 9 && m.map[x][y-1] != 11 && m.map[x][y-1] != 15 && m.map[x][y-1]) { return false; }
    return true;
}

bool Ghost::checkRight(Map& m){
    if(m.map[x][y+1] != 0 && m.map[x][y+1] != 9 && m.map[x][y+1] != 11 && m.map[x][y+1] != 15) { return false; }
    return true;
}

void Ghost::moveGhost(Map& m, int xPacman, int yPacman){
    this->checkPacmanUp(m);
    this->checkPacmanDown(m);
    this->checkPacmanLeft(m);
    this->checkPacmanRight(m);

    if(randattuale == 0 && (checkUp(m))) { this->MoveUp(m);}
    else if(randattuale == 1 && (checkLeft(m))) { this->MoveLeft(m);}
    else if(randattuale == 2 && (checkRight(m))) { this->MoveRight(m);}
    else if(randattuale == 3 && (checkDown(m))) { this->MoveDown(m);}
    else if((checkUp(m) && xPacman < this->x)) {
        this->MoveUp(m);
        randattuale = 0;
    }
    else if((checkDown(m) && xPacman > this->x)) {
        this->MoveDown(m);
        randattuale = 3;
    }
    else if((checkLeft(m) && yPacman < this->y)) {
        this->MoveLeft(m);
        randattuale = 1;
    }
    else if((checkRight(m) && yPacman > this->y)) {
        this->MoveRight(m);
        randattuale = 2;
    }

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

bool Ghost::checkPacmanUp(Map& m) {
    for(int i = x; i > (x - 10) && i > 0; i--) {
        if(m.map[i][y] == 11) {  this->randattuale = 0; return true;}
        else if(m.map[i][y] == 1 || m.map[i][y] == 2 || m.map[i][y] == 3 || m.map[i][y] == 4 || m.map[i][y] == 5 || m.map[i][y] == 6 || m.map[i][y] == 7 || m.map[i][y] == 8) { return false; }
    }
    return false;
}

bool Ghost::checkPacmanDown(Map& m) {
    for(int i = x; i < (x + 10) && i < 33; i++) {
        if(m.map[i][y] == 11) {  this->randattuale = 3; return true; }
        else if(m.map[i][y] == 1 || m.map[i][y] == 2 || m.map[i][y] == 3 || m.map[i][y] == 4 || m.map[i][y] == 5 || m.map[i][y] == 6 || m.map[i][y] == 7 || m.map[i][y] == 8) { return false; }
    }
    return false;
}

bool Ghost::checkPacmanLeft(Map& m) {
    for(int i = y; i > (y - 10) && i > 0; i--) {
        if(m.map[x][i] == 11) {  this->randattuale = 1; return true; }
        else if(m.map[x][i] == 1 || m.map[x][i] == 2 || m.map[x][i] == 3 || m.map[x][i] == 4 || m.map[x][i] == 5 || m.map[x][i] == 6 || m.map[x][i] == 7 || m.map[x][i] == 8) { return false; }
    }
    return false;
}

bool Ghost::checkPacmanRight(Map& m) {
    for(int i = y; i < (y + 10) && i < 30; i++) {
        if(m.map[x][i] == 11) {  this->randattuale = 2; return true; }
        else if(m.map[x][i] == 1 || m.map[x][i] == 2 || m.map[x][i] == 3 || m.map[x][i] == 4 || m.map[x][i] == 5 || m.map[x][i] == 6 || m.map[x][i] == 7 || m.map[x][i] == 8) { return false; }
    }
    return false;
}

bool Ghost::restartGhost(Map& mappa) {
    mappa.map[x][y] = 11;
    x = xinit;
    y = yinit;
    mappa.map[x][y] = ImageInit;
    image = ImageInit;
    this->setRandAttuale(0);
    this->setPrevious(0);
    this->setEatable(false);
}

int Ghost::nextFrame() {
    return (this->frame++%2);
}

void Ghost::changeMovementFrame() {
    if(this->movementFrame == 0) { this->movementFrame = 1; } else { this->movementFrame = 0; }
}
