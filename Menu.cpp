#include <iostream>
#include "Button.cpp"
using namespace std;


class Menu {
public:
	Button *startMenu;
	Button *endMenu;

	inline Menu() {
		startMenu = new Button[3];
		endMenu = new Button[2];

		startMenu[0].setNameButton("NEW GAME");
		startMenu[0].setSelectedButton(true);
		startMenu[1].setNameButton("SOUND");
		startMenu[2].setNameButton("EXIT");

		endMenu[0].setNameButton("BACK");
		endMenu[0].setSelectedButton(true);
		endMenu[1].setNameButton("EXIT");
	}
};