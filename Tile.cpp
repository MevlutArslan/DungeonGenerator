#include <stdio.h>
#include "TileType.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile : public sf::Sprite{
    
private:
    int _size;
    int _x;
    int _y;
    TileType _tileType;
    sf::Texture texture;

public:
    Tile(int size,TileType tileType){
        this->_size = size;
        this->_tileType = tileType;
        
        switch (tileType) {
            case WALL:
                if(!texture.loadFromFile("/Users/mevlutarslan/Documents/codeWorkspaces/DungeonGeneration/ArtThings/Ground&Stone/Ground/ground2.png")){
                    std::cout << "couldnt load texture";
                }
                texture.setSmooth(true);
                this->setTextureRect(sf::IntRect(this->getPosition().x,this->getPosition().y,this->_size,this->_size));
                this->setTexture(texture);
                break;
            case GROUND:
                if(!texture.loadFromFile("/Users/mevlutarslan/Documents/codeWorkspaces/DungeonGeneration/ArtThings/Ground&Stone/Stone/ground2.png")){
                    std::cout << "couldnt load texture";
                }
                this->setTextureRect(sf::IntRect(this->getPosition().x,this->getPosition().y,this->_size,this->_size));
                this->setTexture(texture);
                break;
            default:
                break;
        }
    }
    
    void drawTile(sf::RenderWindow *window){
        sf::Sprite sprite = *this;
        window->draw(sprite);
    }
};
