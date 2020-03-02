#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(void)
{
int a,b,c=0,d=0,i=0,kolor;
srand (time(0));

do{
cout<<"Podaj szerokość obrazka: "<<endl;
cin>>b;
if(b<0 || b>8)
{
cout<<"Zle. Podaj cyfre z zakresu 1-8!"<<endl<<endl;
}
else if (b>0 || b<8)
{
cout<<"dobrze. Szerokosc zapisana"<<endl<<endl;
}
}while(0>b || b>8);

do{
cout<<"Podaj wysokość obrazka: "<<endl<<endl;
cin>>a;
if(a<0 || a>8)
{
cout<<"Zle. Podaj cyfre z zakresu 1-8!"<<endl<<endl;
}
}while(0>a || a>8);

cout<<"wysokość to "<<a<<" szerokosc to "<<b<<endl;



while(c<a || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<7 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d-1<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<6 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d-2<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<5 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d-3<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<4 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d-4<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<3 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d-5<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<a-7 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d-6<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}
c=0;
d=0;

while(c<7 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d+1<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<6 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d+2<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<5 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d+3<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<4 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d+4<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<3 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d+5<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}

c=0;
d=0;

while(c<2 || d<b)
{
kolor=rand() % 8 + 41;
c=c+1;
d=d+1;
cout<<fixed<<"\x1b["<<c<<";"<<d+6<<"H\x1b["<<kolor<<"m "<<"\x1b[0m";
}
return 0;
}
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
if(b<0 || b>8)
{
cout<<"Zle. Podaj cyfre z zakresu 1-8!"<<endl<<endl;
}
else if (b>0 || b<8)
{
cout<<"dobrze. Szerokosc zapisana"<<endl<<endl;
}
}while(0>b || b>8);

do{
cout<<"Podaj wysokość obrazka: "<<endl<<endl;
cin>>a;
if(a<0 || a>8)
{
cout<<"Zle. Podaj cyfre z zakresu 1-8!"<<endl<<endl;
}
}while(0>a || a>8);

cout<<"wysokość to "<<a<<" szerokosc to "<<b<<endl;

