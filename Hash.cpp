#include "stdafx.h"
#include "Hash.h"
#include <string>
#include <iostream>

using namespace std;


Hash::Hash()
{
	//initializes the contents of each element in the array to -999
	for (int i = 0; i < 20; i++) 
	{
		hashTable[i] = -999;
	}
}

//purpose:returns the location in the array in which the passed integer value should be placed (the hash value).
//Arguments:pass the int value from the file that needs to be inserted
int Hash::hashFunction(int _value) {
	return _value % 23;
}

//Purpose: attempts to insert the passed integer value into the array unless there is a key value already in the array
//Arguments: int value from file and location insert was atempted.
bool Hash::insert(int _value, int _location) {
	if (hashTable[_location] == -999) {
		hashTable[_location] = _value;
		return true;
	}
	else {
		cout << "There was a collision at location " << _location << " while attempting to insert value " << _value <<endl;
		return false;
	}
}

//Purpose: Resolve collisions and always find a place for value unless array is full
//Arguments: Int value read from file and location.
bool Hash::resolveColl(int _value, int _Olocation) {
	for (int i = 0; i < 20; i++) {
		if (hashTable[i] == -999) {
			while (hashTable[_Olocation] != -999 && _Olocation <= 19) {
				_Olocation++;
			}
			if (_Olocation > 19) {
				_Olocation = 0;
				while (hashTable[_Olocation] != -999 && _Olocation < 19) {
					_Olocation++;
				}
			}
			hashTable[_Olocation] = _value;
			return true;
		}
	}
	return false;
}

//Purpose: Will print out the Key and value in the hash table
//Arguments: None
void Hash::print() {
	cout << "Key     " << "Value" << endl;
	for (int i = 0; i < 20; i++) {
		cout << i << "        " << hashTable[i] << endl;
	}
}

Hash::~Hash()
{
}
