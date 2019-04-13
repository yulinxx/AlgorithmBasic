//排序算法----基数排序（RadixSort）
//
// 基数排序的思想：
//
//基数排序是非比较型的排序算法，其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。
//将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零。
//然后，从最低位开始，依次进行一次排序。在每一次排序中，按照当前位把数组元素放到对应的桶当中，
//然后把桶0到桶9中的元素按先进先出的方式放回数组中。
//这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。

// 动态演示图:  http://www.runoob.com/wp-content/uploads/2019/03/radixSort.gif 

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