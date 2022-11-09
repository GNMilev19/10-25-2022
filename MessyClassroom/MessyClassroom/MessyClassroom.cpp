#include <iostream>
#include <iomanip>
#include <thread>
#include <string>
#include <mutex>
#include <random>
#include <conio.h>



using namespace std;





string msgs[]{
    "Kude si", "Off", "Da tochno","Beshe qsno"
    "eiii", "vurni tela", "molqta"
};





void log(string msg)
{
    auto tid = this_thread::get_id();
    cout << tid << setw(5) << " | " << msg << "\n";
}



mutex mu;




int getRandomNumber(const int& min, const int& max) {
    static thread_local std::random_device rd;
    static thread_local std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}




void sleepRandMillis()
{
    int millis = getRandomNumber(800, 1000);



    this_thread::sleep_for(chrono::milliseconds(millis));
}



bool doExit = false;



void studentThreadFunc()
{
    rand();



    while (true)
    {
        int index = getRandomNumber(0, 6);



        cout << msgs[index] << "\n";



        if (doExit == true) {
            log("Exitting....");
            break;
        }



        sleepRandMillis();
    }
}



int main()
{
    thread student1(studentThreadFunc);
    sleepRandMillis();
    thread student2(studentThreadFunc);
    sleepRandMillis();
    thread student3(studentThreadFunc);
    sleepRandMillis();



    while (true) {
        auto keyCode = _getch();



        if (keyCode == 27) {
            doExit = true;
            break;
        }
        if (keyCode == 32) {


        }
    }



    auto keyCode = _getch();



    cout << keyCode;



    student1.join();
    student2.join();
    student3.join();
}