#pragma once

#include<iostream>
#include<vector>
using namespace std;

void insert_sort(vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int j = i;
		int index = v[i];
		for (; j>0; j--)
		{
			if (v[j - 1] > index)
				v[j] = v[j - 1];
			else
				break;
		}
		v[j] = index;
	}
}
