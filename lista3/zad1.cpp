#include <iostream>
using namespace std; 

int main() 
{
int q=0,i;
while(q==0)
q=1;
cout<<"Co chcesz zrobić ? (dodawanie[1], odejmowanie[2], dzielenie[3], mnożenie[4]"<<endl;
cin>>i;
while(i==1)
{
if(i==1)
{
int w;
cout<<"wybrales dodawanie, tak?( tak[1]/nie[2] )"<<endl;
cin>>w;
if(w=1)
{
double a,b,c;
cout<<"Podaj pierwszą liczbę:"<<endl;
cin>>a;
cout<<"Podaj drugą liczbę:"<<endl;
cin>>b;
c=a+b;
cout<<"wynikiem dodawania liczb "<<a<<" oraz "<<b<<" jest: "<<c<<endl;
i=i+5;
}
else if(w=2)
{
q=0;
i=0;
break;
cout<<"wyjscie"<<endl;
}
else
{
w=1;
}


}}}
