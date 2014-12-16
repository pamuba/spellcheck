#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

#include "HashTable.h"
#include "Dictionary.h"
#include "SpellChecker.h"

using namespace std;

bool findPunctuation(char c){
	return (c == '.')||(c==',')||(c == '!')||(c == '?');
}

char upperToLower(char c){
	return std::tolower(c);
}

int main(int argc, char *argv[]){
	/**
	* 1.
	* Make sure program has all necessary arguments. */
	if (argc <2){
		cout << "Not enough arguments.\n spellcheck <filename> \n";
		exit (1);
	}

	/**
	* 2. 
	* Open input file and make sure it can be read */
	const char* file = argv[1];
	ifstream inputFile;
	inputFile.open(file);
	if (inputFile.fail()){
		std::cout << "Error: Cannot read input file\n";
		exit(1);
	}
	else if(inputFile.peek() == EOF){
		std::cout << "Error: Input file is empty\n";
		exit(1);
	}
	else{
		std::cout <<"-----Input file loaded-----\n";
	}
	inputFile.close();


	/**
	* 3. 
	* Load dictionary words from wordlist input file*/
	Dictionary *dictionary = new Dictionary();
	ifstream wordFile;
	string temp, dictWord;
	stringstream ss;

	wordFile.open("Program3Fall2014wordlist");
	getline(wordFile, temp);
	while ( wordFile.peek() != EOF ){
		getline(wordFile, temp); //delimiter = new line character \n
		ss << temp;
		getline(ss, dictWord, '\r'); //delimiter = carriage return character \r
		dictionary->add(dictWord);
		ss.clear();
	}
	std::cout << "-----Dictionary loaded-----\n";
	wordFile.close();


	/**
	* 4.
	* Read input file line by line 
	* Send each line to SpellChecker */
	string line, word;
	stringstream ssline;
	SpellChecker *spellchecker = new SpellChecker(dictionary);

	inputFile.open(file);
	while (inputFile.peek() != EOF)
	{
		//read line into string stream	
		getline(inputFile, line); //delimiter = new line character \n
		ssline << line;
		getline(ssline, line, '\r'); //delimiter = carriage return character \r

		if (line != ""){
			//display input line
			std::cout << "\n------\nINPUT: " << line << "\n------\n";

			//break up input line into words
			ssline << line;
			while (ssline.peek()!= EOF){
				ssline >> word;

				//remove punctuation marks from word
				word.erase(std::remove_if(word.begin(), word.end(), findPunctuation), word.end());
				std::transform(word.begin(), word.end(), word.begin(), upperToLower);
				
				//send each word to spellchecker?
				unsigned int wordlen = word.length();
				spellchecker->CheckWord(word);

			}	
		}
		//clear stringstream for next line of input file
		ssline.clear();
	}
	inputFile.close();

	delete dictionary;
	return 0;
}
