#include "ScalarConverter.hpp"
#include <cctype>
#include <limits>

namespace
{
    bool isChar(const std::string& str)
    {
        if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
            return true;
        return false;
    }

    bool isInt(const std::string& str)
    {
        if (str.empty())
            return false;
        if (str[0] == '-' || str[0] == '+')
        {
            if (str[1] == '\0')
                return false;
            for (size_t i = 1; i < str.length(); i++)
            {
                if (!std::isdigit(str[i]))
                    return false;
            }
        }
        else
        {
            for (size_t i = 0; i < str.length(); i++)
            {
                if (!std::isdigit(str[i]))
                    return false;
            }
        }
        long long val = std::atol(str.c_str());
        if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
            return false;
        return true;
    }

    bool isFloat(const std::string& str)
    {
        if (str == "-inff" || str == "+inff" || str == "nanf")
            return true;
        if (str.empty() || str[str.length() - 1] != 'f')
            return false;
        size_t length = str.length() - 1;
        short dot_count = 0;
        short digit_count = 0;
        
        for (size_t i = 0; i < length; i++)
        {
            if (i == 0 && (str[i] == '-' || str[i] == '+'))
                continue;
            if (str[i] == '.')
            {
                dot_count++;
                if (dot_count > 1)
                    return false;
            }
            else if (!std::isdigit(str[i]))
                return false;
            else
                digit_count++;
        }
        if (digit_count == 0)
            return false;
        return true;
    }

    bool isDouble(const std::string &str)
    {
        if (str == "-inf" || str == "+inf" || str == "nan")
            return true;
        if (str.empty())
            return false;
        size_t length = str.length();
        short dot_count = 0;
        short digit_count = 0;
        
        for (size_t i = 0; i < length; i++)
        {
            if (i == 0 && (str[i] == '-' || str[i] == '+'))
                continue;
            if (str[i] == '.')
            {
                dot_count++;
                if (dot_count > 1)
                    return false;
            }
            else if (!std::isdigit(str[i]))
                return false;
            else
                digit_count++;
        }
        if (digit_count == 0)
            return false;
        if (dot_count == 0)
            return false;
        return true;
    }

    void printChar(char c, int i, const std::string& str)
    {
        if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || i < 0 || i > 255)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(c)) 
            std::cout << "char: Non displayable" << std::endl;
        else 
            std::cout << "char: '" << c << "'" << std::endl;
    }

    void printInt(int i, const std::string& str)
    {
        if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
    }

    void printFloat(float f)
    {
        if (f == static_cast<int>(f))
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
    }

    void printDouble(double d)
    {
        if (d == static_cast<int>(d))
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
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
    char c = 0;
    int i = 0;
    float f = 0;
    double d = 0;
    
    if (isChar(str))
    {
        c = str[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt(str))
    {
        i = std::atoi(str.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (isFloat(str))
    {
        f = static_cast<float>(std::atof(str.c_str()));
        i = static_cast<int>(f);
        c = static_cast<char>(f);
        d = static_cast<double>(f);
    }
    else if (isDouble(str))
    {
        d = std::atof(str.c_str());
        i = static_cast<int>(d);
        c = static_cast<char>(d);
        f = static_cast<float>(d);
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }

    printChar(c, i, str);
    printInt(i, str);
    printFloat(f);
    printDouble(d);
}