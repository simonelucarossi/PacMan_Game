
#include "Map.h"


Map::Map() {
    

	
}

/*Map::~Map() {
	// TODO Auto-generated destructor stub
}*/

void Map::stampa() {
	for(int i = 0; i < 33; i++) {
		for(int j = 0; j < 30; j++) {
			if(map[i][j] == 1)
				cout << "." << " ";
			if(map[i][j] == 2)
				cout << "." << " ";
			if(map[i][j] == 3)
				cout << "." << " ";
			if(map[i][j] == 4)
				cout << "." << " ";
			if(map[i][j] == 5)
				cout << "-" << " ";
			if(map[i][j] == 6)
				cout << "|" << " ";
			if(map[i][j] == 7)
				cout << ":-" << " ";
			if(map[i][j] == 8)
				cout << "," << " ";
			if(map[i][j] == 9)
				cout << "o" << " ";
			if(map[i][j] == 0)
				cout << " " << " ";
			if(map[i][j] == 11){
		cout << "ᴥ" << " ";   
			}
		}
	cout << endl;
	}
}

