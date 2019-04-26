#pragma once
#include<iostream>

static void meger_0(int* a, int* ret, int left,int index,int right)
{
	//定义两个序列的头部和尾部
	int b1 = left, b2 = index + 1;
	int e1 = index, e2 = right;
	//记录新数组放入元素的位置
	int k = 0;
	while (b1 <= e1 && b2 <= e2)
	{
		if (a[b1] < a[b2])
			ret[k++] = a[b1++];
		else
			ret[k++] = a[b2++];
	}
	while (b1 <= e1)
		ret[k++] = a[b1++];
	while (b2 <= e2)
		ret[k++] = a[b2++];
	//将新数组中的元素放回
	k = 0;
	for (int i = left; i <= right; i++)
		a[i] = ret[k++];
}

//分治
void meger_sort(int* a, int* ret, int left, int right)
{
	if (left < right)
	{
		int index = (left + right) >> 1;
		meger_sort(a, ret, left, index);
		meger_sort(a, ret, index + 1, right);
		meger_0(a, ret, left, index, right);
	}
}


