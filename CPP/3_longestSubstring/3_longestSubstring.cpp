// 3_longestSubstring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

string longestSubstring(string str)
{
	string sub = "";

	int len = str.length();
	for (int i = 0; i < len - 1; i++)
	{
		set<char> chset;
		chset.insert(str.at(i));

		int j = i + 1;
		for (; j < len; j++)
		{
			if (chset.find(str.at(j)) != chset.end())
			{
				break;
			}
			chset.insert(str.at(j));
		}

		if (chset.size() > sub.length())
		{
			sub = str.substr(i, j - i);
		}
	}

	return sub;
}

string longestSubstring2(string str)
{
	string sub = "";
	int len = str.length();
	
	set<char> chset;
	int ans = 0, i = 0, j = 0;
	while (i < len && j < len)
	{
		if (chset.find(str[j]) != chset.end())
		{
			chset.erase(str[i++]);
		}
		else
		{
			chset.insert(str[j++]);
			if (j - i > ans)
			{
				ans = j - i;
				sub = str.substr(i, ans);
			}
		}
	}

	return sub;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "abcbada";
	string sub = longestSubstring2(str);
	cout << sub << ": " << sub.length() << endl;

	system("pause");
	return 0;
}

