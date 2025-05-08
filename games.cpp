/* Name: Daniel Romanov
Date: 2/21/2025
Assignment: Homework 3: Assorted Games
Due Date: 2/28/2025
About this project: This project is a collection of 4 games that the user can 
play. The games are:Guess the Number, Collect Pairs, High/Low, and Math Quiz. The 
user can also view the rules of each game and view their stats for each game, as 
well as exiting at any time.
Assumptions: idk yet

All work below was performed by Daniel Romanov */
/*Headers/Libraries*/
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

/*Function Declarations*/
void printRules();
int menu();
void viewStats(int wins, int losses);
void guessNumber(int &wins, int &losses);
void highLow(int &wins, int &losses);
void collectPairs(int &wins, int &losses);
void mathQuiz(int &wins, int &losses);

int main()
{
   	
	//seed random number generator
	srand(time(0));
	
	//declaring menu and win/loss variables
        int menuChoice;
        int wins = 0;
        int losses = 0;
	
	//main menu function
        do {
		menuChoice = menu();
        	switch(menuChoice) {
            		case 1:
                		guessNumber(wins, losses);
                		break;
            		case 2:
                		highLow(wins, losses);
                		break;
            		case 3:	
                		collectPairs(wins, losses);
                		break;
            		case 4:
                		mathQuiz(wins, losses);
                		break;
            		case 5:
                		viewStats(wins, losses);
                		break;
            		case 6:
				//stats reset
                		wins = 0;
                		losses = 0;
                		cout << "Statistics reset!\n";
                		break;
            		case 7:
                		printRules();
                		break;
            		case 0:
				//end game
                		viewStats(wins, losses);
                		cout << "Thank you for playing!" << endl;
                		break;
            		default:
                		//warning user about menu choice
				cout << "Invalid choice. Please try again.\n";
        	}
	} while(menuChoice != 0);

	return 0;
}

/*Function definition for GUESSNUMBER*/
void guessNumber(int &wins, int &losses) {
	//generate number
	int secretNumber = rand() % 100 + 1;
	//declare user guesses and tries variables
	int guess;
	int tries = 1;

    	cout << "Guess the Number, 1 -->100!\n";
	//create loop for game
    	while (tries < 7){
		cout << "Attempt "<< tries <<"/6 : ";
        	cin >> guess;
		tries++;
		//winning if case
        	if (guess == secretNumber) {
            		cout << "YOU WIN!\n";
            		wins++;
            		return;
        	} 
		//game feedback/hints
		else if (guess < secretNumber)
            		cout << "TOO SMALL.\n"; 
		else 
	            	cout << "TOO BIG.\n";
    	}
	//losing case
        cout << "Sorry, you lose. The number was " << secretNumber << "\n";
        losses++;
}

