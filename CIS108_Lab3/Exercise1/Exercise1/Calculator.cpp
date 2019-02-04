#include<stdlib.h>
#include<string>
#include<sstream>
#include "Calculator.h"

double memoryVal = 0;

//This function clears the console screen
void clearScr()
{
	system("CLS");

}

//Memory Store - Store the result in Memory
void setMemoryValue(double inputMemoryVal)
{
	memoryVal = inputMemoryVal;
}

//Memory recall - Get the value from Memory
double getMemoryValue() 
{
	return memoryVal;
}

//Clears the calculator memory
void clearMemory() {
	memoryVal = 0;
}


//Invert the current value of the calculator and return it
double invertValue()
{
	memoryVal = -memoryVal;
	return memoryVal;
}

//This function adds 2 numbers and return the result
double Addition(double a,  double b)
{
	double Addition;
	Addition =(a+b);
	return Addition;
		
}

//The function subtracts 2 numbers and return the result
double Subtraction(double a, double b)
{
	double Subtraction;
	Subtraction = (a-b);
	return Subtraction;
}

//This function multiplies 2 numbers and return the result
double Multiplication(double a, double b)
{
	double Multiplication;
	Multiplication = (a*b);
	return Multiplication;
}

//This function divides 2 numbers and return the result
double Division(double a, double b)
{
	double Division;
	Division = (a/b);
	return Division;
}

//This function does power (exponent) to base number and return the result
double power(double a, double b)
{
	double power = 1;
	while (b != 0) {
		power *= a;
		--b;
	}
	return power;
}

//This function converts a string val to its equivalent double value and return the double
double getDoubleString(string sVal)
{
	std::stringstream ss(sVal);
	double dVal;
	ss >> dVal;
	return dVal;
}

//This function converts a double val to its equivalent string value and return the string
string getStringDouble(double dVal)
{
	string sVal;
	std::ostringstream strs;
	strs << dVal;
	sVal = strs.str();
	return sVal;
}

//This function does the calculation based on operator and return the result
double doCalculation(string lValue, string rValue, char opr)
{
	double result;

	if (opr == '+')
	{
		result = Addition(getDoubleString(lValue), getDoubleString(rValue));
	}
	else if (opr == '-')
	{
		result = Subtraction(getDoubleString(lValue), getDoubleString(rValue));
	}
	else if (opr == '*')
	{
		result = Multiplication(getDoubleString(lValue), getDoubleString(rValue));
	}
	else if (opr == '/')
	{
		result = Division(getDoubleString(lValue), getDoubleString(rValue));
	}
	else if (opr == '^')
	{
		result = power(getDoubleString(lValue), getDoubleString(rValue));
	}
	return result;
}