// 10-3_Exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int predictTuition(double currentTuition, double rate, double futureTuition)
{
	int years = 0;
	while (currentTuition < futureTuition)
	{
		currentTuition = currentTuition * (1 + rate);
		years++;
	}
	return years;
}

int predictTuitionByReference(double& currentTuition, double rate, double futureTuition)
{
	int years = 0;
	while (currentTuition < futureTuition)
	{
		currentTuition = currentTuition * (1 + rate);
		years++;
	}
	return years;
}


int main()
{
	cout << "Enter your currant tuition: ";
	double tuition;
	cin >> tuition;
	cout << endl;

	cout << "Enter the increase rate of your tution: ";
	double rate;
	cin.clear();
	cin.ignore(10000, '\n');
	cin >> rate;

	cout << "Enter your future tuition: ";
	double fTuition;
	cin.clear();
	cin.ignore(10000, '\n');
	cin >> fTuition;

	int years = predictTuition(tuition, rate, fTuition);

	cout << "Using predictTuition:" << endl;

	cout << "Your currant tuition is: " << tuition << endl;

	cout << "The amount of years it will take to get to your future tuition is: " << years << endl;

	cout << '\n';
	
	cout << "Using predictTuitionByReference:" << endl;

	years = predictTuitionByReference(tuition, rate, fTuition);

	cout << "Your Tuition is: " << tuition << endl;

	cout << "The amount of years it will take to get to your future tuition is: " << years << endl;

}