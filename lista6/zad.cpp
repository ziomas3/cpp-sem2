#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

#define oknoX 800
#define oknoY 600

int main()
{

int keyonoff=1,x,y,rozmiar1; //c
float vx=0.0,vy=0.0,przyspieszenie=0.05,czas;

sf::RenderWindow window(sf::VideoMode(oknoX, oknoY), "Nasze okno");

//c=sqrt((oknoX*oknoX)+(oknoY*oknoY))/2;
x=oknoX/2;
y=oknoY/2;
rozmiar1=200;

sf::CircleShape shape(rozmiar1); // 200 - promien. .f - float
shape.setPosition((oknoX/2)-rozmiar1,(oknoY/2)-rozmiar1); // x,y to polowa szerokosci/wysokosci okna. Ksztalt rysuje sie (ma srodek) od lewego gornego rogu, wiec jesli rysujemy kolo o promieniu 200 to srodek tego kola ma wspolrzedne 200x200. Odejmujac od polowy szerokosci/wysokosci wspolrzedne srodka ksztaltu otrzymujemy ksztalt dokladnie na srodku okna.
//shape.setOrigin(200,200); // ustawia "srodek" ksztaltu. 0,0 - lewy gorny rog (domyslnie)
shape.setFillColor(sf::Color::Red);






while (window.isOpen())
{
// dopoki okno jest otwarte...
// w tym obiekcie klasy sf::Event
// bedziemy mieli informacje co zrobil uzytkownik
sf::Event event;
while (window.pollEvent(event))
{
// uzytkownik kliknal zamkniecie okna
if (event.type == sf::Event::Closed)
window.close();
// uzytkownik nacisnal klawisz
if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
keyonoff=1-keyonoff;
}
// esc zamyka okno
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
{
    return 0;
}


// czyszczenie (na czarno)
window.clear(sf::Color::Black);
if(keyonoff) {window.draw(shape);} // rysuj kolo w zaleznosci od stanu zmiennej keyonoff
window.display();
}
return 0;
}
