#include "Card.h" 
#include "CardMenue.h"
#include "SealedBooster.h"
#include "BoosterMenue.h"
#include "SealedBox.h"
#include "BoxMenue.h"
using namespace std;

const string cardFilePath = "csv_files/products/Cards.csv";
const string sealedBoosterFilePath = "csv_files/products/SealedBoosters.csv";
const string sealedBoxFilePath = "csv_files/products/SealedBox.csv";

enum Menue
{
    Cards = 1,
    SealedBoosters,
    SealedBoxes,
};

void showMainMenueOptions();

int main()
{
    vector <Card*> cardlist;
    vector <SealedBooster*> sealedBoosterlist;
    vector <SealedBox*> sealedBoxlist;
    system("clear");
    ifstreamCardlist(cardlist, cardFilePath);
    ifstreamPices(cardlist);
    ifstreamSealedBoosterlist(sealedBoosterlist, sealedBoosterFilePath);
    ifstreamPices(sealedBoosterlist);
    ifstreamSealedBoxlist(sealedBoxlist, sealedBoxFilePath);
    ifstreamPices(sealedBoxlist);
    int userInput;
    do
    {   
        cout << endl;
        cout << "   -------  Main Menue  -------  " << endl;
        showMainMenueOptions();
        cout << "Please enter your Choice:" << endl;
        userInput = check_if_int();
        switch (userInput)
        {
        case Cards:
            // CardMenue
            cardMenue(cardlist);
        break;
        
        case SealedBoosters:
            // sealedBooster Menue
            sealedBoosterMenue(sealedBoosterlist);
        break;

        case SealedBoxes:
            // SealedProduct Menue
            sealedBoxMenue(sealedBoxlist);
        break;  
        
        default:
            if(userInput != 0)
            {
            cout << "invalid Input." << endl;
            cout << endl;
            }
            break;
        }
    }while(userInput != 0);
    // functions important for execution @ end of programm
    ofstreamPrices(cardlist);
    ofstreamCardlist(cardlist, cardFilePath);
    deleteObjectsInVector(cardlist);
    ofstreamPrices(sealedBoosterlist);
    ofstreamSealedBoosterList(sealedBoosterlist, sealedBoosterFilePath);
    deleteObjectsInVector(sealedBoosterlist);
    ofstreamPrices(sealedBoxlist);
    ofstreamSealedBoxList(sealedBoxlist, sealedBoxFilePath);
    deleteObjectsInVector(sealedBoxlist);
    cout << "Programm succesfully executed." << endl;
    return 0;
}

void showMainMenueOptions()
{
    cout << "[0] - End Programm" << endl;
    cout << "[1] - Go to Card Menue" << endl;
    cout << "[2] - Go to sealed Boosters Menue" << endl;
    cout << "[3] - Go to sealed Products Menue" << endl;
}