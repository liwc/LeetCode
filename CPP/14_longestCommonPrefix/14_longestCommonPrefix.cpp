// 14_longestCommonPrefix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(std::vector<string> strs)
{
	string str;
	if (strs.size() == 0)
	{
	}
	else if (strs.size() == 1)
	{
		str = strs[0];
	}
	else
	{
		unsigned int i = 0;
		for (; i < strs[0].length(); i++)
		{
			str = strs[0].substr(0, i + 1);

			unsigned int j = 1;
			for (; j < strs.size(); j++)
			{
				if (str != strs[j].substr(0, i + 1))
				{
					break;
				}
			}

			if (j != strs.size())
			{
				str = str.substr(0, i);
				break;
			}
		}
	}

	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string strs1[] = {
		"flower",
		"flow",
		"flight"
	};

	cout << longestCommonPrefix(std::vector<string>(strs1, strs1 + sizeof(strs1) / sizeof(strs1[0]))) << endl;
	system("pause");
	return 0;
}

