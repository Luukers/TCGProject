#pragma once
#include "SealedBox.h"

using namespace std;

enum SealedBoxMenue
{
    SearchBox = 1,
    PrintBoxList,
    AddBox,
    ShowPriceHistoryOfBox,
    AddPriceToBox,
    DeleteBox,
};

void showBoxMenueOptions();

void sealedBoxMenue(vector <SealedBox*>& sealedBoxlist)
{
    int userInput;
    int userCaseInput;
    double price; 
    string date;
    string userSearchword;
    do
    {   
        cout << endl;
        cout << "   -------  Sealed Box Menue  -------  " << endl;
        showBoxMenueOptions();
        cout << "Please enter your Choice:" << endl;
        userInput  = check_if_int();
        switch (userInput)
        {
        case SearchBox:
            cout << "Type Boxname or Setname you want to Search for: " << endl;
            getline(cin, userSearchword);
            searchInList(sealedBoxlist, userSearchword);
            break;

        case PrintBoxList:
            system("clear");
            printList(sealedBoxlist);
            break;

        case AddBox:
            system("clear");
            addSealedBox(sealedBoxlist);
            break;

        case ShowPriceHistoryOfBox:
            system("clear");
            printList(sealedBoxlist);
            cout << "Type number of the Box you want to see Pricehistory from: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > sealedBoxlist.size()-1);
            sealedBoxlist[userCaseInput]->showPriceHistory();
            
            break;

        case AddPriceToBox:
            system("clear");
            printList(sealedBoxlist);
            cout << "Type number of the Box you want to add Price to: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > sealedBoxlist.size()-1);
            cout << "Box chosen: " << endl;
            sealedBoxlist[userCaseInput]->printInfos();
            cout << "Please enter the current Date: " << endl;
            getline(cin, date);
            cout << "Please enter the current Price: " << endl;
            price = check_if_double();
            sealedBoxlist[userCaseInput]->addCurrentPrice(price, date);
            cout << "Current Price added. Boosters Pricehistory: " << endl;
            sealedBoxlist[userCaseInput]->showPriceHistory();
            break;

        case DeleteBox:
            cout << "Type number of the Card you want to delete: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > sealedBoxlist.size()-1);
            deleteSingleObjectInVec(sealedBoxlist, userCaseInput);
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

void showBoxMenueOptions()
{
    cout << "[0] - Go back to Main Menue" << endl;
    cout << "[1] - Search for Box by Name" << endl;
    cout << "[2] - Show whole sealed Box collection" << endl;
    cout << "[3] - Add Box to Collection" << endl;
    cout << "[4] - Show Pricehistory from a single Box" << endl;
    cout << "[5] - Add current Price to Box" << endl;
    cout << "[6] - Delete Box from List" << endl;
}
