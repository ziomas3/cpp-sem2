#include<iostream>
using namespace std;
int silnia(int n);
int main(void)
{
    int n=2;
    while(n<21)
    {
    cout << "silnia z " << n << " = " << silnia(n) <<endl;
    n=n+1;
}
    return 0;
    
}
int silnia(int n)
{
    if(n!=1)
     return n*silnia(n-1);
}

