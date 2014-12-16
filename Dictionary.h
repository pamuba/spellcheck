#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "HashTable.h"


class Dictionary{
	HashTable *dictTable;
public:
	Dictionary();
	~Dictionary();
	bool lookup(std::string entry); //returns true if element is in dictionary, false if not
	void add(std::string entry);
	void remove(std::string entry);

};


#endif