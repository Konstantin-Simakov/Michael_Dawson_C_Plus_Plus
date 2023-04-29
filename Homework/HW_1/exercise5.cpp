// exercise5.cpp
// 'Autodiler' program
#include <iostream>

int main(void)
{
	using namespace std;
	const float TAX_RATE = 0.13;			// 13% of the cost of the car
	const float REGISTRATION_FEE = 0.02;	// 2% of the cost of the car
	const float AGENCY_FEE = 6347.56;		// Fixed sum
	const float DELIVERY = 12500.00;		// Fixed sum
	
	cout << "Enter the cost price of the car: ";
	double cost_price;
	cin >> cost_price;

	// Calculations
	double sum_tax = cost_price * TAX_RATE;
	double sum_reg = cost_price * REGISTRATION_FEE;
	double sum_agency = AGENCY_FEE;
	double sum_delivery = DELIVERY;
	double market_price = cost_price + sum_tax + sum_reg + sum_agency + sum_delivery;

	// Results
	cout << "Market price of the car: " << market_price << endl;

	return 0;
}
