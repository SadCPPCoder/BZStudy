/******************************
* author:zhang, bob
* date: 2020-03-31
* description: Thread api demo.
******************************/

#include <iostream>
#include <thread>
#include <memory>
#include <random>
#include <chrono>

void doSomething(char ch)
{
    using namespace std::chrono;

    // If the backgournd thread throw an exception, and we do not capture it,
    // the program will stop immediately and call std::terminate().
    try
    {
        std::default_random_engine dre(system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> id(20, 1000);

        auto two_secs_later = system_clock::now() + seconds(2);
        while(system_clock::now() < two_secs_later)
        {
            std::cout << ch;
            std::this_thread::sleep_for(milliseconds(id(dre)));
        }
    }
    catch(...)
    {
        std::cout << "error happends in doSomething.\n";
    }
}

auto del = [](int *p){if(p){std::cout << "delete: " << *p << std::endl; delete p;}};


int main()
{
    static std::shared_ptr<int> pLocalStatic(new int(2), del);

    std::shared_ptr<int> pLocal(new int(3), del);

    // here we should capture the unexpected exception
    // std::system_error, if cannot run the target function in a new thread.
    try
    {
        std::thread backThread(doSomething, '#');
        // If we do not detach() or join() a thread, when thread liftime finished,
        // or the thread object has a move assignment, the program will stop 
        // immediately and call std::terminate().
        backThread.detach();
    }
    catch(...)
    {
        std::cout << "start thread faild.\n";
    }

    std::shared_ptr<int> pLocal2(new int(9), del);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // all threa thread will force stopped after main function finished.
}

std::shared_ptr<int> pGlobal(new int(0), del);
static std::shared_ptr<int> pGlobalStatic(new int(6), del);
std::shared_ptr<int> pGlobal2(new int(1), del);
