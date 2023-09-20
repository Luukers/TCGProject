#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Card
{
    public:
        string name;
        string setName;
        string cardNumber;
        string releaseDate;
        string artist;
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

        Card(string _name, string _setName, string _cardNumber, string _releaseDate, string _artist, double _purchasePrice , bool _graded, double _grade, bool _holo, bool _reverseHolo, bool _fullArt, bool _extendetArt, string _bonusInfo):
        name(_name), setName(_setName), cardNumber(_cardNumber), releaseDate(_releaseDate), artist(_artist), purchasePrice(_purchasePrice), graded(_graded), grade(_grade), holo(_holo), reverseHolo(_reverseHolo), extendetArt(_extendetArt), bonusInfo(_bonusInfo){}

        ~Card(){}

        void addCurrentPrice();
        void showPriceHistory();   
};

void fillCardList(vector <Card*>& cardList);
void emtpyCardList(vector <Card*>& cardList);