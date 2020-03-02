#include <iostream> // podstawa
#include <stdlib.h> // rand
#include <ctime> // srand
using namespace std;

int main(void)
{
long double a,q,v,c,b=0,n=0,z,d,g,o=0;
int s=1000;
string m,f,i;
//a - liczba losowa do zgadniecia 
//q - zmienna petli gry (0 - petla dziala, 1 - petla nie dziala) 
//c - liczba podana przez gracza 
//v - licznik prob 
//b - zmienna petli glownej
//n - licznik gier
//m - string dla wyboru ponownej gry
//z - petla wyniku
//s - zmienna zakresu (MAX)
//f - zmienna podpowiedzi ( wyniku )
//o - zmienna petli glownej /// wolna!
//i - string wyboru nowa gra/wyjscie
srand(time(NULL));
cout<<"\x1b[11;0H\x1b[47;30m**********************************************************************************************************\x1b[0m ";
cout<<"\x1b[12;0H\x1b[47;30;1m*                                      Z G A D Y W A N K A                                               *\x1b[0m ";
cout<<"\x1b[13;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[14;0H\x1b[47;30m* Wpisz "<<"\x1b[1;4mnowagra\x1b[0m"<<"\x1b[47;30m, aby zaczac.                                                                             *\x1b[0m ";
cout<<"\x1b[15;0H\x1b[47;30m* Wpisz "<<"\x1b[1;4mwyjscie\x1b[0m"<<"\x1b[47;30m, aby zakonczyc.                                                                          *\x1b[0m ";
cout<<"\x1b[16;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[17;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[18;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[19;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
cin>>i;
if(i=="nowagra")
{
cout<<"\x1b[11;0H\x1b[47;30m**********************************************************************************************************\x1b[0m ";
cout<<"\x1b[12;0H\x1b[47;30;1m*                                      Z G A D Y W A N K A                                               *\x1b[0m ";
cout<<"\x1b[13;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[14;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[15;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[16;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[17;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[18;0H\x1b[47;30m*                                                                                                        *\x1b[0m "; 
cout<<"\x1b[19;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
do // petla glowna
{
d=3;
v=0;
q=0;
b=1;
n=n+1;
a=rand() % s + 1;
do // petla gry
{
cout<<"\x1b[12;0H\x1b[47;30;1m*Lacznie prob: "<<o<<"                       Z G A D Y W A N K A                                     Poziom: "<<n<<" *\x1b[0m ";
cout<<"\x1b[16;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[15;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[13;0H\x1b[47;30m*Podaj liczbe od 1 do "<<s;
cout<<"\x1b[14;0H\x1b[47;30m*liczba do wylosowania to: "<<a;
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m"<<endl;
cin>>c;
v=v+1;
o=o+1;
//
//if(f=="wynik")
//{
//cout<<"liczba do wylosowania to: "<<a<<endl;
//}
//else if(f=="podpowiedz")
//{
//cout<<"liczba do wylosowania znajuje sie w zakresie od"<<s-100<<" do "<<s+100<<endl;
//d=d-1;
//}
//
if(c==a)
{
q=1;
do // petla wyniku
{
z=1;
cout<<"\x1b[11;0H\x1b[47;30m**********************************************************************************************************\x1b[0m ";
cout<<"\x1b[12;0H\x1b[47;30;1m*                                      Z G A D Y W A N K A                                               *\x1b[0m ";
cout<<"\x1b[13;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[14;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[17;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[18;0H\x1b[47;30m*                                                                                                        *\x1b[0m "; 
cout<<"\x1b[19;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[15;6H\x1b[47;30mGratulacje! To byla twoja "<<n<<" gra. "<<"Udalo ci sie w "<<v<<" probach!";
cout<<"\x1b[16;6H\x1b[47;30mCzy chcesz zagrac jeszcze raz ? W nastepnej grze zakres liczb zwiekszy sie o 1000 [tak/nie]";
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
cin>>m;
if(m=="tak")
{
b=0;
s=s+1000;
}
else if(m=="nie") 
{
cout<<"\x1b[11;0H\x1b[47;30m**********************************************************************************************************\x1b[0m ";
cout<<"\x1b[12;0H\x1b[47;30;1m*                                      Z G A D Y W A N K A                                               *\x1b[0m ";
cout<<"\x1b[13;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[14;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[15;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[16;0H\x1b[47;30m*                   Powodzenia! Dziekuje za poswiecony czas!                                             *\x1b[0m ";
cout<<"\x1b[17;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[18;0H\x1b[47;30m*                                                                                                        *\x1b[0m "; 
cout<<"\x1b[19;0H\x1b[47;30m*                                                                                                        *\x1b[0m ";
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
else
{
z=0;
cout<<"\x1b[18;0H\x1b[47;30m*Zle.                                                                                              ";
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
}while(z==0); // koniec wyniku
}
else if(c<1 || c>s)
{
o=o-1;
v=v-1;
cout<<"\x1b[18;0H\x1b[47;30m*Zle!                                                                                              ";
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
else if(c>a) // dla wiekszej
{
if(d>0)
{
 
cout<<"\x1b[18;0H\x1b[47;30m*Za duza!"<<". Pozostaly ci "<<d<<" podpowiedzi. Czy chcesz zobaczyc podpowiedz ?[tak/nie]               ";
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
cin>>f;
}
else
{
 
cout<<"\x1b[18;0H\x1b[47;30m*Za duza!"<<". Nie masz już podpowiedzi!                                                                 ";
cout<<"\x1b[21;0H\x1b[47;30m        \x1b[0m";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
do // petla podpowiedzi
{
g=1;
if(f=="wynik")
{
 
cout<<"\x1b[18;0H\x1b[47;31m*liczba do wylosowania to: "<<a<<"                                                                      ";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
else if(f=="tak")
{
cout<<"\x1b[18;0H\x1b[47;30m*liczba do wylosowania znajuje sie w zakresie od "<<a-100<<" do "<<a+100<<"                                ";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
d=d-1;
}
else if(f=="nie")
{
cout<<"\x1b[18;0H\x1b[47;30m*                                                                                                        *\x1b[0m "; 
}
else
{
g=0;
 
cout<<"\x1b[18;0H\x1b[47;30m*Zle! [tak/nie]"<<"                                                                        ";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
}while(g==0); // koniec petli podpowiedzi
}
else if(c<a) // dla mniejszej 
{
if(d>0)
{
 
cout<<"\x1b[18;0H\x1b[47;30m*Za mała!"<<". Pozostaly ci "<<d<<" podpowiedzi. Czy chcesz zobaczyc podpowiedz ?[tak/nie]               ";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
cin>>f;
}
else
{
 
cout<<"\x1b[18;0H\x1b[47;30m*Za mała!"<<". Nie masz już podpowiedzi!                                               ";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
do // petla podpowiedzi
{
g=1;
if(f=="wynik")
{
cout<<"\x1b[18;0H\x1b[47;31m*liczba do wylosowania to: "<<a<<"                                               " ;
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
else if(f=="tak")
{
cout<<"\x1b[18;0H\x1b[47;30m*liczba do wylosowania znajuje sie w zakresie od "<<a-100<<" do "<<a+100<<"                             ";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
d=d-1;
}
else if(f=="nie")
{
cout<<"\x1b[18;0H\x1b[47;30m*                                                                                                        *\x1b[0m "; 
}
else
{
g=0;
 
cout<<"\x1b[18;0H\x1b[47;30m*Zle! [tak/nie]                                                                                    ";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
}
}while(g==0); // koniec petli podpowiedzi
}
}while(q==0); // koniec petli gry
}while(b==0); // koniec petli glownej
}
else if(i=="wyjscie")
{
return 0;
}
else
{
 
cout<<"\x1b[18;0H\x1b[47;30m*Zle. Ta gra nie jest dla ciebie.                                                                    ";
cout<<"\x1b[20;0H\x1b[47;30m**********************************************************************************************************\x1b[0m "<<endl;
return 0;
}
return 0;
}
