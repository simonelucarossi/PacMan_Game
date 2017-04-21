#ifndef RENDERER_H_
#define RENDERER_H_

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
using namespace std;

#include "PacMan.h"
#include "Ghost.h"
#include "Map.h"

class Renderer {
    private:
        float height;
        float width;
        float cellWidth;
        float cellHeight;
    public:
        Renderer();

        // getters
        float getHeight() { return height; }
        float getWidth() { return width; }

        void draw(PacMan&, Ghost&, Ghost&, Ghost&, Ghost&, Map&);
        void drawInfo(PacMan&, ALLEGRO_FONT&, ALLEGRO_FONT&);
        void ChangePill(int&);
        void changeEatableFrame(int&);
        void drawDeathPacman(PacMan&, int);
};

#endif
