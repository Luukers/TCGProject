#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Card.h"
#include <iostream>
#include <sstream>
#include <string>

// functions

// input lock for double for cin
double check_if_double()
{
    std::cin.clear();
    fflush(stdin);
    std::string line;
    double d;
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        if (ss >> d)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        std::cout << "Error, please decimal number, susing a dot." << std::endl;
    }
    return d;
}

// double to string with standart 0.00 precision
std::string to_string_with_precision(const double a_value, const int n = 2)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return std::move(out).str();
}

#endif