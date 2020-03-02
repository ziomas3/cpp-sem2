#include <iostream>
using namespace std;
void zmien_a(int a)
{
    a=5;
}
int main()
{
    int a=1;
    zmien_a(a);
    cout << a << endl;
    return 0;
}
