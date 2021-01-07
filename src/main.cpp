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
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  backgroundTexture.loadFromFile("/home/fn/Downloads/Webp.net-resizeimage(1).jpg");
  backgroundSpr.setTexture(backgroundTexture);
  // picture part of date and time
  /*sf::Texture texture;
  sf::Sprite spr;
  texture.loadFromFile("/home/fn/Downloads/Webp.net-resizeimage(1).jpg");
  spr.setTexture(texture);*/

  //icon calendar
  sf::Texture calendarTexture;
  sf::Sprite calendarSpr;
  calendarTexture.loadFromFile("/home/fn/Downloads/Webp.net-resizeimage.png");
  calendarSpr.setTexture(calendarTexture);
  calendarSpr.setPosition(sf::Vector2f(10, 0));

  //date and time
  sf::Text timeTxt;
  sf::Font timeFont;
  timeFont.loadFromFile("/home/fn/sfml/OpenSans-Semibold.ttf");
  time_t timetoday;
  time (&timetoday);
  string s = static_cast<string> (asctime(localtime(&timetoday)));
  timeTxt.setFont(timeFont);
  timeTxt.setFillColor(sf::Color::Red);
  timeTxt.setString(s);
  timeTxt.setPosition(sf::Vector2f((calendarSpr.getGlobalBounds().width + 20), 0));

  // a part for add a task
  sf::Text addTxt;
  sf::Font addFont;
  addFont.loadFromFile("/home/fn/sfml/OpenSans-Semibold.ttf");
  addTxt.setFont(addFont);
  addTxt.setFillColor(sf::Color::Red);
  addTxt.setString("+ add a task");
  //addTxt.setOrigin(sf::Vector2f(0, -1*addTxt.getGlobalBounds().height));
  addTxt.setPosition(sf::Vector2f(0, window.getSize().y- 2*addTxt.getGlobalBounds().height));

  while(window.isOpen())
  {
    while(window.pollEvent(event))
    {

      if(event.type == sf::Event::EventType::Closed)
      {
        window.close();
      }
    }
    window.draw(backgroundSpr);// draw picture of background
    window.draw(calendarSpr);// draw calendar icon
    window.draw(timeTxt);// draw date and time
    window.draw(addTxt);// draw + add a task
    window.display();// display window
  }



  return 0;
}
