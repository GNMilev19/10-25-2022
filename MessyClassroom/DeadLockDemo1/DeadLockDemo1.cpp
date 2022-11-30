#include <iostream>
#include<thread>
#include<mutex>
#include<string>
#include<iomanip>



using namespace std;



void log(string msgs)
{
    auto tid = this_thread::get_id();
    cout << tid << setw(5) << " | " << msgs << "\n";
}



mutex mu1;
mutex mu2;



void func1()
{
    log("Func1: Trying to lock mu1");



    lock_guard<mutex> lock1(mu1);



    log("Func1: Trying to lock mu2");



    lock_guard<mutex> lock2(mu2);



    log("Func1: Locked mu2. Doing some heavy work");



    // DO some stuff
    this_thread::sleep_for(chrono::milliseconds(800));



    log("Func1: Done");
}



void func2()
{
    log("Func2: Trying to lock mu2");



    lock_guard<mutex> lock2(mu2);



    log("Func2: Trying to lock mu1");



    lock_guard<mutex> lock1(mu1);




    log("Func2: Locked mu2. Doing some heavy work");



    // DO some stuff
    this_thread::sleep_for(chrono::milliseconds(800));



    log("Func2: Done");
}



int main()
{
    thread t1(func1);
    thread t2(func2);



    log("MT: waiting for t1 and t2");



    t1.join();
    t2.join();



    log("MT: done");
}