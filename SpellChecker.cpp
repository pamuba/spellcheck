#include "SpellChecker.h"
#include "Dictionary.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

//constructor for SpellChecker class
SpellChecker::SpellChecker(Dictionary *dict){
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	dictionary = dict;
}
//destructor
SpellChecker::~SpellChecker(){
	delete dictionary;
}
//check if word is spelled correctly
void SpellChecker::CheckWord(std::string entry){
	if (dictionary->lookup(entry)){
		//word is already in dictionary, spelled correctly
		return;
	}	
	else{
		//find suggested spellings for word 
		//using various check functions
		std::cout <<"\nWORD NOT FOUND: " << entry << std::endl;
		std::cout << "PERHAPS YOU MEANT: " << std::endl;
		CheckSwap(entry);
		CheckInsert(entry);
		CheckDelete(entry);
		CheckReplace(entry);
		CheckSplit(entry);
	}
}
void SpellChecker::CheckSwap(std::string entry){
	unsigned int len = entry.length();
	for (int i = 0; i < len - 1; i++){
		std::string tempstring = entry;
		char tempchar = tempstring[i];
		tempstring[i] = tempstring[i+1];
		tempstring[i+1] = tempchar;

		if (dictionary->lookup(tempstring)){
			std::cout << tempstring << std::endl;
		}

	}
}
void SpellChecker::CheckInsert(std::string entry){
	unsigned int stringlen = entry.length();
	unsigned int alphabetlen = alphabet.length();
	for (int i = 0; i < stringlen; i++){
		for (int j = 0; j < alphabetlen; j++){
			std::string tempstring = entry;
			tempstring.insert(tempstring.begin()+i, 1, alphabet[j]);
			if (dictionary->lookup(tempstring)){
				std::cout << tempstring << std::endl;
			}
		}
	}
	for (int i = 0; i < alphabetlen; i++){
		std::string tempstring = entry;
		tempstring.append(1,alphabet[i]);

		if (dictionary->lookup(tempstring)){
				std::cout << tempstring << std::endl;
			}
	}
}
void SpellChecker::CheckDelete(std::string entry){
	unsigned int len = entry.length();
	for (int i = 0; i < len; i++){
		std::string tempstring = entry;
		tempstring.erase(i, 1);

		if (dictionary->lookup(tempstring)){
			std::cout << tempstring << std::endl;
		}
	}
}
void SpellChecker::CheckReplace(std::string entry){
	unsigned int stringlen = entry.length();
	unsigned int alphabetlen = alphabet.length();
	for (int i = 0; i < stringlen; i++){
		std::string tempstring = entry;
		for (int j = 0; j < alphabetlen; j++){
			tempstring[i] = alphabet[j];

			if (dictionary->lookup(tempstring)){
				std::cout << tempstring << std::endl;
			}
		}
	}
}
void SpellChecker::CheckSplit(std::string entry){
	unsigned int len = entry.length();
	for (int i = 0; i < len-1; i++){
		unsigned int len1 = len - (i + 1);
		unsigned int len2 = len-len1;
		std::string front = entry.substr(0, len1);
		std::string back = entry.substr(len1, len2);

		if ((dictionary->lookup(front)) && (dictionary->lookup(back))){
			std::cout << front << " " << back << std::endl;
		}
	}

}