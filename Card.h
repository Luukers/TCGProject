#ifndef CARD_H
#define CARD_H

#include "functions.h"
#include <iostream>
#include <vector>
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

    virtual void addCurrentPrice(double price) = 0;
    virtual void addCurrentPrice(double price, string date) = 0;
    virtual void showPriceHistory()const = 0;

    Product(string _name,  string _setName, string _language, string _releaseDate, double _purchasePrice, string _bonusInfo):
    name(_name), setName(_setName), language(_language), releaseDate(_releaseDate), purchasePrice(_purchasePrice), bonusInfo(_bonusInfo){}

    virtual ~Product(){}
};



class Card : public Product
{
    public:
        
        string cardNumber;
        string artist;
        bool graded;
        double grade;
        bool holo;
        bool reverseHolo;
        bool fullArt;
        bool extendetArt;
        

        Card( string _name, string _setName, string _language, string _cardNumber, string _releaseDate, double _purchasePrice, string _artist, bool _graded, double _grade, bool _holo, bool _reverseHolo, bool _fullArt, bool _extendetArt, string _bonusInfo):
        Product(_name, _setName, _language, _releaseDate, _purchasePrice, _bonusInfo), cardNumber(_cardNumber), artist(_artist), graded(_graded), grade(_grade), holo(_holo), reverseHolo(_reverseHolo), extendetArt(_extendetArt) {}

        ~Card(){}
        
        void addCurrentPrice(double price) override;
        void addCurrentPrice(double price, string date) override;
        void showPriceHistory()const override ;
          
};

class sealedBooster: public Product
{

};

class sealedBoosterBox: public Product
{

};

void fillCardList(vector <Card*>& cardList, string filename);
void emtpyCardList(vector <Card*>& cardList, string filename);

#endif