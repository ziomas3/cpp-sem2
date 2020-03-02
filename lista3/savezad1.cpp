#include <iostream>
using namespace std;

int main(void)
{
int q=0,w; // q = zmienna dla petli glownej, w = zmienna dla wyboru dzialania, 
do // petla glowna
{
int e=0; // e = petla wewnetrzna dla potwierzenia wyboru dzialania
q=1;
cout<<"Co chcesz zrobić ? (dodawanie[1], odejmowanie[2], dzielenie[3], mnożenie[4], wyjscie[0]"<<endl;
cin>>w;
if(w==1) // dodawanie
{
while(e==0) // petla wewnetrzna dla potwierdzenia wyboru dzialania
{
int r; // r = zmienna dla potwierdzenia wyboru dzialania
e=1;
cout<<"wybrales dodawanie, tak?( tak[1]/nie[2] )"<<endl;
cin>>r;
if(r==1) // potwierdzenie dodawania
{
double a,b,c; // zmienne do dodawania
cout<<"Podaj pierwszą liczbę:"<<endl;
cin>>a;
cout<<"Podaj drugą liczbę:"<<endl;
cin>>b;
c=a+b;
cout<<"wynikiem dodawania liczb "<<a<<" oraz "<<b<<" jest: "<<c<<endl; // wynik
int t=0; // t = zmienna petli wyboru kontynuacji zabawy z kalkulatorem
while(t==0) // petla wewnetrzna dla potwierdzenia kontynuacji zabawy z kalkulatorem
{
int y; // y = zmienna dla potwierdzenia kontynuacji zabawy z kalkulatorem
cout<<endl<<"czy chcesz obliczyc cos innego?( tak[1]/nie[2] )"<<endl;
cin>>y;
if(y==1) // potwierdzenie zabawy - powrot do poczatku
{
q=0;
t=10;
}
else if(y==2) // wyjscie
{
cout<<"dziekuje za skorzystanie z kalkulatora"<<endl;
q=10;
t=10;
}
else // zly wybor (poza 1 i 2)
{
cout<<"wybrales zle"<<endl;
y=0;
}
}
}
else if(r==2) // denied
{
cout<<"wybrales 2"<<endl;
q=0;
}
else // zly wybor (poza 1 i 2) 
{
cout<<"wybrales zle"<<endl;
e=0;
}
}
}
else if(w==2) // odejmowanie
{
while(e==0) // petla wewnetrzna dla potwierdzenia wyboru dzialania
{
int r; // r = zmienna dla potwierdzenia wyboru dzialania
e=1;
cout<<"wybrales odejmowanie, tak?( tak[1]/nie[2] )"<<endl;
cin>>r;
if(r==1) // potwierdzenie odejmowania
{
double a,b,c; // zmienne do odejmowania
cout<<"Podaj pierwszą liczbę:"<<endl;
cin>>a;
cout<<"Podaj drugą liczbę:"<<endl;
cin>>b;
c=a-b;
cout<<"wynikiem odejmowania liczb "<<a<<" oraz "<<b<<" jest: "<<c<<endl;
int t=0; // t = zmienna petli wyboru kontynuacji zabawy z kalkulatorem
while(t==0) // petla wewnetrzna dla potwierdzenia kontynuacji zabawy z kalkulatorem
{
int y; // y = zmienna dla potwierdzenia kontynuacji zabawy z kalkulatorem
cout<<endl<<"czy chcesz obliczyc cos innego?( tak[1]/nie[2] )"<<endl;
cin>>y;
if(y==1) // potwierdzenie zabawy - powrot do poczatku
{
q=0;
t=10;
}
else if(y==2) // wyjscie
{
cout<<"dziekuje za skorzystanie z kalkulatora"<<endl;
q=10;
t=10;
}
else // zly wybor (poza 1 i 2)
{
cout<<"wybrales zle"<<endl;
y=0;
}
}
}
else if(r==2) // denied
{
cout<<"wybrales 2"<<endl;
q=0;
}
else // zly wybor (poza 1 i 2) 
{
cout<<"wybrales zle"<<endl;
e=0;
}
}
}
else if(w==3) // dzielenie
{
while(e==0) // petla wewnetrzna dla potwierdzenia wyboru dzialania
{
int r; // r = zmienna dla potwierdzenia wyboru dzialania
e=1;
cout<<"wybrales dzielenie, tak?( tak[1]/nie[2] )"<<endl;
cin>>r;
if(r==1) // potwierdzenie dzielenia
{
double a,b,c; // zmienne do dzielenia
cout<<"Podaj pierwszą liczbę:"<<endl;
cin>>a;
cout<<"Podaj drugą liczbę:"<<endl;
cin>>b;
c=a/b;
cout<<"wynikiem dzielenia liczb "<<a<<" oraz "<<b<<" jest: "<<c<<endl;
int t=0; // t = zmienna petli wyboru kontynuacji zabawy z kalkulatorem
while(t==0) // petla wewnetrzna dla potwierdzenia kontynuacji zabawy z kalkulatorem
{
int y; // y = zmienna dla potwierdzenia kontynuacji zabawy z kalkulatorem
cout<<endl<<"czy chcesz obliczyc cos innego?( tak[1]/nie[2] )"<<endl;
cin>>y;
if(y==1) // potwierdzenie zabawy - powrot do poczatku
{
q=0;
t=10;
}
else if(y==2) // wyjscie
{
cout<<"dziekuje za skorzystanie z kalkulatora"<<endl;
q=10;
t=10;
}
else // zly wybor (poza 1 i 2)
{
cout<<"wybrales zle"<<endl;
y=0;
}
}
}
else if(r==2) // denied
{
cout<<"wybrales 2"<<endl;
q=0;
}
else // zly wybor (poza 1 i 2) 
{
cout<<"wybrales zle"<<endl;
e=0;
}
}
}
else if(w==4) // mnozenie
{
while(e==0) // petla wewnetrzna dla potwierdzenia wyboru dzialania
{
int r; // r = zmienna dla potwierdzenia wyboru dzialania
e=1;
cout<<"wybrales mnozenie, tak?( tak[1]/nie[2] )"<<endl;
cin>>r;
if(r==1) // potwierdzenie mnozenia
{
double a,b,c; // zmienne do mnozenia
cout<<"Podaj pierwszą liczbę:"<<endl;
cin>>a;
cout<<"Podaj drugą liczbę:"<<endl;
cin>>b;
c=a*b;
cout<<"wynikiem mnozenia liczb "<<a<<" oraz "<<b<<" jest: "<<c<<endl;
int t=0; // t = zmienna petli wyboru kontynuacji zabawy z kalkulatorem
while(t==0) // petla wewnetrzna dla potwierdzenia kontynuacji zabawy z kalkulatorem
{
int y; // y = zmienna dla potwierdzenia kontynuacji zabawy z kalkulatorem
cout<<endl<<"czy chcesz obliczyc cos innego?( tak[1]/nie[2] )"<<endl;
cin>>y;
if(y==1) // potwierdzenie zabawy - powrot do poczatku
{
q=0;
t=10;
}
else if(y==2) // wyjscie
{
cout<<"dziekuje za skorzystanie z kalkulatora"<<endl;
q=10;
t=10;
}
else // zly wybor (poza 1 i 2)
{
cout<<"wybrales zle"<<endl;
y=0;
}
}
}
else if(r==2) // denied
{
cout<<"wybrales 2"<<endl;
q=0;
}
else // zly wybor (poza 1 i 2) 
{
cout<<"wybrales zle"<<endl;
e=0;
}
}
}
else if(w==0) // wyjscie
{
cout<<"wybrales 0"<<endl;
break;
}
else // zly wybor. Powrot do poczatku
{
cout<<"wybrales zle"<<endl;
q=0;
}

}while (q==0); // koniec petli glownej
return 0;
}
