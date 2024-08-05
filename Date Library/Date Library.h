#pragma once

#include <iostream>
#include <string> 

using namespace std;

bool IsLeapYear(short Year)
{
	// leap year if perfectly divisible by 40 
	if (Year % 400 == 0)
	{
		return true;
	}
	// not a leap year if divisible by 100 
	// but not divisible by 400 
	else if (Year % 100 == 0)
	{
		return false;
	}
	// leap year if not divisible by 100 
	// but divisible by 4 
	else if (Year % 4 == 0)
	{
		return true;
	}
	// all other years are not leap years 
	else
	{
		return false;
	}
}

short ReadYear()
{
	short Year = 0;

	cout << "\nPlease enter a year to check? ";
	cin >> Year;

	return Year;
}