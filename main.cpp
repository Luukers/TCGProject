#include "Card.h" 
using namespace std;

const string cardFilePath = "csv_files/products/Cards.csv";

enum Menue
{
    Cards = 1,
    SealedBoosters,
    SealedProducts,
};

int main()
{
    vector <Card*> cardlist;
    fillCardList(cardlist, cardFilePath);

    fetchCardPrices(cardlist);
    cardlist[1]->showPriceHistory();
    cardlist[1]->addCurrentPrice(40.99, "14.11.2023");
    cardlist[1]->showPriceHistory();

    printList(cardlist);
    emtpyCardList(cardlist, cardFilePath);
    deleteObjectsInVector(cardlist);
    cout << "Programm succesfully executed." << endl;
    return 0;
}