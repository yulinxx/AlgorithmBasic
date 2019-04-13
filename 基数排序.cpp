//�����㷨----��������RadixSort��
//
// ���������˼�룺
//
//���������ǷǱȽ��͵������㷨����ԭ���ǽ�������λ���и�ɲ�ͬ�����֣�Ȼ��ÿ��λ���ֱ�Ƚϡ�
//�����д��Ƚ���ֵ����������ͳһΪͬ������λ���ȣ���λ�϶̵���ǰ�油�㡣
//Ȼ�󣬴����λ��ʼ�����ν���һ��������ÿһ�������У����յ�ǰλ������Ԫ�طŵ���Ӧ��Ͱ���У�
//Ȼ���Ͱ0��Ͱ9�е�Ԫ�ذ��Ƚ��ȳ��ķ�ʽ�Ż������С�
//���������λ����һֱ�����λ��������Ժ�, ���оͱ��һ���������С�

// ��̬��ʾͼ:  http://www.runoob.com/wp-content/uploads/2019/03/radixSort.gif 

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 20
//#define SHOWPASS
#define BASE 10

void print(int* a, int n) 
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}

void radixsort(int* a, int n) 
{
	int i, b[MAX], m = a[0], exp = 1;

	for (i = 1; i < n; i++) 
	{
		if (a[i] > m) 
		{
			m = a[i];
		}
	}

	while (m / exp > 0) 
	{
		int bucket[BASE] = { 0 };

		for (i = 0; i < n; i++) 
		{
			bucket[(a[i] / exp) % BASE]++;
		}

		for (i = 1; i < BASE; i++) 
		{
			bucket[i] += bucket[i - 1];
		}

		for (i = n - 1; i >= 0; i--) 
		{
			b[--bucket[(a[i] / exp) % BASE]] = a[i];
		}

		for (i = 0; i < n; i++) 
		{
			a[i] = b[i];
		}

		exp *= BASE;

#ifdef SHOWPASS
		printf("\nPASS   : ");
		print(a, n);
#endif
	}
}


int main() 
{
	int arr[MAX];
	int i, n;

	printf("Enter total elements (n <= %d) : ", MAX);
	scanf("%d", &n);
	n = n < MAX ? n : MAX;

	printf("Enter %d Elements : ", n);
	for (i = 0; i < n; i++) 
	{
		scanf("%d", &arr[i]);
	}

	printf("\nARRAY  : ");
	print(&arr[0], n);

	radixsort(&arr[0], n);

	printf("\nSORTED : ");
	print(&arr[0], n);
	printf("\n");

	return 0;
}