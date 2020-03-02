#include <iostream>
using namespace std;

int main(void)
{
int i=2;
double m=1;
while (i<21)
{
m=i*m;
i=i+1;
cout <<fixed<<"Silnia dla "<<i<<" wynosi: "<< m<<endl;
}
}

