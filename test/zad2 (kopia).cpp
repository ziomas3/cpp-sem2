#include <iostream>
using namespace std;

float readHight()
{
float a;
cin>>a;
return a;
}
float readMass()
{
float b;
cin>>b;
return b;
}
float BMI(float a,float b)
{
return b/(a*a);
}
float BMIprint(float a, float b, float c)
{
cout<<"Mierzysz: "<<a<<"m i wazysz: "<<b<<"kg."<<" Twoj wskaznik BMI wynosi: "<<BMI(a,b)<<endl;
if(c<18.5)
{
cout<<"Masz niedowage."<<endl;
}
else if(c>=18.5 || c<25)
{
cout<<"Twoje BMI jest prawidlowe."<<endl;
}
else if(c>=25)
{
cout<<"Masz nadwage."<<endl;
}
}
int main(void)
{
float a,b,c;
//cout<<"Podaj swoj wzrost (w cm)."<<endl;
//a=readHight()/100;
//cout<<"Podaj swoja wage (w kg)."<<endl;
//b=readMass();
//c=BMI(a,b);
//cout<<"Mierzysz: "<<a<<"m i wazysz: "<<b<<"kg."<<" Twoj wskaznik BMI wynosi: "<<BMI(a,b)<<endl;
//BMIprint(a,b,c);
BMIprint(BMI(readHight(),readMass()))<<endl;
return 0;
}
