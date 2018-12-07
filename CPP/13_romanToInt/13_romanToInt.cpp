// 13_romanToInt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

const std::map<char, int>::value_type data[] = {
	std::map<char, int>::value_type('I', 1),
	std::map<char, int>::value_type('V', 5),
	std::map<char, int>::value_type('X', 10),
	std::map<char, int>::value_type('L', 50),
	std::map<char, int>::value_type('C', 100),
	std::map<char, int>::value_type('D', 500),
	std::map<char, int>::value_type('M', 1000)
};
static std::map<char, int> roman(data, data + sizeof(data) / sizeof(data[0]));

int romanToInt(string s) 
{
	int res = 0;

	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'I' && i + 1 < s.length() && (s[i + 1] == 'V' || s[i + 1] == 'X'))
		{
			res += roman[s[i + 1]] - roman[s[i]];
			i++;
		}
		else if (s[i] == 'X' && i + 1 < s.length() && (s[i + 1] == 'L' || s[i + 1] == 'C'))
		{
			res += roman[s[i + 1]] - roman[s[i]];
			i++;
		}
		else if (s[i] == 'C' && i + 1 < s.length() && (s[i + 1] == 'D' || s[i + 1] == 'M'))
		{
			res += roman[s[i + 1]] - roman[s[i]];
			i++;
		}
		else
		{
			res += roman[s[i]];
		}
	}

	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "III: " << romanToInt("III") << endl;
	cout << "IV: " << romanToInt("IV") << endl;
	cout << "IX: " << romanToInt("IX") << endl;
	cout << "LVIII: " << romanToInt("LVIII") << endl;
	cout << "MCMXCIV: " << romanToInt("MCMXCIV") << endl;

	system("pause");
	return 0;
}

