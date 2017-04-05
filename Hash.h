#pragma once

class Hash
{
private:
	int hashTable[20];
public:
	Hash();
	int hashFunction(int _value);
	bool insert(int _value, int _location);
	bool resolveColl(int _value, int _Olocation);
	void print();
	~Hash();
};

