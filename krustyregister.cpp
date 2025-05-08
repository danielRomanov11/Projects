/* Name: Daniel Romanov
Date: 1/22/2025
Assignment: Krusty Register (#1)
Due Date: 1/22/2025
About this project: Acts as a menu for the Krusty Krab, giving the users menu prices and allowing them to see the total price of their order.  
Assumptions: Assumes that the user inputs the correct format, i.e. integer for integer or character for character prompts. Also assumes that these prices are unadjusted for 
inflation because wow these are some cheap prices.

All work below was performed by Daniel Romanov. */


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declaring and initializing constant variables
	const double KRABBYPATTYPRICE = 3.50;
	const double KELPSHAKEPRICE = 1.00;
	const double BARNACLEFRIESPRICE = 1.50;
	const double CORALBITSPRICE = 2.00;

	//declaring and initializing  undersea tax rate
	const double TAX = 0.055;
	
	//declaring user input variables

	int krabbyPattyAmt;
	int kelpShakeAmt;
	int barnacleFriesAmt;
	int coralBitsAmt;
	
	//declaring total variables
	double krabbyPattyTotal;
	double kelpShakeTotal;
	double barnacleFriesTotal;
	double coralBitsTotal;
	double subTotal;
	double taxAmt;
	double userTotal;

	//converting values to two decimal places
	cout << fixed << showpoint << setprecision(2);
	//welcoming user
	cout << "Welcome to the Krusty Krab, Home of the Krabby Patty." << endl;
	cout << "May I take your order?" << endl << endl;

	//printing menu	
	cout << "\tGalley Grub:" << endl;
	cout << "\tKrabby Patty $" << KRABBYPATTYPRICE << endl;
	cout << "\tKelp Shake $" << KELPSHAKEPRICE << endl;
	cout << "\tBarnacle Fries $" << BARNACLEFRIESPRICE << endl;
	cout << "\tCoral Bits $" << CORALBITSPRICE << endl << endl;
	
	//asking for user input
	cout << "How many Krabby Patties? ";
	cin >> krabbyPattyAmt;
	cout << "How many Kelp Shakes? ";
	cin >> kelpShakeAmt;
	cout << "How many Barnacle Fries? ";
	cin >> barnacleFriesAmt;
	cout << "How many Coral Bits? ";
	cin >> coralBitsAmt;

	//calculating user subtotal
	krabbyPattyTotal = KRABBYPATTYPRICE * krabbyPattyAmt;
	kelpShakeTotal = KELPSHAKEPRICE * kelpShakeAmt;
	barnacleFriesTotal = BARNACLEFRIESPRICE * barnacleFriesAmt;
	coralBitsTotal = CORALBITSPRICE * coralBitsAmt;
	subTotal = krabbyPattyTotal + kelpShakeTotal + barnacleFriesTotal + coralBitsTotal;
	taxAmt = subTotal * TAX;
	userTotal = subTotal + taxAmt;


	//display totals
	cout << "Order Total (Before Undersea Tax): $" << subTotal << endl;
	cout << "Undersea Tax: $" << taxAmt << endl;
	cout << "Final Order Total including Undersea Tax: $" << userTotal << endl << endl;
	cout << "Thanks for dining at the Krusty Krab!" << endl;

     return 0;
}
