#include <chrono>
#include <thread>
#include <iostream>

using namespace std;
using namespace std::chrono;

void doStuff(){
    cout << "Loop executed"<<endl;
}

int main() {
int i=0;
    time_point<system_clock> t = system_clock::now();

    while (1) {
        doStuff();
	i+=1;
        t += milliseconds(33);
        this_thread::sleep_until(t);
	if(i==33)
{
cout<<i<<endl;
i=0;
}
    }
}
