#pragma once
#include "Product.h"

using namespace std;

class SealedBooster : public Product
{
    public:
    int quanitity;

    void printInfos()const override;
    
    SealedBooster(string _name,  string _setName, string _language, string _releaseDate, double _purchasePrice, string _bonusInfo, int _quanitity):
    Product(_name, _setName, _language, _releaseDate, _purchasePrice, _bonusInfo), quanitity(_quanitity){}
};

void ifstreamSealedBoosterlist(vector <SealedBooster*>& sealedBoosterlist, string filepath);
void ofstreamSealedBoosterList(vector <SealedBooster*>& sealedBoosterlist, string filepath);
void addSealedBooster(vector <SealedBooster*>& sealedBoosterList);