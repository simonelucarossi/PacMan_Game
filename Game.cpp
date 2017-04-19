#include "Game.h"

Game::Game() {
    this->mappa = new Map();
    this->renderer = new Renderer();
    this->g1 = new Ghost((*mappa),15,15);
    this->g2 = new Ghost((*mappa),15,16);
    this->g3 = new Ghost((*mappa),15,13);
    this->g4 = new Ghost((*mappa),15,14);
    this->p1 = new PacMan((*mappa));

    this->initializeAllegro();
}

Game::~Game() {
    al_destroy_display(this->display);
    al_destroy_event_queue(this->event_queue);
}

////////////////////
// Public interface

void Game::loop() {
    bool done = false;

    while(!done) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(this->event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    p1->setDirection(0);
                    break;
                case ALLEGRO_KEY_LEFT:
                    p1->setDirection(1);
                    break;
                case ALLEGRO_KEY_RIGHT:
                    p1->setDirection(2);
                    break;
                case ALLEGRO_KEY_DOWN:
                    p1->setDirection(3);
                    break;

                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
            }
        } else if(ev.type == ALLEGRO_EVENT_TIMER) {
            if(ev.timer.source == movementTimer) {
                p1->nextStep(*mappa);

                if(p1->eatPill()) {
                    this->setGhostsToEatable();
                }

                if(p1->CheckCollision(*g1, *g2, *g3, *g4)) {
                    if(p1->getGhostCollision()->getEatable()) {
                        p1->eatGhost(*g1, *g2, *g3, *g4,*mappa);
                    } else {
                        this->restart();
                    }
                } else {
                    g1->moveGhost(*mappa);
                    g2->moveGhost(*mappa);
                    g3->moveGhost(*mappa);
                    g4->moveGhost(*mappa);

                    if(p1->CheckCollision(*g1, *g2, *g3, *g4)) {
                        if(p1->getGhostCollision()->getEatable()) {
                            p1->eatGhost(*g1, *g2, *g3, *g4,*mappa);
                        } else {
                            this->restart();
                        }
                    }
                }
            }

            if(ev.timer.source == animationTimer) {
                renderer->draw(*p1, *g1, *g2, *g3, *g4, *mappa);
                renderer->drawInfo(*p1, *this->font);

                al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));

                if(p1->getLifes() == 0) {
                    al_stop_timer(animationTimer);
                }
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
    mappa->map[g2->getCoordinateX()][g2->getCoordinateY()] = 75;
    g2->setRandAttuale(0);
    g2->setPrevious(0);
    g2->setImage(75);
    g2->setEatable(false);

    mappa->map[g3->getCoordinateX()][g3->getCoordinateY()] = g3->getPrevious();
    g3->setCoordinateX(15);
    g3->setCoordinateY(13);
    mappa->map[g3->getCoordinateX()][g3->getCoordinateY()] = 75;
    g3->setRandAttuale(0);
    g3->setPrevious(0);
    g3->setImage(75);
    g3->setEatable(false);

    mappa->map[g4->getCoordinateX()][g4->getCoordinateY()] = g4->getPrevious();
    g4->setCoordinateX(15);
    g4->setCoordinateY(14);
    mappa->map[g4->getCoordinateX()][g4->getCoordinateY()] = 75;
    g4->setRandAttuale(0);
    g4->setPrevious(0);
    g4->setImage(75);
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
    this->event_queue = al_create_event_queue();
    if(!this->display) { fprintf(stderr, "failed to create display!\n"); }
    if(!this->event_queue) { fprintf(stderr, "failed to create event_queue!\n"); }

    // fonts
    this->font = al_load_font("./Minecraftia.ttf", 12, 0);
    if(!this->font) { fprintf(stderr, "failed to initialize font!\n"); }

    // timers
    this->movementTimer = al_create_timer(1.0 / 3);
    this->animationTimer = al_create_timer(1.0 / 10);


    al_register_event_source(this->event_queue, al_get_display_event_source(display));
    al_register_event_source(this->event_queue, al_get_timer_event_source(movementTimer));
    al_register_event_source(this->event_queue, al_get_timer_event_source(animationTimer));
    al_register_event_source(this->event_queue, al_get_keyboard_event_source());

    al_start_timer(animationTimer);
    al_start_timer(movementTimer);
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
