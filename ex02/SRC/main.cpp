/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:48:17 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 14:00:08 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/A.hpp"
#include "../HEADER/B.hpp"
#include "../HEADER/C.hpp"
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
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A\n";
        return;
    }
    catch(...){}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B\n";
        return;
    } 
    catch(...){}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C\n";
        return;
    }
    catch (...){}
}

int main()
{
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        Base *object = generate();
        std::cout << "Pointer: ";
        identify(object);
        std::cout << "Reference: ";
        identify(*object);
        std::cout << "--------------------" << std::endl;
        delete object;
    }

    return 0;
}
