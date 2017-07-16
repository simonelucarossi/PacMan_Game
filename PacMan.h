#ifndef PACMAN_H_
#define PACMAN_H_

#include "Ghost.h"

class PacMan {
    private:
        string urlImage;
        int x,y;
        int previous;
        int score;
        int lifes;
        int eated;
        int frame;
        int direction;
        Ghost* ghostCollision;
        int Pills;
        bool deathPacman;
        int frameDeath;


    public:
        PacMan(Map&);

        // getters
        bool getDeathPacman() { return deathPacman; }
        int getCoordinateX();
        int getCoordinateY();
        string getUrlImage();
        int getDirection();
        int getScore();
        int getLifes();
        int getFrameDeath() { return frameDeath; }
        inline int getPrevious() { return previous; }
        // setters
        void setUrlImage(string);
        void setCoordinateX(int);
        void setCoordinateY(int);
        void setDirection(int);
        void setLifes(int);
        void setDeathPacman(bool q) { deathPacman = q; }
        void setFrameDeath(int q){ frameDeath = q; }
        inline void setPrevious(int q) { previous = q; } 
        

        // movement
        void nextStep(Map&);
        bool MoveLeft(Map&);
        bool MoveUp(Map&);
        bool MoveDown(Map&);
        bool MoveRight(Map&);
         int nextFrame();

        // other
        void printScore();
        bool CheckCollision(Ghost, Ghost, Ghost,Ghost);
        bool eatGhost(Ghost&, Ghost&, Ghost&, Ghost&, Map&);
        bool eatPill();
        int getPills();
        inline void setPills(int q) { Pills = q; }
        Ghost* getGhostCollision() { return ghostCollision; }
};

#endif
