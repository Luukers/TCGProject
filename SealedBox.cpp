#include "SealedBox.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

//             ----------------------- sealed Box Member -----------------------
// member for printing infos
void SealedBox::printInfos()const
{   
    cout << "Name: " << name << endl;
    cout << "Set Name: " << setName << endl;
    cout << "Language: " << language << endl;
    cout << "Release Date: " << releaseDate << endl;
    cout << "Purchase Price: " << purchasePrice << endl;
    cout << "Bonus Info: " << bonusInfo << endl;
}

//       ------------------ other sealed Box associated functions ---------------------
// reads SealedBox.csv and saves ptr to SealedBox in SealedBox vector
void ifstreamSealedBoxlist(vector <SealedBox*>& sealedBoxlist, string filepath)
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
            getline(lineStorage, bonusInfo, ',');
            // make objekt & push its ptr into cardList
            SealedBox* sBoxptr = new SealedBox(name, setName, language, releaseDate, purchasePrice, bonusInfo);
            sealedBoxlist.push_back(sBoxptr);
        } 
    cout << filepath << " opened." << endl;
    }
}

// Writes runtime changes to SealedBox.csv
void ofstreamSealedBoxList(vector <SealedBox*>& sealedBoxlist, string filepath)
{
    ofstream file(filepath);
    // get header line of csv to save it
    string content;
    file << "string _name,  string _setName, string _language, string _releaseDate, double _purchasePrice, string _bonusInfo, \n";
    for(SealedBox* sBoxPtr : sealedBoxlist)
    {
        content = sBoxPtr->name + ','
        + sBoxPtr->setName + ','
        + sBoxPtr->language + ',' 
        + sBoxPtr->releaseDate + ','
        + to_string_with_precision(sBoxPtr->purchasePrice) + ',' 
        + sBoxPtr->bonusInfo + ',' + "\n";

        file << content;  
    }
    file.close();
    cout << filepath << " was succesfully updated." << endl;
    // heap get cleared from seperate function, be sure it gets called in main
}

// Adds sealed Box to vec by manual user console input
void addSealedBox(vector <SealedBox*>& sealedBoxList)
{
    cout << "Adding sealed Box. " << endl;
    string name;
    string setName;
    string language;
    string releaseDate;
    double purchasePrice;
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
    cout << "Bonus info: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, bonusInfo);
    // create Card with info and add to vector
    SealedBox* sBoxPtr = new SealedBox(name, setName, language, releaseDate, purchasePrice, bonusInfo);
    sealedBoxList.push_back(sBoxPtr);
}