// 0001.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> r;

		map<int, int> m;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			int temp = target - nums[i];
			if (m.find(temp) != m.end())
			{
				r.push_back(m[temp]);
				r.push_back(i);
				break;
			}

			m[nums[i]] = i;
		}

		return r;
	}
};

int main()
{
	int a[] = { 4, 3, 6, 1, 8, 5, 8 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	/*sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.rbegin(), v.rend());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;*/

	Solution s;
	vector<int> r = s.twoSum(v, 14);
	for (vector<int>::iterator it = r.begin(); it != r.end(); it++)
	{
		cout << *it << endl;
	}

	system("pause");
    return 0;
}

