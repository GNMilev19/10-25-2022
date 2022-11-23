
#include <iostream>
#include<atomic>
#include<thread>
using namespace std;



atomic<int> number(0);



void increment(int n)
{
    for (size_t i = 0; i < n; i++)
    {
        number++;
    }
}



int main()
{
    thread t1(increment, 10000);
    thread t2(increment, 10000);
    thread t3(increment, 10000);



    t1.join();
    t2.join();
    t3.join();



    cout << number << "\n";



    //atomic<int> i(15);



    /*i = 20;
     i++;



    cout << i << "\n";*/
}