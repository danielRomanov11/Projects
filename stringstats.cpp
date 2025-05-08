/* Name: Daniel Romanov
Date: 4/3/2025
Assignment: String Statistics (HW #7)
Due Date: 4/9/2025
About this project: This project takes in sentence and word input from the user and returns the punctuation count, vowel counts, word count, world length, and whether or 
not the inputted word appears in the user's inputted sentence.
Assumptions: only one word will be inputted, i.e. no whitespace when prompted, max sentence length 100 chars, and max word length 20 chars.

All work below was performed by Daniel Romanov */

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// function declarations taking in strings by reference and arrays and parameters

int countPunctuation(const string &sentence);
int countVowels(const string &sentence);
int countWords(const string &sentence);
void wordLength(const string &sentence, int lengthCounts[]);
bool isWordInSentence(const string &sentence, const string &word);
bool contResponse();

int main(){
    
	// Declare all variables and word length array at the top of main
	string sentence, word;
    	bool continueAnalysis = true;
    	int wordLengths[21] = {0};
    	int i;   //counter var             

    	while (continueAnalysis){
        	
		//get sentence from user
        	cout << "Enter a sentence: ";
        	getline(cin, sentence);

       		//get word from user
        	cout << "Enter a word: ";
        	cin >> word;
        	cin.ignore(1000, '\n'); //clear input stream to prevent unwanted or spare inputs

        	//reset word length counts array
        	for (i = 0; i <= 20; i++){
            		wordLengths[i] = 0;
        	}

        	//call word length function
        	
		wordLength(sentence, wordLengths);

        	//display analysis
        	cout << "\nSENTENCE ANALYSIS:" << endl << endl;
        	cout << "Punctuation Characters: " << countPunctuation(sentence) << endl;
       	 	cout << "Vowels: " << countVowels(sentence) << endl;
        	cout << "Words: " << countWords(sentence) << endl;

        	cout << "\nWord Lengths: " << endl;
        	for (i = 1; i <= 20; i++){
            		if (wordLengths[i] > 0){
                		cout << i << " characters long: " << wordLengths[i] << " word";
                		if (wordLengths[i] > 1)
                    			cout << "s";
                	
                		cout << "." << endl;
            		}
        	}

        	//display if word is in sentence 
		cout << "\nThe word: \"" << word << "\" "; //make sure that there's a space and not an endl before result
        	if (isWordInSentence(sentence, word))
            		cout << "IS a part of the sentence you entered." << endl;
       
        	else
       			cout << "IS NOT part of the sentence you entered." << endl;
       
		cout << endl;

        	//prompt for user continuation
        	continueAnalysis = contResponse();

        	//clearing the input buffer again just in case
        	cin.ignore(1000, '\n');
    	}

    	return 0;
}

//function initializations

//punctuation counting function
int countPunctuation(const string &sentence){
    	int count = 0;
    	for (int i = 0; i < sentence.length(); i++){
        	if (ispunct(sentence[i]))
    			count++;
     	}
    	return count;
}


//vowel count function
int countVowels(const string &sentence){
    	int count = 0;
    	for (int i = 0; i < sentence.length(); i++){
        	char lowerC = tolower(sentence[i]);
        	if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u')
            		count++;
        
    	}
    	return count;
}

//counting words in sentence (handles multiple spaces)
int countWords(const string &sentence){
    	int count = 0;
    	bool inWord = false;

    	for (int i = 0; i < sentence.length(); i++){
        	if (isspace(sentence[i]))
       			inWord = false;
     
        	else if (!inWord){
            		inWord = true;
            		count++;
        	}
    	}

    	return count;
}

//find length of words inputted
void wordLength(const string &sentence, int lengthCounts[]){
    	string currentWord = "";

    	for (int i = 0; i < sentence.length(); i++){
        	if (isspace(sentence[i])){
            		if (currentWord.length() > 0){
                		int length = currentWord.length();
                		if (length <= 20)
                			lengthCounts[length]++;
                
      				currentWord = "";
            		}
        	}
        	
		else
       			currentWord += sentence[i];
       
    	}

    	//cleaning up last word
    	if (currentWord.length() > 0){
        	int length = currentWord.length();
        	if (length <= 20)
            		lengthCounts[length]++;
       
    	}
}

//checking if word(casespecific)is in sentence
bool isWordInSentence(const string &sentence, const string &word){
	if (word.length() == 0 || sentence.length() == 0 || word.length() > sentence.length())
        	return false;

    	for (int i = 0; i <= sentence.length() - word.length(); i++){
        	bool match = true;

        	for (int j = 0; j < word.length(); j++){
            		if (sentence[i + j] != word[j]){
                		match = false;
                		break;
            		}
        	}

        	if (match)
            		return true;
       
    	}

    return false;
}

//function for continuation or new prompt
bool contResponse(){
    	string response;
    	bool firstPrompt = true;

    	while (true){
        	if (firstPrompt){
            		cout << "Enter another sentence/word for analysis (yes/no): ";
            		firstPrompt = false;
        	}
        else
        	cout << "Enter yes or no: ";
       
	cin >> response;

        //converting to lowercase for comparison
        for (int i = 0; i < response.length(); i++)
        	response[i] = tolower(response[i]);
       

        	if (response == "yes")
            		return true;
        
        	else if (response == "no")
            		return false;
      
        	//invalid inputs repeat loop
    	}
}

