#include "HashTable.h"

#include <stdio.h>
#include <iostream>

//initializes a new hash table
HashTable::HashTable(){
	for (int i = 0; i < maxSize; i++){
		table[i] = "";
	}
}

//convert input string to unsigned int
unsigned int HashTable::hashCode(std::string entry){
	//hash code
	unsigned int h = 0;
	unsigned int stringLength = entry.length();
	for (int i = 0; i< stringLength; i++){
		h = (h << 5 | h >> 27);
		h += (unsigned int)entry.at(i);
	}
	return h;
}

//find initial bucket
unsigned int HashTable::hash1(unsigned int hash){
	unsigned int bucket = hash % maxSize;  
	return bucket;
}

//determine interval for probing
unsigned int HashTable::hash2(unsigned int hash){
	int r = 39;  //this is because 39 and 69997 (table size) are coprime
	unsigned int interv = r - (hash % r);
	return interv;
}

//lookup element in hash table.
//returns true if element exists, false if not
bool HashTable::lookup(std::string entry, unsigned int &initBucket){
	unsigned int hashval = hashCode(entry);
	initBucket = hash1(hashval);

	if (table[initBucket] == ""){
		return false;
	}
	else if (table[initBucket] == entry)
		return true;
	

	unsigned int interval = hash2(hashval);
	unsigned int counter = 0;
	while (table[initBucket] != entry){
		if (table[initBucket] == "")
			return false;
		else if ((counter > maxSize) && (table[initBucket] != "")){
			std::cout << "NO SPACE IN TABLE FOR" << entry << "\n";
			return true;
		}
		initBucket = (initBucket + interval)% maxSize;
		counter += interval;
	}
	return true;
}

//add an element to your hash table
void HashTable::add(std::string entry){
	unsigned int indexA = 0;
	if (!(lookup(entry, indexA))){
		table[indexA] = entry;
	}
	else 
		std::cout << entry << " is already in the dictionary.\n";

}

//remove element from hash table
void HashTable::remove(std::string entry){
	unsigned int indexR = 0;
	if (lookup(entry, indexR))
		table[indexR] = "";
}

