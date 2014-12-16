#include "Dictionary.h"
#include "HashTable.h"
#include <stdio.h>
#include <iostream>

//constructor
Dictionary::Dictionary(){
	dictTable = new HashTable();
}
//destructor
Dictionary::~Dictionary(){
	delete dictTable;
}
//dictionary lookup
//returns true if element is in dictionary, false if not
bool Dictionary::lookup(std::string entry){
	unsigned int indexVal = 0;
	bool result = dictTable->lookup(entry, indexVal);
	return result;
}
//add word to dictionary
void Dictionary::add(std::string entry){
	dictTable->add(entry);
}
//remove word from dictionary
void Dictionary::remove(std::string entry){
	dictTable->remove(entry);
}