/*Function definition for HIGHLOW*/
void highLow(int& wins, int& losses) {
    	//generate the random numbers
	int currentValue = rand() % 1000 + 1;
    	int nextValue;
	//user guesses and attempts variables
    	char guess;
    	int correctGuesses = 0;

    	cout << "High or Low! Stay alive for 5 rounds to win!(Numbers range from 1 to 1,000)\n";
	//game loop
	while (correctGuesses < 5) {
        	cout << "Round " << correctGuesses + 1 << " of 5. The number is " << currentValue << endl;
        	cout << "\t... is the next number [H]igher or [L]ower?: ";
        	cin >> guess;

        	while (guess != 'H' && guess != 'L' && guess != 'h' && guess != 'l') {
            		cout << "Invalid input. Enter H or L: ";
            		cin >> guess;
        	}
		//making sure number is revealed after user guess and potential faulty input
        	nextValue = rand() % 1000 + 1;
            	cout << "The next number is: " << nextValue << "\n";
		//testing for correct answer
        	if ((guess == 'H' && nextValue > currentValue) || (guess == 'L' && nextValue < currentValue) || (guess == 'h' && nextValue > currentValue) || (guess == 'l' && nextValue < currentValue)){
			cout << "Correct!\n";
            		correctGuesses++;
        	} 
		else {
            		cout << "Sorry, you lose.\n";
            		losses++;
            		return;
        	}
		//setting the previous number to the one the user has to reference to guess
        	currentValue = nextValue;
    		}

    	cout << "You WIN!\n";
    	wins++;
}
 /*Function 
definition for COLLECTPAIRS*/
void collectPairs(int& wins, int& losses) {
	//declaring pair values
  	int pair1Found = 0;
    	int pair2Found = 0;
    	int pair3Found = 0;
    	int pair4Found = 0;
    	int pair5Found = 0;
    	int pair6Found = 0;
    	int pairsCount = 0;

    	cout << "Rolling a pair of dice 100 times for pairs!\n";

    	for (int i = 0; i < 100; i++) {
		//die rolling
        	int die1 = rand() % 6 + 1;
        	int die2 = rand() % 6 + 1;
		//finding pairs
        	if (die1 == die2) {
            		if (die1 == 1 && pair1Found == 0) {
                		pair1Found = 1;
                		pairsCount++;
                		cout << "PAIR OF ONES found\n";
            		} 
			else if (die1 == 2 && pair2Found == 0) {
                		pair2Found = 1;
                		pairsCount++;
                		cout << "PAIR OF TWOS found\n";
            		} 
			else if (die1 == 3 && pair3Found == 0) {
                		pair3Found = 1;
                		pairsCount++;
                		cout << "PAIR OF THREES found\n";
            		} 
			else if (die1 == 4 && pair4Found == 0) {
                		pair4Found = 1;
                		pairsCount++;
                		cout << "PAIR OF FOURS found\n";
            		} 
			else if (die1 == 5 && pair5Found == 0) {
                		pair5Found = 1;
                		pairsCount++;
                		cout << "PAIR OF FIVES found\n";
            		} 
			else if (die1 == 6 && pair6Found == 0) {
                		pair6Found = 1;
                		pairsCount++;
                		cout << "PAIR OF SIXES found\n";
            		}
        	}
	}
	//win/lose checks
    	if (pairsCount == 6) {
        	cout << "You WIN!\n";
        	wins++;
    	}	
	else {
        	cout << "Sorry, you lose.\n";
        	losses++;
    	}
}
/*Function definition for MATHQUIZ*/
void mathQuiz(int& wins, int& losses) {
	//select difficulty
	int difficulty;
    	cout << "Select a difficulty for Math Quiz (1: easy, 2: medium, 3: hard) - ";
    	cin >> difficulty;
    	while(difficulty < 1 || difficulty > 3){
        	cout << "Invalid difficulty. Enter 1,2, or 3: ";
        	cin >> difficulty;
    	}
	
    	//set difficulty values
	int minValue, maxValue;
    	if(difficulty == 1){
        	minValue = 0;
        	maxValue = 10;
    	}
	else if (difficulty == 2){
        	minValue = -10;
        	maxValue = 10;
    	}
	else{
        	minValue = -10;
        	maxValue = 20;
    	}
	//declare and initialize number and operator variables
    	int num1 = rand() % (maxValue - minValue + 1) + minValue;
    	int num2 = rand() % (maxValue - minValue + 1) + minValue;
    	int num3 = rand() % (maxValue - minValue + 1) + minValue;
    	char sym1, sym2;
    	int sym1Rand = rand() % 3;
    	int sym2Rand = rand() % 3;
    	int answer;
    	int userAnswer;
	//find symbols for equation
    	switch (sym1Rand) {
        	case 0: sym1 = '+'; break;
        	case 1: sym1 = '-'; break;
        	case 2: sym1 = '*'; break;
    	}

    	switch (sym2Rand) {
        	case 0: sym2 = '+'; break;
        	case 1: sym2 = '-'; break;
        	case 2: sym2 = '*'; break;
    	}
	//print equation
    	cout << "Solve: ";
    	cout << num1 << " " << sym1 << " " << num2 << " " << sym2 << " " << num3 << "\n = ";
    	cin >> userAnswer;
	//set order of operations
    	if (sym2 == '*' && sym1 != '*') {
        	if (sym1 == '+') 
			answer = num1 + (num2 * num3);
        	else 
			answer = num1 - (num2 * num3);
    	}
	else {
        	int temp;
        	if (sym1 == '*') 
			temp = num1 * num2;
        	else if (sym1 == '+') 
			temp = num1 + num2;
        	else 
			temp = num1 - num2;
        	if (sym2 == '*') 
			answer = temp * num3;
        	else if (sym2 == '+') 
			answer = temp + num3;
        	else 
			answer = temp - num3;
    	}

    	if (userAnswer == answer) {
        	cout << "CORRECT!\n";
        	wins++;
    	} 
	else {
        	cout << "Wrong. Answer: " << answer << endl;
        	losses++;
    	}
}
/*Function definition for VIEWSTATS*/
void viewStats(int wins, int losses) {
	double winPercentage = 0.0;
	//calculate winning percentage
	if (wins + losses > 0)
        	winPercentage = (double)wins / (wins + losses) * 100;
    	cout << "STATISTICS:\n-------------------------\n";
    	cout << "Wins: " << wins << "\tLosses: " << losses << "\n";
	cout << "Total Win Percentage: " << fixed << setprecision(1) << winPercentage << "%\n";
}

/*Function definition for MENU */
int menu() {
    	int menuChoice;
    	bool validChoice = false;
	//create the menu
    	while (!validChoice) {
        	cout << "GAME MENU:\n--------------------------\n";
        	cout << "1: PLAY Guess the Number\n";
        	cout << "2: PLAY High Low\n";
        	cout << "3: PLAY Collect Pairs\n";
        	cout << "4: PLAY Math Quiz\n";
        	cout << "5: VIEW Statistics\n";
        	cout << "6: RESET Statistics\n";
        	cout << "7: RULES\n";
        	cout << "0: QUIT\n";
        	cout << "--------------------------\n> ";
        	cin >> menuChoice;

        	if (menuChoice >= 0 && menuChoice <= 7) {
            		validChoice = true;
        	} 	
		else {
            		cout << "Invalid choice. Please try again.\n";
        	}
    	}

    	return menuChoice;
}

/*Function definition for PRINTRULES
this function prints the rules of all of the games available to the user in this 
program
that is all this function is responsible for*/
void printRules()
{
    cout << "\nRULES:\n\nGuess the Number Game:\n";
    cout << "You'll only get 6 tries to guess a number between 1 and 100!\n";
    cout << "Guess Wisely!\n\n";
    cout << "High/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
    cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
    cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
    cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then you win!\n\n";
    cout << "Math Quiz Game:\nAnswer the math equation correctly to win!\n\n";
    return;
}
