/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:47:33 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 16:51:28 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <limits>
#include <cmath>
#include <iomanip>

namespace
{
    bool isChar(const std::string& str)
    {
        if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
            return true;
        return false;
    }

    bool isInt(const std::string& str)
    {
        if (str.empty())
            return false;
        if (str[0] == '-' || str[0] == '+')
        {
            if (str.length() == 1)
                return false;
            for (size_t i = 1; i < str.length(); i++)
            {
                if (!std::isdigit((static_cast<unsigned char>(str[i]))))
                    return false;
            }
        }
        else
        {
            for (size_t i = 0; i < str.length(); i++)
            {
                if (!std::isdigit((static_cast<unsigned char>(str[i]))))
                    return false;
            }
        }
        try
        {
            long long val = std::stol(str.c_str());
            if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
                return false;
        }
        catch(...)
        {
            return false;
        }
        return true;
    }

    bool isFloat(const std::string& str)
    {
        if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
            return true;
        if (str.empty() || str[str.length() - 1] != 'f')
            return false;
        std::string temp = str.substr(0, str.length() - 1);
        char* endptr = NULL;
        std::strtod(temp.c_str(), &endptr);
        return (*endptr == '\0');
    }

    bool isDouble(const std::string &str)
    {
        if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
            return true;
        char* endptr = NULL;
        std::strtod(str.c_str(), &endptr);
        if (*endptr == '\0' && (str.find('.') != std::string::npos || str.find('e') != std::string::npos))
            return true;
        return false;
    }

    void printChar(double d)
    {
        std::cout << "char: ";
        if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
            std::cout << "impossible" << std::endl;
        else if (!std::isprint(static_cast<int>(d))) 
            std::cout << "Non displayable" << std::endl;
        else 
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    void printInt(double d)
    {
        std::cout << "int: ";
        if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(d) << std::endl;
    }

    void printFloat(double d)
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    }

    void printDouble(double d)
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

void ScalarConverter::convert(const std::string& str)
{
    double d;
    
    if (isChar(str))
    {
        d = static_cast<double>(str[0]);
    }
    else if (isInt(str) || isFloat(str) || isDouble(str))
    {
        d = std::atof(str.c_str());
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
    std::cout << std::endl;
}