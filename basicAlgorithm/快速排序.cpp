
// 交换排序—快速排序（Quick Sort）

// 快速排序的基本思想是
// 1、先从数列中取出一个数作为基准数
// 2、分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边
// 3、再对左右区间重复第二步，直到各区间只有一个数

#include<stdio.h>

void quickSort(int* a, int nLeft, int nRight)
{
	if (nLeft >= nRight)
		return;

	int i = nLeft;
	int j = nRight;
	int temp = a[nLeft];

	while (i != j)
	{
		while (i < j && a[j] >= temp) // 右侧指针往左走,直到找到右侧比左侧小的值
			j--;

		if (j > i)
			a[i] = a[j]; // 将右侧比左侧小的值赋给左侧. a[i]已经赋值给temp,所以直接将a[j]赋值给a[i],赋值完之后a[j],有空位

		while (i < j && a[i] <= temp) // 左侧指针往右走,直到找到比原始左侧值小的数
			i++;

		if (i < j)
			a[j] = a[i];
	}

	a[i] = temp; // 把基准插入,此时i与j已经相等R[low..pivotpos-1].keys≤R[pivotpos].key≤R[pivotpos+1..high].keys

	quickSort(a, nLeft, i - 1); // 递归左边

	quickSort(a, i + 1, nRight); // 递归右边
}


////////////////////////////////////////////////////////
int main()
{
	printf("快速排序\n\n");
	// int a[] = { 8,2,6,12 ,1,9,5,5,10 };
	int a[] = { 3, 5, 6, 9, 3, 7 };

	int nSize = sizeof(a) / sizeof(int);
	quickSort(a, 0, nSize -1 ); // 排好序的结果

	for (int i = 0; i < nSize; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n\n");

	return 0;
}