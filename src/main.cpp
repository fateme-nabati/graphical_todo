#include <iostream>
#include "SFML/Graphics.hpp"
using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(605, 1076), "To Do");
  sf::Event event;
  sf::Texture texture;
  sf::Sprite spr;
  texture.loadFromFile("/home/fn/Downloads/Webp.net-resizeimage(1).jpg");
  spr.setTexture(texture);
  while(window.isOpen())
  {
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::EventType::Closed)
      {
        window.close();
      }
    }
    window.draw(spr);
    window.display();
  }

  return 0;
}
