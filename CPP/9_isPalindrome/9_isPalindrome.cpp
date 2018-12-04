// 9_isPalindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int val) 
{
	int reverse = 0;
	int temp = abs(val);
	for (; temp != 0; temp = temp / 10)
	{
		reverse = reverse * 10 + temp % 10;
	}
	return (reverse == val ? true : false);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 121, y = -121;
	cout << x << ": " << isPalindrome(x) << endl;
	cout << y << ": " << isPalindrome(y) << endl;
	system("pause");
	return 0;
}

