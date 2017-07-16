#include "Game.h"
#include <ctime>

Game::Game() {
    this->mappa = new Map();
    this->renderer = new Renderer();
    this->g1 = new Ghost((*mappa),15,15,75);
    this->g2 = new Ghost((*mappa),15,16,77);
    this->g3 = new Ghost((*mappa),15,13,78);
    this->g4 = new Ghost((*mappa),15,14,79);
    this->p1 = new PacMan((*mappa));
    this->menuGame = new Menu();
    this->sample = NULL;
    this->sample2 = NULL;
    this->sample3 = NULL;
    this->sample4 = NULL;
    this->initializeAllegro();
    this->paused = false;
    this->pausedStopped = true;
    this->musicPlayed = false;
    this->startMenu = true;
    this->endMenu = false;
    this->playMusic = true;
}

Game::~Game() {
    al_destroy_display(this->display);
    al_destroy_sample(sample);
    al_destroy_sample(sample2);
    al_destroy_sample(sample3);
    al_destroy_sample(sample4);
    al_destroy_event_queue(this->event_queue);
    delete g1;
    delete g2;
    delete g3;
    delete g4;
    delete p1;
    delete renderer;
    delete mappa;
    delete menuGame;
}

////////////////////
// Public interface

void Game::loop() {
    bool done = false;
    int seconds = 0;

    paused = pausedStopped;
    this->ChangePaused();


    /*renderer->draw(*p1, *g1, *g2, *g3, *g4, *mappa);
    renderer->drawInfo(*p1, *this->font, *this->font2);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));*/
    renderer->setReady(false);

    al_start_timer(animationTimer);
    al_start_timer(movementTimer);
    al_start_timer(pillsTimer);
    al_start_timer(menuTimer);
    al_start_timer(endMenuTimer);

    while(!done) {
        ALLEGRO_EVENT ev;
            p1->setPills(mappa->getNumberOfPills());    
        al_wait_for_event(this->event_queue, &ev);
        
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN && startMenu == false && endMenu == false) {
                if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
                    p1->setDirection(0);
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                    p1->setDirection(1);
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                    p1->setDirection(2);
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                    p1->setDirection(3);
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_W) {
                    p1->setDirection(0);
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_A) {
                    p1->setDirection(1);
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_D) {
                    p1->setDirection(2);
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_S) {
                    p1->setDirection(3);
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_P){
                    paused = pausedStopped;
                    this->ChangePaused();
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    done = true;
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_R){
                    this->restart();
                }

        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN && startMenu == true) {
                if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
                    this->switchUp(*menuGame);
                }
                
                else if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                    this->switchDown(*menuGame);
                }

                else if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                    this->whichFunctionButton(done, playMusic);
                }

                else if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    done = true;
                }
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN && endMenu == true) {
                if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
                    this->switchLeft(*menuGame);
                }
                
                else if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                    this->switchRight(*menuGame);
                }

                else if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                    this->whichFunctionButton(done, playMusic);
                }

                else if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    done = true;
                }
        }
                
             
        

        else if(ev.type == ALLEGRO_EVENT_TIMER){
            if(ev.timer.source == movementTimer  && !paused && (p1->getDeathPacman() == false) && p1->getLifes() > 0  && startMenu == false && endMenu == false) {
                p1->nextStep(*mappa);
                this->CheckEatingLittlePills();


                if(p1->eatPill()) {
                    p1->setPrevious(0);
                    this->setGhostsToEatable();
                    seconds = 0;
                }

                if(p1->CheckCollision(*g1, *g2, *g3, *g4)) {
                    if(p1->getGhostCollision()->getEatable()) {
                        p1->eatGhost(*g1, *g2, *g3, *g4,*mappa);
                    } else {
                        p1->setFrameDeath(0);
                        p1->setDeathPacman(true);
                    }
                } else {
                    g1->moveGhost(*mappa, p1->getCoordinateX(), p1->getCoordinateY());
                    g2->moveGhost(*mappa, p1->getCoordinateX(), p1->getCoordinateY());
                    g3->moveGhost(*mappa, p1->getCoordinateX(), p1->getCoordinateY());
                    g4->moveGhost(*mappa, p1->getCoordinateX(), p1->getCoordinateY());

                    if(p1->CheckCollision(*g1, *g2, *g3, *g4)) {
                        if(p1->getGhostCollision()->getEatable()) {
                            p1->eatGhost(*g1, *g2, *g3, *g4,*mappa);
                        } else {
                            p1->setFrameDeath(0);
                            p1->setDeathPacman(true);
                        }
                    }
                }
                seconds++;
                if(seconds == 70) {
                    this->setGhostsToUneatable();
                }
            }

            if(ev.timer.source == pillsTimer  && startMenu == false && endMenu == false) {
                renderer->drawPillsAndGhostEatable(*mappa);

            }

            if(ev.timer.source == animationTimer && (p1->getDeathPacman() == false) && p1->getLifes() > 0  && startMenu == false && endMenu == false) {
                renderer->draw(*p1, *g1, *g2, *g3, *g4, *mappa);
                renderer->drawInfo(*p1, *this->font, *this->font2);
                al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));
                if(p1->getLifes() == 0) {
                    al_stop_timer(animationTimer);
                }
                else if(p1->getPills() == 0) {
                    al_stop_timer(movementTimer);
                }
                

            }
            if(ev.timer.source == pillsTimer && (p1->getDeathPacman() == true) && startMenu == false && endMenu == false) {
                renderer->draw(*p1, *g1, *g2, *g3, *g4, *mappa);
                renderer->drawDeathPacman(*p1, p1->getFrameDeath());
                renderer->drawInfo(*p1, *this->font, *this->font2);
                

                if(p1->getFrameDeath() == 0) { 
                    if(playMusic) {
                        al_play_sample(sample4, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id4);
                    }
                }

                
                    

                    p1->setFrameDeath(p1->getFrameDeath() + 1);
                    if(p1->getFrameDeath() == 11) { 
                        p1->setDeathPacman(false); 
                        this->restart();
                    }

                    al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));
                
            }

            if((p1->getLifes() == 0 || p1->getPills() == 0) && startMenu == false) {
                    endMenu = true;
            }

            if(ev.timer.source == endMenuTimer && (p1->getLifes() == 0 || p1->getPills() == 0) && endMenu == true){
                renderer->draw(*p1, *g1, *g2, *g3, *g4, *mappa);
                renderer->drawFinalMenu(*menuGame, *this->fontM, *this->fontH);
                renderer->drawInfo(*p1, *this->font, *this->font2);
                al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));
            }

            if(ev.timer.source == menuTimer && startMenu == true) {
                renderer->drawMenu(*menuGame,  *this->fontL, *this->fontM, *this->fontH, this->playMusic);
                al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));
            }

        }
    
        if(p1->getLifes() == 0 || p1->getPills() == 0) {
            if(playMusic) {
                al_stop_sample(&id);
                al_stop_sample(&id2);
                al_stop_sample(&id3);
                al_stop_sample(&id4);
            }
        }
    }

}

