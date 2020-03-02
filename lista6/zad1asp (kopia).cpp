#include <iostream>
#include <unistd.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main(void)
{
const int oknoX=800,oknoY=600;
int ryskolo=1,b;
float vx=0.05,vy=0.05,x,y;

sf::RenderWindow okno(sf::VideoMode(oknoX,oknoY), "Moje okno");
//
sf::Texture tekstura;
tekstura.loadFromFile("tekstura.jpg");
//
sf::CircleShape kolo(200);
x=(oknoX/2)-200;
y=(oknoY/2)-200;
kolo.setTexture(&tekstura);

while(okno.isOpen()) // petla glowna
{
okno.display();

sf::Event event; // magazyn zdarzen
while(okno.pollEvent(event))
{

if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
{
ryskolo=1-ryskolo;
}

//zamykanie okna
if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
{
okno.close();
}

if (event.type == sf::Event::Closed)
{
okno.close();
}
// koniec zamykanie okna
}//koniec petli zdarzen

okno.clear(); // czyszczenie okna

/// poruszanie sie kola z odbijaniem.

for(int i=0;i<100;i++)
{
x=x+vx;
y=y+vy;
kolo.setPosition(x,y);
sf::Vector2f pozycja=kolo.getPosition();
cout<<pozycja.x<<" "<<pozycja.y<<endl;
if(pozycja.y >= (oknoY/2)-100)
{
vy*=-1;
}
if(pozycja.y <= 0)
{
vy*=-1;
}
if(pozycja.x >= oknoX/2)
{
vx*=-1;
}
if(pozycja.x <= 0)
{
vx*=-1;
}
}

///////////koniec poruszania sie kola z odbijaniem
if(ryskolo==1)
{
okno.draw(kolo);
}

}// koniec petli glownej

return 0;
}
