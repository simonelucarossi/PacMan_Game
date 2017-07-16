#include "Renderer.h"
#include <sstream>


int WALL_THICKNESS = 5;

Renderer::Renderer() {
    this->cellWidth  = 20;
    this->cellHeight = 20;
    this->height = (cellHeight*33)+50; // 710
    this->width  = cellWidth*30; // 600
    this->gamePaused = false;
    this->framePill = 3;
    this->alMassimo = true;
    this->alMinimo = false;
    this->frameGhostEatable = 0;
    this->ready = true;
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

    int spritesGhostEatable[2][2] = {
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
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
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
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
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
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
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
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
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
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
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
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
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
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
                        0
                    );
                    break;
                case(75):
                    directionGhostRed = g1.getRandAttuale();

                    al_draw_scaled_bitmap(image,
                        spritesGhostRed[g1.getMovementFrame()+g1.getRandAttuale()*2][0],
                        spritesGhostRed[g1.getMovementFrame()+g1.getRandAttuale()*2][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
                        0
                    );

                    g1.changeMovementFrame();
                    break;


                case(77):
                    directionGhostRed = g2.getRandAttuale();

                    al_draw_scaled_bitmap(image,
                        spritesGhostPink[g2.getMovementFrame()+g2.getRandAttuale()*2][0],
                        spritesGhostPink[g2.getMovementFrame()+g2.getRandAttuale()*2][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
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
                        20, 20,
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
                        20, 20,
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



    if(pacman.getLifes() > 0 && pacman.getPills()!= 0  && this->gamePaused == false) {
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
        al_draw_scaled_bitmap(image,
                                96,
                                12,
                                74, 12,
                                this->width/2-40, this->height-53,
                                74, 30,
                                0
                            );
    }

    else if(pacman.getPills() == 0) {
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
    else if(this->ready == false) {
       al_draw_text(&font, al_map_rgb(254,254,33), 245, this->height/2-2, ALLEGRO_ALIGN_LEFT, "PAUSED");
        al_draw_text(&font, al_map_rgb(255,255,255), 24, this->height-60, ALLEGRO_ALIGN_LEFT, scoreinfo.str().c_str());
        al_draw_text(&font, al_map_rgb(255,255,255), this-> width-192, this->height-60, ALLEGRO_ALIGN_LEFT, lifesinfo.str().c_str());
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
        al_draw_text(&font2, al_map_rgb(255,255,255), this-> width/2-44, this->height-20, ALLEGRO_ALIGN_LEFT, pillsinfo.str().c_str());
    }


    else if(this->ready == true) {
        al_draw_text(&font, al_map_rgb(254,254,33), 210, this->height/2-2, ALLEGRO_ALIGN_LEFT, "GET READY!!");
        al_draw_text(&font, al_map_rgb(255,255,255), 24, this->height-60, ALLEGRO_ALIGN_LEFT, scoreinfo.str().c_str());
        al_draw_text(&font, al_map_rgb(255,255,255), this-> width-192, this->height-60, ALLEGRO_ALIGN_LEFT, lifesinfo.str().c_str());
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
        al_draw_text(&font2, al_map_rgb(255,255,255), this-> width/2-44, this->height-20, ALLEGRO_ALIGN_LEFT, pillsinfo.str().c_str());
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
                        cellCenterY - 10, cellCenterX - 10,
                        20, 20,
                        0
                    );
}

void Renderer::ChangePill() {
    if(alMassimo == true) { this-> framePill++; } else { this-> framePill--;}
    if(this-> framePill == 6) { alMassimo = false; alMinimo = true; } 
    else if(this-> framePill == 2) { alMassimo = true; alMinimo = false; }

}

void Renderer::drawPillsAndGhostEatable(Map& map) {
    ALLEGRO_COLOR white   = al_map_rgb(240,240,240);
    ALLEGRO_BITMAP *image = al_load_bitmap("sprite.png");
    al_convert_mask_to_alpha(image, al_map_rgb(255,255,255));
    float halfCellX = this->cellWidth/2;
    float halfCellY = this->cellHeight/2;

    int spritesGhostEatable[2][2] = {
        192,96,
        216,96,
    };    



    for(int y = 0; y < 33; y++) {
        for(int x = 0; x < 30; x++) {
            float cellCenterX = (this->cellWidth*x)+halfCellX;
            float cellCenterY = (this->cellHeight*y)+halfCellY;

            if(map.map[y][x] == 15) {            
                al_draw_filled_circle(cellCenterX, cellCenterY, framePill, white);                            
            }
            if(map.map[y][x] == 76){
                if(this->frameGhostEatable == 0){
                    al_draw_scaled_bitmap(image,
                        spritesGhostEatable[0][0],
                        spritesGhostEatable[0][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
                        0
                        );
                }
                else if(this->frameGhostEatable == 1){
                    al_draw_scaled_bitmap(image,
                        spritesGhostEatable[1][0],
                        spritesGhostEatable[1][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
                        0
                        );
                }
            }
        }
    }
    this->ChangePill();
    this->changeEatableFrame();
}

void Renderer::drawMenu(Menu _startMenu, ALLEGRO_FONT &fontL, ALLEGRO_FONT &fontM, ALLEGRO_FONT &fontH, bool _playMusic) {
    ALLEGRO_BITMAP *image = al_load_bitmap("logomenu.png");
    al_convert_mask_to_alpha(image, al_map_rgb(255,255,255));
        stringstream newgame;
        stringstream sound;
        stringstream exit;
        newgame << _startMenu.startMenu[0].getNameButton();
        sound << _startMenu.startMenu[1].getNameButton();
        exit << _startMenu.startMenu[2].getNameButton();  


        al_draw_scaled_bitmap(image,
                        0,
                        0,
                        796, 466,
                        0, 10,
                        this->width, this->height/3 + 150,
                        0
                        );


        if(_startMenu.startMenu[0].getSelectedButton()){
            al_draw_text(&fontH, al_map_rgb(255,255,251), (this->width/2), this->height/2 + 100, ALLEGRO_ALIGN_CENTRE, newgame.str().c_str());
        }
        else {
            al_draw_text(&fontM, al_map_rgb(255,255,251), (this->width/2), this->height/2 + 100, ALLEGRO_ALIGN_CENTRE, newgame.str().c_str());

        }

        if(_startMenu.startMenu[1].getSelectedButton()){
            if(_playMusic)
                al_draw_text(&fontH, al_map_rgb(161,246,26), (this->width/2), (this->height/2 + 150), ALLEGRO_ALIGN_CENTRE, "SOUND ON");
            else {
                al_draw_text(&fontH, al_map_rgb(227,2,8), (this->width/2), (this->height/2 + 150), ALLEGRO_ALIGN_CENTRE, "SOUND OFF");
            }
        }
        else {
            if(_playMusic)
                al_draw_text(&fontM, al_map_rgb(161,246,26), (this->width/2), (this->height/2 + 150), ALLEGRO_ALIGN_CENTRE, "SOUND ON");
            else {
                al_draw_text(&fontM, al_map_rgb(227,2,8), (this->width/2), (this->height/2 + 150), ALLEGRO_ALIGN_CENTRE, "SOUND OFF");
            }
        }   
        
        if(_startMenu.startMenu[2].getSelectedButton()){
            al_draw_text(&fontH, al_map_rgb(255,255,255), (this->width/2), (this->height/2 + 200), ALLEGRO_ALIGN_CENTRE, exit.str().c_str());
        }

        else {
            al_draw_text(&fontM, al_map_rgb(255,255,255), (this->width/2), (this->height/2 + 200), ALLEGRO_ALIGN_CENTRE, exit.str().c_str());
        }

        al_draw_text(&fontL, al_map_rgb(255,255,255), (this->width/2), (this->height), ALLEGRO_ALIGN_CENTRE, "GAME CREATED BY SIMONE LUCA ROSSI & LUIGI PINGITORE");

}

void Renderer::drawFinalMenu(Menu _startMenu, ALLEGRO_FONT &fontM, ALLEGRO_FONT &fontH) {
        stringstream back;
        stringstream exit;
        back << _startMenu.endMenu[0].getNameButton();
        exit << _startMenu.endMenu[1].getNameButton(); 


        //al_draw_text(&font, al_map_rgb(255,255,255), 24, this->height/2-2, ALLEGRO_ALIGN_LEFT, "BACK");
        //al_draw_text(&font, al_map_rgb(255,255,255), this-> width-105, this->height/2-2, ALLEGRO_ALIGN_LEFT, "EXIT");

        if(_startMenu.endMenu[0].getSelectedButton()){
            al_draw_text(&fontH, al_map_rgb(255,255,255), 24, this->height/2-2, ALLEGRO_ALIGN_LEFT, "BACK");
        }
        else {
            al_draw_text(&fontM, al_map_rgb(255,255,255), 24, this->height/2-2, ALLEGRO_ALIGN_LEFT, "BACK");

        }

        if(_startMenu.endMenu[1].getSelectedButton()){
            al_draw_text(&fontH, al_map_rgb(255,255,255), this-> width-105, this->height/2-2, ALLEGRO_ALIGN_LEFT, "EXIT");
        }
        else {
            al_draw_text(&fontM, al_map_rgb(255,255,255), this-> width-105, this->height/2-2, ALLEGRO_ALIGN_LEFT, "EXIT");
        }   
}

void Renderer::changeEatableFrame() {
    if(this->frameGhostEatable == 0) { this->frameGhostEatable = 1; } else { this->frameGhostEatable = 0;  }
}
