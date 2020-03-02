#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main(void)
{
 int keyonoff=1;
 
 sf::RenderWindow window(sf::VideoMode(1024,768),"Nasze okno");
 sf::Texture texture;
 texture.loadFromFile( "tekstura.jpg" );

  sf::CircleShape shape(80, 3);
  shape.setPosition(100, 100);
  shape.setFillColor(sf::Color::Red);
  shape.setOutlineThickness(10);
  shape.setOutlineColor(sf::Color(250, 150, 100));
  shape.setOrigin(80, 3);
  shape.setTexture(&texture);
  shape.setTextureRect(sf::IntRect(10, 10, 100, 100));

  window.draw( shape );

  sf::CircleShape shape1(80, 4);
  shape1.setPosition(300, 100);
  shape1.setFillColor(sf::Color::Blue);
  shape1.setOutlineThickness(10);
  shape1.setOutlineColor(sf::Color(150, 150, 100));

  sf::CircleShape shape2(80, 12);
  shape2.setPosition(700, 100);
  shape2.setFillColor(sf::Color::Green);
  shape2.setOutlineThickness(10);
  shape2.setOutlineColor(sf::Color(100, 100, 150));
  
  while(window.isOpen())
  {
  
   sf::Event event;
   
   while(window.pollEvent(event))
   {
    if(event.type==sf::Event::Closed)
      window.close();
     /////////////////////////////////////////////////////////////// shape
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    // left key is pressed: move our character
    shape.move(-1, 0);
}
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
    // left key is pressed: move our character
    shape.move(1, 0);
}
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
    // left key is pressed: move our character
    shape.move(0, -1);
}
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
    // left key is pressed: move our character
    shape.move(0, 1);
}
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
{
    // left key is pressed: move our character
    shape.rotate(-1);;
}
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
{
    // left key is pressed: move our character
    shape.rotate(1);;
}
///////////////////////////////////////////////////////////////////////////////// shape
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
{
    // left key is pressed: move our character
    shape2.move(-1, 0);
}
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
{
    // left key is pressed: move our character
    shape2.move(1, 0);
}
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
{
    // left key is pressed: move our character
    shape2.move(0, -1);
}
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
{
    // left key is pressed: move our character
    shape2.move(0, 1);
}


//        float Mx = sf::Mouse::getPosition(window).x;
//        float My = sf::Mouse::getPosition(window).y;
//
//     if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//{
//        shape1.move(Mx,My);
//}



   }
    window.clear(sf::Color::Black);
    
    if(keyonoff)
      window.draw(shape);
      window.draw(shape1);
      window.draw(shape2);
    
    window.display();
  }
  return 0;
}
