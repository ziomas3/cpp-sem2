#include <iostream>
#include <unistd.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main(void)
{
srand( time( NULL ) );
const sf::Vector2i okno(800,600); // wektor wymiarow okna
const int N=3;
int ryskolo=1;

sf::RenderWindow oknoApl(sf::VideoMode(okno.x,okno.y), "Moje okno");
//
sf::Texture tekstura;
tekstura.loadFromFile("tekstura.jpg");
//
sf::CircleShape kolo[N];

for(int i=0;i<=N;i++)
{
kolo[i].setRadius(200);
kolo[i].setTexture(&tekstura);
}

float pbx[N],pby[N];
float vx[N],vy[N];

for(int i=0 ; i<N ; i++)
	{
		pbx[i]=rand()%okno.x;
	}
	
	for(int i=0 ; i<N ; i++)
	{
		pby[i]=rand()%okno.y;
	}
	
	for(int i=0 ; i<N ; i++)
	{
		vx[i]=(float)rand()/RAND_MAX;
	}
	
	for(int i=0 ; i<N ; i++)
	{
		vy[i]=(float)rand()/RAND_MAX;
	}

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
sf::Vector2f poz[N];
/// poruszanie sie kola z odbijaniem.
if(ryskolo==1)
{
for(int i=0;i<N;i++)
{
kolo[i].setPosition(pbx[i],pby[i]);
pbx[i]=pbx[i]+vx[i];
pby[i]=pby[i]+vy[i];
poz[i]=kolo[i].getPosition(); // wektor pozycji po zmianie
if(poz[i].y >= (okno.y/2)-100)
{
vy[i]*=-1;
}
if(poz[i].y <= 0)
{
vy[i]*=-1;
}
if(poz[i].x >= okno.x/2)
{
vx[i]*=-1;
}
if(poz[i].x <= 0)
{
vx[i]*=-1;
}
oknoApl.draw(kolo[i]);
}
}
///////////koniec poruszania sie kola z odbijaniem
}// koniec petli glownej

return 0;
}
