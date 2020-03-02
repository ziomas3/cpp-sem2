#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct przelaczniki //grupa zmiennych
{
    int poczekaj;
    int startczywznow;
    int glownemenu;
    int dzwiekoff;
    int gamepause;
    int menuopen;
};
void zapiszgre(int const &record)
{
    std::fstream plik;
    plik.open( "save/save.dat", ios::binary |ios::trunc | std::ios::out );
    if( plik.good() == true )
    {
        plik << record;
        plik.close();
    }
}
void wczytajgre(int &record)
{
    std::fstream plik;
    plik.open( "save/save.dat", std::ios::in | ios::binary );
    if( plik.good() == true )
    {
        plik >> record;
        plik.close();
    }
}
void przemiescwrogowizliczpunkty(float vw[],struct przelaczniki &stan,float sw[], float ww[], float &y, float &vy, int szerokosc, int &score, vector<sf::Sprite> &przeszkody, sf::FloatRect boxgracz, float y0, float x, sf::Sound &go)
{
//przemieszczanie przeciwnikow i wykrywanie kolizji oraz liczenie punktów.
    for(int i=0; i<przeszkody.size(); i++)
    {
        if (score<25)
            vw[i]=4; //predkosc lecenia wrogow ponizej 25 score
        if (sw[i]<-50) //gdy przeciwnik wyleci poza mape
        {
            sw[i]=szerokosc; // wroc go na poczatek
            ww[i]=rand() /float(RAND_MAX)*550; //ustaw mu losowa wysokosc
            if (score>25)
                vw[i]=rand() /float(RAND_MAX)* 5+2; //ustaw mu losowa predkosc 2-7 gdy score powyzej 25
        }
        sw[i]=sw[i]-vw[i]; //zmiana X wrogow (przemieszczenie)
        przeszkody[i].setPosition(sf::Vector2f(sw[i],ww[i])); //przemieszczenie wrogow (ustawienie wspolzednych)
        sf::FloatRect wrogBox = przeszkody[i].getGlobalBounds(); //ustawienie recta (obrysu)
        if (boxgracz.intersects(wrogBox)) //sprawdzenie kolizji
        {
            go.play(); //krzyk dziecka
            stan.poczekaj=0; //wlaczenie odliczania 3,2,1
            for (int i=0; i<9; i++) //ustawienie wszystkiego do pozycji poczatkowej
            {
                ww[i]=rand() /float(RAND_MAX)* 550;
                sw[i]=szerokosc+i*100;
                przeszkody[i].setPosition(sf::Vector2f(sw[i],ww[i]));
                y=y0;
                vy=0;
                score=0;
            }
        }
        if(sw[i]<=x+1&&sw[i]>=x-1) //gdy przeciwnik minie moja skladowa X to dodaje mi punkt
            score++;
    }

}
void ogarnijwynik(int const &score,sf::Text &wynik,sf::Font const &font,sf::String &strwynik,std::ostringstream &strint)
{
    //ogarnianie wyniku
    strwynik= "Wynik: ";
    strint << score;
    strwynik += strint.str(); //zmiana inta na stringa i dodanie do strwynik tzn "wynik" + numer
    wynik.setFont(font);
    wynik.setString(strwynik);
    wynik.setCharacterSize(30);
    wynik.setFillColor(sf::Color::White);
    wynik.setPosition(sf::Vector2f(25,0));
}
void ogarnijnajwynik(int const &record,sf::String &strnajwynik,sf::Text &najwynik,std::ostringstream &strnajint,sf::Font const &font)
{
    //to samo co wyzej tylko z najlepszym wynikiem
    strnajwynik= "Najlepszy wynik: ";
    strnajint << record;
    strnajwynik += strnajint.str();
    najwynik.setFont(font);
    najwynik.setString(strnajwynik);
    najwynik.setCharacterSize(30);
    najwynik.setFillColor(sf::Color::White);
    najwynik.setPosition(sf::Vector2f(500,0));
}
void ogarnijpauza (sf::String &pauza,sf::Text &pause,sf::Font const &font)
{
    //napis pauza

    pause.setFont(font);
    pause.setString(pauza);
    pause.setCharacterSize(50);
    pause.setFillColor(sf::Color::White);
    pause.setPosition(sf::Vector2f(320,300));
}
void ogarnijodliczanie(int odltxt,struct przelaczniki &stan,sf::Text &odliczanie,sf::Font const &font,sf::String &strodliczanie,std::ostringstream &strod)
{
    //odliczanie 3 2 1
    if (stan.poczekaj>0&&stan.poczekaj<50)
    {
        odltxt=3; //napisz 3
        strod << odltxt;
        strodliczanie = strod.str();
        odliczanie.setPosition(sf::Vector2f(380,150));
    }
    else if (stan.poczekaj>50&&stan.poczekaj<100)
    {
        odltxt=2; // napisz 2
        strod << odltxt;
        strodliczanie = strod.str();
        odliczanie.setPosition(sf::Vector2f(380,150));
    }
    else if (stan.poczekaj>100&&stan.poczekaj<150)
    {
        odltxt=1; // napisz 1
        strod << odltxt;
        strodliczanie = strod.str();
        odliczanie.setPosition(sf::Vector2f(380,150));
    }
    else if (stan.poczekaj>150&&stan.poczekaj<200)
    {
        strodliczanie="START!"; // napisz start
        odliczanie.setPosition(sf::Vector2f(280,150));
    }
    odliczanie.setFont(font);
    odliczanie.setString(strodliczanie);
    odliczanie.setCharacterSize(70);
    odliczanie.setFillColor(sf::Color::White);

}
void rysujplansze(struct przelaczniki &stan,sf::Text const &odliczanie,sf::RenderWindow &window,sf::Sprite const &tlo,sf::Text const &wynik,sf::Text const &najwynik,sf::Sprite const &shape,vector<sf::Sprite> const &przeszkody,sf::Text &pause, sf::Sprite const &start, sf::Sprite const &wznow, sf::Sprite const &opcje, sf::Sprite const &wyjdz,sf::Sprite const &dzwiek, sf::Sprite const &reset, sf::Sprite const &cofnij)
{
    //jesli zmienna menuopen ==0 to wyswietla gre
    if (!stan.menuopen)
    {
        window.draw(tlo);
        window.draw(wynik);
        window.draw(najwynik);
        window.draw(shape);
        for (int i=0; i<przeszkody.size(); i++)
            window.draw(przeszkody[i]);
        if (stan.poczekaj<200)
            window.draw(odliczanie);
        if (!stan.gamepause)
            window.draw(pause);
    }
    else //jesli menuopen==1 to wyswietla menu
    {
        if (stan.glownemenu) // jesli menuglowne ==1 to wyswietla menu glowne
        {
            window.draw(tlo);
            if (!stan.startczywznow)
                window.draw(start);
            else
                window.draw(wznow);
            window.draw(opcje);
            window.draw(wyjdz);
        }
        else // jesli menu glowne ==0 to wyswietla menu opcji
        {
            window.draw(tlo);
            window.draw(dzwiek);
            window.draw(reset);
            window.draw(cofnij);
        }
    }
    window.display();
}

