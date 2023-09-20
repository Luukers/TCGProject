#include "Card.h"
#include <sstream>
#include <string>

// forward declaration
class Card;
// functions
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

