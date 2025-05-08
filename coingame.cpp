/* Name: Daniel Romanov
Date: 2/15/2025
Assignment: Coin Game #3
Due Date: 2/18/2025
About this project: In this coin game, the user inputs a dollar amount and uses different amounts of coins to try to match the initial amount 
Assumptions: The user doesn't input any non-negative integers

All work below was performed by Daniel Romanov */


#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;
int main()
{	
	//declaring and initializing coin amounts as constants
	const double HALFDOLLAR = 0.50;
	const double QUARTER = 0.25;
	const double DIME = 0.10;
	const double NICKEL = 0.05;
	const double PENNY = 0.01;
	
	//declaring user inputs
	double totalMoney;
	double userHD;
	double userQuarters;
	double userDimes;
	double userNickels;
	double userPennies;

	//performing math
	double totalHD;
	double totalQuarters;
	double totalDimes;
	double totalNickels;
	double totalPennies;
	double amountOff;
	
	//receiving continuation input
	char userContinue;
	
	//variable to track attempts
	int userAttempts = 0;
	
	//variable to calculate win percentage
	int userWins = 0;
	int userLosses = 0;
	double winPercentage;
	

	cout << "Welcome to the \"Making Change\" Game!" << endl;
	do{
		cout << fixed << showpoint << setprecision(2);
		cout << endl;
		
		cout << "Enter a dollar amount: ";
		cin >> totalMoney;
		cout << "Match the dollar amount $" << totalMoney << endl;
		cout << "Half Dollars: ";
		cin >> userHD;
		cout << "Quarters: ";
		cin >> userQuarters;
		cout << "Dimes: ";
		cin >> userDimes;
		cout << "Nickels: ";
		cin >> userNickels;
		cout << "Pennies: ";
		cin >> userPennies;
		
		//math
		totalHD = userHD * HALFDOLLAR;
		totalQuarters = userQuarters * QUARTER;
		totalDimes = userDimes * DIME;
		totalNickels = userNickels * NICKEL;
		totalPennies = userPennies * PENNY;

		amountOff = totalMoney - (totalHD + totalQuarters + totalDimes + totalNickels + totalPennies); 
		if (amountOff == 0){
			userWins++;
			cout << "You Win!" << endl;
		}
		else{
			userLosses++;
			cout << "You lost by: $" << fabs(amountOff) << endl; 
		}
		//ask and check for user input to continue or exit code

		cout << "Play again? (y or n): ";
		cin >> userContinue;
		cout << endl;
		if (userContinue != 'y' && userContinue != 'Y' &&  userContinue != 'n' &&  userContinue != 'N'){
			cout << "Please enter y or n: ";
			cin >> userContinue;
		}
	}while(userContinue != 'n' &&  userContinue != 'N');

	//results display
	cout << fixed << showpoint << setprecision(0);
	cout << "Wins: " << userWins << endl;
	cout << "Losses: " << userLosses << endl;
	winPercentage = userWins/(userWins + userLosses)*100;
	cout << fixed << showpoint << setprecision(1);
	cout << "Win Percentage: " << winPercentage << "%" << endl;
	cout << "Thanks for playing!" << endl;

     return 0;
}

