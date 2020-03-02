#include <iostream>
#include <ctime> // srand
#include <stdlib.h> // rand
using namespace std;

void plansza()
{
cout<<"\x1b[6;0H   |   |   "<<endl;
cout<<"\x1b[7;0H   |   |   "<<endl;
cout<<"\x1b[8;0H   |   |   "<<endl;
cout<<"\x1b[9;0H---|---|---"<<endl;
cout<<"\x1b[10;0H   |   |   "<<endl;
cout<<"\x1b[11;0H   |   |   "<<endl;
cout<<"\x1b[12;0H   |   |   "<<endl;
cout<<"\x1b[13;0H---|---|---"<<endl;
cout<<"\x1b[14;0H   |   |   "<<endl;
cout<<"\x1b[15;0H   |   |   "<<endl;
cout<<"\x1b[16;0H   |   |   "<<endl;
cout<<"\x1b[25;0H"<<endl;
}

void planszapokazowa()
{
cout<<"\x1b[6;15H   |   |   "<<endl;
cout<<"\x1b[7;15H 1 | 2 | 3 "<<endl;
cout<<"\x1b[8;15H   |   |   "<<endl;
cout<<"\x1b[9;15H---|---|---"<<endl;
cout<<"\x1b[10;15H   |   |   "<<endl;
cout<<"\x1b[11;15H 4 | 5 | 6 "<<endl;
cout<<"\x1b[12;15H   |   |   "<<endl;
cout<<"\x1b[13;15H---|---|---"<<endl;
cout<<"\x1b[14;15H   |   |   "<<endl;
cout<<"\x1b[15;15H 7 | 8 | 9 "<<endl;
cout<<"\x1b[16;15H   |   |   "<<endl;
cout<<"\x1b[25;0H"<<endl;
}

void planszatest()
{
cout<<"\x1b[5;30H"<<endl;
cout<<"\x1b[6;30H   |   |   "<<endl;
cout<<"\x1b[7;30H 6 | 6 | 6 "<<endl;
cout<<"\x1b[8;30H 0 | 5 | 9 "<<endl;
cout<<"\x1b[9;30H---|---|---"<<endl;
cout<<"\x1b[10;30H   |   |   "<<endl;
cout<<"\x1b[11;30H10 |10 |10 "<<endl;
cout<<"\x1b[12;30H 0 | 5 | 9 "<<endl;
cout<<"\x1b[13;30H---|---|---"<<endl;
cout<<"\x1b[14;30H   |   |   "<<endl;
cout<<"\x1b[15;30H14 |14 |14 "<<endl;
cout<<"\x1b[16;30H 0 | 5 | 9 "<<endl;
cout<<"\x1b[25;0H"<<endl;
}

void wstawx(int y, int x)
{
cout<<"\x1b["<<y<<";"<<x<<"H* *"<<endl;
cout<<"\x1b["<<y+1<<";"<<x<<"H * "<<endl;
cout<<"\x1b["<<y+2<<";"<<x<<"H* *"<<endl;
cout<<"\x1b[25;0H"<<endl;
}

void wstawo(int y, int x)
{
cout<<"\x1b["<<y<<";"<<x<<"H***"<<endl;
cout<<"\x1b["<<y+1<<";"<<x<<"H* *"<<endl;
cout<<"\x1b["<<y+2<<";"<<x<<"H***"<<endl;
cout<<"\x1b[25;0H"<<endl;
}

