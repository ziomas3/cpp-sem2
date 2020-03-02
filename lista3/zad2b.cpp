#include <iostream>

using namespace std;

int main()
{
	int a, sum = 0 ;

       /* or use this
            int a,sum;
            sum = 0;
        */

 
	int arrayname[] = {1, 2, 3, 4, 5};

	for (a=0; a<5; a++)
	{
		

		sum+=arrayname[a];
	}

	cout << sum << endl;

	return 0;
}
