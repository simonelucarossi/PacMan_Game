#include "Renderer.h"
#include <sstream>

int WALL_THICKNESS = 5;

Renderer::Renderer() {
    this->cellWidth  = 20;
    this->cellHeight = 20;
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

    int frame;
    int direction;
    int sprites[12][2] = {
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


    for(int y = 0; y < 33; y++) {
        for(int x = 0; x < 30; x++) {

            float cellCenterX = (this->cellWidth*x)+halfCellX;
            float cellCenterY = (this->cellHeight*y)+halfCellY;

            switch(map.map[y][x]) {
                case(1):
                    al_draw_line(
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
                            );
                    break;
                case(2):
                    al_draw_line(
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
                            );
                    break;
                case(3):
                    al_draw_line(
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
                            );
                    break;
                case(4):
                    al_draw_line(
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
                            );
                    break;
                case(5):
                    al_draw_line(
                            cellCenterX-halfCellX, cellCenterY,
                            cellCenterX+halfCellX, cellCenterY,
                            blue,
                            WALL_THICKNESS
                            );
                    break;
                case(6):
                    al_draw_line(
                            cellCenterX, cellCenterY-halfCellY,
                            cellCenterX, cellCenterY+halfCellY,
                            blue,
                            WALL_THICKNESS
                            );
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
                    frame = pacman.nextFrame();
                    direction = pacman.getDirection();

                    al_draw_scaled_bitmap(image,
                        sprites[frame+direction*3][0],
                        sprites[frame+direction*3][1],
                        24, 24,
                        cellCenterX-10, cellCenterY-10,
                        20, 20,
                        0
                    );
                    break;
                case(15):
                    al_draw_filled_circle(cellCenterX, cellCenterY, 5, white);
                    break;
                case(75):
                    al_draw_scaled_bitmap(image, 0, 144, 24, 24, cellCenterX-10, cellCenterY-10, 20, 20, 0);
                    break;
                case(76):
                    break;
                default:

                    break;
            }

        }
    }
}

void Renderer::drawInfo(PacMan& pacman, ALLEGRO_FONT &font) {
    if(pacman.getLifes() > 0) {
        stringstream info;
        info << "Score: " << pacman.getScore();

        al_draw_text(&font, al_map_rgb(255,255,255), 20, this->height-40, ALLEGRO_ALIGN_LEFT, info.str().c_str());
    } else {
        al_draw_text(&font, al_map_rgb(255,255,255), this->width/2-60, this->height/2, ALLEGRO_ALIGN_LEFT, "GAME OVER");
    }
}
