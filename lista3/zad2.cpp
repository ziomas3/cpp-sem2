#include <iostream>
#include <fstream> // file input/output
#include <stdlib.h> //rand
#include <iomanip> //setprecision
#include <ctime> //srand
using namespace std;

int main(void)
{
srand (time(NULL)); // seed
double liczby[99999]; // definiuje tablice (maksyamlna wielkosc tablicy - 99999)
int i,q=0,n=0; // i - zmienna pozycji w tablicy, q - zmienna petli glownej, n - zmienna petli liczacej
double a; // zmienna ktora sumuje wszystkie liczby w tablicy
ofstream fout("zad2.dat"); // otwieram plik zad2.dat, a jesli nie istnieje - tworze plik zad2.dat. ios::app - przechodze do ostatniej linijki pliku
if(fout.is_open()) // sprawdzam, czy plik zostal otwarty, czy nie.
{
cout<<"plik zad2.dat zostal otwarty"<<endl;
for(q=0;q<=999;q++) // petla glowna
{
    n=n+1;// musi ogarniaæ n.
    a=0;
    i=0;
do // petla liczaca
{
i=i+1;
liczby[i] = (double)rand() / ((double)RAND_MAX + 1); // przypisuje pod miejsce ` i ` w tablicy jakas losowa liczbe w zakresie od 0 do 1
cout<<"wylosowane liczby: "<<i<<" "<<liczby[i]<<endl;
a=a+liczby[i];
}while(i<=n-1); // koniec petli liczacej
cout<<n<<"	"<<a<<"  "<<a/n<<endl;
fout<<n<<"	"<<a/n<<endl; // wpisuje n i srednia do pliku
} // koniec petli glownej
}
else // jesli plik nie zostal otwarty
{
cout<<"plik nie mogl zostac otwarty"<<endl;
}
return 0;
}
