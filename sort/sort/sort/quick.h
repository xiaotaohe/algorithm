#pragma once
#include<iostream>
#include<vector>

//◊Û”“÷∏’Î∑®
int partion(vector<int>& v, int left, int right)
{
	int begin = left, end = right;
	int cur = right;
	while (begin < end)
	{
		while (begin < end&&v[begin] <= v[cur])
			begin++;
		while (begin < end&&v[end] >= v[cur])
			end--;
		swap(v[begin], v[end]);
	}
	swap(v[begin], v[cur]);
	return begin;
}

void quick_sort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;
	int index = partion(v, left, right);
	quick_sort(v, left, index - 1);
	quick_sort(v, index + 1, right);
}