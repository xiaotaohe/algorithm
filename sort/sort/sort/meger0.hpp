#pragma once
#include<iostream>

static void meger_0(int* a, int* ret, int left,int index,int right)
{
	//�����������е�ͷ����β��
	int b1 = left, b2 = index + 1;
	int e1 = index, e2 = right;
	//��¼���������Ԫ�ص�λ��
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
	//���������е�Ԫ�طŻ�
	k = 0;
	for (int i = left; i <= right; i++)
		a[i] = ret[k++];
}

//����
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


