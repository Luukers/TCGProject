#pragma once
#include "SealedBooster.h"

using namespace std;

enum SealedBoosterMenue
{
    SearchBooster = 1,
    PrintBoosterList,
    AddBooster,
    ShowPriceHistoryOfBooster,
    AddPriceToBooster,
    DeleteBooster
};

void showBoosterMenueOptions();

void sealedBoosterMenue(vector <SealedBooster*>& sealedBoosterlist)
{
    int userInput;
    int userCaseInput;
    double price; 
    string date;
    string userSearchword;
    do
    {   
        cout << endl;
        cout << "   -------  Sealed Booster Menue  -------  " << endl;
        showBoosterMenueOptions();
        cout << "Please enter your Choice:" << endl;
        userInput  = check_if_int();
        switch (userInput)
        {
        case SearchBooster:
            cout << "Type Boostername or Setname you want to Search for: " << endl;
            getline(cin, userSearchword);
            searchInList(sealedBoosterlist, userSearchword);
            break;

        case PrintBoosterList:
            system("clear");
            printList(sealedBoosterlist);
            break;

        case AddBooster:
            system("clear");
            addSealedBooster(sealedBoosterlist);
            break;

        case ShowPriceHistoryOfBooster:
            system("clear");
            printList(sealedBoosterlist);
            cout << "Type number of the Booster you want to see Pricehistory from: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > sealedBoosterlist.size()-1);
            sealedBoosterlist[userCaseInput]->showPriceHistory();
            
            break;

        case AddPriceToBooster:
            system("clear");
            printList(sealedBoosterlist);
            cout << "Type number of the Booster you want to add Price to: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > sealedBoosterlist.size()-1);
            cout << "Booster chosen: " << endl;
            sealedBoosterlist[userCaseInput]->printInfos();
            cout << "Please enter the current Date: " << endl;
            getline(cin, date);
            cout << "Please enter the current Price: " << endl;
            price = check_if_double();
            sealedBoosterlist[userCaseInput]->addCurrentPrice(price, date);
            cout << "Current Price added. Boosters Pricehistory: " << endl;
            sealedBoosterlist[userCaseInput]->showPriceHistory();
            break;

        case DeleteBooster:
            cout << "Type number of the Card you want to delete: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > sealedBoosterlist.size()-1);
            deleteSingleObjectInVec(sealedBoosterlist, userCaseInput);
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
}

void showBoosterMenueOptions()
{
    cout << "[0] - Go back to Main Menue" << endl;
    cout << "[1] - Search for Booster by Name" << endl;
    cout << "[2] - Show whole sealed Booster collection" << endl;
    cout << "[3] - Add Booster to Collection" << endl;
    cout << "[4] - Show Pricehistory from a single Booster" << endl;
    cout << "[5] - Add current Price to Booster" << endl;
    cout << "[6] - Delete Booster from list" << endl;
}
