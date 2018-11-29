// 5_longestPalindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string src) 
{
	string dst = "";

	int len = src.length();
	for (int i = 0; i < len; i++)
	{
		int left = i - 1;
		int right = i + 1;
		while (right < len)
		{
			if (src[right] != src[i])
			{
				break;
			}

			right++;
			i = right - 1;
		}

		while (left >= 0 && right < len)
		{
			if (src[left] != src[right])
			{
				break;
			}

			left--;
			right++;
		}

		int temp = right - left -1;
		if (temp > 1 && temp > dst.length())
		{
			dst = src.substr(left + 1, temp);
		}

		if (right >= len)
		{
			break;
		}
	}

	return dst;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "abcccabbaabcba";
	cout << longestPalindrome(str) << endl;

	system("pause");
	return 0;
}

