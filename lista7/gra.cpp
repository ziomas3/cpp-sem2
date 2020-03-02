#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <ctime>
#include <unistd.h>
#include <fstream>
#include <chrono> // c++11
#include <thread> // c++11

using namespace std;
using namespace std::chrono;

int main(void)
{
    time_point<system_clock> t = system_clock::now(); // definiuje czas. Punkt czasowy<klasa zegara> zmienna = <klasa zegara> w aktualnej chwili. - Po prostu pobiera aktualny czas systemowy i zapisuje go pod zmienna t.
    srand(time(NULL));
    int czyszczenie = 1, a, pktg1 = 0, pktg2 = 0, muzyka = 1, u = 0, fullscreen = 0, pwrup1, pwrup2, pwrup3 = 1, pwrup4 = 0, pwrup5 = 0;
    float q = 0.1, stangry[5][10], stangry2[20];
    const sf::Vector2i okno(1440, 900); // wektor wymiarow okna
    sf::RenderWindow oknogry(sf::VideoMode(okno.x, okno.y), "Pong by Aleksander Makowka"); //sf::Style::Fullscreen
    //oknogry.setVerticalSyncEnabled(false);
    //oknogry.setFramerateLimit(60);

    sf::Texture tlo;
    tlo.loadFromFile("pongbg.jpg");

    sf::Font fontmenu;
    fontmenu.loadFromFile("Amatic-Bold.ttf");

    sf::Font fonttytul;
    fonttytul.loadFromFile("LLPIXEL.ttf");

    //plansza
    //sf::RectangleShape plansza;
    //plansza.setSize(sf::Vector2f(okno.x,okno.y-40));
    //plansza.setPosition(sf::Vector2f(20,40));
    //plansza.setFillColor(sf::Color::White);
    //plansza.setTexture(&tlo);

    //tlo
    sf::RectangleShape tlo1;
    tlo1.setSize(sf::Vector2f(1, okno.y));
    tlo1.setFillColor(sf::Color(255, 255, 255));
    tlo1.setPosition(sf::Vector2f(okno.x / 2, 0));

    //pasek menu
    sf::RectangleShape pasek;
    pasek.setSize(sf::Vector2f(okno.x, 40));
    pasek.setFillColor(sf::Color(200, 200, 200));
    pasek.setPosition(sf::Vector2f(0, 0));

    //tekst gracz niebieski
    sf::Text textn;
    textn.setFont(fonttytul);
    textn.setCharacterSize(30);
    textn.setColor(sf::Color::Black);
    textn.setStyle(sf::Text::Regular);
    textn.setPosition(sf::Vector2f(0, 0));

    //tekst gracz czerwony
    sf::Text textc;
    textc.setFont(fonttytul);
    textc.setCharacterSize(30);
    textc.setColor(sf::Color::Black);
    textc.setStyle(sf::Text::Regular);
    textc.setPosition(sf::Vector2f(okno.x - 175, 0));

    //gracz 1
    sf::RectangleShape gracz1;
    gracz1.setSize(sf::Vector2f(20, 200));
    gracz1.setFillColor(sf::Color(150, 150, 150));
    gracz1.setPosition(sf::Vector2f(10, (okno.y / 2) - 100));

    //gracz 2
    sf::RectangleShape gracz2;
    gracz2.setSize(sf::Vector2f(20, 200));
    gracz2.setFillColor(sf::Color(150, 150, 150));
    gracz2.setPosition(sf::Vector2f(okno.x - 30, (okno.y / 2) - 100));

    //pilka
    sf::CircleShape pilka;
    pilka.setRadius(20);
    pilka.setFillColor(sf::Color(255, 255, 255));
    pilka.setOrigin(20, 20);
    sf::Vector2f pb((okno.x / 2), (okno.y / 2)); // wektor polozenia bazowego pilki
    sf::Vector2f v(0.1, 0.1); // wektor predkosci pilki

    //// do dopisania !

    //przeszkoda 1
    sf::RectangleShape przeszkoda1;
    przeszkoda1.setSize(sf::Vector2f(50, 100));
    przeszkoda1.setFillColor(sf::Color(185, 100, 155));
    //przeszkoda 2
    sf::RectangleShape przeszkoda2;
    przeszkoda2.setSize(sf::Vector2f(50, 100));
    przeszkoda2.setFillColor(sf::Color(185, 100, 155));
    //przeszkoda 3
    sf::RectangleShape przeszkoda3;
    przeszkoda3.setSize(sf::Vector2f(50, 100));
    przeszkoda3.setFillColor(sf::Color(185, 100, 155));

    sf::Texture ppwrup;
    ppwrup.loadFromFile("pup.png");

    //power up!
    sf::CircleShape powrup;
    powrup.setTexture(&ppwrup);
    powrup.setRadius(20);
    powrup.setFillColor(sf::Color(0, 200, 200));
    powrup.setOrigin(10, 10);
    sf::Vector2f pup((okno.x / 2), 40);
    sf::Vector2f vpup(0, 1);

    /////////////////////////////////////////////////////////////////////////////

    //muzyka!

    //muzyka w tle
    sf::Music muzykatlo;
    muzykatlo.openFromFile("pong.wav");
    muzykatlo.setVolume(20);
    muzykatlo.setLoop(true);

    //muzyka odbicie
    sf::Music odbicie;
    odbicie.openFromFile("odbicie.wav");
    odbicie.setVolume(100);

    //muzyka przyspieszenie
    sf::Music pwrup;
    pwrup.openFromFile("pwrup.wav");
    pwrup.setVolume(100);

    //muzyka strata punktu
    sf::Music stratapkt;
    stratapkt.openFromFile("stratapkt.wav");
    stratapkt.setVolume(100);

    //muzyka kolizja z power up
    sf::Music kolpwrup;
    kolpwrup.openFromFile("kolpwrup.wav");
    kolpwrup.setVolume(100);

    sf::Texture button;
    button.loadFromFile("button.png");

    //Gracz Vs. Gracz
    sf::Sprite button1;
    button1.setTexture(button);
    button1.setPosition((okno.x / 2), (okno.y / 2) - 175);
    button1.setOrigin(sf::Vector2f(button1.getTexture()->getSize().x * 0.5, button1.getTexture()->getSize().y * 0.5));
    button1.setScale(0.5, 0.5);
    sf::Color cbutton1 = button1.getColor();

    sf::Text textgvg;
    textgvg.setFont(fontmenu);
    textgvg.setCharacterSize(70);
    textgvg.setColor(sf::Color::White);
    textgvg.setStyle(sf::Text::Regular);
    textgvg.setPosition(sf::Vector2f((okno.x / 2) - 120, (okno.y / 2) - 230));
    textgvg.setString("Gracz Vs. Gracz");

    //Gracz Vs.Komputer
    sf::Sprite button2;
    button2.setTexture(button);
    button2.setPosition((okno.x / 2), (okno.y / 2));
    button2.setOrigin(sf::Vector2f(button2.getTexture()->getSize().x * 0.5, button2.getTexture()->getSize().y * 0.5));
    button2.setScale(0.5, 0.5);
    sf::Color cbutton2 = button2.getColor();

    sf::Text textgvk;
    textgvk.setFont(fontmenu);
    textgvk.setCharacterSize(70);
    textgvk.setColor(sf::Color::White);
    textgvk.setStyle(sf::Text::Regular);
    textgvk.setPosition(sf::Vector2f((okno.x / 2) - 120, (okno.y / 2) - 50));
    textgvk.setString("Gracz Vs. Komp");

    //Wyjscie
    sf::Sprite button3;
    button3.setTexture(button);
    button3.setPosition((okno.x / 2), (okno.y / 2) + 175);
    button3.setOrigin(sf::Vector2f(button3.getTexture()->getSize().x * 0.5, button3.getTexture()->getSize().y * 0.5));
    button3.setScale(0.5, 0.5);
    sf::Color cbutton3 = button3.getColor();

    sf::Text textquit;
    textquit.setFont(fontmenu);
    textquit.setCharacterSize(70);
    textquit.setColor(sf::Color::White);
    textquit.setStyle(sf::Text::Regular);
    textquit.setPosition(sf::Vector2f((okno.x / 2) - 80, (okno.y / 2) + 120));
    textquit.setString("Wyjscie");

    //Kontynuuj
    sf::Sprite button4;
    button4.setTexture(button);
    button4.setPosition(200, (okno.y / 2) - 175);
    button4.setOrigin(sf::Vector2f(button4.getTexture()->getSize().x * 0.5, button4.getTexture()->getSize().y * 0.5));
    button4.setScale(0.2, 0.2);
    sf::Color cbutton4 = button4.getColor();

    sf::Text textk;
    textk.setFont(fontmenu);
    textk.setCharacterSize(30);
    textk.setColor(sf::Color::White);
    textk.setStyle(sf::Text::Regular);
    textk.setPosition(sf::Vector2f(160, (okno.y / 2) - 200));
    textk.setString("Kontynuuj");

    //Tytul
    sf::Text texttytul;
    texttytul.setFont(fonttytul);
    texttytul.setCharacterSize(120);
    texttytul.setColor(sf::Color::White);
    texttytul.setStyle(sf::Text::Regular);
    texttytul.setPosition(sf::Vector2f((okno.x / 2) - 180, 0));
    texttytul.setString("PONG");

    //podpis
    sf::Text textpodp;
    textpodp.setFont(fonttytul);
    textpodp.setCharacterSize(10);
    textpodp.setColor(sf::Color::White);
    textpodp.setStyle(sf::Text::Regular);
    textpodp.setPosition(sf::Vector2f((okno.x / 2) - 180, 125));
    textpodp.setString("Aleksander Makowka");

    //menuglowne podpowiedz
    sf::Text textpdp;
    textpdp.setFont(fonttytul);
    textpdp.setCharacterSize(10);
    textpdp.setColor(sf::Color::White);
    textpdp.setStyle(sf::Text::Regular);
    textpdp.setPosition(sf::Vector2f(2, okno.y - 12));
    textpdp.setString("wcisnij  ESC by wyjsc z gry | wcisnij  F12 by wlaczyc/wylaczyc pelny ekran");

    //podpowiedz (pasek)
    sf::Text textpdpp;
    textpdpp.setFont(fonttytul);
    textpdpp.setCharacterSize(30);
    textpdpp.setColor(sf::Color::Black);
    textpdpp.setStyle(sf::Text::Regular);
    textpdpp.setPosition(sf::Vector2f((okno.x / 2) - 180, 0));
    textpdpp.setString("wcisnij F5 by wrocic do menu");

    while (oknogry.isOpen()) // petla glowna
    {
        oknogry.display();

        if (czyszczenie == 1)
            ;
        {
            czyszczenie = 0;
            oknogry.clear();
        }
        sf::Event event; // magazyn zdarzen
        while (oknogry.pollEvent(event)) {

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                oknogry.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F12) {
                if (fullscreen == 1) {
                    fullscreen = 0;
                    oknogry.create(sf::VideoMode(okno.x, okno.y), "Pong by Aleksander Makowka", sf::Style::Default);
                }
                else if (fullscreen == 0) {
                    fullscreen = 1;
                    oknogry.create(sf::VideoMode(okno.x, okno.y), "Pong by Aleksander Makowka", sf::Style::Fullscreen);
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                oknogry.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
                oknogry.clear();
                pb.x = (okno.x / 2);
                pb.y = (okno.y / 2);
                v.x = 0.15;
                v.y = 0.15;
                gracz2.setPosition(sf::Vector2f(okno.x - 10, (okno.y / 2) - 100));
                gracz1.setPosition(sf::Vector2f(0, (okno.y / 2) - 100));
                u = 0;
                pktg1 = 0;
                pktg2 = 0;
            }

            if (muzyka == 1) {
                muzyka = 0;
                muzykatlo.play();
            }

            //zamykanie okna
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                oknogry.close();
            }

            if (event.type == sf::Event::Closed) {
                oknogry.close();
            }
            // koniec zamykanie okna
        } //koniec petli zdarzen
        // menu glowne
        sf::FloatRect kbutton1(button1.getGlobalBounds());
        sf::FloatRect kbutton2(button2.getGlobalBounds());
        sf::FloatRect kbutton3(button3.getGlobalBounds());
        sf::FloatRect kbutton4(button4.getGlobalBounds());

        if (u == 0) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2f pozmyszy(sf::Mouse::getPosition(oknogry));
                //cout<<pozmyszy.x<<" "<<pozmyszy.y<<endl;
                if (kbutton1.contains(pozmyszy)) {
                    u = 1;
                    oknogry.clear();
                }
                if (kbutton2.contains(pozmyszy)) {
                    u = 2;
                    oknogry.clear();
                }
                if (kbutton3.contains(pozmyszy)) {
                    u = 3;
                    oknogry.clear();
                }
                if (kbutton4.contains(pozmyszy)) {
                    u = 4;
                    oknogry.clear();
                }
            }
        }
        sf::Vector2f pozmyszy(sf::Mouse::getPosition(oknogry));

        if (kbutton1.contains(pozmyszy)) {
            button1.setColor(sf::Color(200, 200, 200));
        }
        else if (kbutton1.contains(pozmyszy) == false) {
            button1.setColor(cbutton1);
        }

        if (kbutton2.contains(pozmyszy)) {
            button2.setColor(sf::Color(200, 200, 200));
        }
        else if (kbutton2.contains(pozmyszy) == false) {
            button2.setColor(cbutton2);
        }

        if (kbutton3.contains(pozmyszy)) {
            button3.setColor(sf::Color(200, 200, 200));
        }
        else if (kbutton3.contains(pozmyszy) == false) {
            button3.setColor(cbutton3);
        }

        if (kbutton4.contains(pozmyszy)) {
            button4.setColor(sf::Color(200, 200, 200));
        }
        else if (kbutton4.contains(pozmyszy) == false) {
            button4.setColor(cbutton4);
        }

        if (u == 1) {
            //Napisy na pasku
            ostringstream ssn;
            //ss<<"X: "<<pb.x<<"   "<<"Y: "<<pb.y<<" "<<"Vx: "<<v.x<<" "<<"a: "<<a<<endl;
            ssn << "Gracz 1: " << pktg1 << endl;
            textn.setString(ssn.str());

            ostringstream ssc;
            ssc << "Gracz 2: " << pktg2 << endl;
            textc.setString(ssc.str());

            //ruch kulki

            ///Kolizja!

            sf::FloatRect kgracz1(gracz1.getGlobalBounds());
            sf::FloatRect kgracz2(gracz2.getGlobalBounds());
            sf::FloatRect kpilka(pilka.getGlobalBounds());
            sf::FloatRect kpwrup(powrup.getGlobalBounds());

            /// poruszanie sie pilki z odbijaniem.

            //for(int i=0;i<1;i++) //////////// petla gry gracz vs gracz
            //{

            if (v.x < 0 && q > 0) {
                q *= -1;
            }
            if (v.x > 0 && q < 0) {
                q *= -1;
            }

            if (v.x > 0 && v.x < 15) {
                v.x = v.x + q; // predkosc x + stala q
            }
            else if (v.x < 0 && v.x > -15) {
                v.x = v.x + q; // predkosc x + stala q
            }

            if (v.y < 0 && q > 0) {
                q *= -1;
            }
            if (v.y > 0 && q < 0) {
                q *= -1;
            }

            if (v.y > 0 && v.y < 15) {
                v.y = v.y + q;
            }
            else if (v.y < 0 && v.y > -15) {
                v.y = v.y + q;
            }

            pb.x += v.x; // pozycja bazowa x zwiekszana o predkosc x
            pb.y += v.y;
            pilka.setPosition(pb.x, pb.y);
            sf::Vector2f pz = pilka.getPosition(); // wektor pozycji po zmianie
            sf::Vector2f g2kpz((pz.x + 20), (pz.y));
            sf::Vector2f g1kpz((pz.x - 20), (pz.y));
            //cout<<pz.x<<" "<<pz.y<<" "<<v.x<<endl;
            if (pz.y >= okno.y - 20) // kolizja z dolem
            {
                v.y *= -1;
            }
            if (pz.y <= 60) // kolizja z gora
            {
                v.y *= -1;
            }
            if (kgracz2.contains(g2kpz)) // kolizja z graczem 2
            {
                //pilka.move(sf::Vector2f(pz.x - 1000, pz.y));
                odbicie.play();
                v.x *= -1;
                q *= -1;
                a = rand() % 3;
                if (a == 1) {
                    pwrup.play();
                    a = 5;
                    v.y *= -1;
                }
            }
            if (kgracz1.contains(g1kpz)) // kolizja z graczem 1
            {
                //pilka.setPosition(sf::Vector2f(pz.x + 1, pz.y));
                odbicie.play();
                v.x *= -1;
                q *= -1;
                a = rand() % 3;
                if (a == 1) {
                    pwrup.play();
                    a = 5;
                    v.y = v.y + 1;
                    v.y *= -1;
                }
            }
            sf::Vector2f pzpup = powrup.getPosition();
            if (kpwrup.contains(pz)) // kolizja z powrup
            {
                kolpwrup.play();
                pwrup2 = 0;
                pup.x = (okno.x / 2); //
                pup.y = 0; //
                powrup.setPosition(pup.x, pup.y); //
                pwrup5 = 1;
            }
            //cout<<pb.x<<" "<<pb.y<<endl;
            //cout<<pzpup.x<<" "<<pzpup.y<<endl;
            //cout<<pwrup5<<endl;
            //cout<<pwrup4<<endl;
            if (pwrup5 == 1) {
                pwrup4 = rand() % 4;
                if (pwrup4 == 0) {
                    pilka.setFillColor(sf::Color(0, 0, 0));
                }
                else if (pwrup4 == 1) {
                    pilka.setFillColor(sf::Color(255, 255, 255));
                }
            }
            /// power up!
            if (pwrup3 == 1) {
                pwrup1 = rand() % 1000;
            }
            if (pwrup1 == 100) {
                pwrup1 = 0;
                pwrup2 = 1;
                pwrup3 = 0;
            }
            if (pwrup2 == 1) {
                powrup.setPosition(pup.x, pup.y);
                pup.y += vpup.y;
                if (pup.y >= okno.y) {
                    pup.y = 0;
                }
            }
            ////////////////////////////////////////////////////////////////////////////////////////////////////////

            // wygrana graczy
            if (pz.x >= okno.x - 20) // kolizja ze sciana za graczem 2
            {
                stratapkt.play();
                pktg1 = pktg1 + 1;
                pwrup3 = 1; //
                pwrup2 = 0; //
                pwrup5 = 0; //
                pwrup4 = 0; //
                pup.x = (okno.x / 2); //
                pup.y = 0; //
                pilka.setFillColor(sf::Color(255, 255, 255)); //
                powrup.setPosition(pup.x, pup.y); //
                if (v.x > 0) {
                    v.x = 0.15;
                }
                if (v.x < 0) {
                    v.x = -0.15;
                }
                if (v.y > 0) {
                    v.y = 0.15;
                }
                if (v.y < 0) {
                    v.y = -0.15;
                }
                pb.x = (okno.x / 2);
                pb.y = (okno.y / 2);
                usleep(500000);
            }
            if (pz.x <= 20) // kolizja ze sciana za graczem 1
            {
                stratapkt.play();
                pktg2 = pktg2 + 1;
                pwrup3 = 1; //
                pwrup2 = 0; //
                pwrup5 = 0; //
                pwrup4 = 0; //
                pup.x = (okno.x / 2); //
                pup.y = 0; //
                pilka.setFillColor(sf::Color(255, 255, 255)); //
                powrup.setPosition(pup.x, pup.y); //
                if (v.x > 0) {
                    v.x = 0.15;
                }
                if (v.x < 0) {
                    v.x = -0.15;
                }
                if (v.y > 0) {
                    v.y = 0.15;
                }
                if (v.y < 0) {
                    v.y = -0.15;
                }
                pb.x = (okno.x / 2);
                pb.y = (okno.y / 2);
                usleep(500000);
            }

            //} // koniec petli gracz vs gracz
            //koniec poruszania sie pilki
            //ruchy graczy
            sf::Vector2f pozgracz1 = gracz1.getPosition(); // wektor pozycji gracza1
            // ruch w dol
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (pozgracz1.y <= okno.y - 200) {
                    gracz1.move(0, 8);
                }
                else if (pozgracz1.y > okno.y) {
                } // nic nie rob.
            }
            // koniec ruchu w dol
            // ruch do gory
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (pozgracz1.y >= 48) {
                    gracz1.move(0, -8);
                }
                else if (pozgracz1.y < 48) {
                } // nic nie rob.
            }

            sf::Vector2f pozgracz2 = gracz2.getPosition(); // wektor pozycji gracza2
            // ruch w dol
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                if (pozgracz2.y <= okno.y - 200) {
                    gracz2.move(0, 8);
                }
                else if (pozgracz2.y > okno.y) {
                } // nic nie rob.
            }
            // koniec ruchu w dol
            // ruch do gory
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                if (pozgracz2.y >= 48) {
                    gracz2.move(0, -8);
                }
                else if (pozgracz2.y < 48) {
                } // nic nie rob.
            }
            //// zapisywanie ostatniego stanu gry
            stangry[0][0] = pb.x;
            stangry[0][1] = pb.y;
            stangry[0][2] = v.x;
            stangry[0][3] = v.y;
            stangry[1][0] = gracz1.getPosition().y;
            stangry[1][1] = pktg1;
            stangry[2][0] = gracz2.getPosition().y;
            stangry[2][1] = pktg2;
            stangry[3][0] = u;

            ofstream fout("zapis.dat");
            fout << stangry[0][0] << endl
                 << stangry[0][1] << endl
                 << stangry[0][2] << endl
                 << stangry[0][3] << endl;
            fout << stangry[1][0] << endl
                 << stangry[1][1] << endl;
            fout << stangry[2][0] << endl
                 << stangry[2][1] << endl;
            fout << stangry[3][0] << endl;
            ///// [0][x] - pilka. [1][x] - gracz1. [2][x] - gracz2. [3][x] - tryb wybranej rozgrywki

            // koniec ruchow graczy
        }
        ////////////////////////////////////////////////////////////////
        if (u == 2) {
            //Napisy na pasku
            ostringstream ssn;
            //ss<<"X: "<<pb.x<<"   "<<"Y: "<<pb.y<<" "<<"Vx: "<<v.x<<" "<<"a: "<<a<<endl;
            ssn << "Gracz 1: " << pktg1 << endl;
            textn.setString(ssn.str());

            ostringstream ssc;
            ssc << "Gracz 2: " << pktg2 << endl;
            textc.setString(ssc.str());

            //ruch kulki

            ///Kolizja!

            sf::FloatRect kgracz1(gracz1.getGlobalBounds());
            sf::FloatRect kgracz2(gracz2.getGlobalBounds());
            sf::FloatRect kpilka(pilka.getGlobalBounds());
            sf::FloatRect kpwrup(powrup.getGlobalBounds());

            /// poruszanie sie pilki z odbijaniem.

            //for(int i=0;i<20;i++)  // petla gry gracz vs komputer
            //{
            if (v.x < 0 && q > 0) {
                q *= -1;
            }
            if (v.x > 0 && q < 0) {
                q *= -1;
            }

            if (v.x > 0 && v.x < 15) {
                v.x = v.x + q; // predkosc x + stala q
            }
            else if (v.x < 0 && v.x > -15) {
                v.x = v.x + q; // predkosc x + stala q
            }

            if (v.y < 0 && q > 0) {
                q *= -1;
            }
            if (v.y > 0 && q < 0) {
                q *= -1;
            }

            if (v.y > 0 && v.y < 15) {
                v.y = v.y + q;
            }
            else if (v.y < 0 && v.y > -15) {
                v.y = v.y + q;
            }

            pb.x += v.x; // pozycja bazowa x zwiekszana o predkosc x
            pb.y += v.y;
            pilka.setPosition(pb.x, pb.y);
            sf::Vector2f pz = pilka.getPosition(); // wektor pozycji po zmianie
            sf::Vector2f g2kpz((pz.x + 20), (pz.y));
            sf::Vector2f g1kpz((pz.x - 20), (pz.y));
            //cout<<pz.x<<" "<<pz.y<<" "<<v.x<<endl;
            if (pz.y >= okno.y - 20) // kolizja z dolem
            {
                v.y *= -1;
            }
            if (pz.y <= 60) // kolizja z gora
            {
                v.y *= -1;
            }
            if (kgracz2.contains(g2kpz)) // kolizja z graczem 2
            {
                //pilka.move(sf::Vector2f(pz.x - 1000, pz.y));
                odbicie.play();
                v.x *= -1;
                q *= -1;
                a = rand() % 2;
                if (a == 1) {
                    pwrup.play();
                    a = 5;
                    v.y = v.y + 3;
                    v.y *= -1;
                }
            }
            if (kgracz1.contains(g1kpz)) // kolizja z graczem 1
            {
                //pilka.setPosition(sf::Vector2f(pz.x + 1, pz.y));
                odbicie.play();
                v.x *= -1;
                q *= -1;
                a = rand() % 2;
                if (a == 1) {
                    pwrup.play();
                    a = 5;
                    if (v.y > 0) {
                        v.y = v.y + 1;
                    }
                    if (v.y < 0) {
                        v.y = v.y - 1;
                    }
                    v.y *= -1;
                }
            }
            sf::Vector2f pzpup = powrup.getPosition();
            if (kpwrup.contains(pz)) // kolizja z powrup
            {
                kolpwrup.play();
                pwrup2 = 0;
                pup.x = (okno.x / 2); //
                pup.y = 0; //
                powrup.setPosition(pup.x, pup.y); //
                pwrup5 = 1;
            }
            //cout<<pb.x<<" "<<pb.y<<endl;
            //cout<<pzpup.x<<" "<<pzpup.y<<endl;
            //cout<<pwrup5<<endl;
            //cout<<pwrup4<<endl;
            if (pwrup5 == 1) {
                pwrup4 = rand() % 4;
                if (pwrup4 == 0) {
                    pilka.setFillColor(sf::Color(0, 0, 0));
                }
                else if (pwrup4 == 1) {
                    pilka.setFillColor(sf::Color(255, 255, 255));
                }
            }
            /// power up!
            if (pwrup3 == 1) {
                pwrup1 = rand() % 1000;
            }
            if (pwrup1 == 100) {
                pwrup1 = 0;
                pwrup2 = 1;
                pwrup3 = 0;
            }
            if (pwrup2 == 1) {
                powrup.setPosition(pup.x, pup.y);
                pup.y += vpup.y;
                if (pup.y >= okno.y) {
                    pup.y = 0;
                }
            }
            // wygrana graczy
            if (pz.x >= okno.x - 20) // kolizja ze sciana za graczem 2
            {
                stratapkt.play();
                pktg1 = pktg1 + 1;
                pwrup3 = 1; //
                pwrup2 = 0; //
                pwrup5 = 0; //
                pwrup4 = 0; //
                pup.x = (okno.x / 2); //
                pup.y = 0; //
                pilka.setFillColor(sf::Color(255, 255, 255)); //
                powrup.setPosition(pup.x, pup.y); //
                if (v.x > 0) {
                    v.x = 0.25;
                }
                if (v.x < 0) {
                    v.x = -0.25;
                }
                if (v.y > 0) {
                    v.y = 0.25;
                }
                if (v.y < 0) {
                    v.y = -0.25;
                }
                pb.x = (okno.x / 2);
                pb.y = (okno.y / 2);
                usleep(500000);
            }
            if (pz.x <= 20) // kolizja ze sciana za graczem 1
            {
                stratapkt.play();
                pktg2 = pktg2 + 1;
                pwrup3 = 1; //
                pwrup2 = 0; //
                pwrup5 = 0; //
                pwrup4 = 0; //
                pup.x = (okno.x / 2); //
                pup.y = 0; //
                pilka.setFillColor(sf::Color(255, 255, 255)); //
                powrup.setPosition(pup.x, pup.y); //
                if (v.x > 0) {
                    v.x = 0.25;
                }
                if (v.x < 0) {
                    v.x = -0.25;
                }
                if (v.y > 0) {
                    v.y = 0.25;
                }
                if (v.y < 0) {
                    v.y = -0.25;
                }
                pb.x = (okno.x / 2);
                pb.y = (okno.y / 2);
                usleep(500000);
            }

            //}
            //koniec poruszania sie pilki
            //ruchy graczy
            sf::Vector2f pozgracz1 = gracz1.getPosition(); // wektor pozycji gracza1
            // ruch w dol
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (pozgracz1.y <= okno.y - 220) {
                    gracz1.move(0, 20);
                }
                else if (pozgracz1.y > okno.y) {
                } // nic nie rob.
            }
            // koniec ruchu w dol
            // ruch do gory
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (pozgracz1.y >= 60) {
                    gracz1.move(0, -20);
                }
                else if (pozgracz1.y < 60) {
                } // nic nie rob.
            }
            sf::Vector2f pz1 = pilka.getPosition(); // wektor pozycji pilki
            sf::Vector2f pozgracz2 = gracz2.getPosition(); // wektor pozycji gracza2
            // ruch w dol
            if (v.y >= 0) {
                if (pozgracz2.y < pz1.y - 60) {
                    if (pozgracz2.y <= okno.y - 220) {
                        gracz2.move(0, 20);
                    }
                    else if (pozgracz2.y > okno.y) {
                    } // nic nie rob.
                }
                // koniec ruchu w dol
            }
            // ruch do gory
            if (v.y < 0) {
                if (pozgracz2.y > pz1.y - 60) {
                    if (pozgracz2.y >= 59) {
                        gracz2.move(0, -20);
                    }
                    else if (pozgracz2.y < 60) {
                    } // nic nie rob.
                }
            }

            //// zapisywanie ostatniego stanu gry
            stangry[0][0] = pb.x;
            stangry[0][1] = pb.y;
            stangry[0][2] = v.x;
            stangry[0][3] = v.y;
            stangry[1][0] = gracz1.getPosition().y;
            stangry[1][1] = pktg1;
            stangry[2][0] = gracz2.getPosition().y;
            stangry[2][1] = pktg2;
            stangry[3][0] = u;

            ofstream fout("zapis.dat");
            fout << stangry[0][0] << endl
                 << stangry[0][1] << endl
                 << stangry[0][2] << endl
                 << stangry[0][3] << endl;
            fout << stangry[1][0] << endl
                 << stangry[1][1] << endl;
            fout << stangry[2][0] << endl
                 << stangry[2][1] << endl;
            fout << stangry[3][0] << endl;

            // koniec ruchow graczy
        }

        if (u == 3) // klikniecie buttonu (wyjscie)
        {
            oknogry.close();
        }

        if (u == 4) // klikniecie buttonu (kontynuuj)
        {
            ifstream fin("zapis.dat");

            fin >> stangry2[0];
            fin >> stangry2[1];
            fin >> stangry2[2];
            fin >> stangry2[3];
            fin >> stangry2[4];
            fin >> stangry2[5];
            fin >> stangry2[6];
            fin >> stangry2[7];
            fin >> stangry2[8];

            pb.x = stangry2[0];
            pb.y = stangry2[1];
            v.x = stangry2[2];
            v.y = stangry2[3];
            gracz1.setPosition(0, stangry2[4]);
            pktg1 = stangry2[5];
            gracz2.setPosition(okno.x - 30, stangry2[6]);
            pktg2 = stangry2[7];
            u = stangry2[8];

            cout << pb.x << endl;
            cout << pb.y << endl;
            cout << v.x << endl;
            cout << u << endl;
        }

        if (u == 0) {
            oknogry.draw(button1);
            oknogry.draw(button2);
            oknogry.draw(button3);
            oknogry.draw(button4);
            oknogry.draw(textgvg);
            oknogry.draw(textgvk);
            oknogry.draw(textquit);
            oknogry.draw(textk);
            oknogry.draw(textpdp);
            if (okno.x >= 1440 && okno.y >= 900) {
                oknogry.draw(texttytul);
                oknogry.draw(textpodp);
            }
        }

        if (u == 1) {
            //oknogry.draw(plansza);
            oknogry.draw(tlo1);
            oknogry.draw(powrup);
            oknogry.draw(pasek);
            oknogry.draw(gracz1);
            oknogry.draw(gracz2);
            oknogry.draw(pilka);
            oknogry.draw(textn);
            oknogry.draw(textc);
            oknogry.draw(textpdpp);
        }

        if (u == 2) {
            //oknogry.draw(plansza);
            oknogry.draw(tlo1);
            oknogry.draw(powrup);
            oknogry.draw(pasek);
            oknogry.draw(gracz1);
            oknogry.draw(gracz2);
            oknogry.draw(pilka);
            oknogry.draw(textn);
            oknogry.draw(textc);
            oknogry.draw(textpdpp);
        }
        t += milliseconds(17); /// ograniczenie fps (1000ms/60=~17)
        this_thread::sleep_until(t); /// ograniczenie fps z wykorzystaniem watkow. Zatrzymuje prace kodu dopoki nie minie 17ms.
    } // koniec petli glownej

    return 0;
}
