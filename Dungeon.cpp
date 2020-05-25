
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
//        this->initalFill();
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

