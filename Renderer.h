#ifndef RENDERER_H_
#define RENDERER_H_

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
using namespace std;

#include "Menu.cpp"
#include "PacMan.h"
#include "Ghost.h"
#include "Map.h"

class Renderer {
    private:
        float height;
        float width;
        float cellWidth;
        float cellHeight;
        bool gamePaused;
        int framePill;
        bool alMassimo;
        bool alMinimo;
        int frameGhostEatable;
        bool ready;
    public:
        Renderer();

        // getters
        float getHeight() { return height; }
        float getWidth() { return width; }
        bool getReady() { return ready; }


        void draw(PacMan&, Ghost&, Ghost&, Ghost&, Ghost&, Map&);
        void drawInfo(PacMan&, ALLEGRO_FONT&, ALLEGRO_FONT&);
        void ChangePill();
        void changeEatableFrame();
        void drawDeathPacman(PacMan&, int);
        void setGamePaused(bool paused) { this->gamePaused = paused; }
        void drawPillsAndGhostEatable(Map&);
        void setReady(bool q) { ready = q; }
        void drawMenu(Menu, ALLEGRO_FONT&, ALLEGRO_FONT&, ALLEGRO_FONT&, bool);   
        void drawFinalMenu(Menu, ALLEGRO_FONT&, ALLEGRO_FONT&); 
};

#endif
