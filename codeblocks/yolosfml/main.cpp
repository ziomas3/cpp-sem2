#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;


int main()
{

//textura tlo_s_txt
    sf::Texture piestxt;
    if (!piestxt.loadFromFile("tlo_s.png"))
    {
        return -3;
    }
    piestxt.setSmooth(true);

//spirit
    vector<sf::Sprite> pies(73);
    for (int i=1; i<=72; i++)
    {

        pies[i].setTexture(piestxt);
        pies[i].setPosition(sf::Vector2f(500,200));
        pies[i].setScale(sf::Vector2f(0.5f, 0.5f));
        for(int j=0; j<i; j++)
        {
            pies[i].rotate(5);
            pies[i].scale(sf::Vector2f(0.98f, 0.98f));
        }
    }
    sf::Sprite tlo_s;
    tlo_s.setTexture(piestxt);
//ustawienia okna
    sf::RenderWindow window(sf::VideoMode(1366,768), "test");
    window.setFramerateLimit(45);

window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {


        for (int i=1; i<360/5; i++)
        {
            window.clear();
            window.draw(tlo_s);
            for(int j=1; j<=i; j++)
            {
                window.draw(pies[j]);
            }
            window.display();
        }


    }
    return 0;
}
