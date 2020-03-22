// this file is the example code from "C++ Standard Library ED2"
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <random>

using namespace std;

int doSomething(char c)
{
    // random-number generator(use c as seed to get different sequences)
    default_random_engine dre(c);
    uniform_int_distribution<int> id(10,1000);

    // print thread number
    cout << "create async thread with id: " << this_thread::get_id() << ".\n";

    // loop to print character after a random period of time
    for(int i=0; i<10; ++i)
    {
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }

    return c;
}

int func1()
{
    return doSomething('.');
}

int func2()
{
    return doSomething('+');
}

int async_demo0()
{
    cout << "starting func1() in background"
         << " and func2() in foreground: " << endl;

    // start func1() asynchronously(now or later or never);
    future<int> result1(std::async(func1));

    int result2 = func2(); // call func2() synchronously(here and now)

    // print result(wait for func1() to finish and add its result to result2
    int result = result1.get() + result2;

    std::cout << "\nresult of func1()+func2(): " << result << endl;
}

int do_something_ver_1(int type)
{
	cout << __func__ << endl;

	if(type<10)
    {
    	cout << "\tthrow a double type exception\n";
		throw 1.6;
    }
	else if(type>100)
    {
	    cout << "\tthrow a string type exception\n";
		throw "hello";
    }

    cout << "\tcalculate finished!\n";
    return 1;
}

void async_demo1()
{
    auto f1 = async(launch::async, do_something_ver_1, 9);
    auto f2 = async(launch::async, do_something_ver_1, 999);
    auto f3 = async(launch::async, do_something_ver_1, 99);

    try
    {
        f1.get(); // capture the double exception
        f2.get(); // throw string exception
        f3.get(); // run well
    }
    catch(const double& err)
    {
        cout << "catch a double exception!\n";
    }
    catch(...)
    {
        cout << "oops! catch a unknown exception.\n";
    }
}

void async_demo2(bool flag)
{
    auto f1 = async(launch::deferred, doSomething, '*');
    auto f2 = async(launch::deferred, doSomething, '+');

    auto result = flag ? f1.get() : f2.get();

    cout << "lazy evaluation result: " << result << ".\n";
}

int main()
{
    //async_demo0();
    //async_demo1();
    async_demo2(true);
    async_demo2(false);
}
