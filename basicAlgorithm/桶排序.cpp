/*
 * @Author: xx xx@ubuntu.com
 * @Date: 2022-07-24 22:50:20
 * @LastEditors: xx xx@ubuntu.com
 * @LastEditTime: 2022-07-24 23:09:41
 * @FilePath: /AlgorithmBasic/basicAlgorithm/桶排序.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//桶排序 / 基数排序(Radix Sort)

//桶排序是一种效率很高的排序算法，它的时间复杂度为O(N + M)，(N个元素，范围为0--M)，
//但桶排序有一定的限制，必须为非负整数，而且元素不宜过大。
//
//算法思想：
//
//设待排序序列的元素取值范围为0到m，则我们新建一个大小为m + 1的临时数组并把初始值都设为0，遍历待排序序列，
//把待排序序列中元素的值作为临时数组的下标，找出临时数组中对应该下标的元素使之 + 1；
//然后遍历临时数组，把临时数组中元素大于0的下标作为值按次序依次填入待排序数组，
//元素的值作为重复填入该下标的次数，遍历完成则排序结束序列有序。


#include<stdio.h>
#include<malloc.h>


void BucketSort(int intArray[], int Count_intArray, int max)
{
	//待排序序列intArray的元素都是非负整数
	//设待排序序列intArray的元素有Count_intArray个
	//其取值范围为0到max，则我们新建一个大小为max+1的临时数组并把初始值都设为0
	//此处是开辟max+1而不是max，因为比如给909,...0排序，是有1000个数，需要开辟999+1长度的数组
	int* TmpArray = (int*)malloc(sizeof(int) * (max + 1)); //开辟一个新数组，这个数组即为桶；

	for (int* p = TmpArray; p < TmpArray + max + 1; p++)  *p = 0; //初始化桶，是桶中的每个元素为0；

	for (int* p = intArray; p < intArray + Count_intArray; p++) TmpArray[*p] += 1; //将TmpArray下标中等于intArray[i]的元素+1

	int InsertIndex = 0; //指向intArray的指标

	for (int j = 0; j < max + 1; j++)
	{
		for (int k = 1; k <= TmpArray[j]; k++)//需要插入的元素的个数必须>1
			intArray[InsertIndex++] = j;
	}

	free(TmpArray);
}


////////////////////////////////////////////////////////
int main()
{
	printf("桶排序\n\n");
	
	//void BucketSort(int intArray[], int Count_intArray, int max);

	int intArray[10] = { 999,55,10,1,0,1,87,45,55,4 };
	int Count_intArray = 10;
	int max = 999;

	BucketSort(intArray, Count_intArray, max);

	for (int i = 0; i < 10; i++)
		printf("%d ", intArray[i]);

	printf("\n");
	return 0;
}