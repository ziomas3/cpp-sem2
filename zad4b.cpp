#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(void)
{
int a,b,c=0,d=0,kolor,z=0;
srand (time(0));

do{
cout<<"Podaj szerokość obrazka (wartosc wieksza od 8): "<<endl;
cin>>b;
if(b<8)
{
cout<<"Zle. Podaj liczbe wieksza od 8."<<endl<<endl;
}
}while(8>b);

do{
cout<<"Podaj wysokość obrazka (wartosc wieksza od 8): "<<endl<<endl;
cin>>a;
if(a<8)
{
cout<<"Zle. Podaj liczbe wieksza od 8."<<endl<<endl;
}
}while(8>a);

cout<<"wysokość to "<<a<<" szerokosc to "<<b<<endl;

int x=b;

do
{
c=c+1;
kolor=rand() % 8 + 41;
cout<<fixed<<"\x1b["<<c<<";"<<b<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
if(c==a)
{
c=0;
b=b-1;
}
else if(b==0)
{
for(b=0;b<x;b+1)
{
cout<<fixed<<"\x1b[1;"<<b<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
if(b=x)
{
c=a+1;
do
{
d=d+1;
kolor=rand() % 8 + 41;
cout<<fixed<<"\x1b[1;"<<d<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}while(d<x);
break;
}
}
}
}while(c<a);
}



