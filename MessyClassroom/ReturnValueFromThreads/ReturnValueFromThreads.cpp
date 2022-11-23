#include<thread>
#include <iostream>
using namespace std;



void calcFib(int n, int* result)
{
    int t1 = 0, t2 = 1, nextTerm = 0;




    nextTerm = t1 = t2;



    while (nextTerm <= n)
    {
        *result += nextTerm;
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}



void sum(int a, int b, int& result)
{
    result = a + b;
}



int main()
{
    int result1 = 0;



    /*thread t1(calcFib, 10, &result1);*/



    thread t1(sum, 5, 6, std::ref(result1));



    t1.join();
    cout << result1 << "\n";
}