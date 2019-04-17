#pragma once
#include<iostream>
#include<vector>
using namespace std;

//shell排序是对插入排序的改进，进行分组

void shell_insert(vector<int>& v, int gap)
{
	for (int i = gap; i < v.size(); i += gap)
	{
		int index = v[i];
		int j = i;
		for (; j>0; j -= gap)
		{
			if (v[j - gap] > index)
				v[j] = v[j - gap];
			else
				break;
		}
		v[j] = index;
	}
}

void shell_sort(vector<int>& v)
{
	int gap = v.size();
	while (1)
	{
		gap = gap / 3 + 1;
		shell_insert(v, gap);
		if (gap == 1)
			break;
	}
}
