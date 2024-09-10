// CS303HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "functions.h"
using namespace std;

int main()
{
    string filename = "A1input.txt";    //declare and initialize filename

    //in this program I use std::array to simplify passing the arrays through
    //different functions
    array<int, 100> numArray;   //declare the array to be used
    array<int, 200> newArray;
   
    cout << "Reading input file - " << filename << "\n";
    numArray = readFile(filename);
    checkInt(numArray);
    changeInt(numArray);
    newArray = addInt(numArray);
    removeInt(numArray);
}