#include "Card.h" 
#include "CardMenue.h"
using namespace std;

const string cardFilePath = "csv_files/products/Cards.csv";

enum Menue
{
    Cards = 1,
    SealedBoosters,
    SealedProducts,
};

void showMainMenueOptions();

int main()
{
    vector <Card*> cardlist;
    fillCardList(cardlist, cardFilePath);
    fetchPrices(cardlist);
    int userInput;
    do
    {   
        cout << "   ------- Main Menue -------  " << endl;
        showMainMenueOptions();
        cout << "Please enter your Choice:" << endl;
        userInput = check_if_int();
        switch (userInput)
        {
        case Cards:
            // CardMenue
            cardMenue(cardlist);
        break;
        
        case SealedProducts:
            // SealedProduct Menue
        break;  
        
        case SealedBoosters:
            // sealedBooster Menue
        break;
        
        
        default:
            if(userInput != 0)
            {
            cout << "invalid Input." << endl;
            }
            break;
        }
    }while(userInput != 0);
    // functions important for execution @ end of programm
    ofstreamPrices(cardlist);
    emtpyCardList(cardlist, cardFilePath);
    deleteObjectsInVector(cardlist);
    cout << "Programm succesfully executed." << endl;
    return 0;
}

void showMainMenueOptions()
{
    cout << "[0] - End Programm" << endl;
    cout << "[1] - Go to Card Menue" << endl;
    cout << "[2] - Go to sealed Boosters Menue" << endl;
    cout << "[3] - Go to sealed Boxes Menue" << endl;
}