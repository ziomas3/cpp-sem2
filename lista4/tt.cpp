#include <iostream>
#include <cmath>

#define oknoX 800
#define oknoY 600

using namespace std;

int main(void)
{
int keyonoff=1,x,y,c=0;

c=sqrt((oknoX*oknoX)+(oknoY*oknoY))/2;

cout<<"c = "<<c<<endl;
return 0;
}

if(window.isOpen())
{
do
{
if(py <= 0)
shape.move(0, vy);
else if(py >= 0)
shape.move(0, -vy);
}while(o==1);
do
{
if(px <= 0)
shape.move(vx, 0);
else if(px >= 800)
shape.move(-vx, 0);
}while(p==1);
}

/// poruszanie sie obiektu (petla)
if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
{
do
{
if(py <= 0)
shape.move(0, vy);
else if(py >= 0)
shape.move(0, -vy);
}while(o==1);
do
{
if(px <= 0)
shape.move(vx, 0);
else if(px >= 800)
shape.move(-vx, 0);
}while(p==1);
}
///// koniec petli

////////////// szybkosc poruszania sie obiektu
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    vx=vx-1;
	if(vx<0)
	{
	vx=0;
	}
}
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
    vx=vx+1;
}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
    vy=vy-1;
	if(vy<0)
	{
	vy=0;
	}
}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
    vy=vy+1;
}
