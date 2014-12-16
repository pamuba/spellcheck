#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include "Dictionary.h"

class SpellChecker{
	std::string alphabet;
	Dictionary *dictionary;
public:
	SpellChecker(Dictionary *dict);
	~SpellChecker();
	void CheckWord(std::string entry); //checks to see if word is in dictionary
	void CheckSwap(std::string entry);
	void CheckInsert(std::string entry);
	void CheckDelete(std::string entry);
	void CheckReplace(std::string entry);
	void CheckSplit(std::string entry);

};


#endif