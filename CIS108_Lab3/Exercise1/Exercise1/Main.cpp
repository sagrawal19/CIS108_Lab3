#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "Calculator.h"
#include <string>
#include <sstream>
using namespace std;

int main()
{
	clearScr();
	double result = 0.0;
	char cKey;
	char op = ' ';
	string keysTyped = "";
	string lVal = "";
	string rVal = "";
	cout << '<';
	
	do 
	{
		//Store the input key by the user
		cKey = char(_getch());
		
		//output the entered key to console if not c,r,m, s or i
		if (cKey != 'C' && cKey != 'c' && cKey != 'R' && cKey != 'r' && cKey != 'M' && cKey != 'm' && cKey != 'S' && cKey != 's' && cKey != 'I' && cKey != 'i')
		{
			cout << cKey;
		}

		//read char by char and append until a operator is encountered
		//When an operator is encountered, we need to start constructing the second value
		if (cKey=='+' || cKey == '-' || cKey == '*' || cKey == '/' || cKey == '^')
		{
			//If op is not empty, then multiple operator are input
			//do the calculation on previous operator and have the result assign as left value
			if (!isblank(op))
			{
				lVal = getStringDouble(doCalculation(lVal, keysTyped, op));
			}
			else
			{
				//If the First Value is not entered, then use the memory value
				if (keysTyped == "")
				{
					//get the memory value and convert to string to assign as left value
					lVal = getStringDouble(getMemoryValue());
				}
				else {
					//If first value is entered, then use it as left value
					lVal = keysTyped;
				}
			}
			
			//Stored the operator in op var to do the operation later when enter key is pressed
			op = cKey;
			
			//Reset the keysTyped to start constructing the new value
			keysTyped = "";
		}
		else {
			//read char by char to construct the value
			keysTyped += cKey;
		}

		//When an enter is encoutered, then we need to assign the KeysTyped as RightVal and do the calculation based on operator.
		if (cKey =='\r') 
		{
			//Assign the KeysTyped value as RightVal
			rVal = keysTyped;
			
			//Based on Operator needs to call the function and output result			
			result = doCalculation(lVal,rVal,op);

			cout << endl;
			cout << result << endl;
			
			//reset the keysTyped
			keysTyped = "";

			//reset the operator
			op = ' ';
			//Now store the result in the memory
			setMemoryValue(result);

			cout << '<';

		}

		//Clear the calculator screen
		if (cKey == 'C' || cKey == 'c')
		{
			clearScr();
			keysTyped = "";
			cout << '<';
		}
		//Recall the calculator Memory Value
		if (cKey == 'R' || cKey == 'r')
		{
			cout << getMemoryValue() << endl;
			keysTyped = "";
			cout << '<';
		}

		//Clear the calculator Memory Value
		if (cKey == 'M' || cKey == 'm')
		{
			clearMemory();
			keysTyped = "";
		}

		//Store the value in Calculator Memory
		if (cKey == 'S' || cKey == 's')
		{
			setMemoryValue(result);
			keysTyped = "";
		}
	

		//To invert the calculator memory value
		if (cKey == 'I' || cKey == 'i')
		{
			cout<<invertValue()<<endl;
			keysTyped = "";
		}
		//Continue until the user pressed X or X to exit the calculator
	} while (cKey != 'X' && cKey != 'x');

	return 0;
}

