using namespace std;
#include <iostream>
#include <fstream>
#include <array>
#include <sstream>

//function returns an array
array<int, 100> readFile(string fileName) {

	ifstream inputFile(fileName);	//open the file

	////ERROR CHECKING////
	//check if file is open, alert the user if not
	if (!inputFile) {
		cout << "Could not open input file" << endl;
	}
	
	array<int, 100> numArray;	//declare the array
	string line;	//declare string for parsing input file
	
	int i = 0;	//int i will be used to keep our place in the array (array index)						

	//read the file line by line
	while (getline(inputFile, line)) {
		istringstream stream(line);	//create a string stream
		int num;	//declare a temp number that will be inserted into the array
		
		//extract integers from the line
		while (stream >> num) {
			numArray[i] = num;	//using i (array index), add the extracted int to the array
			i++;	//increment i
		}
	}

	inputFile.close();	//close the input file

	return numArray;	//return the array
}

void checkInt(array<int,100> numArray) {
	
	int checkNum;	//declare variable for user input

	//ADD TRY-CATCH BLOCKS HERE//
	cout << "\nEnter the number to check if it exists in the Array" << endl;
	cin >> checkNum;	//get input from the user

	//search the array
	for (int i = 0; i < 100; i++) {
		//catches if checkNum is equal to the number in the array at index i
		if (checkNum == numArray[i]) {
			//if number is found, return the index where it was found and end the search by calling return
			cout << "Your number was found at index " << i << endl;
			return;
		}
	}

	//return is called when the number is found, so this executes if
	//the array is searched but the number is not found
	cout << "Your number was not found in the Array" << endl;

}

void changeInt(array<int, 100> numArray) {

	int changeNum;
	int index;

	//Get index and number from user
	cout << "\nEnter the index of the number you want to change" << endl;
	cin >> index;
	cout << "Enter the number you would like in place of " << numArray[index] << " at index " << index << endl;
	cin >> changeNum;
	cout << "You changed the number at index " << index << " from " << numArray[index] << " to " << changeNum << endl;

	//use index and number to change array
	numArray[index] = changeNum;

}

array<int, 200> addInt(array<int, 100> numArray) {

	array<int, 200> newArray;
	int addNum;
	int addIndex = 100;

	for (int i = 0; i < 100; i++) {
		newArray[i] = numArray[i];
	}

	cout << "\nEnter a number to add at the end of the array " << endl;
	cin >> addNum;
	cout << "You added the number " << addNum << " at index 100" << endl;
	
	newArray[addIndex] = addNum;
	
	return newArray;
}

void removeInts(array<int, 100> numArray) {

	int index;

	cout << "\nEnter the index of the number you want to remove from the Array" << endl;
	cin >> index;
	cout << "The number " << numArray[index] << " at index " << index << " was changed to zero.";

	numArray[index] = 0;
	 
}