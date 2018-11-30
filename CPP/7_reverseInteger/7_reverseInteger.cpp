// 7_reverseInteger.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int reverseInteger(int val)
{
	char tmp[32] = {0};
	sprintf_s(tmp, "%d", val);
	string str = tmp;
	int begin = 0;
	if (str[begin] == '-')
	{
		begin = 1;
	}
	int end = str.length() - 1;

	while (begin < end)
	{
		char ch = str[begin];
		str[begin] = str[end];
		str[end] = ch;

		begin++;
		end--;
	}

	return atoi(str.c_str());
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 123, y = -123, z = -120;
	cout << x << ": " << reverseInteger(x) << endl;
	cout << y << ": " << reverseInteger(y) << endl;
	cout << z << ": " << reverseInteger(z) << endl;
	system("pause");
	return 0;
}

