
#include <iostream>

#include <SFML/Graphics.hpp>

#include "roadfighter/include/World.h"



void runGame(std::string inputFile)
{
    sf::Sprite background;
    sf::Texture backgroundTexture;

    backgroundTexture.loadFromFile(inputFile);

    sf::Vector2u sizeBackground = backgroundTexture.getSize();

    background.setTexture(backgroundTexture);

//    sf::RenderWindow window(sf::VideoMode(294, 164), "roadfighter");

    sf::RenderWindow window(sf::VideoMode(800, 600), "roadfighter");

    sf::View view(sf::FloatRect(0.f, 0.f, 8000.f, 6000.f));

    background.scale(8000.0/294, 6000.0/164);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
            }
        }


        window.draw(background);

        window.setView(view);

        window.display();
    }
}






int main(int argc, char* argv[]) {

    RF::World road;


    runGame(argv[1]);

    return 0;
}