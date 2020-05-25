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
    
    
};
