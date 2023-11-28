#include "SealedBooster.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

//             ----------------------- sealed Booster Member -----------------------
// member for printing infos
void SealedBooster::printInfos()const
{   
    cout << "          Name: " << name << endl;
    cout << "      Set Name: " << setName << endl;
    cout << "      Language: " << language << endl;
    cout << "  Release Date: " << releaseDate << endl;
    if(purchasePrice != 0)
    {
    cout << "Purchase Price: " << purchasePrice << "€" << endl;
    }
    cout << "     Quanitity: " << quanitity << endl;
    if(!bonusInfo.empty())
    {
    cout << "    Bonus Info: " << bonusInfo << endl;
    }
    calculateProfit();
}

//       ------------------ other sealed Booster associated functions ---------------------
// reads SealedBoosters.csv and saves ptr to SealedBooster in SealedBooster vector
void ifstreamSealedBoosterlist(vector <SealedBooster*>& sealedBoosterlist, string filepath)
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
        string releaseDate;
        double purchasePrice;
        string bonusInfo;
        int quanitity;
        // skip first line of csv
        getline(file, line);
        // fetch infos and fill vector with ptr to card
        while (getline(file, line))
        {
            lineStorage << line;
            getline(lineStorage, name, ',');
            getline(lineStorage, setName, ',');
            getline(lineStorage, language, ',');
            getline(lineStorage, releaseDate, ',');
            lineStorage >> purchasePrice; lineStorage.ignore();
            lineStorage >> quanitity; lineStorage.ignore();
            getline(lineStorage, bonusInfo, ',');
            // make objekt & push its ptr into cardList
            SealedBooster* sBoosterptr = new SealedBooster(name, setName, language, releaseDate, purchasePrice, bonusInfo, quanitity);
            sealedBoosterlist.push_back(sBoosterptr);
        } 
    cout << filepath << " opened." << endl;
    }
}

// Writes runtime changes to SealedBoosters.csv
void ofstreamSealedBoosterList(vector <SealedBooster*>& sealedBoosterlist, string filepath)
{
    ofstream file(filepath);
    // get header line of csv to save it
    string content;
    file << "string _name,  string _setName, string _language, string _releaseDate, double _purchasePrice, int _quanitity, string _bonusInfo, \n";
    for(SealedBooster* sBoosterPtr : sealedBoosterlist)
    {
        content = sBoosterPtr->name + ','
        + sBoosterPtr->setName + ','
        + sBoosterPtr->language + ',' 
        + sBoosterPtr->releaseDate + ','
        + to_string_with_precision(sBoosterPtr->purchasePrice) + ',' 
        + to_string(sBoosterPtr->quanitity) + ','
        + sBoosterPtr->bonusInfo + ',' + "\n";

        file << content;  
    }
    file.close();
    cout << filepath << " was succesfully updated." << endl;
    // heap get cleared from seperate function, be sure it gets called in main
}

// Adds sealed Booster to vec by manual user console input
void addSealedBooster(vector <SealedBooster*>& sealedBoosterList)
{
    cout << "Adding sealed Booster. " << endl;
    string name;
    string setName;
    string language;
    string releaseDate;
    double purchasePrice;
    int quanitity;
    string bonusInfo;
    // fetch info vie std::cin
    cout << "Name: ";
    getline(cin, name);
    cout << "Setname: ";
    getline(cin, setName);
    cout << "Language: ";
    getline(cin, language);
    cout << "Releasedate: ";
    getline(cin, releaseDate);
    cout << "Purchase Price: ";
    purchasePrice = check_if_double();
    cout << "Quantity: ";
    quanitity = check_if_int();
    cout << "Bonus info: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, bonusInfo);
    // create Card with info and add to vector
    SealedBooster* sBoosterPtr = new SealedBooster(name, setName, language, releaseDate, purchasePrice, bonusInfo, quanitity);
    sealedBoosterList.push_back(sBoosterPtr);
}