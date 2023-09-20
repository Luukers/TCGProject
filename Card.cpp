#include "Card.h"
#include "functions.h"
#include <windows.h>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


// adds Current price by typing and current
void Card::addCurrentPrice()
{   
    // current date:
    SYSTEMTIME currentTime;
    GetLocalTime(&currentTime);
    std::stringstream ss;
    ss << currentTime.wYear << "." << currentTime.wMonth << "." << currentTime.wDay;
    std::string currentDate = ss.str();
    dateCurrentPrice.push_back(currentDate);
    // current price:
    cout << "Type in current Price: " << endl;
    double price = check_if_double();
    currentPrice.push_back(price);
}


void Card::showPriceHistory()
{
    for (size_t i = 0; i < currentPrice.size(); i++)
    {
        cout << "Date: " << dateCurrentPrice[i] << " Price: " << currentPrice[i] << endl;
    }
}


void fillCardList(vector <Card*>& cardList, string filename)
{
    ifstream info (filename);
    if (!info.is_open())  
    {                    
        cout << "Error, " << filename << "could not be opened." << endl;
    }
    else 
    {
        string line;
        stringstream lineStorage;
        // assisting variables
        string name;
        string setName;
        string cardNumber;
        string artist;
        string releaseDate;
        double purchasePrice;
        bool graded;
        double grade;
        bool holo;
        bool reverseHolo;
        bool fullArt;
        bool extendetArt;
        string bonusInfo;
        // skip first line of csv
        getline(info, line);
        // get infos and fill vector with ptr to card
        while (getline(info, line))
        {
            lineStorage << line;
            getline(lineStorage, name, ',');
            getline(lineStorage, setName, ',');
            getline(lineStorage, cardNumber, ',');
            getline(lineStorage, artist, ',');
            getline(lineStorage, releaseDate, ',');
            lineStorage >> purchasePrice; lineStorage.ignore();
            lineStorage >> graded; lineStorage.ignore();
            lineStorage >> grade; lineStorage.ignore();
            lineStorage >> holo; lineStorage.ignore();
            lineStorage >> fullArt; lineStorage.ignore();
            lineStorage >> extendetArt; lineStorage.ignore();
            getline(lineStorage, bonusInfo, ',');
            // make objekt & push its ptr into cardList
            Card* cardptr = new Card(name, setName, cardNumber, artist, releaseDate, purchasePrice, graded, grade, holo, reverseHolo, fullArt, extendetArt, bonusInfo);
            cardList.push_back(cardptr);
        } 
    cout << filename << " opened." << endl;
    }
}