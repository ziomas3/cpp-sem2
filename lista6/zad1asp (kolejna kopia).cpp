#include <iostream>
#include <unistd.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main(void)
{
const sf::Vector2i okno(800,600); // wektor wymiarow okna
int ryskolo=1;

sf::RenderWindow oknoApl(sf::VideoMode(okno.x,okno.y), "Moje okno");
//
sf::Texture tekstura;
tekstura.loadFromFile("tekstura.jpg");
//
sf::CircleShape kolo;
kolo.setRadius(200);
kolo.setTexture(&tekstura);
sf::Vector2f pozbazowa((okno.x/2)-200,(okno.y/2)-200); // wektor polozenia bazowego
sf::Vector2f predkosc(0.05,0.05); // wektor predkosci 

while(oknoApl.isOpen()) // petla glowna
{
oknoApl.display();

sf::Event event; // magazyn zdarzen
while(oknoApl.pollEvent(event))
{

if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
{
ryskolo=1-ryskolo;
}

//zamykanie okna
if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
{
oknoApl.close();
}

if (event.type == sf::Event::Closed)
{
oknoApl.close();
}
// koniec zamykanie okna
}//koniec petli zdarzen

oknoApl.clear(); // czyszczenie okna

/// poruszanie sie kola z odbijaniem.

for(int i=0;i<100;i++)
{
pozbazowa.x=pozbazowa.x+predkosc.x;
pozbazowa.y=pozbazowa.y+predkosc.y;
kolo.setPosition(pozbazowa.x,pozbazowa.y);
sf::Vector2f pozycja=kolo.getPosition(); // wektor pozycji po zmianie
cout<<pozycja.x<<" "<<pozycja.y<<endl;
if(pozycja.y >= (okno.y/2)-100)
{
predkosc.y*=-1;
}
if(pozycja.y <= 0)
{
predkosc.y*=-1;
}
if(pozycja.x >= okno.x/2)
{
predkosc.x*=-1;
}
if(pozycja.x <= 0)
{
predkosc.x*=-1;
}
}

///////////koniec poruszania sie kola z odbijaniem
if(ryskolo==1)
{
oknoApl.draw(kolo);
}

}// koniec petli glownej

return 0;
}
