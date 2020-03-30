/****************************************
* author: zhang, bob
* date: 2020-03-30
* description: example for time_point
****************************************/
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;
using namespace std::chrono;

string asString(const system_clock::time_point& tp)
{
    time_t t = system_clock::to_time_t(tp);
    string ts = ctime(&t);
    ts.resize(ts.size()-1);
    return ts;
}

int main(void)
{
    auto nowTime = system_clock::now();
    cout << "now time: " << asString(nowTime) << endl;

    auto oneMinLater = nowTime + minutes(1);
    cout << "one minute later: " << asString(oneMinLater) << endl;

    auto diffDur = oneMinLater - nowTime;
    cout << "one minute later and now time's diff duration count:" << diffDur.count() << ", duration unit: " << double(decltype(diffDur)::period::num)/decltype(diffDur)::period::den << "s\n";
}
