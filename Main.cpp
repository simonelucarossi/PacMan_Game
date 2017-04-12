#include <stdio.h>
#include "PacMan.h"

void restart(Map&, PacMan&, Ghost&, Ghost&, Ghost&, Ghost&);

//#include <allegro5/allegro.h>


int main() {
	Map mappa;

	Ghost g1(mappa,15,15);
	Ghost g2(mappa,15,16);
	Ghost g3(mappa,15,13);
	Ghost g4(mappa,15,14);
	PacMan p1(mappa);

	char moveGhost;


	mappa.stampa();
	while(p1.getLifes() > 0){
		cin >> moveGhost;
		if(moveGhost == 'a'){
			p1.MoveLeft(mappa);
			if(p1.eatPill()) {
				g1.setEatable(true);
				g2.setEatable(true);
				g3.setEatable(true);
				g4.setEatable(true);
				g1.setImage(76);
				g2.setImage(76);
				g3.setImage(76);
				g4.setImage(76);
			}
		}
		if(moveGhost == 'w'){
			p1.MoveUp(mappa);
			if(p1.eatPill()) {
				g1.setEatable(true);
				g2.setEatable(true);
				g3.setEatable(true);
				g4.setEatable(true);
				g1.setImage(76);
				g2.setImage(76);
				g3.setImage(76);
				g4.setImage(76);
			}
		}

		if(moveGhost == 's'){
			p1.MoveDown(mappa);
			if(p1.eatPill()) {
				g1.setEatable(true);
				g2.setEatable(true);
				g3.setEatable(true);
				g4.setEatable(true);
				g1.setImage(76);
				g2.setImage(76);
				g3.setImage(76);
				g4.setImage(76);
			}
		}
		
		if(moveGhost == 'd'){
			p1.MoveRight(mappa);
			if(p1.eatPill()) {
				g1.setEatable(true);
				g2.setEatable(true);
				g3.setEatable(true);
				g4.setEatable(true);
				g1.setImage(76);
				g2.setImage(76);
				g3.setImage(76);
				g4.setImage(76);
			}
		}
		if(p1.CheckCollision(g1, g2, g3,g4) && !(g1.getEatable())){
			restart(mappa,p1,g1,g2,g3,g4);
			mappa.stampa();
		}

		else if(p1.CheckCollision(g1, g2, g3,g4) && (g1.getEatable())) {
				p1.eatGhost(g1,g2,g3,g4,mappa);
				mappa.stampa();
		}

		else{
			g1.moveGhost(mappa);
			g2.moveGhost(mappa);
			g3.moveGhost(mappa);
			g4.moveGhost(mappa);
			mappa.stampa();
			if(p1.CheckCollision(g1, g2, g3,g4) && !(g1.getEatable())){
				restart(mappa,p1,g1,g2,g3,g4);
				mappa.stampa();
			}
			else if(p1.CheckCollision(g1, g2, g3,g4) && (g1.getEatable())) {
				p1.eatGhost(g1,g2,g3,g4,mappa);
				mappa.stampa();
			}
		}
		if(p1.getLifes() > 0) { p1.printScore(); }
		else { cout << "        GAME OVER!"; }	


	cout << "PacMan Cordinates: " << p1.getCoordinateX() << ":" << p1.getCoordinateY() << endl;
	cout << "Ghost 1: " << g1.getCoordinateX() << ":" << g1.getCoordinateY() << " " << g1.getEatable() <<endl;
	cout << "Ghost 2: " << g2.getCoordinateX() << ":" << g2.getCoordinateY() << " " << g2.getEatable() << endl;
	cout << "Ghost 3: " << g3.getCoordinateX() << ":" << g3.getCoordinateY() << " " << g3.getEatable() << endl;
	cout << "Ghost 4: " << g4.getCoordinateX() << ":" << g4.getCoordinateY() << " " << g4.getEatable() << endl;
	}
		




/*ALLEGRO_DISPLAY *display = NULL;

if(!al_init())
{
fprintf(stderr, "failed to initialize allegro!\n");
return -1;
}

display = al_create_display(640, 480);

if(!display)
{
fprintf(stderr, "failed to create display!\n");
return -1;
}

al_clear_to_color(al_map_rgb(0,0,0));
al_flip_display();
al_rest(10.0);
al_destroy_display(display);
*/
return 0;
}

void restart(Map& mappa, PacMan& p1, Ghost& g1,Ghost& g2,Ghost& g3, Ghost& g4){
	if(p1.getCoordinateX() != 22 || p1.getCoordinateY() != 13){
		mappa.map[p1.getCoordinateX()][p1.getCoordinateY()] = 0;
		p1.setCoordinateX(22);
		p1.setCoordinateY(13);
		mappa.map[p1.getCoordinateX()][p1.getCoordinateY()] = 11;
	}
	
	mappa.map[g1.getCoordinateX()][g1.getCoordinateY()] = g1.getPrevious();
	g1.setCoordinateX(15);
	g1.setCoordinateY(15);
	mappa.map[g1.getCoordinateX()][g1.getCoordinateY()] = 75;
	g1.setRandAttuale(0);
	g1.setPrevious(0);

	mappa.map[g2.getCoordinateX()][g2.getCoordinateY()] = g2.getPrevious();
	g2.setCoordinateX(15);
	g2.setCoordinateY(16);
	mappa.map[g2.getCoordinateX()][g2.getCoordinateY()] = 75;
	g2.setRandAttuale(0);
	g2.setPrevious(0);

	mappa.map[g3.getCoordinateX()][g3.getCoordinateY()] = g3.getPrevious();
	g3.setCoordinateX(15);
	g3.setCoordinateY(13);
	mappa.map[g3.getCoordinateX()][g3.getCoordinateY()] = 75;
	g3.setRandAttuale(0);
	g3.setPrevious(0);

	mappa.map[g4.getCoordinateX()][g4.getCoordinateY()] = g4.getPrevious();
	g4.setCoordinateX(15);
	g4.setCoordinateY(14);
	mappa.map[g4.getCoordinateX()][g4.getCoordinateY()] = 75;
	g4.setRandAttuale(0);
	g4.setPrevious(0);
}

