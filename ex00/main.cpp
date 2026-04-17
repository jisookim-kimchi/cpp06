/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:47:27 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 16:30:35 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

int main()
{
    std::cout << "char test" << std::endl;
    std::cout << std::endl;
    ScalarConverter::convert("a");
    ScalarConverter::convert("\n");
    
    std::cout << "int test" << std::endl;
    std::cout << std::endl;
    ScalarConverter::convert(std::to_string(std::numeric_limits<int>::max()));
    ScalarConverter::convert(std::to_string(std::numeric_limits<int>::min()));
    
    std::cout << "float test" << std::endl;
    std::cout << std::endl;
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-4.2f");
    ScalarConverter::convert("340282346638528859811704183484516925440.0f"); // float max
    ScalarConverter::convert("inff");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("nanf");

    std::cout << "double test" << std::endl;
    std::cout << std::endl;
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("42.42");
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("-4.2");
    ScalarConverter::convert("1.79769e+308"); //double max
    ScalarConverter::convert("inf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("nan");

    std::cout << "invalid test" << std::endl;
    ScalarConverter::convert("");
    ScalarConverter::convert("hello");
    ScalarConverter::convert("123abc");
    ScalarConverter::convert("++42");
    ScalarConverter::convert("--42");
    return 0;
}