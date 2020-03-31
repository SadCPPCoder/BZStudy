// this file is the example code from "C++ Standard Library ED2"
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <random>
#include <memory>
#include <typeinfo>

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

enum var_type
{
    var_local = 0,
    var_local_static,
    var_global,
    var_global_static,
    var_type_cnt,
};

string varTypeStr(int type)
{
    static string type_arr[var_type_cnt] = {"var_local", "var_local_static", "var_global", "var_global_static"};

    if(type<var_type_cnt)
    {
        return type_arr[type];
    }

    return "error type";
}

auto del = [](int* p)
{
    if(p)
    {
    cout << "del type: " << *p << "-" << varTypeStr(*p) << endl;
    delete p;
    p = nullptr;
    }
};

void outputTest()
{
    using namespace std::chrono;
    auto threr_secs_later = system_clock::now() + seconds(1);
    while(system_clock::now() < threr_secs_later)
    {
        cout << '%';
        this_thread::yield();
    }
}

void async_demo_exit()
{
    shared_ptr<int> pInFunc(new int(var_local), del);
    auto f = async(launch::async, outputTest);   
    f.get();
}

static shared_ptr<int> pGlobalStatic(new int(var_global_static), del);
int main()
{
    //async_demo0();
    //async_demo1();
    //async_demo2(true);
    //async_demo2(false);

    static shared_ptr<int> pStaticMain(new int(var_local_static), del);
    shared_ptr<int> pMain(new int(99), del);

    async_demo_exit();

    cout << "enum item name: " << typeid(var_global).name() <<endl;
}
