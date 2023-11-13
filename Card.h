#pragma once
#include "Product.h"
using namespace std;


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

        void printInfos()const override;

        Card(){}
        
        Card(string _name, string _setName, string _language, string _cardNumber, string _releaseDate, double _purchasePrice, string _artist, bool _graded, double _grade, bool _holo, bool _reverseHolo, bool _fullArt, bool _extendetArt, string _bonusInfo):
        Product(_name, _setName, _language, _releaseDate, _purchasePrice, _bonusInfo), cardNumber(_cardNumber), artist(_artist), graded(_graded), grade(_grade), holo(_holo), reverseHolo(_reverseHolo), extendetArt(_extendetArt) {}

        ~Card(){}       
};

void fillCardList(vector <Card*>& cardList, string filename);
void emtpyCardList(vector <Card*>& cardList, string filename);
void addCard(vector <Card*>& cardList);



