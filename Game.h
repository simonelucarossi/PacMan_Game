#ifndef GAME_H
#define GAME_H

#include "PacMan.h"
#include "Map.h"
#include "Renderer.h"
#include "Ghost.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Game{
    private:
        Map* mappa;
        Renderer* renderer;
        PacMan* p1;
        Ghost* g1;
        Ghost* g2;
        Ghost* g3;
        Ghost* g4;

        char movePacman;

        // allegro stuff
        ALLEGRO_DISPLAY *display;
        ALLEGRO_EVENT_QUEUE *event_queue;
        ALLEGRO_FONT *font;
        ALLEGRO_TIMER *animationTimer;
        ALLEGRO_TIMER *movementTimer;

        // functions
        void initializeAllegro();
        void setGhostsToEatable();

    public:
        Game();
        ~Game();

        void loop();
        void restart();

};

#endif
