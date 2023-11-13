#include "Functions.h"
#include <iostream>
#include <sstream>
using namespace std;

// converts double to string with standartprecision of .2
string to_string_with_precision(double a_value, const int n)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return std::move(out).str();
}

// userinput lock for int only
int check_if_int()
{
    std::cin.clear();
    fflush(stdin);
    std::string line;
    int d;
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
        std::cerr << "Input has to be an integer. Please enter again: " << std::endl;
    }
    return d;
}

// userinput lock for doubles only
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
        std::cerr << "Input has to be a decimal number. Please enter again: " << std::endl;
    }
    return d;
}

// userinput lock for bool only
int check_if_bool()
{
    int input;
    bool boolValue;

    while (true) {
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Wrong input." << std::endl;
            continue;
        }

        if (input == 0 || input == 1) {
            boolValue = static_cast<bool>(input);
            break;
        } else {
            std::cerr << "Input has to be 0 or 1. Please enter again: " << std::endl;
        }
    }
    return boolValue;
}

