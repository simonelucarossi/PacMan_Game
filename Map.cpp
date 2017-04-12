
#include "Map.h"
#include <stdio.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

Map::Map() {
    

	
}

/*Map::~Map() {
	// TODO Auto-generated destructor stub
}*/

void Map::stampa() {
	for(int i = 0; i < 33; i++) {
		for(int j = 0; j < 30; j++) {
			if(map[i][j] == 1)
				cout << BOLDBLUE << "•" << RESET << " ";
			if(map[i][j] == 2)
				cout << BOLDBLUE << "•" << RESET << " ";
			if(map[i][j] == 3)
				cout << BOLDBLUE << "•" << RESET << " ";
			if(map[i][j] == 4)
				cout << BOLDBLUE << "•" << RESET << " ";
			if(map[i][j] == 5)
				cout << BOLDBLUE << "-" << RESET << " ";
			if(map[i][j] == 6)
				cout << BOLDBLUE << "|" << RESET << " ";
			if(map[i][j] == 7)
				cout << RED << ":" << RESET << " ";
			if(map[i][j] == 8)
				cout << RED << "-" << RESET << " ";
			if(map[i][j] == 9)
				cout << MAGENTA << "🍟" << RESET << " ";
			if(map[i][j] == 15)
				cout << MAGENTA << "🍓" << RESET << " ";
			if(map[i][j] == 0)
				cout << " " << " ";
			if(map[i][j] == 11){
				cout << BOLDYELLOW << "🐒" << RESET << " ";   
			}
			if(map[i][j] == 75){
				cout << BLUE << "☺" << RESET << " ";   
			}
			if(map[i][j] == 76){
				cout << RED << "☺" << RESET << " ";   
			}
		}
	cout << endl;
	}
}


