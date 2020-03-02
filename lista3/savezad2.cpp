#include <iostream>
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
liczby[i] = (double)rand() / ((double)RAND_MAX + 1);
a+=liczby[i];
}while(i<n); // koniec petli liczacej
}
}while(q==0); // koniec petli glownej
cout<<n<<"	"<<a/n<<endl;
return 0;
}
