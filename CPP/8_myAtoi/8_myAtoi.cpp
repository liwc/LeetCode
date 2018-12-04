// 8_myAtoi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int myAtoi(string str)
{
	int res = 0, sign = 1;

	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] == ' ')
		{
			continue;
		}
		else if (str[i] == '-' && res == 0)
		{
			sign = -1;
		}
		else if (str[i] < 48 || str[i] > 57)
		{
			break;
		}
		else
		{
			res = res * 10 + str[i] - 48;
		}
	}

	return res * sign;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str1 = "42";
	string str2 = "   -42";
	string str3 = "4193 with words";
	string str4 = "words and 987";
	string str5 = "-91283472332";

	cout << str1 << ": " << myAtoi(str1) << endl;
	cout << str2 << ": " << myAtoi(str2) << endl;
	cout << str3 << ": " << myAtoi(str3) << endl;
	cout << str4 << ": " << myAtoi(str4) << endl;
	system("pause");
	return 0;
}

