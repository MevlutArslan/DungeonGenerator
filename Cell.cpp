//
//  Cell.cpp
//  DungeonGeneration
//
//  Created by Mevlut Arslan on 25/05/2020.
//  Copyright © 2020 Mevlut Arslan. All rights reserved.
//

#include <stdio.h>
#include <vector>

struct Local{
    int x;
    int y;
};

class Cell{
    
private:
    Local _location;
    
public:
    bool living = false;
    bool neighbourState[8];
    char indicator;
    
    Cell(int x ,int y,char indicator){
        this->_location.x = x;
        this->_location.y = y;
        this->indicator = indicator;
    }
    
    void countAliveNeighbours(std::vector<std::vector<Cell>> cellMap, int x, int y){
    int count = 0;
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            int neighbour_x = x+i;
            int neighbour_y = y+j;
            //If we're looking at the middle point
            if(i == 0 && j == 0){
                //Do nothing, we don't want to add ourselves in!
            }
            //In case the index we're looking at it off the edge of the map
            else if(neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= cellMap.size() || neighbour_y >= cellMap[0].size()){
                count = count + 1;
            }
            //Otherwise, a normal check of the neighbour
            else if(cellMap[neighbour_x][neighbour_y].living){
                count = count + 1;
            }
        }
    }
    }
};