void Game::restart() {
    if(p1->getCoordinateX() != 22 || p1->getCoordinateY() != 13){
        mappa->map[p1->getCoordinateX()][p1->getCoordinateY()] = 0;
        p1->setCoordinateX(22);
        p1->setCoordinateY(13);
        mappa->map[p1->getCoordinateX()][p1->getCoordinateY()] = 11;
    }

    mappa->map[g1->getCoordinateX()][g1->getCoordinateY()] = g1->getPrevious();
    g1->setCoordinateX(15);
    g1->setCoordinateY(15);
    mappa->map[g1->getCoordinateX()][g1->getCoordinateY()] = 75;
    g1->setRandAttuale(0);
    g1->setPrevious(0);
    g1->setImage(75);
    g1->setEatable(false);

    mappa->map[g2->getCoordinateX()][g2->getCoordinateY()] = g2->getPrevious();
    g2->setCoordinateX(15);
    g2->setCoordinateY(16);
    mappa->map[g2->getCoordinateX()][g2->getCoordinateY()] = 77;
    g2->setRandAttuale(0);
    g2->setPrevious(0);
    g2->setImage(77);
    g2->setEatable(false);

    mappa->map[g3->getCoordinateX()][g3->getCoordinateY()] = g3->getPrevious();
    g3->setCoordinateX(15);
    g3->setCoordinateY(13);
    mappa->map[g3->getCoordinateX()][g3->getCoordinateY()] = 78;
    g3->setRandAttuale(0);
    g3->setPrevious(0);
    g3->setImage(78);
    g3->setEatable(false);

    mappa->map[g4->getCoordinateX()][g4->getCoordinateY()] = g4->getPrevious();
    g4->setCoordinateX(15);
    g4->setCoordinateY(14);
    mappa->map[g4->getCoordinateX()][g4->getCoordinateY()] = 79;
    g4->setRandAttuale(0);
    g4->setPrevious(0);
    g4->setImage(79);
    g4->setEatable(false);
}

