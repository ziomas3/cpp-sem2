#include <unistd.h>

#include <iostream>

#include <cstdio>

#include <cstdlib>

using namespace std;

 

const int NX = 20;

const int NY = 15;

 

typedef struct

{

   int x;

   int y;

} wektor;

 

typedef struct 

{

   wektor p;

   wektor v;

   void rysuj()

   {

 cout << "\x1b[" << p.y << ";" << p.x << "Hx" << endl;

   }

   

   float m;

} point;

 

void przesun(point *r)

{

   r->p.x = r->p.x + r->v.x;

   r->p.y = r->p.y + r->v.y;

   if(r->p.x >= NX) r->v.x *= (-1);

   if(r->p.y >= NY) r->v.y *= (-1);

   if(r->p.x <= 0) r->v.x *= (-1);

   if(r->p.y <= 0) r->v.y *= (-1);  

}

 

int main()

{

   const int N = 5;

   point punkty[N];

 

   for(int i=0; i<N; i++)

{   

 

      punkty[i].p.x = N * (rand()/(float)RAND_MAX);

  punkty[i].p.y = i;

      punkty[i].v.x = 1;

      punkty[i].v.y = 1.5;

}

   

 

   for(;;)

{

 

//p1.p.x += 1;

//if(p1.p.x > 20) p1.p.x = 1;

 

  for(int i=0; i<N; i++)

  przesun( & (punkty[i]) );

 

  cout << "\x1b[2J\n";

  

  for(int i=0; i<N; i++) 

punkty[i].rysuj();

  

usleep(75000);

}   

   

   return 0;

}
