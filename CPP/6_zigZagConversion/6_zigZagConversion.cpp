// 6_zigZagConversion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string zigZagConversion(string src, int num)
{
	int row = 0, flag = 1;
	map<int, vector<char>> rowMap;
	for (int i = 0; i < (int)src.length(); i++)
	{
		rowMap[row].push_back(src[i]);
		if (flag == 1)
		{
			if (++row == num - 1)
			{
				flag = 0;
			}
		}
		else
		{
			if (--row == 0)
			{
				flag = 1;
			}
		}
	}

	string dst;
	map<int, vector<char>>::iterator iter1 = rowMap.begin();
	for (; iter1 != rowMap.end(); iter1++)
	{
		vector<char>::iterator iter2 = iter1->second.begin();
		for (; iter2 != iter1->second.end(); iter2++)
		{
			dst += *iter2;
		}
	}
	return dst;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "PAYPALISHIRING";
	cout << zigZagConversion(str, 4) << endl;
	system("pause");
	return 0;
}

