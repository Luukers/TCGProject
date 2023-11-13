#pragma once
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//        --------------- General Functions ---------------
// converts double to string with standartprecision of .2
string to_string_with_precision(double a_value, const int n = 2);

// userinput lock for int only
int check_if_int();

// userinput lock for doubles only
double check_if_double();

// userinput lock for bool only
int check_if_bool();


//        --------------- Template Functions ---------------
// funktion for clearing heap, takes every kind of vec through using template
template <typename T>
void deleteObjectsInVector(std::vector<T*>& vec) 
{
    for (auto ptr : vec) {
        delete ptr;
    }
    vec.clear();
    cout << "Heap cleared " << endl;
}

// funktion to call all printInfos() from vector independently from type of object
template <typename T>
void printList(std::vector<T*>& vec)
{
    for (auto ptr : vec) {
        cout << endl;
        cout << "------------------------------" << endl;
        ptr->printInfos();
        cout << endl;
    }
}

// funktion for filling all price and date vecs from objects from fitting csv files
template <typename T>
void fetchCardPrices(const vector <T*>& vec)
{
    for(auto ptr: vec)
    {
        ptr->fetchPriceHistory();
    }
}