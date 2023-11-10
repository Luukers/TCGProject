#pragma once
#include <iostream>
#include <vector>
#include <sstream>

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

    vector <double> currentPrice;
    vector <string> dateCurrentPrice;

    // virtual void addCurrentPrice(double price) = 0;
    virtual void addCurrentPrice(double price, string date) = 0;
    virtual void showPriceHistory()const = 0;

    Product(){}

    Product(string _name,  string _setName, string _language, string _releaseDate, double _purchasePrice, string _bonusInfo):
    name(_name), setName(_setName), language(_language), releaseDate(_releaseDate), purchasePrice(_purchasePrice), bonusInfo(_bonusInfo){}

    virtual ~Product(){}
};


class sealedBooster: public Product
{
    
};

class sealedBox: public Product
{

};



