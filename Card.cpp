#include "Card.h"
#include <string>
#include <sstream>
#include <fstream>
// #include <windows.h>??
using namespace std;

//             ----------------------- Member -----------------------
// member for printing infos
void Card::printInfos()const
{   
    cout << "Name: " << name << endl;
    if(graded == true)
    {
        cout << "Grade: " << grade << endl;
    }
    cout << "Set Name: " << setName << endl;
    cout << "Cardnumber: " << cardNumber << endl;
    cout << "Language: " << language << endl;
    cout << "Release Date: " << releaseDate << endl;
    cout << "Purchase Price: " << purchasePrice << endl;
    cout << "Artist: " << artist << endl;
    cout << "Bonus Info: " << bonusInfo << endl;
}

//       ------------------ other Card associated functions ---------------------
// reads Cards.csv and saves ptr to card in cardlist vector
void ifstreamCardlist(vector <Card*>& cardlist, string filepath)
{
    ifstream file(filepath);
    if (!file.is_open())  
    {                    
        cerr << "Error, " << filepath << " could not be opened." << endl;
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
        string releaseDate;
        double purchasePrice;
        string artist;
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
            getline(lineStorage, releaseDate, ',');
            lineStorage >> purchasePrice; lineStorage.ignore();
            getline(lineStorage, artist, ',');
            lineStorage >> graded; lineStorage.ignore();
            lineStorage >> grade; lineStorage.ignore();
            lineStorage >> holo; lineStorage.ignore();
            lineStorage >> reverseHolo; lineStorage.ignore();
            lineStorage >> fullArt; lineStorage.ignore();
            lineStorage >> extendetArt; lineStorage.ignore();
            getline(lineStorage, bonusInfo, ',');
            // make objekt & push its ptr into cardList
            Card* cardptr = new Card(name, setName, language, cardNumber, releaseDate, purchasePrice, artist, graded, grade, holo, reverseHolo, fullArt, extendetArt, bonusInfo);
            cardlist.push_back(cardptr);
        } 
    cout << filepath << " opened." << endl;
    }
}

// Writes runtime changes to Cards.csv
void ofstreamCardlist(vector <Card*>& cardlist, string filepath)
{
    ofstream file(filepath);
    // get header line of csv to save it
    string content;
    file << "string _name, string _setName, string _language, string _cardNumber, string _releaseDate, double _purchasePrice, string _artist, bool _graded, double _grade, bool _holo, bool _reverseHolo, bool _fullArt, bool _extendetArt, string _bonusInfo,\n";
    for(Card* cardPtr : cardlist)
    {
        content = cardPtr->name + ','
        + cardPtr->setName + ','
        + cardPtr->language + ',' 
        + cardPtr->cardNumber + ',' 
        + cardPtr->releaseDate + ','
        + to_string_with_precision(cardPtr->purchasePrice) + ','
        + cardPtr->artist + ','  
        + to_string(cardPtr->graded) + ','  
        + to_string_with_precision(cardPtr->grade) + ',' 
        + to_string(cardPtr->holo) + ',' 
        + to_string(cardPtr->reverseHolo) + ',' 
        + to_string(cardPtr->fullArt) + ',' 
        + to_string(cardPtr->extendetArt) + ',' 
        + cardPtr->bonusInfo + ',' + "\n";
        file << content;  
    }
    file.close();
    cout << filepath << " was succesfully updated." << endl;
    // heap get cleared from seperate function, be sure it gets called in main
}

// Adds Card to vec by manual user console input
void addCard(vector <Card*>& cardlist)
{  
    
    cout << "Adding Card: " << endl;
    string name;
    string setName;
    string language;
    string cardNumber;
    string artist;
    string releaseDate;
    double purchasePrice;
    bool graded = 0;
    double grade = 0;
    bool holo = 0;
    bool reverseHolo = 0;
    bool fullArt = 0;
    bool extendetArt = 0;
    string bonusInfo;
    // fetch data via std::cin
    cout << "Name: ";
    getline(cin, name);
    cout << "Setname: ";
    getline(cin, setName);
    cout << "Language: ";
    getline(cin, language);
    cout << "Cardnumber: ";
    getline(cin, cardNumber);
    cout << "Artist: ";
    getline(cin,artist);
    cout << "Releasedate: ";
    getline(cin, releaseDate);
    cout << "Purchase Price: ";
    purchasePrice = check_if_double();
    cout << "Graded?: [1] yes / [0] no" << endl;
    graded = check_if_bool();
    if(graded == true)
    {
        cout << "Grade: " << endl;
        grade = check_if_double();
    }
    cout << "Normal Holo?: [1] yes / [0] no" << endl;
    holo = check_if_bool();
    if(holo != true)
    {
        cout << "Reverse Holo?: [1] yes / [0] no" << endl;
        reverseHolo = check_if_bool();
    }
    if(holo != true  && reverseHolo != true)
    {
        cout << "Full Art?: [1] yes / [0] no" << endl;
        fullArt = check_if_bool();
    }
    if(holo != true  && reverseHolo != true && fullArt != true)
    {
        cout << "Extended Art?: [1] yes / [0] no" << endl;
        extendetArt = check_if_bool();
    }
    cout << "Bonus info: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, bonusInfo);
    // create Card with info and add to vector
    Card* cardptr = new Card(name, setName, cardNumber, language, releaseDate, purchasePrice, artist, graded, grade, holo, reverseHolo, fullArt, extendetArt, bonusInfo);
    cardlist.push_back(cardptr);
}



