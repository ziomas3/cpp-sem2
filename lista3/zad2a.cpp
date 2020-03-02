#include <iostream>
#include <fstream> // file input/output
#include <stdlib.h> //rand
#include <iomanip> //setprecision
#include <ctime> //srand
using namespace std;

int main(void)
{
srand (time(NULL));
double liczby[99999];
int q=0,i=0;
double a=0,n;
ofstream fout("zad2a.dat",ios::app); // otwieram plik zad2a.dat, a jesli nie istnieje - tworze plik zad2.dat. ios::app - przechodze do ostatniej linijki pliku
if(fout.is_open()) // sprawdzam, czy plik zostal otwarty, czy nie.
{
cout<<"plik zad2.dat zostal otwarty"<<endl;
do // petla glowna
{
cout<<"podaj z ilu liczb ma byc policzona srednia: [1 - 99999]"<<endl;
cin>>n;
if(n>99999 || n<1) // sprawdzam czy podana wartosc jest prawidlowa (1-99999)
{
cout<<"zle. Podaj liczbe od 1 do 99999"<<endl;
}
else 
{
q=1;
do // petla liczaca
{
i=i+1;
liczby[i] = rand()%2;
a+=liczby[i];
}while(i<n); // koniec petli liczacej
}
}while(q==0); // koniec petli glownej
cout<<setprecision(4)<<n<<"	"<<a/n<<endl;
fout<<setprecision(4)<<n<<"	"<<a/n<<endl; // wpisuje n i srednia do pliku
}
else
{
cout<<"plik nie mogl zostac otwarty"<<endl;
}
return 0;
}
