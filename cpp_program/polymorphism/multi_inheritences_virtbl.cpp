#include <iostream>
#include <typeinfo>

#define OUTPUT(msg) std::cout << __func__ << ": type: " << #msg << std::endl;

class A 
{ 
public: 
    virtual void output(){OUTPUT(A);} 
};
class B 
{ 
public: 
    virtual void output(){OUTPUT(B);} 
};
class C : public A
{ 
public: 
    virtual void output(){OUTPUT(C)} 
};
class D : public A, public B
{ 
public: 
    virtual void output(){OUTPUT(D)} 
};

template<class T>
void outputType(T type)
{
    std::cout << "Type: " << typeid(type).name() << ", size: " << sizeof(type) << std::endl;
}

int main()
{
    A a;
    B b;
    C c;
    D d;

    outputType(a);
    outputType(b);
    outputType(c);
    outputType(d);

    std::cout << "obect call: " << std::endl;
    a.output();
    b.output();
    c.output();
    d.output();

    std::cout << "virtual call: \n";
    A *pa = &a;
    pa->output();
    pa = &c;
    pa->output();
    pa = &d;
    pa->output();

    B *pb = &b;
    pb->output();
    pb = &d;
    pb->output();

}