void zdarzenia(sf::Texture &backgroundtexture, sf::Sprite &shape, float &x, float &y, float &y0, int &score, vector<sf::Sprite> &przeszkody,
               int const &szerokosc, float ww[], float sw[], int &record, sf::Music &music, struct przelaczniki &stan,
               sf::RenderWindow &window, sf::Event event, float &vy, sf::Sound &js, sf::Sound &go, sf::Sprite &start,
               sf::FloatRect &startrekt, sf::Sprite &wznow, sf::FloatRect &wznowrekt, sf::Sprite &opcje,
               sf::FloatRect &opcjerekt, sf::Sprite &wyjdz, sf::FloatRect &wyjdzrekt, sf::Sprite &dzwiek,
               sf::FloatRect &dzwiekrekt, sf::Sprite &reset, sf::FloatRect &resetrekt, sf::Sprite &cofnij,
               sf::FloatRect &cofnijrekt)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                if (!stan.glownemenu) //jesli wlacznone menu iocji (menuglowne==0) to przechodzi do menu glownego (menuglowne==1)
                    stan.glownemenu=1;
                else //jesli nie jest w menu opcji to wlacza lub wylacza menu glowne
                {
                    stan.poczekaj=0;
                    stan.gamepause=1-stan.gamepause;
                    stan.menuopen=1-stan.menuopen;
                }
            }
            else if (event.key.code == sf::Keyboard::P) // pauza
            {
                stan.poczekaj=0;
                stan.gamepause=1-stan.gamepause;
            }
            else if (event.key.code == sf::Keyboard::G) // dziwny efekt xD
            {
                backgroundtexture.update(window);
            }
            else // inne klawisze robia podbicie
            {
                vy=15;
                js.play();
            }
        }
        if(event.type == event.MouseButtonPressed &&stan.menuopen&& event.mouseButton.button == sf::Mouse::Left)
        {
            if (stan.glownemenu)
            {
                if(startrekt.contains(event.mouseButton.x, event.mouseButton.y) == true) // wcisniecie na start i tak dalej ...
                {
                    stan.poczekaj=0;
                    stan.gamepause=1-stan.gamepause;
                    stan.menuopen=0;
                    js.play();
                }
                if(opcjerekt.contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    stan.glownemenu=0;
                    js.play();
                }
                if(wyjdzrekt.contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    window.close();
                    js.play();
                }
            }
            else
            {
                if(dzwiekrekt.contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    stan.dzwiekoff=1-stan.dzwiekoff; //wciesniecie na dziwek zmienia wartosc dzwiekoff miedzy 0 a 1
                    if (stan.dzwiekoff) //dla jednego wycisza dzwieki
                    {
                        go.setVolume(0);
                        js.setVolume(0);
                        music.setVolume(0);
                    }
                    else //dla 0 odcisza dzwieki
                    {
                        go.setVolume(100);
                        js.setVolume(100);
                        music.setVolume(100);

                    }
                    js.play(); //dzwiek klikniecia
                }
                if(resetrekt.contains(event.mouseButton.x, event.mouseButton.y) == true) //resetowanei stanu gry
                {
                    record=0;
                    stan.startczywznow=0;
                    for (int i=0; i<9; i++)
                    {
                        ww[i]=rand() /float(RAND_MAX)* 550;
                        sw[i]=szerokosc+i*100;
                        przeszkody[i].setPosition(sf::Vector2f(sw[i],ww[i]));
                        y=y0;
                        vy=0;
                        score=0;
                    }
                    shape.setPosition(sf::Vector2f(x,y0));
                    js.play();
                }
                if(cofnijrekt.contains(event.mouseButton.x, event.mouseButton.y) == true)
                {
                    stan.glownemenu=1;
                    js.play();
                }
            }
        }
        else if(event.type == sf::Event::MouseMoved) // ten fragment odpowiada za podsweitlanie przyciskow po najechaniu na nie
        {
            if(startrekt.contains(event.mouseMove.x, event.mouseMove.y) == true)
            {
                start.setColor(sf::Color(255, 0, 0));
            }
            else
            {
                start.setColor(sf::Color(0, 0, 255));
            }

            if(wznowrekt.contains(event.mouseMove.x, event.mouseMove.y) == true)
            {
                wznow.setColor(sf::Color(255, 0, 0));
            }
            else
            {
                wznow.setColor(sf::Color(0, 0, 255));
            }
            if(opcjerekt.contains(event.mouseMove.x, event.mouseMove.y) == true)
            {
                opcje.setColor(sf::Color(255, 0, 0));
            }
            else
            {
                opcje.setColor(sf::Color(0, 0, 255));
            }
            if(wyjdzrekt.contains(event.mouseMove.x, event.mouseMove.y) == true)
            {
                wyjdz.setColor(sf::Color(255, 0, 0));
            }
            else
            {
                wyjdz.setColor(sf::Color(0, 0, 255));
            }
            if(dzwiekrekt.contains(event.mouseMove.x, event.mouseMove.y) == true)
            {

            }
            else
            {
                // fajna zmiana koloru przycisku od dzwieku :D
                if (stan.dzwiekoff)
                    dzwiek.setColor(sf::Color(255, 0, 0));
                else
                    dzwiek.setColor(sf::Color(0, 255, 0));
            }
            if(resetrekt.contains(event.mouseMove.x, event.mouseMove.y) == true)
            {
                reset.setColor(sf::Color(255, 0, 0));
            }
            else
            {
                reset.setColor(sf::Color(0, 0, 255));
            }
            if(cofnijrekt.contains(event.mouseMove.x, event.mouseMove.y) == true)
            {
                cofnij.setColor(sf::Color(255, 0, 0));
            }
            else
            {
                cofnij.setColor(sf::Color(0, 0, 255));
            }
        }

    }
}

