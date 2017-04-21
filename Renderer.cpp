#include "Renderer.h"
#include <sstream>

int CELL_WIDTH = 20;
int CELL_HEIGHT = 20;

int WALL_THICKNESS = 5;

int WALL_SPRITE_SIZE = CELL_WIDTH;
int GHOST_SPRITE_SIZE = CELL_WIDTH;
int PACMAN_SPRITE_SIZE = CELL_WIDTH;

Renderer::Renderer() {
    this->cellWidth  = CELL_WIDTH;
    this->cellHeight = CELL_HEIGHT;
    this->height = (cellHeight*33)+50;
    this->width  = cellWidth*30;
}

void Renderer::draw(PacMan& pacman, Ghost& g1, Ghost& g2, Ghost& g3, Ghost& g4, Map& map) {
    ALLEGRO_BITMAP *image = al_load_bitmap("sprite.png");
    al_convert_mask_to_alpha(image, al_map_rgb(255,255,255));

    ALLEGRO_COLOR white   = al_map_rgb(240,240,240);
    ALLEGRO_COLOR red     = al_map_rgb(208,0,0);
    ALLEGRO_COLOR gateRed = al_map_rgb(160,29,0);
    ALLEGRO_COLOR blue    = al_map_rgb(30,144,255);

    float halfCellX = this->cellWidth/2;
    float halfCellY = this->cellHeight/2;

    int framePacman;
    int directionPacman;
    int directionGhostRed;
    int frameGhostRed;
    int frameGhostEatable = 0;
    int framePill = 0;


    int spritesPacman[12][2] = {
        // up
        24, 72,
        72,72,
        0, 168,

        // left
        0, 72,
        48,72,
        0, 168,

        // right
        96,72,
        144,72,
        0, 168,

        // down
        120,72,
        168,72,
        0, 168,
    };

    int spritesGhostRed[8][2] = {
        // up
        144, 144,
        168,144,

        // left
        96, 144,
        120,144,

        // right
        0, 144,
        24,144,

        // down
        48, 144,
        72,144,
    };

    int spritesGhostBlue[8][2] = {
        // up
        312, 192,
        336,192,

        // left
        264, 192,
        288,192,

        // right
        192, 192,
        216,192,

        // down
        240, 192,
        264,192,
    };

    int spritesGhostPink[8][2] = {
        // up
        144, 192,
        168,192,

        // left
        96, 192,
        120,192,

        // right
        0, 192,
        48,192,

        // down
        48, 192,
        72,192,
    };

    int spritesGhostOrange[8][2] = {
        // up
        144, 216,
        168,216,

        // left
        96, 216,
        120,216,

        // right
        0, 216,
        48,216,

        // down
        48, 216,
        72,216,
    };

    int spritesGhostEatable[8][2] = {
        192,96,
        216,96,
        192,96,
        216,96,
        192,96,
        216,96,
        192,96,
        216,96,
    };



    for(int y = 0; y < 33; y++) {
        for(int x = 0; x < 30; x++) {

            float cellCenterX = (this->cellWidth*x)+halfCellX;
            float cellCenterY = (this->cellHeight*y)+halfCellY;

            switch(map.map[y][x]) {
                case(1):
                    al_draw_scaled_bitmap(image,
                        96, 96,
                        24, 24,
                        cellCenterX-(WALL_SPRITE_SIZE/2), cellCenterY-(WALL_SPRITE_SIZE/2),
                        WALL_SPRITE_SIZE, WALL_SPRITE_SIZE,
                        0
                    );
                    /*al_draw_line(
                            cellCenterX, cellCenterY,
                            cellCenterX+halfCellX, cellCenterY,
                            blue,
                            WALL_THICKNESS
                            );
                    al_draw_line(
                            cellCenterX, cellCenterY,
                            cellCenterX, cellCenterY+halfCellY,
                            blue,
                            WALL_THICKNESS
                            );*/
                    break;
                case(2):
                    al_draw_scaled_bitmap(image,
                        48, 96,
                        24, 24,
                        cellCenterX-(WALL_SPRITE_SIZE/2), cellCenterY-(WALL_SPRITE_SIZE/2),
                        WALL_SPRITE_SIZE, WALL_SPRITE_SIZE,
                        0
                    );
                    /*al_draw_line(
                            cellCenterX, cellCenterY,
                            cellCenterX+halfCellX, cellCenterY,
                            blue,
                            WALL_THICKNESS
                            );
                    al_draw_line(
                            cellCenterX, cellCenterY,
                            cellCenterX, cellCenterY-halfCellY,
                            blue,
                            WALL_THICKNESS
                            );*/
                    break;
                case(3):
                    al_draw_scaled_bitmap(image,
                        120, 96,
                        24, 24,
                        cellCenterX-(WALL_SPRITE_SIZE/2), cellCenterY-(WALL_SPRITE_SIZE/2),
                        WALL_SPRITE_SIZE, WALL_SPRITE_SIZE,
                        0
                    );
                    /*al_draw_line(
                            cellCenterX, cellCenterY,
                            cellCenterX-halfCellX, cellCenterY,
                            blue,
                            WALL_THICKNESS
                            );
                    al_draw_line(
                            cellCenterX, cellCenterY,
                            cellCenterX, cellCenterY+halfCellY,
                            blue,
                            WALL_THICKNESS
                            );*/
                    break;
                case(4):
                    al_draw_scaled_bitmap(image,
                        72, 96,
                        24, 24,
                        cellCenterX-(WALL_SPRITE_SIZE/2), cellCenterY-(WALL_SPRITE_SIZE/2),
                        WALL_SPRITE_SIZE, WALL_SPRITE_SIZE,
                        0
                    );
                    /*al_draw_line(
                            cellCenterX, cellCenterY,
                            cellCenterX-halfCellX, cellCenterY,
                            blue,
                            WALL_THICKNESS
                            );
                    al_draw_line(
                            cellCenterX, cellCenterY,
                            cellCenterX, cellCenterY-halfCellY,
                            blue,
                            WALL_THICKNESS
                            );*/
                    break;
                case(5):
                    al_draw_scaled_bitmap(image,
                        0, 96,
                        24, 24,
                        cellCenterX-(WALL_SPRITE_SIZE/2), cellCenterY-(WALL_SPRITE_SIZE/2),
                        WALL_SPRITE_SIZE, WALL_SPRITE_SIZE,
                        0
                    );


                    /*al_draw_line(
                            cellCenterX-halfCellX, cellCenterY,
                            cellCenterX+halfCellX, cellCenterY,
                            blue,
                            WALL_THICKNESS
                            );*/
                    break;
                case(6):
                    al_draw_scaled_bitmap(image,
                        24, 96,
                        24, 24,
                        cellCenterX-(WALL_SPRITE_SIZE/2), cellCenterY-(WALL_SPRITE_SIZE/2),
                        WALL_SPRITE_SIZE, WALL_SPRITE_SIZE,
                        0
                    );
                    /*al_draw_line(
                            cellCenterX, cellCenterY-halfCellY,
                            cellCenterX, cellCenterY+halfCellY,
                            blue,
                            WALL_THICKNESS
                            );*/
                    break;
                case(7):
                    al_draw_line(
                            cellCenterX-halfCellX, cellCenterY,
                            cellCenterX+halfCellX, cellCenterY,
                            gateRed,
                            WALL_THICKNESS
                            );
                    break;
                case(8):
                    al_draw_line(
                            cellCenterX-halfCellX, cellCenterY,
                            cellCenterX+halfCellX, cellCenterY,
                            gateRed,
                            0
                            );
                    break;
                case(9):
                    al_draw_filled_rectangle(
                            cellCenterX-2, cellCenterY-2,
                            cellCenterX+2, cellCenterY+2,
                            white
                            );
                    break;
                case(11):
                    framePacman = pacman.nextFrame();
                    directionPacman = pacman.getDirection();

                    al_draw_scaled_bitmap(image,
                        spritesPacman[framePacman+directionPacman*3][0],
                        spritesPacman[framePacman+directionPacman*3][1],
                        24, 24,
                        cellCenterX-(PACMAN_SPRITE_SIZE/2), cellCenterY-(PACMAN_SPRITE_SIZE/2),
                        PACMAN_SPRITE_SIZE, PACMAN_SPRITE_SIZE,
                        0
                    );
                    break;
                case(15):

                    al_draw_filled_circle(cellCenterX, cellCenterY, 4, white);

                    break;
                case(75):
                    directionGhostRed = g1.getRandAttuale();

                    al_draw_scaled_bitmap(image,
                        spritesGhostRed[g1.getMovementFrame()+g1.getRandAttuale()*2][0],
                        spritesGhostRed[g1.getMovementFrame()+g1.getRandAttuale()*2][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        GHOST_SPRITE_SIZE, GHOST_SPRITE_SIZE,
                        0
                    );

                    g1.changeMovementFrame();
                    break;

                case(76):

                    if(frameGhostEatable == 0){
                                        al_draw_scaled_bitmap(image,
                                            spritesGhostEatable[0][0],
                                            spritesGhostEatable[0][1],
                                            24, 24,
                                            cellCenterX-10, cellCenterY-10,
                                            GHOST_SPRITE_SIZE, GHOST_SPRITE_SIZE,
                                            0
                                        );
                                    }
                    if(frameGhostEatable == 1){
                                        al_draw_scaled_bitmap(image,
                                            spritesGhostEatable[1][0],
                                            spritesGhostEatable[1][1],
                                            24, 24,
                                            cellCenterX-10, cellCenterY-10,
                                            GHOST_SPRITE_SIZE, GHOST_SPRITE_SIZE,
                                            0
                                        );
                                    }

                    this->changeEatableFrame(frameGhostEatable);

                    break;

                case(77):
                    directionGhostRed = g2.getRandAttuale();

                    al_draw_scaled_bitmap(image,
                        spritesGhostPink[g2.getMovementFrame()+g2.getRandAttuale()*2][0],
                        spritesGhostPink[g2.getMovementFrame()+g2.getRandAttuale()*2][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        GHOST_SPRITE_SIZE, GHOST_SPRITE_SIZE,
                        0
                    );
                    g2.changeMovementFrame();
                    break;

                    case(78):
                    directionGhostRed = g3.getRandAttuale();

                    al_draw_scaled_bitmap(image,
                        spritesGhostOrange[g3.getMovementFrame()+g3.getRandAttuale()*2][0],
                        spritesGhostOrange[g3.getMovementFrame()+g3.getRandAttuale()*2][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        GHOST_SPRITE_SIZE, GHOST_SPRITE_SIZE,
                        0
                    );

                    g3.changeMovementFrame();
                    break;

                    case(79):
                    directionGhostRed = g4.getRandAttuale();

                    al_draw_scaled_bitmap(image,
                        spritesGhostBlue[g4.getMovementFrame()+g4.getRandAttuale()*2][0],
                        spritesGhostBlue[g4.getMovementFrame()+g4.getRandAttuale()*2][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        GHOST_SPRITE_SIZE, GHOST_SPRITE_SIZE,
                        0
                    );
                    g4.changeMovementFrame();
                    break;

                default:

                    break;
            }

        }
    }
}

void Renderer::drawInfo(PacMan& pacman, ALLEGRO_FONT &font, ALLEGRO_FONT &font2) {
    ALLEGRO_BITMAP *image = al_load_bitmap("sprite.png");
    al_convert_mask_to_alpha(image, al_map_rgb(255,255,255));
        stringstream scoreinfo;
        stringstream lifesinfo;
        stringstream pillsinfo;
        scoreinfo << "SCORE: " << pacman.getScore();
        lifesinfo << "LIFES: ";
        pillsinfo << "PILLS: " << pacman.getPills();



    if(pacman.getLifes() > 0 && pacman.getPills()!= 0) {
        al_draw_text(&font, al_map_rgb(255,255,251), 24, this->height-60, ALLEGRO_ALIGN_LEFT, scoreinfo.str().c_str());
        al_draw_text(&font, al_map_rgb(255,255,255), this-> width-192, this->height-60, ALLEGRO_ALIGN_LEFT, lifesinfo.str().c_str());
         al_draw_text(&font2, al_map_rgb(255,255,255), this-> width/2-44, this->height-20, ALLEGRO_ALIGN_LEFT, pillsinfo.str().c_str());
        for(int i = 0; i < pacman.getLifes(); i++){
                al_draw_scaled_bitmap(image,
                                48,
                                72,
                                24, 24,
                                this->width-89 + (25*i), this->height-53,
                                24, 24,
                                0
                            );
            }
        al_draw_scaled_bitmap(image,
                                96,
                                12,
                                74, 12,
                                this->width/2-40, this->height-53,
                                74, 30,
                                0
                            );

    } else if (pacman.getLifes() == 0) {
        al_draw_text(&font, al_map_rgb(160,29,0), 213, this->height/2-2, ALLEGRO_ALIGN_LEFT, "GAME OVER");
        al_draw_text(&font, al_map_rgb(255,255,251), 24, this->height-60, ALLEGRO_ALIGN_LEFT, scoreinfo.str().c_str());
        al_draw_text(&font, al_map_rgb(160,29,0), this-> width-192, this->height-60, ALLEGRO_ALIGN_LEFT, lifesinfo.str().c_str());
        al_draw_text(&font, al_map_rgb(255,255,255), 24, this->height/2-2, ALLEGRO_ALIGN_LEFT, "BACK");
        al_draw_text(&font, al_map_rgb(255,255,255), this-> width-105, this->height/2-2, ALLEGRO_ALIGN_LEFT, "EXIT");
        for(int i = 0; i < pacman.getLifes(); i++){
                al_draw_scaled_bitmap(image,
                                48,
                                72,
                                24, 24,
                                this->width-89 + (25*i), this->height-53,
                                24, 24,
                                0
                            );}
        al_draw_scaled_bitmap(image,
                                96,
                                12,
                                74, 12,
                                this->width/2-40, this->height-53,
                                74, 30,
                                0
                            );
    }

    else {
        al_draw_text(&font, al_map_rgb(95,180,44), 207, this->height/2-2, ALLEGRO_ALIGN_LEFT, "COMPLETED");
        al_draw_text(&font, al_map_rgb(95,180,44), 24, this->height-60, ALLEGRO_ALIGN_LEFT, scoreinfo.str().c_str());
        al_draw_text(&font, al_map_rgb(95,180,44), this-> width-192, this->height-60, ALLEGRO_ALIGN_LEFT, lifesinfo.str().c_str());
        for(int i = 0; i < pacman.getLifes(); i++){
                al_draw_scaled_bitmap(image,
                                48,
                                72,
                                24, 24,
                                this->width-89 + (25*i), this->height-53,
                                24, 24,
                                0
                            );}
        al_draw_scaled_bitmap(image,
                                96,
                                12,
                                74, 12,
                                this->width/2-40, this->height-53,
                                74, 30,
                                0
                            );
    }
}

void Renderer::drawDeathPacman(PacMan& p1, int i) {
    ALLEGRO_BITMAP *image = al_load_bitmap("sprite.png");
    al_convert_mask_to_alpha(image, al_map_rgb(255,255,255));

    float halfCellX = this->cellWidth/2;
    float halfCellY = this->cellHeight/2;
    float cellCenterX = (this->cellWidth*p1.getCoordinateX())+halfCellX;
    float cellCenterY = (this->cellHeight*p1.getCoordinateY())+halfCellY;

    int spritesDeathPacman[11][2] = {
        96, 168,
        120, 168,
        144, 168,
        168, 168,
        192, 168,
        216, 168,
        240, 168,
        264, 168,
        288, 168,
        312, 168,
        336, 168,
    };

    al_draw_scaled_bitmap(image,
                        spritesDeathPacman[i][0],
                        spritesDeathPacman[i][1],
                        24, 24,
                        (p1.getCoordinateX()*cellWidth), (p1.getCoordinateY()*cellHeight),
                        PACMAN_SPRITE_SIZE, PACMAN_SPRITE_SIZE,
                        0
                    );
}

void Renderer::ChangePill(int& framePill) {
    bool alMassimo = true;
    bool alMinimo = false;

    if(alMassimo) { framePill++; } else { framePill--;}
    if(framePill == 8) { alMassimo = false; alMinimo = true; }
    else if(framePill == 3) { alMassimo = true; alMinimo = false; }

}

void Renderer::changeEatableFrame(int& eatableFrame) {
    if(eatableFrame == 0) { eatableFrame = 1; } else { eatableFrame = 0;  }
}
