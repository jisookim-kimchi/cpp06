#include "Base.hpp"
#include <iostream>

Base::~Base()
{
    std::cout << "Base destructed" << std::endl;
}