////////////////////
// Private functions
void Game::initializeAllegro() {
    if(!al_init()) { fprintf(stderr, "failed to initialize allegro!\n"); }

    if(!al_install_keyboard()) { fprintf(stderr, "failed to initialize the keyboard!\n"); }
    if(!al_init_font_addon()) { fprintf(stderr, "failed to initialize fonts!\n"); }
    if(!al_init_ttf_addon()) { fprintf(stderr, "failed to initialize fonts!\n"); }
    if(!al_init_image_addon()) { fprintf(stderr, "failed to initialize images!\n"); }


    // system
    this->display = al_create_display(this->renderer->getWidth(), this->renderer->getHeight());

    int windowWidth = al_get_display_width(display);
    int windowHeight = al_get_display_height(display);
    int screenWidth = 600;
    int screenHeight = 750;

    float sx = windowWidth / (float)screenWidth;
    float sy = windowHeight / (float)screenHeight;

    ALLEGRO_TRANSFORM trans;
    al_identity_transform(&trans);
    al_scale_transform(&trans, sx, sy);
    al_use_transform(&trans);

    this->event_queue = al_create_event_queue();
    if(!this->display) { fprintf(stderr, "failed to create display!\n"); }
    if(!this->event_queue) { fprintf(stderr, "failed to create event_queue!\n"); }
    
    //audio
    if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
    }

    if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
    }
    
    if (!al_reserve_samples(3)){
      fprintf(stderr, "failed to reserve samples!\n");
    }
    
    this->sample = al_load_sample( "dot.wav" );
    this->sample2 = al_load_sample( "siren.wav" );
    this->sample3 = al_load_sample( "intro.wav" );
    this->sample4 = al_load_sample( "pacman_death.wav" );

    if (!sample){
      printf( "Audio clip sample not loaded!\n" ); 
    }
    

    // fonts
    this->font = al_load_font("./crackman.ttf", 30, 0);
    if(!this->font) { fprintf(stderr, "failed to initialize font!\n"); }
    this->font2 = al_load_font("./crackman.ttf", 15, 0);
    if(!this->font) { fprintf(stderr, "failed to initialize font!\n"); }
    this->fontL = al_load_font("./crackman.ttf", 18, 0);
    if(!this->font) { fprintf(stderr, "failed to initialize font!\n"); }
    this->fontM = al_load_font("./crackman.ttf", 27, 0);
    if(!this->font) { fprintf(stderr, "failed to initialize font!\n"); }
    this->fontH = al_load_font("./crackman.ttf", 35, 0);
    if(!this->font) { fprintf(stderr, "failed to initialize font!\n"); }

    // timers
    this->movementTimer = al_create_timer(1.0/7);
    this->animationTimer = al_create_timer(1.0/14);
    this->pillsTimer = al_create_timer(1.0/14);
    this->deathPacmanTimer = al_create_timer(1.0);
    this->menuTimer = al_create_timer(1.0/5);
    this->endMenuTimer = al_create_timer(1.0/5);

    // events
    al_register_event_source(this->event_queue, al_get_display_event_source(display));
    al_register_event_source(this->event_queue, al_get_timer_event_source(movementTimer));
    al_register_event_source(this->event_queue, al_get_timer_event_source(animationTimer));
    al_register_event_source(this->event_queue, al_get_timer_event_source(pillsTimer));
    al_register_event_source(this->event_queue, al_get_timer_event_source(deathPacmanTimer));
    al_register_event_source(this->event_queue, al_get_timer_event_source(menuTimer));
    al_register_event_source(this->event_queue, al_get_timer_event_source(endMenuTimer));

    al_register_event_source(this->event_queue, al_get_keyboard_event_source());

    
    al_rest(0.0);
    
        al_play_sample(sample2, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&id2);
        al_play_sample(sample2, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&id);
    
}

void Game::setGhostsToEatable() {
    this->g1->setEatable(true);
    this->g2->setEatable(true);
    this->g3->setEatable(true);
    this->g4->setEatable(true);

    this->g1->setImage(76);
    this->g2->setImage(76);
    this->g3->setImage(76);
    this->g4->setImage(76);
}

void Game::setGhostsToUneatable() {
    this->g1->setEatable(false);
    this->g2->setEatable(false);
    this->g3->setEatable(false);
    this->g4->setEatable(false);

    this->g1->setImage(75);
    this->g2->setImage(77);
    this->g3->setImage(78);
    this->g4->setImage(79);
}


