#include "Product.h"
#include <fstream>
using namespace std;


// Windows Only - adds Current price by typing and current date automatically 
/* void Card::addCurrentPrice(double price)
{   
    // current price:
    priceHistory.push_back(price);
    // current date:
    SYSTEMTIME currentTime;
    GetLocalTime(&currentTime);
    std::stringstream ss;
    ss << currentTime.wDay << "." << currentTime.wMonth << "." << currentTime.wYear ;
    std::string currentDate = ss.str();
    dateForPricehistory.push_back(currentDate);
}*/

// fill member vectors with objects proce data from namefitting csv file
void Product::fetchPriceHistory()
{
    string filepath = "csv_files/prices/" + name + "_" + setName + ".csv";
    ifstream file(filepath);
    if (!file.is_open())  
    {                    
        cerr << "Error, " << filepath << " could not be opened." << endl;
    }
    else
    {   
        cout << filepath << " was opened for fetching price info." << endl;
        string line;
        stringstream lineStorage;
        string _date;
        double _price;
        // skip first line of csv
        getline(file, line);
        // fetch infos and fill vector with ptr to card
        while (getline(file, line))
        {
            lineStorage << line;
            getline(lineStorage, _date, ',');
            dateForPricehistory.push_back(_date);
            lineStorage >> _price; lineStorage.ignore();
            priceHistory.push_back(_price);
        }  
    }
}

// adds current price by userinput
void Product::addCurrentPrice(double price, string date)
{   
    // current date:
    dateForPricehistory.push_back(date); 
    // current price:
    priceHistory.push_back(price);
}

// shows price history of a single card
void Product::showPriceHistory() const
{
    if(!priceHistory.empty())
    {
        cout << endl;
        cout << name << " from " << setName << " price history:" << endl;
        for (size_t i = 0; i < priceHistory.size(); i++)
        {
            cout << "Date: " << dateForPricehistory[i] << "  Price: " << priceHistory[i] << endl;
        }
        cout << endl;
    }
    else
    cout << name << " from " << setName << " price history is empty" << endl;
}

