//Ͱ���� / ��������(Radix Sort)

//Ͱ������һ��Ч�ʺܸߵ������㷨������ʱ�临�Ӷ�ΪO(N + M)��(N��Ԫ�أ���ΧΪ0--M)��
//��Ͱ������һ�������ƣ�����Ϊ�Ǹ�����������Ԫ�ز��˹���
//
//�㷨˼�룺
//
//����������е�Ԫ��ȡֵ��ΧΪ0��m���������½�һ����СΪm + 1����ʱ���鲢�ѳ�ʼֵ����Ϊ0���������������У�
//�Ѵ�����������Ԫ�ص�ֵ��Ϊ��ʱ������±꣬�ҳ���ʱ�����ж�Ӧ���±��Ԫ��ʹ֮ + 1��
//Ȼ�������ʱ���飬����ʱ������Ԫ�ش���0���±���Ϊֵ����������������������飬
//Ԫ�ص�ֵ��Ϊ�ظ�������±�Ĵ�����������������������������


#include<stdio.h>
#include<malloc.h>


void BucketSort(int intArray[], int Count_intArray, int max)
{
	//����������intArray��Ԫ�ض��ǷǸ�����
	//�����������intArray��Ԫ����Count_intArray��
	//��ȡֵ��ΧΪ0��max���������½�һ����СΪmax+1����ʱ���鲢�ѳ�ʼֵ����Ϊ0
	//�˴��ǿ���max+1������max����Ϊ�����909,...0��������1000��������Ҫ����999+1���ȵ�����
	int* TmpArray = (int*)malloc(sizeof(int) * (max + 1)); //����һ�������飬������鼴ΪͰ��

	for (int* p = TmpArray; p < TmpArray + max + 1; p++)  *p = 0; //��ʼ��Ͱ����Ͱ�е�ÿ��Ԫ��Ϊ0��

	for (int* p = intArray; p < intArray + Count_intArray; p++) TmpArray[*p] += 1; //��TmpArray�±��е���intArray[i]��Ԫ��+1

	int InsertIndex = 0; //ָ��intArray��ָ��

	for (int j = 0; j < max + 1; j++)
	{
		for (int k = 1; k <= TmpArray[j]; k++)//��Ҫ�����Ԫ�صĸ�������>1
			intArray[InsertIndex++] = j;
	}

	free(TmpArray);
}


int main()
{
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