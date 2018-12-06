// 12_intToRoman.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string convert(char ch1, int num1, char ch2, int num2)
{
	string dst;

	for (int i = 0; i < num1; i++)
	{
		dst += ch1;
	}

	for (int i = 0; i < num2; i++)
	{
		dst += ch2;
	}

	return dst;
}

string intToRoman(int num) 
{
	string dst;

	int divisor = 10;
	while (1)
	{
		int digit = num % divisor;

		string tmp;
		if (digit < 10)
		{
			if (digit <= 3)
			{
				tmp = convert('I', digit, ' ', 0);
			}
			else if (digit == 4)
			{
				tmp = convert('I', 1, 'V', 1);
			}
			else if (digit <= 8)
			{
				tmp = convert('V', 1, 'I', digit - 5);
			}
			else
			{
				tmp = convert('I', 1, 'X', 1);
			}
		}
		else if (digit < 100)
		{
			if (digit <= 30)
			{
				tmp = convert('X', digit / 10, ' ', 0);
			}
			else if (digit == 40)
			{
				tmp = convert('X', 1, 'L', 1);
			}
			else if (digit <= 80)
			{
				tmp = convert('L', 1, 'X', digit / 10 - 5);
			}
			else
			{
				tmp = convert('X', 1, 'C', 1);
			}
		}
		else if (digit < 1000)
		{
			if (digit <= 300)
			{
				tmp = convert('C', digit / 100, ' ', 0);
			}
			else if (digit == 40)
			{
				tmp = convert('C', 1, 'D', 1);
			}
			else if (digit <= 8)
			{
				tmp = convert('D', 1, 'C', digit / 100 - 5);
			}
			else
			{
				tmp = convert('C', 1, 'M', 1);
			}
		}
		else if (digit < 10000)
		{
			if (digit <= 3000)
			{
				tmp = convert('M', digit / 1000, ' ', 0);
			}
		}

		dst = tmp + dst;
		if (num / divisor == 0)
		{
			break;
		}

		num -= digit;
		divisor *= 10;
	}

	return dst;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "3: " << intToRoman(3) << endl;
	cout << "4: " << intToRoman(4) << endl;
	cout << "9: " << intToRoman(9) << endl;
	cout << "58: " << intToRoman(58) << endl;
	cout << "1994: " << intToRoman(1994) << endl;

	system("pause");
	return 0;
}

