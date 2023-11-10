#include "Card.h"
#include <string>
#include <sstream>
#include <fstream>
#include "Functions.h"
// #include <windows.h>??

using namespace std;

// Windows Only - adds Current price by typing and current date automatically 
/* void Card::addCurrentPrice(double price)
{   
    // current price:
    currentPrice.push_back(price);
    // current date:
    SYSTEMTIME currentTime;
    GetLocalTime(&currentTime);
    std::stringstream ss;
    ss << currentTime.wDay << "." << currentTime.wMonth << "." << currentTime.wYear ;
    std::string currentDate = ss.str();
    dateCurrentPrice.push_back(currentDate);
}*/ 

void Card::addCurrentPrice(double price, string date)
{   
    // current price:
    currentPrice.push_back(price);
    // current date:
    dateCurrentPrice.push_back(date);  
}

// shows price history of a single card
void Card::showPriceHistory()const
{
    for (size_t i = 0; i < currentPrice.size(); i++)
    {
        cout << "Date: " << dateCurrentPrice[i] << " Price: " << currentPrice[i] << endl;
    }
}

// reads Cards.csv and saves ptr to card in cardlist vector
void fillCardList(vector <Card*>& cardList, string filename)
{
    ifstream file(filename);
    if (!file.is_open())  
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
        string language;
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
        getline(file, line);
        // fetch infos and fill vector with ptr to card
        while (getline(file, line))
        {
            lineStorage << line;
            getline(lineStorage, name, ',');
            getline(lineStorage, setName, ',');
            getline(lineStorage, language, ',');
            getline(lineStorage, cardNumber, ',');
            getline(lineStorage, artist, ',');
            getline(lineStorage, releaseDate, ',');
            lineStorage >> purchasePrice; lineStorage.ignore();
            lineStorage >> graded; lineStorage.ignore();
            lineStorage >> grade; lineStorage.ignore();
            lineStorage >> holo; lineStorage.ignore();
            lineStorage >> reverseHolo; lineStorage.ignore();
            lineStorage >> fullArt; lineStorage.ignore();
            lineStorage >> extendetArt; lineStorage.ignore();
            getline(lineStorage, bonusInfo, ',');
            // make objekt & push its ptr into cardList
            Card* cardptr = new Card(name, setName, cardNumber, language, releaseDate, purchasePrice, artist, graded, grade, holo, reverseHolo, fullArt, extendetArt, bonusInfo);
            cardList.push_back(cardptr);
        } 
    cout << filename << " opened." << endl;
    }
}

// clears heap from cards and writes runtime changes to Cards.csv
void emtpyCardList(vector <Card*>& cardList, string filename)
{
    ofstream file(filename);
    if (!file.is_open())  
    {                    
        cout << "Error, " << filename << "could not be opened." << endl;
        cout << "Created new File: " << filename << "." << endl;
    }
    // write infos 
    string content;
    for(Card* cardPtr : cardList)
    {
        content = cardPtr->name + ','
        + cardPtr->setName + ',' 
        + cardPtr->cardNumber + ',' 
        + cardPtr->artist + ',' 
        + cardPtr->releaseDate + ',' 
        + to_string_with_precision(cardPtr->purchasePrice) + ','
        + to_string(cardPtr->graded) + ','  
        + to_string(cardPtr->grade) + ',' 
        + to_string(cardPtr->holo) + ',' 
        + to_string(cardPtr->fullArt) + ',' 
        + to_string(cardPtr->extendetArt) + ',' 
        + cardPtr->bonusInfo + ',' + "\n";
        file << content;  
    }
    file.close();
    cout << filename << "was succesfully updated." << endl;
    // clear heap
    for( Card* cardPtr : cardList)
    {
        delete cardPtr;
    }
    // emtpy vec
    cardList.clear();
}