void Game::ChangePaused() {
    if(paused == true) {
        pausedStopped = false; 
        if(playMusic) {
            al_stop_sample(&id);
            al_stop_sample(&id2);
            al_stop_sample(&id3);
            al_stop_sample(&id4);
        }
        musicPlayed = false;
    }

    else {
        pausedStopped = true;
        if(playMusic) {
            al_play_sample(sample2, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&id2);
        }
    }
    renderer->setGamePaused(paused);

}

void Game::CheckEatingLittlePills() {
    bool eatingPills = false;

    if(p1->getPrevious() == 9 || p1->getPrevious() == 15) { 
        eatingPills = true; 
    }


    if(eatingPills == true && musicPlayed == false) {
        if(playMusic) {
            al_stop_sample(&id2);
            al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&id);
        }
        musicPlayed = true;
    }
    else if(eatingPills == false && musicPlayed == true) {         
        if(playMusic) {
            al_stop_sample(&id);
            al_play_sample(sample2, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&id2);
        }
        musicPlayed = false;
    }

}

void Game::gameStarting() {
    if(playMusic) {
        al_play_sample(sample3, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,&id3);
    }
    
    //this->ChangePaused();
    
}

void Game::switchDown(Menu _gameMenu) {
    if(_gameMenu.startMenu[0].getSelectedButton() == true) {
        _gameMenu.startMenu[0].setSelectedButton(false);
        _gameMenu.startMenu[1].setSelectedButton(true);
    }

    else if(_gameMenu.startMenu[1].getSelectedButton() == true) {
        _gameMenu.startMenu[1].setSelectedButton(false);
        _gameMenu.startMenu[2].setSelectedButton(true);
    }
}

void Game::switchUp(Menu _gameMenu) {
    if(_gameMenu.startMenu[2].getSelectedButton() == true) {
        _gameMenu.startMenu[2].setSelectedButton(false);
        _gameMenu.startMenu[1].setSelectedButton(true);
    }

    else if(_gameMenu.startMenu[1].getSelectedButton() == true) {
        _gameMenu.startMenu[1].setSelectedButton(false);
        _gameMenu.startMenu[0].setSelectedButton(true);
    }
}

void Game::switchRight(Menu _gameMenu) {
    if(_gameMenu.endMenu[0].getSelectedButton() == true) {
        _gameMenu.endMenu[0].setSelectedButton(false);
        _gameMenu.endMenu[1].setSelectedButton(true);
    }
}

void Game::switchLeft(Menu _gameMenu) {
    if(_gameMenu.endMenu[1].getSelectedButton() == true) {
        _gameMenu.endMenu[1].setSelectedButton(false);
        _gameMenu.endMenu[0].setSelectedButton(true);
    }
}

void Game::whichFunctionButton(bool& _done, bool& _playMusic) {
    if(this->startMenu == true) {    
        if(this->menuGame->startMenu[0].getSelectedButton() == true) { 
            this->restartGame();
            this->menuGame->startMenu[0].setSelectedButton(true);
            this->menuGame->startMenu[1].setSelectedButton(false);
            this->menuGame->startMenu[2].setSelectedButton(false);
        }
        else if(this->menuGame->startMenu[1].getSelectedButton() == true) { if(this->playMusic == true) { _playMusic = false; } else { _playMusic = true; } }
        else if(this->menuGame->startMenu[2].getSelectedButton() == true) { _done = true; }
    }

    else if(this->endMenu == true) {
        if(this->menuGame->endMenu[0].getSelectedButton() == true) { 
            this->endMenu = false;
            this->startMenu = true;
        }
        else { _done = true; }
    }
}


void Game::restartGame() {
    delete this->mappa;
    delete this->g1;
    delete this->g2;
    delete this->g3;
    delete this->g4;
    delete this->p1;

    this->mappa = new Map();
    this->renderer = new Renderer();
    this->g1 = new Ghost((*mappa),15,15,75);
    this->g2 = new Ghost((*mappa),15,16,77);
    this->g3 = new Ghost((*mappa),15,13,78);
    this->g4 = new Ghost((*mappa),15,14,79);
    this->p1 = new PacMan((*mappa));
    this->paused = false;
    this->pausedStopped = true;
    this->musicPlayed = false;
    this->startMenu = false;
    this->renderer->setReady(false);

}
