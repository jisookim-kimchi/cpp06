#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate()
{
    switch (rand() % 3)
    {
        case 0: return new A();
        case 1: return new B();
        default : return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch(...){}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } 
    catch(...){}
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (...){}
}

int main()
{
    srand(time(0));
    Base *object = generate();
    identify(object);
    delete object;

    return 0;
}