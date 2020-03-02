#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void)
{
  for(double i=-M_PI;i<M_PI;i=i+0.02)
  {
		double sin( double i );
		cout<<setprecision(2)<<fixed<<i<<"	"<<sin (i)<<"	"<<sin (i)*sin (i)<<endl;
  }
}
