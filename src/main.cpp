#include <iostream>
#include <chrono>
#include <ctime>
#include "SFML/Graphics.hpp"
using namespace std;

int main()
{
  //object of class RenderWindow and Event
  sf::RenderWindow window(sf::VideoMode(605, 1076), "To Do");
  sf::Event event;

  // background
  sf::Texture texture;
  sf::Sprite spr;
  texture.loadFromFile("/home/fn/Downloads/Webp.net-resizeimage(1).jpg");
  spr.setTexture(texture);

  //icon calendar
  sf::Texture texture2;
  sf::Sprite spr2;
  texture2.loadFromFile("/home/fn/Downloads/Webp.net-resizeimage.png");
  spr2.setTexture(texture2);
  spr2.setPosition(sf::Vector2f(10, 0));

  //date and time
  sf::Text txt;
  sf::Font font;
  font.loadFromFile("/home/fn/sfml/OpenSans-Semibold.ttf");
  time_t timetoday;
  time (&timetoday);
  string s = static_cast<string> (asctime(localtime(&timetoday)));
  txt.setFont(font);
  txt.setFillColor(sf::Color::Red);
  txt.setString(s);
  txt.setPosition(sf::Vector2f((spr2.getGlobalBounds().width + 20), 0));

  while(window.isOpen())
  {
    while(window.pollEvent(event))
    {

      if(event.type == sf::Event::EventType::Closed)
      {
        window.close();
      }
    }
    window.draw(spr);// draw picture of background
    window.draw(spr2);// draw calendar icon
    window.draw(txt);// draw date and time
    window.display();// display window
  }



  return 0;
}
