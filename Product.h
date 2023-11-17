#pragma once
#include "Functions.h"
#include <iostream>
#include <vector>
#include <sstream>
// include <windows.h>
using namespace std;

class Product
{
    public:
    string name;
    string setName;
    string language;
    string releaseDate;
    double purchasePrice;
    string bonusInfo;

    vector <string> dateForPricehistory;
    vector <double> priceHistory;

    // void addCurrentPrice(double price); // automatic date filling
    void fetchPriceHistory();
    void addCurrentPrice(double price, string date);
    void showPriceHistory()const;
    virtual void printInfos() const = 0;
    void ofstreamPriceHistory();

    Product(){}
    // overloaded constructor also executes data collecting for objects price history
    Product(string _name,  string _setName, string _language, string _releaseDate, double _purchasePrice, string _bonusInfo):
    name(_name), setName(_setName), language(_language), releaseDate(_releaseDate), purchasePrice(_purchasePrice), bonusInfo(_bonusInfo)
    {}

    virtual ~Product(){}
};




/* 
class sealedBooster: public Product
{
    
};

class sealedBox: public Product
{

};
*/


