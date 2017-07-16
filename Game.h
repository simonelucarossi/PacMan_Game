#ifndef GAME_H
#define GAME_H

#include "PacMan.h"
#include "Map.h"
#include "Renderer.h"
#include "Ghost.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class Game{
    private:
        Map* mappa;
        Renderer* renderer;
        PacMan* p1;
        Ghost* g1;
        Ghost* g2;
        Ghost* g3;
        Ghost* g4;
        bool paused, pausedStopped, musicPlayed, starting, startMenu, endMenu, playMusic;
        Menu* menuGame;

        char movePacman;

        // allegro stuff
        ALLEGRO_DISPLAY *display;
        ALLEGRO_EVENT_QUEUE *event_queue;
        ALLEGRO_FONT *font;
        ALLEGRO_FONT *font2;
        ALLEGRO_FONT *fontL;
        ALLEGRO_FONT *fontM;
        ALLEGRO_FONT *fontH;
        ALLEGRO_TIMER *animationTimer;
        ALLEGRO_TIMER *movementTimer;
        ALLEGRO_TIMER *pillsTimer;
        ALLEGRO_TIMER *deathPacmanTimer;
        ALLEGRO_TIMER *menuTimer;
        ALLEGRO_TIMER *endMenuTimer;

        ALLEGRO_SAMPLE *sample;
        ALLEGRO_SAMPLE *sample2;
        ALLEGRO_SAMPLE *sample3;
        ALLEGRO_SAMPLE *sample4;
        ALLEGRO_SAMPLE_ID id;
        ALLEGRO_SAMPLE_ID id2;
        ALLEGRO_SAMPLE_ID id3;
        ALLEGRO_SAMPLE_ID id4;

        // functions
        void initializeAllegro();
        void setGhostsToEatable();
        void setGhostsToUneatable();
        void ChangePaused();
        void CheckEatingLittlePills();
        void gameStarting();
        void switchUp(Menu);
        void switchDown(Menu);
        void switchLeft(Menu);
        void switchRight(Menu);
        void whichFunctionButton(bool&, bool&);
        void restartGame();
    public:
        Game();
        ~Game();

        void loop();
        void restart();

};

#endif
