#include "Dungeon.cpp"
#include <iostream>

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(900,900), "SFML window");
    window.setFramerateLimit(60);
    
    Dungeon dungeon = Dungeon(900,900,30,&window);
    dungeon.fillCellMap();
    dungeon.generate();
    
    
    for(auto i = 0; i < dungeon.cellMap.size();i++){
        for(auto j = 0; j < dungeon.cellMap[i].size(); j++){
            std::cout << dungeon.cellMap[i][j].indicator;
        }
        std::cout<<std::endl;
    }
    

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        window.clear();

        
        dungeon.drawTextureForm(&window);
        window.display();
    }
}
