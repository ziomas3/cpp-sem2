#include <iostream>
#include <iomanip>
#include <cfloat>
using namespace std;

int main(void)
{
int i=2,a;
long double m=1;
cout<<endl<<"Podaj liczbę do ktorej chcesz obliczyc silnie:"<<endl<<endl;
cin>>a;
cout<<"Silnia dla 1 wynosi: 1"<<endl<<endl;
while (i<a+1)
{
m=i*m;
i=i+1;
cout <<fixed<<setprecision(0)<<"Silnia dla "<<i-1<<" wynosi: "<<m<<endl;
if(m>LDBL_MAX)
{
cout<<"Silnia z "<<i-1<<" jest wieksza od LDBL_MAX:"<< LDBL_MAX <<". Kolejne silnie nie sa mozliwe do obliczenia (przy uzyciu ldbl)"<<endl;
break;
}
}
}

