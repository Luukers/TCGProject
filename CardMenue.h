#pragma once
#include "Card.h"
using namespace std;

enum CardMenue
{
    PrintCardList = 1,
    AddCard,
    ShowPriceHistoryOfCard,
    AddPriceToCard
};

void showCardMenueOptions();

void cardMenue(vector <Card*>& cardlist)
{
    int userInput;
    int userCaseInput;
    double price; 
    string date;
    do
    {   
        std::cin.clear();
        cout << "   ------- Card Menue -------  " << endl;
        showCardMenueOptions();
        cout << "Please enter your Choice:" << endl;
        userInput  = check_if_int();
        switch (userInput)
        {
        case PrintCardList:
            printList(cardlist);
            break;

        case AddCard:
            addCard(cardlist);
            break;

        case ShowPriceHistoryOfCard:
            printList(cardlist);
            cout << "Type number of the Card you want to see Pricehistory from: " << endl;
            do{
            userCaseInput = check_if_int() -1;
            }while(userCaseInput < 0 || userCaseInput > cardlist.size()-1);
            cardlist[userCaseInput]->showPriceHistory();
            
            break;

        case AddPriceToCard:
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

        default:
            if(userInput != 0)
            {
            cout << "invalid Input." << endl;
            }
            break;
        }
    }while(userInput != 0);
} 

void showCardMenueOptions()
{
    cout << "[0] - Go back to Main Menue" << endl;
    cout << "[1] - Show whole Card collection" << endl;
    cout << "[2] - Add Card to Collection" << endl;
    cout << "[3] - Show Pricehistory from single Card" << endl;
    cout << "[4] - Add current Price to Card" << endl;
}
