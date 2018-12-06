// 11_maxArea.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int maxArea(int a[], int len) 
{
	int res = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			int temp = (j - i) * (a[i] < a[j] ? a[i] : a[j]);
			if (res < temp)
			{
				res = temp;
			}
		}
	}

	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << maxArea(a, sizeof(a) / sizeof(a[0])) << endl;

	system("pause");
	return 0;
}

