#include<iostream>
using namespace std;
int factorial(int n);
int main()
{
    int n=2;
while (n<21)
{
    cout << "Silnia z " << n << " = " << factorial(n)<<endl;
n=n+1;
    }
return 0;
}
int factorial(int n)
{
    if(n!=1)
     return n*factorial(n-1);
}

