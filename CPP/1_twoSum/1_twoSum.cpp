// 1_twoSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Approach 1: Brute Force
vector<int> twoSum1(vector<int>& nums, int target) 
{
	vector<int> indices;
	for (int i = 0; i < (int)nums.size() - 1; i++)
	{
		for (int j = i + 1; j < (int)nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				indices.push_back(i);
				indices.push_back(j);
				break;
			}
		}

		if (!indices.empty())
		{
			break;
		}
	}
	return indices;
}

// Approach 2: Two-pass Hash Table
vector<int> twoSum2(vector<int>& nums, int target) 
{
	vector<int> indices;

	map<int, int> numsMap;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		numsMap[nums[i]] = i;
	}

	map<int, int>::iterator iter = numsMap.begin();
	for (; iter != numsMap.end(); iter++)
	{
		int temp = target - iter->first;
		if (numsMap.find(temp) != numsMap.end() && numsMap[temp] != iter->second)
		{
			indices.push_back(numsMap[temp]);
			indices.push_back(iter->second);
			break;
		}
	}

	return indices;
}

// Approach 3: One-pass Hash Table
vector<int> twoSum3(vector<int>& nums, int target) 
{
	vector<int> indices;

	map<int, int> numsMap;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		int temp = target - nums[i];
		if (numsMap.find(temp) != numsMap.end())
		{
			indices.push_back(numsMap[temp]);
			indices.push_back(i);
			break;
		}

		numsMap[nums[i]] = i;
	}

	return indices;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	nums.push_back(11);
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(15);

	vector<int> indices = twoSum3(nums, 9);
	for (int i = 0; i < (int)indices.size(); i++)
	{
		cout << indices[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

