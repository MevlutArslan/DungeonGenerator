
#include <string>
#include "Tile.cpp"
#include "Cell.cpp"

class Dungeon{
    
private:
    int _verticalSize;
    int _horizontalSize;
    int _gridItemSize;
    std::vector<std::vector<char>> dungeonMap;
    
    
public:
    std::vector<std::vector<Cell>> cellMap;
    
    Dungeon(int verticalSize, int horizontalSize, int gridItemSize, sf::RenderWindow *window){
        this->_verticalSize = window->getSize().y / gridItemSize;
        this->_horizontalSize = window->getSize().x / gridItemSize;
        this->_gridItemSize = gridItemSize;
        this->fillCellMap();
        this->generate();
    }
    
//    void initalFill(){
//        for(auto i = 0; i < this->_verticalSize;i++){
//            std::vector<char> temp;
//            for(auto j = 0; j < this->_horizontalSize; j++){
//                temp.push_back('0');
//            }
//            dungeonMap.push_back(temp);
//        }
//    }
    
    void fillCellMap(){
        for(auto i = 0; i < this->_verticalSize;i++){
            std::vector<Cell> temp;
            for(auto j = 0; j < this->_horizontalSize; j++){
                temp.push_back(Cell('0'));
            }
            cellMap.push_back(temp);
        }
    }
    
    void generate(){
        float chanceToStartAlive = 0.45f;
        for(auto i = 0; i < this->_verticalSize;i++){
            for(auto j = 0; j < this->_horizontalSize; j++){
                if((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) < chanceToStartAlive){
                    this->cellMap[i][j].living = true;
                    this->cellMap[i][j].indicator = '1';
                }
                else{
                    this->cellMap[i][j].indicator = '2';
                }
            }
        }
    }
    
    std::vector<std::vector<Cell>> simulateStep(std::vector<std::vector<Cell>> map){
        
        std::vector<std::vector<Cell>> newMap;
        
        for(auto x = 0; x <map.size();x++){
            for(auto y = 0; y < map[0].size(); y++){
                int aliveNeighbours = countAliveNeighbours(map, x, y);
                
                if(map[x][y].living){
                    if(aliveNeighbours < 2 || aliveNeighbours > 3){
                        map[x][y].living = false;
                    }
                }
                if(!map[x][y].living){
                    if(aliveNeighbours == 4){
                        map[x][y].living = true;
                    }
                }
            }
        }
        return newMap;
    }
    
    int countAliveNeighbours(std::vector<std::vector<Cell>> cellMap, int x, int y){
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
    
    void drawTextureForm(sf::RenderWindow *window){
        for(auto i = 0; i < this->_verticalSize;i++){
            for(auto j = 0; j < this->_horizontalSize; j++){
                switch(this->cellMap[i][j].indicator) {
                    case '0':{
                        break;
                    }
                    case '1':{
                        Tile ground = Tile(this->_gridItemSize,GROUND);
                        ground.setPosition(j * this->_gridItemSize, i * this->_gridItemSize);
                        window->draw(ground);
                        break;
                    }
                    case '2':{
                        Tile wall = Tile(this->_gridItemSize,WALL);
                        wall.setPosition(j * this->_gridItemSize, i * this->_gridItemSize);
                        window->draw(wall);
                        break;
                    }
                }
            }
        }
    }
    
    void drawArrayForm(sf::RenderWindow *window){
        
    }

    std::vector<std::vector<char>> getMap(){
        return this->dungeonMap;
    }

};

