#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void rysuj(char gra[],int wynik[],int i)
{
   //to ma byc takie dlugie ze wzgledu na ochrone kodu
   cout << " \t Runda nr: " << i <<"\n "<<endl;
   cout << "Wynik gracza: " << wynik[0]<<"        Wynik komputera: " << wynik[1]<<" \n \n"<<endl;
   cout <<" 1    2    3" <<endl<<"["<<gra[1]<<"]  "<<"["<<gra[2]<<"]  "<<"["<<gra[3]<<"]"<<endl<<" 4    5    6"<<endl<<"["<<gra[4]<<"]  "<<"["<<gra[5]<<"]  "<<"["<<gra[6]<<"]  "<<endl<<" 7    8    9"<<endl<<"["<<gra[7]<<"]  "<<"["<<gra[8]<<"]  "<<"["<<gra[9]<<"]  "<<endl;

}
void pytanie(char gra[])
{
   int wybrana;
   cout << "gdzie wstawic X ?: ";
   bool prawda;
   do
     {
	cin >> wybrana;
	prawda=cin.good();
	cin.clear();
	cin.ignore(1000,'\n');
	if(gra[wybrana]!=' ')
	  prawda=0;
     }while (prawda==0);
   gra[wybrana]='X';
}
void bot(char gra[])
{
  int strzal;
   int dobrystrzal=0;
   do
     {
	strzal=rand() / float(RAND_MAX)*9+1;
	if (gra[strzal]==' ')
	{
	   gra[strzal]='O';
	   dobrystrzal=1;
	}

     }while(dobrystrzal==0);

}
void wyczysc()
{
   for (int seba=0;seba<10;seba++)
     cout << "\n \n \n \n \n";
}
void logika(char gra[],int wynik[],int &zaba,int &koniec)
{
   //sprawdzanie gracza
   if(gra[1]=='X'&&gra[2]=='X'&&gra[3]=='X'||gra[4]=='X'&&gra[5]=='X'&&gra[6]=='X'||gra[7]=='X'&&gra[8]=='X'&&gra[9]=='X'||
      gra[1]=='X'&&gra[4]=='X'&&gra[7]=='X'||gra[2]=='X'&&gra[5]=='X'&&gra[8]=='X'||gra[3]=='X'&&gra[6]=='X'&&gra[9]=='X'||
      gra[1]=='X'&&gra[5]=='X'&&gra[9]=='X'||gra[3]=='X'&&gra[5]=='X'&&gra[7]=='X')
     {
	wynik[0]+=1;
	zaba=1;
	koniec=5;
	cout <<"wygrana"<< endl;
     }
   //sprawdzanie bota
    if(gra[1]=='O'&&gra[2]=='O'&&gra[3]=='O'||gra[4]=='O'&&gra[5]=='O'&&gra[6]=='O'||gra[7]=='O'&&gra[8]=='O'&&gra[9]=='O'||
      gra[1]=='O'&&gra[4]=='O'&&gra[7]=='O'||gra[2]=='O'&&gra[5]=='O'&&gra[8]=='O'||gra[3]=='O'&&gra[6]=='O'&&gra[9]=='O'||
      gra[1]=='O'&&gra[5]=='O'&&gra[9]=='O'||gra[3]=='O'&&gra[5]=='O'&&gra[7]=='O')
     {
	wynik[1]+=1;
	zaba=1;
	koniec=5;
	cout<<"Przegrana!"<< endl;
     }
}

void gameplay()
{
   int wynik[2]={0,0};
   for (int hehe=1;hehe>0;hehe++)
     {

	char gra[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	//gra[0] to zmienna punktowa, a 1=9 to zaznaczenie pola :D
	wyczysc(); //wyczysc ekran na start
	rysuj(gra,wynik,hehe); //narysuj plansze na start
	int zaba=0;
	int koniec;
	for (koniec=0;koniec<4;koniec++)
	  {
	     pytanie(gra);
	     wyczysc();
	     bot(gra);
	     rysuj(gra,wynik,hehe);
	     logika(gra,wynik,zaba,koniec);
	  }
	if (koniec==4&&zaba==0)
	  {
	     pytanie(gra);
	     wyczysc();
	     rysuj(gra,wynik,koniec);
	     hehe==-1;
	     cout << "Remis!"<<endl;
	  }

	char ponow;
	cout<<"Wpisz T jesli chcesz zagrać jeszcze raz?: ";
	cin >> ponow;
	if (ponow=='T'||ponow=='t')
	  {
	     //bo tak a co! xD
	  }
	else
	  {
	     hehe=-1;
	  }
     }
}

int main()
{
   srand(time(NULL));
   gameplay();
   //po co mi ta funkcja ;_;
   return 0;
}
