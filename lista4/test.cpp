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
int q=1,e=1,r,a=0,t=1,u=1;
string w;
int polex[10] = {0,0,0,0,0,0,0,0,0,0};
int poleo[10] = {0,0,0,0,0,0,0,0,0,0};
srand(time(NULL)); // seed
// q - zmienna "start gry"
// e - petla wyboru pola gry dla kolka
// r - zmienna wyboru pola gry
// w - string "kolko" lub "krzyzyk" (wybor x lub o )
// t - zmienna petli ruchu przeciwnika
// polex - tabela zawierajaca zapisane pozycje z x na polu gry
// poleo - tabela zawierajace zapisane pozycje z o na polu gry

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
do // petla wyniku
{
e=1;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==1 || poleo[4]==1 && poleo[5]==1 && poleo[6]==1 || poleo[7]==1 && poleo[8]==1 && poleo[9]==1 || poleo[1]==1 && poleo[4]==1 && poleo[7]==1 || poleo[2]==1 && poleo[5]==1 && poleo[8]==1 || poleo[3]==1 && poleo[6]==1 && poleo[9]==1 || poleo[1]==1 && poleo[5]==1 && poleo[9]==1 || poleo[7]==1 && poleo[5]==1 && poleo[3]==1)
{
cout<<"WYGRANA!"<<endl;
return 0;
}
else if(polex[1]==1 && polex[2]==1 && polex[3]==1 || polex[4]==1 && polex[5]==1 && polex[6]==1 || polex[7]==1 && polex[8]==1 && polex[9]==1 || polex[1]==1 && polex[4]==1 && polex[7]==1 || polex[2]==1 && polex[5]==1 && polex[8]==1 || polex[3]==1 && polex[6]==1 && polex[9]==1 || polex[1]==1 && polex[5]==1 && polex[9]==1 || polex[7]==1 && polex[5]==1 && polex[3]==1)
{
cout<<"PRZEGRANA!!"<<endl;
return 0;
}
else if(polex[1]+polex[2]+polex[3]+polex[4]+polex[5]+polex[6]+polex[7]+polex[8]+polex[9]+poleo[1]+poleo[2]+poleo[3]+poleo[4]+poleo[5]+poleo[6]+poleo[7]+poleo[8]+poleo[9]==9)
{
cout<<"REMIS!!"<<endl;
return 0;
}
do // petla wyboru pozycji na polu gry ( kolko )
{
cout<<"\x1b[23;0HGdzie chcesz postawic kolko?                        ";
cout<<"\x1b[25;0H\x1b[47;30m            ";
cout<<"\x1b[25;0H";
cin>>r;
cout<<"\x1b[0m";
////////////////////////////////
if(r==1)
{
if(polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
if(polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==3)
{
if(polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==4)
{
if(polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==5)
{
if(polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==6)
{
if(polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==7)
{
if(polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==8)
{
if(polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==9)
{
if(polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(poleo[1]==1 && poleo[2]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[3]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[3]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[4]==1 && poleo[5]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[6]=1;
}
else if(poleo[5]==1 && poleo[6]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[4]==1 && poleo[6]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[7]==1 && poleo[8]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[8]==1 && poleo[9]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[7]==1 && poleo[9]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[1]==1 && poleo[4]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[4]==1 && poleo[7]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[7]==1 && poleo[4]==0 && polex[4]==0)
{
wstawx(10,0);
polex[4]=1;
}
else if(poleo[3]==1 && poleo[6]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[6]==1 && poleo[9]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[9]==1 && poleo[6]==0 && polex[6]==0)
{
wstawx(10,9);
polex[3]=1;
}
else if(poleo[2]==1 && poleo[5]==1 && poleo[8]==0 && polex[8]==0)
{
wstawx(14,5);
polex[8]=1;
}
else if(poleo[5]==1 && poleo[8]==1 && poleo[2]==0 && polex[2]==0)
{
wstawx(6,5);
polex[2]=1;
}
else if(poleo[2]==1 && poleo[8]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[1]==1 && poleo[5]==1 && poleo[9]==0 && polex[9]==0)
{
wstawx(14,9);
polex[9]=1;
}
else if(poleo[5]==1 && poleo[9]==1 && poleo[1]==0 && polex[1]==0)
{
wstawx(6,0);
polex[1]=1;
}
else if(poleo[1]==1 && poleo[9]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else if(poleo[3]==1 && poleo[5]==1 && poleo[7]==0 && polex[7]==0)
{
wstawx(14,0);
polex[7]=1;
}
else if(poleo[5]==1 && poleo[7]==1 && poleo[3]==0 && polex[3]==0)
{
wstawx(6,9);
polex[3]=1;
}
else if(poleo[3]==1 && poleo[7]==1 && poleo[5]==0 && polex[5]==0)
{
wstawx(10,5);
polex[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
polex[1]=1;
wstawx(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
polex[2]=1;
wstawx(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
polex[3]=1;
wstawx(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
polex[4]=1;
wstawx(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
polex[5]=1;
wstawx(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
polex[6]=1;
wstawx(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
polex[7]=1;
wstawx(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
polex[8]=1;
wstawx(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
polex[9]=1;
wstawx(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else
{
}
////////////////////////////////
}while(e==1); // koniec petli wyboru pozycji na polu gry
}while(u==1); // petla wyniku
}// koniec petli z "if" dla wyboru kolka
else if(w=="krzyzyk") // w przypadku wyboru krzyzyka
{
do // petla wyniku
{
e=1;
if(polex[1]==1 && polex[2]==1 && polex[3]==1 || polex[4]==1 && polex[5]==1 && polex[6]==1 || polex[7]==1 && polex[8]==1 && polex[9]==1 || polex[1]==1 && polex[4]==1 && polex[7]==1 || polex[2]==1 && polex[5]==1 && polex[8]==1 || polex[3]==1 && polex[6]==1 && polex[9]==1 || polex[1]==1 && polex[5]==1 && polex[9]==1 || polex[7]==1 && polex[5]==1 && polex[3]==1)
{
cout<<"WYGRANA!"<<endl;
return 0;
}
else if(poleo[1]==1 && poleo[2]==1 && poleo[3]==1 || poleo[4]==1 && poleo[5]==1 && poleo[6]==1 || poleo[7]==1 && poleo[8]==1 && poleo[9]==1 || poleo[1]==1 && poleo[4]==1 && poleo[7]==1 || poleo[2]==1 && poleo[5]==1 && poleo[8]==1 || poleo[3]==1 && poleo[6]==1 && poleo[9]==1 || poleo[1]==1 && poleo[5]==1 && poleo[9]==1 || poleo[7]==1 && poleo[5]==1 && poleo[3]==1)
{
cout<<"PRZEGRANA!!"<<endl;
return 0;
}
else if(polex[1]+polex[2]+polex[3]+polex[4]+polex[5]+polex[6]+polex[7]+polex[8]+polex[9]+poleo[1]+poleo[2]+poleo[3]+poleo[4]+poleo[5]+poleo[6]+poleo[7]+poleo[8]+poleo[9]==9)
{
polex[1] = 0;
polex[2] = 0;
polex[3] = 0;
polex[4] = 0;
polex[5] = 0;
polex[6] = 0;
polex[7] = 0;
polex[8] = 0;
polex[9] = 0;
poleo[1] = 0;
poleo[2] = 0;
poleo[3] = 0;
poleo[4] = 0;
poleo[5] = 0;
poleo[6] = 0;
poleo[7] = 0;
poleo[8] = 0;
poleo[9] = 0;
plansza();
}

do // petla wyboru pozycji na polu gry ( kolko )
{
cout<<"\x1b[23;0HGdzie chcesz postawic krzyzyk?                        "<<poleo[1]+poleo[2]+poleo[3]+poleo[4]+poleo[5]+poleo[6]+poleo[7]+poleo[8]+poleo[9]+polex[1]+polex[2]+polex[3]+polex[4]+polex[5]+polex[6]+polex[7]+polex[8]+polex[9];
cout<<"\x1b[25;0H\x1b[47;30m            ";
cout<<"\x1b[25;0H";
cin>>r;
cout<<"\x1b[0m";
////////////////////////////////
if(r==1)
{
if(polex[1]==0 && poleo[1]==0)
{
wstawx(6,0);
polex[1]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
if(polex[2]==0 && poleo[2]==0)
{
wstawx(6,5);
polex[2]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==3)
{
if(polex[3]==0 && poleo[3]==0)
{
wstawx(6,9);
polex[3]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==4)
{
if(polex[4]==0 && poleo[4]==0)
{
wstawx(10,0);
polex[4]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==5)
{
if(polex[5]==0 && poleo[5]==0)
{
wstawx(10,5);
polex[5]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==6)
{
if(polex[6]==0 && poleo[6]==0)
{
wstawx(10,9);
polex[6]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==7)
{
if(polex[7]==0 && poleo[7]==0)
{
wstawx(14,0);
polex[7]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==8)
{
if(polex[8]==0 && poleo[8]==0)
{
wstawx(14,5);
polex[8]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else if(r==9)
{
if(polex[9]==0 && poleo[9]==0)
{
wstawx(14,9);
polex[9]=1;
e=0;
do // petla ruchu przeciwnika
{
t=0;
if(polex[1]==1 && polex[2]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[3]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[3]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[4]==1 && polex[5]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[6]=1;
}
else if(polex[5]==1 && polex[6]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[4]==1 && polex[6]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[7]==1 && polex[8]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[8]==1 && polex[9]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[7]==1 && polex[9]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[1]==1 && polex[4]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[4]==1 && polex[7]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[7]==1 && polex[4]==0 && poleo[4]==0)
{
wstawo(10,0);
poleo[4]=1;
}
else if(polex[3]==1 && polex[6]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[6]==1 && polex[9]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[9]==1 && polex[6]==0 && poleo[6]==0)
{
wstawo(10,9);
poleo[3]=1;
}
else if(polex[2]==1 && polex[5]==1 && polex[8]==0 && poleo[8]==0)
{
wstawo(14,5);
poleo[8]=1;
}
else if(polex[5]==1 && polex[8]==1 && polex[2]==0 && poleo[2]==0)
{
wstawo(6,5);
poleo[2]=1;
}
else if(polex[2]==1 && polex[8]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[1]==1 && polex[5]==1 && polex[9]==0 && poleo[9]==0)
{
wstawo(14,9);
poleo[9]=1;
}
else if(polex[5]==1 && polex[9]==1 && polex[1]==0 && poleo[1]==0)
{
wstawo(6,0);
poleo[1]=1;
}
else if(polex[1]==1 && polex[9]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else if(polex[3]==1 && polex[5]==1 && polex[7]==0 && poleo[7]==0)
{
wstawo(14,0);
poleo[7]=1;
}
else if(polex[5]==1 && polex[7]==1 && polex[3]==0 && poleo[3]==0)
{
wstawo(6,9);
poleo[3]=1;
}
else if(polex[3]==1 && polex[7]==1 && polex[5]==0 && poleo[5]==0)
{
wstawo(10,5);
poleo[5]=1;
}
else
{
a=rand() % 9 + 1;
 
if(a==1) // dla 1
{
if(polex[1]==0 && poleo[1]==0)
{
poleo[1]=1;
wstawo(6,0);
}
else if(polex[1]==1 || poleo[1]==1)
{
t=1;
 
}
} // koniec dla 1
else if(a==2)
{
if(polex[2]==0 && poleo[2]==0)
{
poleo[2]=1;
wstawo(6,5);
}
else if(polex[2]==1 || poleo[2]==1)
{
t=1;
 
}
} 
else if(a==3)
{
if(polex[3]==0 && poleo[3]==0)
{
poleo[3]=1;
wstawo(6,9);
}
else if(polex[3]==1 || poleo[3]==1)
{
t=1;
 
}
} 
else if(a==4)
{
if(polex[4]==0 && poleo[4]==0)
{
poleo[4]=1;
wstawo(10,0);
}
else if(polex[4]==1 || poleo[4]==1)
{
t=1;
 
}
} 
else if(a==5)
{
if(polex[5]==0 && poleo[5]==0)
{
poleo[5]=1;
wstawo(10,5);
}
else if(polex[5]==1 || poleo[5]==1)
{
t=1;
 
}
} 
else if(a==6)
{
if(polex[6]==0 && poleo[6]==0)
{
poleo[6]=1;
wstawo(10,9);
}
else if(polex[6]==1 || polex[6]==1)
{
t=1;
}
} 
else if(a==7)
{
if(polex[7]==0 && poleo[7]==0)
{
poleo[7]=1;
wstawo(14,0);
}
else if(polex[7]==1 || poleo[7]==1)
{
t=1;
}
} 
else if(a==8)
{
if(polex[8]==0 && poleo[8]==0)
{
poleo[8]=1;
wstawo(14,5);
}
else if(polex[8]==1 || poleo[8]==1)
{
t=1;
}
}
else if(a==9)
{
if(polex[9]==0 && poleo[9]==0)
{
poleo[9]=1;
wstawo(14,9);
}
else if(polex[9]==1 || poleo[9]==1)
{
t=1;
}
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
else
{
}
////////////////////////////////
}while(e==1); // koniec petli wyboru pozycji na polu gry
}while(u==1); // petla wyniku
}// koniec petli z "if" dla wyboru kolka
return 0;
}
