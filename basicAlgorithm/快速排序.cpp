
// 交换排序—快速排序（Quick Sort）

//快速排序的基本思想是
//1、先从数列中取出一个数作为基准数
//2、分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边
//3、再对左右区间重复第二步，直到各区间只有一个数
//
#include<stdio.h>

void quickSort(int a[], int nLeft, int nRight)
{
	int i = nLeft;
	int j = nRight;
	int temp = a[nLeft];

	if (nLeft >= nRight)
	{
		return;
	}

	while (i != j)
	{
		while (i < j && a[j] >= temp)
		{
			j--;
		}

		if (j > i)
		{
			a[i] = a[j];//a[i]已经赋值给temp,所以直接将a[j]赋值给a[i],赋值完之后a[j],有空位
		}

		while (i < j && a[i] <= temp)
		{
			i++;
		}

		if (i < j)
		{
			a[j] = a[i];
		}
	}

	a[i] = temp;//把基准插入,此时i与j已经相等R[low..pivotpos-1].keys≤R[pivotpos].key≤R[pivotpos+1..high].keys
	quickSort(a, nLeft, i - 1);/*递归左边*/
	quickSort(a, i + 1, nRight);/*递归右边*/
}

int main()
{
	int a[9] = { 8,2,6,12,1,9,5,5,10 };

	int i;

	quickSort(a, 0, 8);/*排好序的结果*/

	for (i = 0; i < 8; i++)
	{
		printf("%4d", a[i]);
	}

	getchar();
	return 0;
}