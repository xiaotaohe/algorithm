//最长单调递增子序列求解，时间复杂度为O(nLogN)
int main()
{
	int a[] = { 2, 1, 6, 4, 5, 2, 7, 4 };
	//辅助数组，此数组维护一个当前最长子序列的，最小末尾（i位置，存储长度为i+1子序列的最小末尾）
	//有效区长度为最长子序列长度
	int b[sizeof(a) / sizeof(a[0])] = { 1 };
	//当遍历2的时候， i=0,i+1 = 1,此时子序列为i+1，i位置存储的长度为1的子序列的最小末尾为2
	//遍历1的时候秩序更新2为1，在有效区内找到第一个比此时遍历值大的数，并更新
	b[0] = a[0];
	//标识有效区长度
	int index = 1;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		//二分查找，在有效区内找到第一个比a[i]大的数，找到更新
		//找不到更新有效区长度，将该数放入有效区
		int left = 0;
		int right = index - 1;
		int first_big = -1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (b[mid] >= a[i])
			{
				first_big = mid;
				right = mid - 1;
			}
			if (b[mid] <= a[i])
				left = mid + 1;
		}
		//如果没找到的话，更新有效区，并将该数放入有效区末尾
		//找到的话，更新该位置为a[i]
		if (first_big == -1)
			b[index++] = a[i];
		else
			b[first_big] = a[i];
	}
	cout << index << endl;
	return 0;
}