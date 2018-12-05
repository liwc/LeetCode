// 10_isRegularMatch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool isRegularMatch(string s, string p) 
{
	char precede;
	int slen = s.length();
	int plen = p.length();

	int i = 0, j = 0;
	while (i < slen && j < plen)
	{
		if (s[i] == p[j] || p[j] == '.')
		{
			precede = s[i];

			i++;
			j++;
		}
		else
		{
			if (p[j] == '*')
			{
				if (s[i] == precede)
				{
					i++;
				}
				else
				{
					j++;
				}
			}
			else
			{
				if (j + 1 < plen && p[j + 1] == '*')
				{
					j = j + 2;
				}
				else
				{
					break;
				}
			}
		}
	}

	return (i >= slen ? true : false);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "s = \"aa\", p = \"a\": " << isRegularMatch("aa", "a") << endl;
	cout << "s = \"aa\", p = \"a*\": " << isRegularMatch("aa", "a*") << endl;
	cout << "s = \"aa\", p = \".*\": " << isRegularMatch("aa", ".*") << endl;
	cout << "s = \"aab\", p = \"c*a*b\": " << isRegularMatch("aab", "c*a*b") << endl;
	cout << "s = \"mississippi\", p = \"mis*is*p*.\": " << isRegularMatch("mississippi", "mis*is*p*.") << endl;
	system("pause");
	return 0;
}

