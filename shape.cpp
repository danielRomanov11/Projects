/* Name: Daniel Romanov
Date: 2/1/2025
Assignment: Shape Calculator (#2)
Due Date: 1/22/2025
About this project: Acts a shape dimensions calculator where the user 
inputs values for the program to calculate and return the results. It 
will calculate the area and the perimeter of the chosen shape. 

Assumptions: Assumes that the user inputs the correct format, i.e. 
integer for integer or character for character prompts. Also assuming that the user inputs positive, non-zero values for calculation
All work below was performed by Daniel Romanov. */ 

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	//declaring and initializing variables
	const double PI = 3.14159;
	char shapeInput;
	double radius;
	double length;
	double width;
	double perimeter;
	double area;
	double semiPerim;
	double hypo;
	double smallA;
	double smallB;
	
	//forcing program to print one decimal place
	cout << fixed << showpoint << setprecision(1);
	//Asking for user's shape of choice
	cout << "Choose a shape:\nC - Circle\nR - Rectangle\nT - Triangle\nChoice: ";
	cin >> shapeInput;
	cout << endl;	
	//testing for correct user input
	if (shapeInput == 'C' || shapeInput == 'c'){
		//getting user's input values
		cout << "Radius: ";
		cin >> radius;
		perimeter = radius * PI * 2;
		area = PI * pow(radius, 2);
		cout << "PERIMETER: " << perimeter << endl;
		cout << "AREA: " << area << endl;
	}
	else if (shapeInput == 'R' || shapeInput == 'r'){
		//getting user's input values
		cout << "Length: ";
		cin >> length;
		cout << "Width: ";
		cin >> width;
		perimeter = (length * 2) + (width * 2);
		area = length * width;
		cout << "PERIMETER: " << perimeter << endl;
		cout << "AREA: " << area << endl;
	}
	else if (shapeInput == 'T' || shapeInput == 't'){
		//getting user's input values
		cout << "Length of the Biggest side: ";
		cin >> hypo;
		cout << "Length of the two Smaller sides: ";
		cin >> smallA >> smallB;
		//checking for valid values
		if (smallA >=  hypo || smallB >= hypo){
			cout << "Invalid entries, make sure you enter the biggest side value first." << endl;
		}	
		else if (smallA + smallB <  hypo){
			cout << "It is impossible for the side lengths of " << smallA << " " << smallB << " and " << hypo << " to form the sides of a triangle." << endl;
		}
		else{
			//calculations
			perimeter = hypo + smallA + smallB;
			semiPerim = perimeter * 0.5;
			area = sqrt(semiPerim * (semiPerim - hypo) * (semiPerim - smallA) * (semiPerim - smallB));
			cout << "PERIMETER: " << perimeter << endl;
			cout << "AREA: " << area << endl;	
		}	
	}
	//dealing with invalid menu choice
	else{
		cout << "Invalid menu choice. Exiting program." << endl;
	}
	return 0;
}
