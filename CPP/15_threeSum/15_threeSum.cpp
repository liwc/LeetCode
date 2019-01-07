// 15_threeSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> triplets;
	vector<set<int>> filters;

	unsigned int i = 0, j = 0, k = 0, r = 0;
	for (i = 0; i < nums.size() - 2; i++)
	{
		for (j = i + 1; j < nums.size() - 1; j++)
		{
			for (k = j + 1; k < nums.size(); k++)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					for (r = 0; r < filters.size(); r++)
					{
						if (filters[r].find(nums[i]) != filters[r].end() && 
							filters[r].find(nums[j]) != filters[r].end() && 
							filters[r].find(nums[k]) != filters[r].end())
						{
							break;
						}
					}

					if (r == filters.size())
					{
						set<int> filter;
						filter.insert(nums[i]);
						filter.insert(nums[j]);
						filter.insert(nums[k]);
						filters.push_back(filter);

						vector<int> triplet;
						triplet.push_back(nums[i]);
						triplet.push_back(nums[j]);
						triplet.push_back(nums[k]);
						triplets.push_back(triplet);
					}
				}
			}
		}
	}

	return triplets;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nums[] = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> triplets = threeSum(vector<int>(nums, nums + sizeof(nums) / sizeof(nums[0])));
	for (unsigned i = 0; i < triplets.size(); i++)
	{
		for (unsigned j = 0; j < triplets[i].size(); j++)
		{
			cout << triplets[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

