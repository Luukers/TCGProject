#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Card
{
    public:
        string name;
        string set;
        string cardNumber;
        string setName;
        string artist;
        string releaseDate;
        double purchasePrice;
        vector <double> currentPrice;
        vector <string> dateCurrentPrice;
        bool graded;
        double grade;
        bool holo;
        bool reverseHolo;
        bool fullArt;
        bool extendetArt;
        string bonusInfo;

        Card(string _name, string _set, string _cardNumber, string _setName, string _artist, string _releaseDate, double _purchasePrice):
        name(_name), set(_set), cardNumber(_cardNumber), setName(_setName), artist(_artist), releaseDate(_releaseDate), purchasePrice(_purchasePrice){}

        ~Card(){}

        void addCurrentPrice();
        void showPriceHistory();   
};

void fillCardList(vector <Card*>& cardList);