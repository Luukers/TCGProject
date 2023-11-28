#pragma once
#include "Card.h"
using namespace std;

enum CardMenue
{
    SearchCard = 1,
    PrintCardList,
    AddCard,
    ShowPriceHistoryOfCard,
    AddPriceToCard,
    DeleteCard
};

void showCardMenueOptions();

void cardMenue(vector <Card*>& cardlist)
{
    int userInput;
    int userCaseInput;
    double price; 
    string date;
    string userSearchword;
    do
    {   
        cout << endl;
        cout << "   -------  Card Menue  -------  " << endl;
        showCardMenueOptions();
        cout << "Please enter your Choice:" << endl;
        userInput  = check_if_int();
        switch (userInput)
        {
        case SearchCard:
            cout << "Type Cardname or Setname you want to Search for: " << endl;
            getline(cin, userSearchword);
            searchInList(cardlist, userSearchword);
            break;

        case PrintCardList:
            system("clear");
            printList(cardlist);
            break;

        case AddCard:
            system("clear");
            addCard(cardlist);
            break;

        case ShowPriceHistoryOfCard:
            system("clear");
            printList(cardlist);
            cout << "Type number of the Card you want to see Pricehistory from: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > cardlist.size()-1);
            cardlist[userCaseInput]->showPriceHistory();
            break;

        case AddPriceToCard:
            system("clear");
            printList(cardlist);
            cout << "Type number of the Card you want to add Price to: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > cardlist.size()-1);
            cout << "Card chosen: " << endl;
            cardlist[userCaseInput]->printInfos();
            cout << "Please enter the current Date: " << endl;
            getline(cin, date);
            cout << "Please enter the current Price: " << endl;
            price = check_if_double();
            cardlist[userCaseInput]->addCurrentPrice(price, date);
            cout << "Current Price added. Cards Pricehistory: " << endl;
            cardlist[userCaseInput]->showPriceHistory();
            break;
        
        case DeleteCard:
            cout << "Type number of the Card you want to delete: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > cardlist.size()-1);
            deleteSingleObjectInVec(cardlist, userCaseInput);
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

void showCardMenueOptions()
{
    cout << "[0] - Go back to Main Menue" << endl;
    cout << "[1] - Search for Card by Name" << endl;
    cout << "[2] - Show whole Card collection" << endl;
    cout << "[3] - Add Card to Collection" << endl;
    cout << "[4] - Show Pricehistory from a single Card" << endl;
    cout << "[5] - Add current Price to Card" << endl;
    cout << "[6] - Delete Card from List" << endl;
}
