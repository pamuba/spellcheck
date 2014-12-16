#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

class HashTable{
	const static int maxSize = 69997;
	std::string table[maxSize];
public:
	HashTable();
	unsigned int hashCode(std::string entry);
	unsigned int hash1(unsigned int hash);
	unsigned int hash2(unsigned int hash);
	bool lookup(std::string entry, unsigned int &initBucket);
	void add(std::string entry);
	void remove(std::string entry);
};

#endif