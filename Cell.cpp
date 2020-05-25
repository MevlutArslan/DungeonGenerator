//
//  Cell.cpp
//  DungeonGeneration
//
//  Created by Mevlut Arslan on 25/05/2020.
//  Copyright © 2020 Mevlut Arslan. All rights reserved.
//

#include <stdio.h>
#include <vector>


class Cell{
    
private:
    
public:
    bool living = false;
    bool neighbourState[8];
    char indicator;
    
    Cell(char indicator){
        this->indicator = indicator;
    }
    
    void countAliveNeighbours(std::vector<std::vector<Cell>> cellMap, int x, int y){
    int count = 0;
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            int neighbour_x = x+i;
            int neighbour_y = y+j;
            
            if(i == 0 && j == 0){
                //do nothing
            }
            //if edge of the map
            else if(neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= cellMap.size() || neighbour_y >= cellMap[0].size()){
                count = count + 1;
            }
            
            //normal check
            else if(cellMap[neighbour_x][neighbour_y].living){
                count = count + 1;
            }
        }
    }
    }
};
