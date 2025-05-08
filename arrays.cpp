/* Name: Daniel Romanov
Date: 3/20/2025
Assignment: Homework 5: Array Analyzer
Due Date: 3/27/2025

About this project: This project will take in an array of 15, take the values (which are either randomized or inputted by the user), and then return the minimum, maximum, 
sum, mean, median, rotated, sorted, and the most frequent number in the array.

Assumptions: the user will input the current amount of integers into the array, and that these will always be integers. may be negative integers.

All work below was performed by Daniel Romanov. */

//libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

//declaring functions
void arrayRotate(int list[], int SIZE);
void arraySort(int list[], int SIZE);
int arrayFreq(int list[], int SIZE, int &number);
void printFreqNums(int list[], int SIZE, int frequency);

using namespace std;
int main(){

	//seed random number generator
    	srand(time(0));

    	//declare const size and array
    	const int SIZE = 15;
    	int list[SIZE];

    	//declare variables
    	char userChoice;
    	double sum = 0;
    	double mean;
    	double median;
    	int min, max;
    	int firstFreqNum = 0;
	int frequency;

    	//get user input for custom or random values
    	cout << "Enter (c)ustom or (r)andom values? --> ";
    	cin >> userChoice;
    	
	//validate user input
    	while (userChoice != 'c' && userChoice != 'C' && userChoice != 'r' && userChoice != 'R'){
        	//force good input
        	cout << "Enter (c)ustom or (r)andom values? --> ";
        	cin >> userChoice;
    	}

    	cout << endl;
    	cout << "Array analysis: " << endl;
    	cout << "-------------------------------" << endl;

    	if (userChoice == 'c' || userChoice == 'C'){
        	//get user input for array
        	for (int i = 0; i < SIZE; i++){
	      		cout << "Enter value " << i + 1 << ": ";
            		cin >> list[i];
        	}
    	}
    	
	else if (userChoice == 'r' || userChoice == 'R'){
	        // fill array with random numbers
        	for (int i = 0; i < SIZE; i++){
	        list[i] = rand() % 100 + 1;
        	}
    	}

    	//initialize min and max here
    	min = list[0];
    	max = list[0];

    	//print array
    	cout << "Your array: " << list[0];
    		for (int i = 1; i < SIZE; i++){
        	cout << ", " << list[i];
    	}
    	cout << endl;
    	cout << endl;
    
	//finding minimum
    	for (int i = 1; i < SIZE; i++){
		if (list[i] < min){
	            min = list[i];
        	}
    	}
    	
	//finding maximum
 	for (int i = 1; i < SIZE; i++){
        	if (list[i] > max){
	            max = list[i];
        	}
    	}
    	
	//finding sum
    	for (int i = 0; i < SIZE; i++){
        	sum += list[i];
    	}
    
	//finding mean
    	mean = sum / SIZE;
    
	//rotating array
    	arrayRotate(list, SIZE);

    	//printing first results to screen
    	cout << "Minimum: " << min << endl;
    	cout << "Maximum: " << max << endl;
    	cout << "Sum: " << sum << endl;
    	cout << fixed << setprecision(1) << "Mean: " << mean << endl;
    	cout << "Rotated: " << list[0];
    	for (int i = 1; i < SIZE; i++){
        	cout << ", " << list[i];
    	}
    	
	//sorting array
    	arraySort(list, SIZE);
    
	//finding median
    	if (SIZE % 2 == 0)
        	median = (list[SIZE / 2 - 1] + list[SIZE / 2]) / 2.0;
    	else
        	median = list[SIZE / 2];

    	cout << endl;
    	cout << "Sorted: " << list[0];
   	for (int i = 1; i < SIZE; i++)
        	cout << ", " << list[i];
    	
	cout << endl;
    	cout << fixed << setprecision(1) << "Median: " << median << endl;

    	//finding frequency
    	frequency = arrayFreq(list, SIZE, firstFreqNum);
	cout << "Highest frequency: " << frequency << endl;
    	cout << "Values that appear " << frequency << " times: ";
    	
	//finding most frequent nums
	printFreqNums(list, SIZE, frequency);
    	cout << endl;
    	return 0;
}

//function to rotate array
void arrayRotate(int list[], int SIZE){
    	int rotations;
    	if (SIZE % 2 == 0)
        	rotations = SIZE / 2;
    	else
        	rotations = (SIZE + 1) / 2;

    	//perform rotations
    	for (int j = 0; j < rotations; j++){
        	int temp = list[SIZE - 1];
        	for (int i = SIZE - 1; i > 0; i--)
            		list[i] = list[i - 1];
  
	      	list[0] = temp;
	}
}

// function to sort array
void arraySort(int list[], int SIZE){
	//create swapped boolean to check passes
	bool swapped;
    	do{
        	swapped = false;
        	for (int i = 0; i < SIZE - 1; i++){
            		if (list[i] > list[i + 1]){
                		int temp = list[i];
                		list[i] = list[i + 1];
                		list[i + 1] = temp;
                		swapped = true;
  	        	}
        	}
    	} while(swapped);
}

int arrayFreq(int list[], int SIZE, int &number){
	int maxCount = 0;
    	number = list[0];

  	for (int i = 0; i < SIZE; i++){
        	//initialize a counter
		int count = 0;
        	for (int j = 0; j < SIZE; j++){
            		if (list[j] == list[i])
                	count++;
        	}
		//check if new freq is higher than prev freq
        	if (count > maxCount){
            		maxCount = count;
            		number = list[i];
    	    	}
    	}
    	return maxCount;
}

void printFreqNums(int list[], int SIZE, int frequency){
    	bool first = true;
    	for (int i = 0; i < SIZE; i++){
        	//skip if number was already counted
        	bool counted = false;
        	for (int j = 0; j < i; j++){
           		if (list[j] == list[i]){
                		counted = true;
                		break;
            		}
        	}
        	if (counted)
            		continue;

        	//count occurrences
        	int count = 0;
        	for (int j = 0; j < SIZE; j++){
            		if (list[j] == list[i])
                	count++;
        	}

        	//print if frequency matches
        	if (count == frequency){
            		if (first){
                		cout << list[i];
                		first = false;
            		}
            	else
                	cout << ", " << list[i];
       		}    
       }
}

