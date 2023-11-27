#pragma once
#include "Product.h"

using namespace std;

class SealedBox : public Product
{
    public:

    void printInfos()const override;
    
    SealedBox(string _name,  string _setName, string _language, string _releaseDate, double _purchasePrice, string _bonusInfo):
    Product(_name, _setName, _language, _releaseDate, _purchasePrice, _bonusInfo){}
};

void ifstreamSealedBoxlist(vector <SealedBox*>& sealedBoosterlist, string filepath);
void ofstreamSealedBoxList(vector <SealedBox*>& sealedBoosterlist, string filepath);
void addSealedBox(vector <SealedBox*>& sealedBoosterList);