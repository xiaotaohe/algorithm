//���������������
//��������̬�滮
int main()
{
	int a[] = { 2, 1, 6, 4, 5, 2, 7, 4 };
	//��������
	int b[sizeof(a) / sizeof(a[0])] = { 1 };
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i]>a[j])
			{
				//���´�λ�õĳ���
				int len = b[j] + 1;
				if (len>b[i])
					b[i] = len;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (b[i]>max)
			max = b[i];
	}
	cout << max << endl;
	return 0;
}