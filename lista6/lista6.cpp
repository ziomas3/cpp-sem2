#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
//#include <stdlib.h>
using namespace std;

int main()
{
	srand( time( NULL ) );
	const int H = 600;
	const int W = 800;
	const int srednica = 20;
	const int promien = srednica/2;
	const int N=101;
	float x[N],y[N];
	float vx[N], vy[N];
	sf::CircleShape shape[N];

	for(int i=0 ; i<N ; i++)
	{
		x[i]=rand()%(W-(srednica*2));
	}
	for(int i=0 ; i<N ; i++)
	{
		y[i]=rand()%(H-(srednica*2));
	}
	for(int i=0 ; i<N ; i++)
	{
		vx[i]=(float)rand()/RAND_MAX;
	}
	for(int i=0 ; i<N ; i++)
	{
		vy[i]=(float)rand()/RAND_MAX;
	}
	for(int i=0; i<N ; i++)
	{
		shape[i]=sf::CircleShape (srednica);
		shape[i].setFillColor(sf::Color::Red);
	}
		
	int keyonoff=1;	
	sf::RenderWindow window(sf::VideoMode(W,H), "Nasze okno"); //,sf::Style::Fullscreen;

	while (window.isOpen())
	{
		sf::Event event;
		while( window.pollEvent(event) )
		{
			if (event.type == sf::Event::Closed) window.close();
			
			if (event.type == sf::Event::KeyPressed) keyonoff=1-keyonoff;	
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}
		
		window.clear(sf::Color::Black);
		if(keyonoff) 
		{
			for(int i=0; i<N; i++)
			{
				shape[i].setPosition(x[i],y[i]);
				vx[i]=vx[i]+0.000001;
				vy[i]=vy[i]+0.000001;
				x[i] = x[i]+vx[i];
				y[i] = y[i]+vy[i];
				if(x[i]>=W-(srednica*2) || x[i]<0) vx[i]=-vx[i];
				if(y[i]>=H-(srednica*2) || y[i]<0) vy[i]=-vy[i];			 
				window.draw(shape[i]);
			}		
		}
		window.display();
	}	
		
	return 0;
}
