#include <iostream>
#include<thread>
#include<string>
#include<iomanip>
#include<mutex>

using namespace std;

string msgs[]{
    "Blabla", "Azis", "Galena",
    "Fiki", "Preslava", "Toni", "Storaro"
};

void log(string msg)
{
    auto tid = this_thread::get_id();
    cout << tid << setw(5) << " | " << msg << endl;
}

mutex mu;

int getRandNumber(int upperLimit)
{
    lock_guard<mutex> lock(mu);

    return rand() % upperLimit;
}

void sleepRandMillis()
{
    int millis = getRandNumber(1000) + 800;

    this_thread::sleep_for(chrono::milliseconds(millis));
}

void studentThreadFunc() 
{
    rand();
    while (true) 
    {
        int index = getRandNumber(7);

        cout << msgs[index] << endl;
        sleepRandMillis();
    }
}

int main()
{
    thread student1(studentThreadFunc);
    sleepRandMillis();
    thread student2(studentThreadFunc);
    sleepRandMillis();

    student1.join();
    student2.join();
}
