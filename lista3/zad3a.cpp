#include <iostream> // podstawa
#include <stdlib.h> // rand
#include <ctime> // srand
#include <unistd.h>
using namespace std;

int main(void)
{
long double a,q,v,c,b=0,n=0,z,d,g;
int s=1000;
string m,f;
//a - liczba losowa do zgadniecia 
//q - zmienna petli gry (0 - petla dziala, 1 - petla nie dziala) 
//c - liczba podana przez gracza 
//v - licznik prob 
//b - zmienna petli glownej
//n - licznik gier
//m - string dla wyboru ponownej gry
//z - petla wyniku
//s - zmienna zakresu (MAX)
//d - zmienna podpowiedzi
//f - zmienna podpowiedzi ( wyniku )
srand(time(NULL));
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
cout<<"Podaj liczbe od 1 do "<<s<<endl;
cout<<"liczba do wylosowania to: "<<a<<endl;
cin>>c;
v=v+1;
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
cout<<"Gratulacje! To byla twoja "<<n<<" gra. "<<"Udalo ci sie w "<<v<<" probach!"<<endl;
cout<<"Czy chcesz zagrac jeszcze raz ? W nastepnej grze zakres liczb zwiekszy sie o 1000"<<endl;
cin>>m;
if(m=="tak")
{
b=0;
s=s+1000;
}
else if(m=="nie") 
{
cout<<"Powodzenia!"<<endl;
}
else
{
z=0;
cout<<"Zle."<<endl;
}
}while(z==0); // koniec wyniku
}
else if(c<1 || c>s)
{
cout<<"Zle!"<<endl;
}
else if(c>a) // dla wiekszej
{
if(d>0)
{
cout<<"Za duza!"<<". Pozostaly ci "<<d<<" podpowiedzi. Czy chcesz zobaczyc podpowiedz ?[tak/nie]"<<endl;
cin>>f;
}
else
{
cout<<"Za duza!"<<". Nie masz już podpowiedzi!"<<endl;
}
do // petla podpowiedzi
{
g=1;
if(f=="wynik")
{
cout<<"liczba do wylosowania to: "<<a<<endl;
}
else if(f=="tak")
{
cout<<"liczba do wylosowania znajuje sie w zakresie od "<<a-100<<" do "<<a+100<<endl;
d=d-1;
}
else if(f=="nie"){}
else
{
g=0;
cout<<"Zle! [tak/nie]"<<endl;
}
}while(g==0); // koniec petli podpowiedzi
}
else if(c<a) // dla mniejszej 
{
if(d>0)
{
cout<<"Za mała!"<<". Pozostaly ci "<<d<<" podpowiedzi. Czy chcesz zobaczyc podpowiedz ?[tak/nie]"<<endl;
cin>>f;
}
else
{
cout<<"Za mała!"<<". Nie masz już podpowiedzi!"<<endl;
}
do // petla podpowiedzi
{
g=1;
if(f=="wynik")
{
cout<<"liczba do wylosowania to: "<<a<<endl;
}
else if(f=="tak")
{
cout<<"liczba do wylosowania znajuje sie w zakresie od "<<a-100<<" do "<<a+100<<endl;
d=d-1;
}
else if(f=="nie"){}
else
{
g=0;
cout<<"Zle! [tak/nie]"<<endl;
}
}while(g==0); // koniec petli podpowiedzi
}
}while(q==0); // koniec petli gry
}while(b==0); // koniec petli glownej
return 0;
}
