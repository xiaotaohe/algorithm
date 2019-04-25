#pragma once
#include<vector>
#include<iostream>
using namespace std;

//合并部分
void meger(vector<int>&v, vector<int>&ret, int left, int index, int right)
{
	//合并两个序列，分别标出两个序列的开头和结尾
	int b1 = left, b2 = index + 1;
	int e1 = index, e2 = right;
	//将合并的结果放入ret中，最后放入v中
	int k = 0;
	while (b1 <= e1 &&b2 <= e2)
	{
		if (v[b1] < v[b2])
		{
			ret[k++] = v[b1];
			b1++;
		}
		else
		{
			ret[k++] = v[b2];
			b2++;
		}
	}
	while (b1 <= e1)
	{
		ret[k++] = v[b1];
		b1++;
	}
	while (b2 <= e2)
	{
		ret[k++] = v[b2];
		b2++;
	}
	//将合并好的序列放回原序列
	k = 0;
	for (int i = left; i <= right;i++)
	{
		v[i] = ret[k++];
	}
}

void meger_sort(vector<int>& v, vector<int>& ret,int left, int right)
{
	if (left < right)
	{
		int index = (left + right) >> 1;
		meger_sort(v, ret,left, index);
		meger_sort(v, ret,index + 1, right);
		meger(v, ret, left, index, right);
	}
}

