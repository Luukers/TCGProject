#include "Card.h"
#include "functions.h"
#include <windows.h>
#include <string>
#include <sstream>
using namespace std;


// adds Current price by typing and current
void Card::addCurrentPrice()
{   
    // current date:
    SYSTEMTIME currentTime;
    GetLocalTime(&currentTime);
    std::stringstream ss;
    ss << currentTime.wYear << "." << currentTime.wMonth << "." << currentTime.wDay;
    std::string currentDate = ss.str();
    dateCurrentPrice.push_back(currentDate);
    // current price:
    cout << "Type in current Price: " << endl;
    double price = check_if_double();
    currentPrice.push_back(price);
}

void Card::showPriceHistory()
{
    for (size_t i = 0; i < currentPrice.size(); i++)
    {
        cout << "Date: " << dateCurrentPrice[i] << " Price: " << currentPrice[i] << endl;
    }
}

void fillCardList(vector <Card*>& cardList)
{
    
}