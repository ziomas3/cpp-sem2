#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(void)
{
sf::RenderWindow okno(sf::VideoMode(800,600,32), "Aplikacja SFML od podstaw"); 
// sf::Window - tworzy okno. okno - nazwa zmiennej mojego okna aplikacji. sf::VideoMode - Rysuje okno o wymiarach x - 800, y - 600 i z 32 bitowa glebia kolorow. " " - nazwa okna.
//mozna to tez zrobic tak:
//sf::Window okno;
//okno.create(sf::VideoMode(800,600,32), "Aplikacja SFML od podstaw");
/////

sf::Texture tekstura,tekstura2;
tekstura.loadFromFile("tekstura.jpg"); // Tworze zmienna tekstury (sf::texture tekstura;) i nastepnie laduje ja z pliku (tekstura.loadFromFile("");
tekstura2.loadFromFile("tekstura2.jpg");

sf::Sprite sprajt1; // tworze sprajta
sprajt1.setTexture(tekstura); //oteksturowuje wczesniej stworzona tekstura.
sprajt1.setPosition(100,100); //lub sprajt1.setPosition(sf:Vector2f(100,100)); ustawiam pozycje sprajta na 100x 100y
sprajt1.setRotation(45); // obracam wzgledem oryginalnego polozenia. sprajt1.rotate(kat); obraca wzgledem aktualnego polozenia.
sprajt1.setScale(0.1,0.1); // skaluje wzgledem oryginalnego rozmiaru. sprajt1.scale(x,y); skaluje wzgledem aktualnego rozmiaru. 

sf::RectangleShape prostokat(sf::Vector2f(100,200)); // tworze prostokat
prostokat.setPosition(0,0);
prostokat.setTexture(&tekstura2); // w przypadku ksztaltow (CircleShape, RectangleShape itd.

/// Petla glowna programu
while(okno.isOpen() )
{

sf::Event zdarzenia; // magazyn zdarzen (events)
while( okno.pollEvent(zdarzenia)) // petla zdarzen. wykonuje sie ciagle i sprawdza co robimy. 
{



////////////////////// zamykanie okna
if( zdarzenia.type == sf::Event::Closed )
{
okno.close();
} // zamkniecie okna (krzyzykiem) zamyka okno

if(zdarzenia.type == sf::Event::KeyPressed && zdarzenia.key.code == sf::Keyboard::Escape)
{
    okno.close();
} // wcisniecie ESC wylacza okno

if( zdarzenia.type == sf::Event::MouseButtonPressed && zdarzenia.mouseButton.button == sf::Mouse::Middle )
{    
 okno.close();
} // wcisniecie srodkowego klawisza myszy wylacza okno
//////////////////// koniec zamykania okna
}
okno.display(); // wyswietl okno
okno.clear(); // czysci okno (na czarno). Jesli chce dodac inny kolor to w nawiasie umieszczam sf::Color(r,g,b)) lub sf:Color::Black;
okno.draw(sprajt1); // rysuje sprajta w oknie
okno.draw(prostokat);
}
// koniec petli glownej

return 0;
}
