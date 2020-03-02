#include <iostream>
#include <fstream>
using namespace std;
    const int H=1024;
    const int W=1024;
    int R[H][W];
    int G[H][W];
    int B[H][W];

void clear(int tab[H][W])
{
    for (int i=0;i<W;i++)
        for (int j=0;j<H; j++)
            tab[j][i]=0;
}
void saveppm(int _R[H][W],
    int _G[H][W],
    int _B[H][W])
{
    ofstream rys("rysunek.ppm");
    //rys << "Hallo!"<<endl;
    rys <<"P3"<<endl<<"# nasz pierwszy rysunek"<<endl<<W<<" "<<H<<endl<<255<<endl;
    for (int i=0;i<W;i++)
       {
           for (int j=0;j<H; j++)
           {
               rys <<_R[j][i]<< " " <<_G[j][i]<< " "<<_B[j][i]<<" ";
           }
       }


    rys.close();
}
int main(void)
{
    clear(R);
    clear(G);
    clear(B);
    saveppm(R,G,B);

return 1;
}
