
//堆排序（HeapSort）
//杨鑫 https://blog.csdn.net/u012965373/article/details/48290747

#include <stdio.h>
#include <stdlib.h>

//堆调整，构建大顶堆，arr[]是待调整的数组，i是待调整的数组
//元素的位置，length是数组的长度

void HeapAdjust(int arr[], int i, int length)
{
	int Child;
	int temp;
	for (; 2 * i + 1 < length; i = Child)
	{
		//子节点的位置 = 2 * (parent(父结点)) + 1
		Child = 2 * i + 1;

		//得到子结点中较大的结点
		if (Child < length - 1 && arr[Child + 1] > arr[Child])
		{
			++Child;
		}

		//如果较大的子结点大于父结点那么把较大的子结点往上移动
		//替换它的父结点

		if (arr[i] < arr[Child])
		{
			temp = arr[i];
			arr[i] = arr[Child];
			arr[Child] = temp;
		}
		else
		{
			break;
		}
	}
}

//堆排序算法
void HeapSort(int arr[], int length)
{
	int i;

	//调整序列的前半部分元素，调整完之后第一个元素
	//是序列的最大元素，length/2-1是最后一个非叶子结点

	for (i = length / 2 - 1; i >= 0; --i)
	{
		HeapAdjust(arr, i, length);
	}

	//从最后一个元素开始对序列进行调整，不断的缩小调整
	//的范围直到第一个元素
	//循环里是把第一个元素和当前的最后一个元素交换
	//保证当前的最后一个位置的元素是现在这个序列的最大的
	//不断的缩小调整heap的范围，每一次调整完毕保证第一个

	//元素是当前序列的最大的元素

	for (i = length - 1; i > 0; --i)
	{
		arr[i] = arr[0] ^ arr[i];
		arr[0] = arr[0] ^ arr[i];
		arr[i] = arr[0] ^ arr[i];

		HeapAdjust(arr, 0, i);						//递归调整
	}
}


////////////////////////////////////////////////////////
int main()
{
	printf("堆排序\n\n");
	
	int i;
	int num[] = { 98, 48, 777, 63, 57, 433, 23, 1112, 1 };

	printf("==================堆排序==============\n");
	printf("实质上是一颗完全二叉树，利用树的根结点\n与子节点的性质进行排序\n");
	printf("======================================\n\n");
	printf("待排序的数据是：\n");
	for (i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		printf("%d ", num[i]);
	}

	printf("\n");

	HeapSort(num, sizeof(num) / sizeof(int));

	printf("排序后的数据是：\n");

	for (i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}