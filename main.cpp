#include <SFML/Graphics.hpp>
#include "particle.h"
#include <memory>

#include<sstream>





int main(int argc, char const *argv[])
{
  // Window 800 by 800 pixels, 
    sf::RenderWindow window(sf::VideoMode(800,800), "Particle Simulation Test");
     // Particle & physics maybe
    sf::Clock clock;

    // List of particles
    std::vector<std::unique_ptr<Particle>> particles;
   
    // Font setup
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
      return -1;
    }
    sf::Text text;
    text.setFont(font);
    std::string partic;
    


    // FIrst manually created particle object
   
    int amountParticles = 0;
    
    // Main loop, if button pressed increment var with 1 and print it on screen
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition();
          
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              particles.push_back(std::make_unique<Particle>(
                                      mousePos.x, mousePos.y,5.0f
                    ));
              
              amountParticles += 1;
              std::string XPos = std::to_string(mousePos.x);
    
              std::string partic = std::to_string(amountParticles);
              text.setString(XPos);
            }
            
        }
        text.setCharacterSize(24);
        window.clear();
        window.draw(text);
        for (const auto& p : particles) {
          sf::CircleShape circle(p->radius);
          circle.setPosition(p->x, p->y);
          circle.setFillColor(sf::Color::White);
          window.draw(circle);
        }
         
        window.display();
        
    }

    return 0;
}
