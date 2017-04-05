#include "stdafx.h"
#include "Hash.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
void main()
{
	string file;
	//Create an instance of the Hash class.
	Hash hashTable;
	//Allow the user to enter the name and path of the file
	cout << "Please enter the file you would like to be used:";
	cin >> file;
	fstream readFile;
	readFile.open(file);
	//Read an element from the file, if the end of the file is encountered continue with step 6
	while (!readFile.eof()) {
		getline(readFile, file);
		//Call the Hash function to get the location where the integer should be stored
		//Call the Insert function to store the integer
		//If the Insert function succeeds repeat with step 3
		if (hashTable.insert(stoi(file), hashTable.hashFunction(stoi(file))));
		else
			//If the Insert function fails (collision is detected), print the error message, 
			//then resolve the collision by calling the Resolve Collision function, repeat with step 3.  
			//If the array is full and the Resolve Collision function fails, print a message to the screen and call the Show function.
			if(hashTable.resolveColl(stoi(file), hashTable.hashFunction(stoi(file))));
	}
	//After processing all of the integers in the file, call the Show function to print the contents of the Hash table on the screen.
	hashTable.print();
	system("PAUSE");
}