void gra(float vw[],struct przelaczniki &stan, float &vy, float const &g, float const &dt, float &y, int &score, int &record, float const &yk, sf::Sound &go, float ww[], float sw[], vector<sf::Sprite> &przeszkody, int const &szerokosc, sf::FloatRect boxgracz, float y0, float &x, sf::Sprite &shape)
{
    stan.startczywznow=1;
    vy=vy+g*dt;
    y=y-vy*dt;
    if (score>record) // jesli score wiekszy niz record przypisz recordowi scoe
        record=score;
    if(y>yk) //jesli gracz spadnie poza mape
    {
        go.play();
        stan.poczekaj=0;
        for (int i=0; i<9; i++)
        {
            ww[i]=rand() /float(RAND_MAX)*550;
            sw[i]=szerokosc+i*100;
            przeszkody[i].setPosition(sf::Vector2f(sw[i],ww[i]));
            y=y0;
            vy=0;
            score=0;
        }
    }
    if (y<0) // ograniczenie by nie wyskoczyl ponad mape
        y=0;
    przemiescwrogowizliczpunkty(vw,stan,sw,ww,y,vy,szerokosc,score,przeszkody,boxgracz,y0,x,go);
    shape.setPosition(sf::Vector2f(x,y)); // ustawienie mojego ziomka
}
int main()
{



    int data[0];


    sf::UdpSocket socket;

// bind the socket to a port
    if (socket.bind(54000) != sf::Socket::Done)
    {
        // error...
    }








    //deklarowanie zmiennych
    struct przelaczniki stan;
    stan.poczekaj=0;
    stan.startczywznow=0;
    stan.glownemenu=1;
    stan.dzwiekoff=0;
    stan.gamepause=0;
    stan.menuopen=1;

    srand(time(NULL));
    float vw[20];
    float ww[20];
    float sw[20];
    int szerokosc=800;
    int wysokosc=600;
    int promien=20;
    float x=szerokosc/2-promien;
    float y0=wysokosc/2-2*promien;

    float vy=0, dt=0.91, g=-1;
    float y=y0;
    int score=0;
    int record=0;
    int odltxt=3;
//wczytaj gre
    wczytajgre(record);
//textura doge
    sf::Texture doge;
    if (!doge.loadFromFile("rocket.png"))
    {
        return -3;
    }
    doge.setSmooth(true);
    float yk=wysokosc-doge.getSize().y;
//texture enemy
    sf::Texture enemy;
    if (!enemy.loadFromFile("asteroid.png"))
    {
        return -3;
    }
    enemy.setSmooth(true);
//background
    sf::Texture backgroundtexture;
    if (!backgroundtexture.loadFromFile("background.jpg", sf::IntRect(0, -20, 800, 600 )))

    {
        return -2;
    }
    backgroundtexture.setSmooth(true);
//texture startbutton
    sf::Texture txstart;
    if (!txstart.loadFromFile("start.png"))
    {
        return -3;
    }
    txstart.setSmooth(true);
//texture wznowbutton
    sf::Texture txwznow;
    if (!txwznow.loadFromFile("wznow.png"))
    {
        return -3;
    }
    txwznow.setSmooth(true);
//texture opcjebutton
    sf::Texture txopcje;
    if (!txopcje.loadFromFile("opcje.png"))
    {
        return -3;
    }
    txopcje.setSmooth(true);
//texture wyjdzbutton
    sf::Texture txwyjdz;
    if (!txwyjdz.loadFromFile("wyjdz.png"))
    {
        return -3;
    }
    txwyjdz.setSmooth(true);
//texture dzwiekbutton
    sf::Texture txdzwiek;
    if (!txdzwiek.loadFromFile("dzwiek.png"))
    {
        return -3;
    }
    txdzwiek.setSmooth(true);
//texture resetbutton
    sf::Texture txreset;
    if (!txreset.loadFromFile("reset.png"))
    {
        return -3;
    }
    txreset.setSmooth(true);
//texture resetbutton
    sf::Texture txcofnij;
    if (!txcofnij.loadFromFile("cofnij.png"))
    {
        return -3;
    }
    txcofnij.setSmooth(true);
//spirit
    sf::Sprite shape;
    shape.setTexture(doge);
    shape.setPosition(sf::Vector2f(x,y));
//menu
//start
    sf::Sprite start;
    start.setTexture(txstart);
    start.setPosition(sf::Vector2f(350,150));
    sf::FloatRect startrekt = start.getGlobalBounds();
//wznow
    sf::Sprite wznow;
    wznow.setTexture(txwznow);
    wznow.setPosition(sf::Vector2f(350,150));
    sf::FloatRect wznowrekt = wznow.getGlobalBounds();
//opcje
    sf::Sprite opcje;
    opcje.setTexture(txopcje);
    opcje.setPosition(sf::Vector2f(350,250));
    sf::FloatRect opcjerekt = opcje.getGlobalBounds();
//wyjdz
    sf::Sprite wyjdz;
    wyjdz.setTexture(txwyjdz);
    wyjdz.setPosition(sf::Vector2f(350,350));
    sf::FloatRect wyjdzrekt = wyjdz.getGlobalBounds();
//dzwiek
    sf::Sprite dzwiek;
    dzwiek.setTexture(txdzwiek);
    dzwiek.setPosition(sf::Vector2f(350,150));
    sf::FloatRect dzwiekrekt = dzwiek.getGlobalBounds();
//reset
    sf::Sprite reset;
    reset.setTexture(txreset);
    reset.setPosition(sf::Vector2f(350,250));
    sf::FloatRect resetrekt = reset.getGlobalBounds();
//cofnij
    sf::Sprite cofnij;
    cofnij.setTexture(txcofnij);
    cofnij.setPosition(sf::Vector2f(350,350));
    sf::FloatRect cofnijrekt = cofnij.getGlobalBounds();
//dzwieki
    sf::SoundBuffer jumpsound;
    jumpsound.loadFromFile("jump.wav");
    sf::Sound js;
    js.setBuffer(jumpsound);
    sf::SoundBuffer death;
    death.loadFromFile("gameover.ogg");
    sf::Sound go;
    go.setBuffer(death);

    sf::Sprite tlo;
    tlo.setTexture(backgroundtexture);
//tworzenie przeciwnikow

    vector<sf::Sprite> przeszkody;
    for (int i=0; i<9; i++)
    {
        ww[i]=rand() /float(RAND_MAX)*550;
        przeszkody.push_back(sf::Sprite());
        sw[i]=szerokosc+i*100;
        przeszkody[i].setPosition(sf::Vector2f(sw[i],ww[i]));
        przeszkody[i].setTexture(enemy);
    }
//muzyka
    sf::Music music;
    if (!music.openFromFile("music.wav"))
        return -1;
    music.play();
    music.setLoop(true);
//deklaracja czcionki
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))return -1;


