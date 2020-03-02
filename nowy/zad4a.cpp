#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(void)
{
int a,b,c=0,kolor;
srand (time(0));

do{
cout<<"Podaj szerokość obrazka: "<<endl;
cin>>b;
if(b<0)
{
cout<<"Zle. Podaj liczbe dodatnia."<<endl<<endl;
}
else if (b>0)
{
cout<<"dobrze. Szerokosc zapisana"<<endl<<endl;
}
}while(0>b);

do{
cout<<"Podaj wysokość obrazka: "<<endl<<endl;
cin>>a;
if(a<0)
{
cout<<"Zle. Podaj liczbe dodatnia."<<endl<<endl;
}
}while(0>a);

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
break;
}
}
}
}while(c<a);

}





