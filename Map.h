#ifndef MAP_H_
#define MAP_H_

#include <iostream>
using namespace std;

class Map {
    public:
        Map();

        int map[33][30] = {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,1,5,5,5,5,5,5,5,5,5,5,5,5,3,1,5,5,5,5,5,5,5,5,5,5,5,5,3,0,
            0,6,9,9,9,9,9,9,9,9,9,9,9,9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,6,0,
            0,6,9,1,5,5,3,9,1,5,5,5,3,9,6,6,9,1,5,5,5,3,9,1,5,5,3,9,6,0,
            0,6,15,6,0,0,6,9,6,0,0,0,6,9,6,6,9,6,0,0,0,6,9,6,0,0,6,15,6,0,
            0,6,9,2,5,5,4,9,2,5,5,5,4,9,2,4,9,2,5,5,5,4,9,2,5,5,4,9,6,0,
            0,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,0,
            0,6,9,1,5,5,3,9,1,3,9,1,5,5,5,5,5,5,3,9,1,3,9,1,5,5,3,9,6,0,
            0,6,9,2,5,5,4,9,6,6,9,2,5,5,3,1,5,5,4,9,6,6,9,2,5,5,4,9,6,0,
            0,6,9,9,9,9,9,9,6,6,9,9,9,9,6,6,9,9,9,9,6,6,9,9,9,9,9,9,6,0,
            0,2,5,5,5,5,3,9,6,2,5,5,3,0,6,6,0,1,5,5,4,6,9,1,5,5,5,5,4,0,
            0,0,0,0,0,0,6,9,6,1,5,5,4,0,2,4,0,2,5,5,3,6,9,6,0,0,0,0,0,0,
            0,0,0,0,0,0,6,9,6,6,0,0,0,0,0,0,0,0,0,0,6,6,9,6,0,0,0,0,0,0,
            0,0,0,0,0,0,6,9,6,6,0,1,5,7,8,8,7,5,3,0,6,6,9,6,0,0,0,0,0,0,
            0,5,5,5,5,5,4,9,2,4,0,6,0,0,0,0,0,0,6,0,2,4,9,2,5,5,5,5,5,0,
            0,0,0,0,0,0,0,9,0,0,0,6,0,0,0,0,0,0,6,0,0,0,9,0,0,0,0,0,0,0,
            0,5,5,5,5,5,3,9,1,3,0,6,0,0,0,0,0,0,6,0,1,3,9,1,5,5,5,5,5,0,
            0,0,0,0,0,0,6,9,6,6,0,2,5,5,5,5,5,5,4,0,6,6,9,6,0,0,0,0,0,0,
            0,0,0,0,0,0,6,9,6,6,0,0,0,0,0,0,0,0,0,0,6,6,9,6,0,0,0,0,0,0,
            0,0,0,0,0,0,6,9,6,6,0,1,5,5,5,5,5,5,3,0,6,6,9,6,0,0,0,0,0,0,
            0,1,5,5,5,5,4,9,2,4,0,2,5,5,3,1,5,5,4,0,2,4,9,2,5,5,5,5,3,0,
            0,6,9,9,9,9,9,9,9,9,9,9,9,9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,6,0,
            0,6,9,1,5,5,3,9,1,5,5,5,3,9,6,6,9,1,5,5,5,3,9,1,5,5,3,9,6,0,
            0,6,9,2,5,3,6,9,2,5,5,5,4,9,2,4,9,2,5,5,5,4,9,6,1,5,4,9,6,0,
            0,6,15,9,9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,6,9,9,15,6,0,
            0,2,5,3,9,6,6,9,1,3,9,1,5,5,5,5,5,5,3,9,1,3,9,6,6,9,1,5,4,0,
            0,1,5,4,9,2,4,9,6,6,9,2,5,5,3,1,5,5,4,9,6,6,9,2,4,9,2,5,3,0,
            0,6,9,9,9,9,9,9,6,6,9,9,9,9,6,6,9,9,9,9,6,6,9,9,9,9,9,9,6,0,
            0,6,9,1,5,5,5,5,4,2,5,5,3,9,6,6,9,1,5,5,4,2,5,5,5,5,3,9,6,0,
            0,6,9,2,5,5,5,5,5,5,5,5,4,9,2,4,9,2,5,5,5,5,5,5,5,5,4,9,6,0,
            0,6,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6,0,
            0,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        };

    int numberOfPills = 0;
    
    inline int getNumberOfPills() {
        numberOfPills = 0;
        for(int i = 0; i < 33; i++) {
            for(int j = 0; j < 30; j++) {
                if(map[i][j] == 9 || map[i][j] == 15) {
                    numberOfPills++;
                }
            }
        }
        return numberOfPills;
    }   
};

#endif /* MAP_H_ */
