#include <iostream>
#include <unistd.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main(void)
{
const int oknoX=1440,oknoY=900;
int ryskolo=1,b=1,c=1;
float vx=0.05,vy=0.05,x,y,odbX,odbY;
odbX=(oknoX/2);
odbY=(oknoY/2);
sf::RenderWindow okno(sf::VideoMode(oknoX,oknoY), "Moje okno");

sf::Texture tekstura;
tekstura.loadFromFile("tekstura.jpg");

sf::CircleShape kolo(200);
x=(oknoX/2)-200;
y=(oknoY/2)-200;
kolo.setPosition(x,y);
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

//przyspieszanie kola
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
b=b+1;
}

     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
b=b-1;
if(b<2)
{
b=1;
}
}

     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
c=c+1;
if(c>20)
{
c=20;
}
}

     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
c=c-1;
if(c<2)
{
c=1;
}
}

//

//poruszanie sie kola

//prawo/lewo
for(int i=0;i<b;i++)
{
kolo.move(vx,0);
odbX=odbX+vx;
//cout<<"odbX= "<<odbX<<endl;

if(odbX+200>=oknoX)
{
vx*=-1;
}
else if(odbX-200<=0)
{
vx*=-1;
}
}
//gora/dol
for(int i=0;i<c;i++)
{
vy=vy+(0.01*i);
//if(vy>1.5)
//{
//vy=1.4;
//}
cout<<"vy = "<<vy<<endl;
cout<<"c = "<<c<<endl;
kolo.setFillColor(sf::Color((c*10),0,0));
kolo.move(0,vy);
odbY=odbY+vy;
//cout<<"odbY= "<<odbY<<endl;

if(odbY+200>=oknoY)
{
vy*=-1;
}
else if(odbY-200<=0) //else
{
vy*=-1;
}
}

//
///////////koniec poruszania sie kola z odbijaniem
if(ryskolo==1)
{
okno.draw(kolo);
}

}// koniec petli glownej

return 0;
}