int main(void)
{
plansza();
planszapokazowa();
planszatest();
//wstawx(6,0); // 1
//wstawo(6,5); // 2
//wstawo(6,9); // 3
//wstawo(10,0); // 4
//wstawo(10,5); // 5
//wstawo(10,9); // 6
//wstawo(14,0); // 7
//wstawo(14,5); // 8
//wstawo(14,9); // 9
int q=1,e=1,r,a=0,t=1;
string w;
int pole[9] = {0,0,0,0,0,0,0,0,0};
srand(time(NULL)); // seed
// q - zmienna "start gry"
// e - petla wyboru pola gry dla kolka
// r - zmienna wyboru pola gry
// w - string "kolko" lub "krzyzyk" (wybor x lub o )
// t - zmienna petli ruchu przeciwnika
// pole - tabela zawierajaca zapisane pozycje z x lub z o na polu gry

////////////////////////////////////////////////////////////////////////////////////
do // start gry
{
cout<<"\x1b[23;0HWitaj! kolko, czy krzyzyk [kolko/krzyzyk] ?";
cout<<"\x1b[25;0H\x1b[47;30m            ";
cout<<"\x1b[25;0H";  
cin>>w;
cout<<"\x1b[0m";  
if(w=="kolko")
{
cout<<"\x1b[23;0HWybrales kolko!                        ";
cout<<"\x1b[25;0H\x1b[47;30m            ";
cout<<"\x1b[0m";
q=0;
}
else if(w=="krzyzyk")
{
cout<<"\x1b[23;0HWybrales krzyzyk!                        ";
cout<<"\x1b[25;0H\x1b[47;30m            ";
cout<<"\x1b[0m";
q=0;
}
else
{
}
}while(q==1); // koniec startu gry 
///////////////////////////////////////////////////////////////////////////////////
if(w=="kolko") // w przypadku wyboru kolka
{
do // petla wyboru pozycji na polu gry
{
cout<<"\x1b[23;0HGdzie chcesz postawic kolko?                        ";
cout<<"\x1b[25;0H\x1b[47;30m            ";
cout<<"\x1b[25;0H";
cin>>r;
cout<<"\x1b[0m";
////////////////////////////////
if(r==1)
{
if(pole[1]==0)
{
wstawo(6,0);
pole[1]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
a=rand() % 9 + 1;
if(a==1) // dla 1
{
if(pole[1]==0)
{
pole[1]=1;
wstawx(6,0);
}
else if(pole[1]==1)
{
t=1;
cout<<a;
}
} // koniec dla 1
else if(a==2)
{
if(pole[2]==0)
{
pole[2]=1;
wstawx(6,5);
}
else if(pole[2]==1)
{
t=1;
cout<<a;
}
} 
else if(a==3)
{
if(pole[3]==0)
{
pole[3]=1;
wstawx(6,9);
}
else if(pole[3]==1)
{
t=1;
cout<<a;
}
} 
else if(a==4)
{
if(pole[4]==0)
{
pole[4]=1;
wstawx(10,0);
}
else if(pole[4]==1)
{
t=1;
cout<<a;
}
} 
else if(a==5)
{
if(pole[5]==0)
{
pole[5]=1;
wstawx(10,5);
}
else if(pole[5]==1)
{
t=1;
cout<<a;
}
} 
else if(a==6)
{
if(pole[6]==0)
{
pole[6]=1;
wstawx(10,9);
}
else if(pole[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(pole[7]==0)
{
pole[7]=1;
wstawx(14,0);
}
else if(pole[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(pole[8]==0)
{
pole[8]=1;
wstawx(14,5);
}
else if(pole[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(pole[9]==0)
{
pole[9]=1;
wstawx(14,9);
}
else if(pole[9]==1)
{
t=1;
}
}
}while(t==1); // koniec petli ruchu przeciwnika
////
}
else
{
cout<<"\x1b[22;0H\x1b[31mTo pole jest zajęte. Wybierz inne!";
cout<<"\x1b[0m";
} 
}
////////////////////////////////
else if(r==2)
{
}
////////////////////////////////
else if(r==3)
{
}
////////////////////////////////
else if(r==4)
{
}
////////////////////////////////
else if(r==5)
{
}
////////////////////////////////
else if(r==6)
{
}
////////////////////////////////
else if(r==7)
{
}
////////////////////////////////
else if(r==8)
{
}
////////////////////////////////
else if(r==9)
{
}
////////////////////////////////
else
{
}
////////////////////////////////
}while(e==1); // koniec petli wyboru pozycji na polu gry
}// koniec petli "if" dla wyboru kolka

return 0;
}
