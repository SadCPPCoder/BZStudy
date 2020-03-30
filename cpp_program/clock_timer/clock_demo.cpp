/******************************************
* author: Zhang, Bob
* date: 2020.03.26
* description: colock related function practice.
******************************************/

#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <string>

using namespace std;
using namespace chrono;

string getTimeString(system_clock::time_point &tp)
{
    time_t tt = system_clock::to_time_t(tp);
    return ctime(&tt);
}

int main()
{
    auto nowTime = system_clock::now();

    cout << "current time: " << getTimeString(nowTime);
    
    auto oneMinLater = nowTime + minutes(1);

    cout << "one minute later: " << getTimeString(oneMinLater);
    
    do
    {
        // If we change our system time to 2 minutes before, then the while loop
        // will totoaly run 3 minutes.
        nowTime = system_clock::now();
        cout << "current time: " << getTimeString(nowTime);
        cout << "one minute later: " << getTimeString(oneMinLater);
        this_thread::sleep_for(seconds(5));

    } while(nowTime < oneMinLater);
}