//napis PAUZA
    sf::String pauza;
    pauza= "PAUZA";
    sf::Text pause;
//deklaracaj event
    sf::Event event;
    //textura tlo_s_txt
    sf::Texture piestxt;
    if (!piestxt.loadFromFile("tlo_s.jpg"))
    {
        return -3;
    }
    piestxt.setSmooth(true);

//spirity do animacji poczatkowej
    vector<sf::Sprite> pies(180);
    for (int i=0; i<=181; i++)
    {

        pies[i].setTexture(piestxt);
        pies[i].setPosition(sf::Vector2f(400,300));
        pies[i].setScale(sf::Vector2f(0.5f, 0.5f));
        for(int j=0; j<i; j++)
        {
            pies[i].rotate(2);
            pies[i].scale(sf::Vector2f(0.99f, 0.99f));
        }
    }
//spirit gracza
    sf::Sprite tlo_s;
    tlo_s.setTexture(piestxt);
    tlo_s.setPosition(sf::Vector2f(0,0));
    int animacja_startowa=1;
//ustawienia okna
    sf::RenderWindow window(sf::VideoMode(szerokosc,wysokosc), "FlappyBilon®");
    window.setFramerateLimit(50);
//Początek pętli okna
    while (window.isOpen())
    {
        data[0]=record;
        // UDP socket:
        sf::IpAddress recipient = "188.116.46.20";
        unsigned short port = 54000;
        if (socket.send(data, 1, recipient, port) != sf::Socket::Done)
        {
            // error...
        }


        if (animacja_startowa) // animacja poczatkowa
        {
            for (int i=1; i<360/2; i++)
            {
                window.clear();
                window.draw(tlo_s);
                for(int j=1; j<=i; j++)
                {
                    window.draw(pies[j]);
                }
                window.display();
                animacja_startowa=0;
            }
        }
        //zapis wyniku
        zapiszgre(record);
        //napisy
        //wynik
        sf::Text wynik;
        sf::String strwynik;
        std::ostringstream strint;
        //najwynik
        sf::String strnajwynik;
        sf::Text najwynik;
        std::ostringstream strnajint;
        //odliczanie
        sf::Text odliczanie;
        sf::String strodliczanie;
        std::ostringstream strod;
        ogarnijwynik(score,wynik,font,strwynik,strint);
        ogarnijodliczanie(odltxt,stan,odliczanie,font,strodliczanie,strod);
        ogarnijnajwynik(record,strnajwynik,najwynik,strnajint,font);
        ogarnijpauza(pauza,pause,font);
        //./napisy
        sf::FloatRect boxgracz = shape.getGlobalBounds();
        //event
        zdarzenia(backgroundtexture,shape,x,y,y0,score,przeszkody,szerokosc,ww,sw,record,music,stan,window,event,vy,js,go,start,startrekt,wznow,wznowrekt,opcje,opcjerekt,wyjdz,wyjdzrekt,dzwiek,dzwiekrekt,reset,resetrekt,cofnij,cofnijrekt);

        if (stan.gamepause)
        {
            if (stan.poczekaj>150)
                gra(vw,stan,vy,g,dt,y,score,record,yk,go,ww,sw,przeszkody,szerokosc,boxgracz,y0,x,shape);
            stan.poczekaj+=2;
        }



        //window.clear(sf::Color::Black);
        rysujplansze(stan,odliczanie,window,tlo,wynik,najwynik,shape,przeszkody,pause,start,wznow,opcje,wyjdz,dzwiek,reset,cofnij);
    }
    return 0;
}

