#include <iostream>
using namespace std;

///a)
void a()
{
cout<<"Hello World"<<endl;
}
///b)
float b(float q)
{
return q;
}
///c)
int c(int w,int g)
{
return w+g;
}
///d)
float d(int h,float j,float k)
{
return h*j*k;
}
//e1)
int e1(int x)
{
int z,i=1,tab[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
for(z=0;z<x;z++)
{
i=tab[z]*i;
}
return i;
}
//e2)
int e2(int x)
{
int z,tab[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
z=sizeof(tab);
return z;
}
//f)
int f()
{
int p=0,o=0,q=0,i=0,tab[4][3]={{1,2,3},{1,2,3},{1,2,3},{1,2,3}};
do
{
q=q+tab[i][o];
i=i+1;
p=p+1;
if(p==12 && o==2)
{
break;
}
else if(p%4 == 0)
{
i=0;
o=o+1;
}
}while(i<4);
return q;
}



int main(void)
{
float q,j,k;
int w,g,h,x;
//a)
a();
//b)
cout<<"Podaj wartosc do pkt. b"<<endl;
cin>>q;
cout<<"Wartosc jaka wpisales to: "<<b(q)<<endl;
//c)
cout<<"Podaj dwie wartosci do pkt.c"<<endl;
cin>>w>>g;
cout<<"Suma tych wartosci to: "<<c(w,g)<<endl;
//d)
cout<<"Podaj trzy wartosci do pkt.d. Pierwszą calkowita, pozostale moga byc rzeczywiste."<<endl;
cin>>h>>j>>k;
cout<<"Iloczyn tych wartosci to: "<<static_cast<int>(d(h,j,k))<<endl;
//e)
cout<<"Tablica sklada sie z 15 wartosci calkowitych od 1 do 15. Z ilu jej wartosci chcesz poznac iloczyn ?"<<endl;
cin>>x;
cout<<"Iloczyn pierwszych "<<x<<" wartosci jest rowny: "<<e1(x)<<endl;
cout<<"Całkowity rozmiar tablicy jest rowny: "<<e2(x)<<" bajtów."<<endl;
//f)
cout<<"Dana jest tablica dwuwymiarowa 4x3 o wartosciach 1,2,3. Suma jej elementow jest rowna: "<<f()<<endl;
return 0;
}
