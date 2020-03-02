#include <iostream>
using namespace std;

int main(void)
{
int i=0;
while (i<6)
 {
cout<<"\x1b["<<i<<"m tekst "<<i<<"\x1b[0m"<<"     kod:"<<i<<endl;
i=i+1;
}
i=30;
while (i<38) 
{
if(i==30)
cout<<"\x1b[47;"<<i<<"m tekst "<<"\x1b[0m"<<"     kod:"<<i<<endl;
else 
cout<<"\x1b["<<i<<"m tekst "<<"\x1b[0m"<<"     kod:"<<i<<endl;
i=i+1;
}
i=40;
while (i<48)
{
if(i==47)
cout<<"\x1b[30;"<<i<<"m tekst "<<"\x1b[0m"<<"     kod:"<<i<<endl;
else
cout<<"\x1b["<<i<<"m tekst "<<"\x1b[0m"<<"     kod:"<<i<<endl;
i=i+1;
}
}

