
//������HeapSort��
//���� https://blog.csdn.net/u012965373/article/details/48290747

#include <stdio.h>
#include <stdlib.h>

//�ѵ����������󶥶ѣ�arr[]�Ǵ����������飬i�Ǵ�����������
//Ԫ�ص�λ�ã�length������ĳ���

void HeapAdjust(int arr[], int i, int length)
{
	int Child;
	int temp;
	for (; 2 * i + 1 < length; i = Child)
	{
		//�ӽڵ��λ�� = 2 * (parent(�����)) + 1
		Child = 2 * i + 1;

		//�õ��ӽ���нϴ�Ľ��
		if (Child < length - 1 && arr[Child + 1] > arr[Child])
		{
			++Child;
		}

		//����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ�
		//�滻���ĸ����

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

//�������㷨
void HeapSort(int arr[], int length)
{
	int i;

	//�������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ��
	//�����е����Ԫ�أ�length/2-1�����һ����Ҷ�ӽ��

	for (i = length / 2 - 1; i >= 0; --i)
	{
		HeapAdjust(arr, i, length);
	}

	//�����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С����
	//�ķ�Χֱ����һ��Ԫ��
	//ѭ�����ǰѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ���
	//��֤��ǰ�����һ��λ�õ�Ԫ��������������е�����
	//���ϵ���С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��

	//Ԫ���ǵ�ǰ���е�����Ԫ��

	for (i = length - 1; i > 0; --i)
	{
		arr[i] = arr[0] ^ arr[i];
		arr[0] = arr[0] ^ arr[i];
		arr[i] = arr[0] ^ arr[i];

		HeapAdjust(arr, 0, i);						//�ݹ����
	}
}



int main()
{

	int i;
	int num[] = { 98, 48, 777, 63, 57, 433, 23, 1112, 1 };

	printf("==================������==============\n");
	printf("ʵ������һ����ȫ���������������ĸ����\n���ӽڵ�����ʽ�������\n");
	printf("======================================\n\n");
	printf("������������ǣ�\n");
	for (i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		printf("%d ", num[i]);
	}

	printf("\n");

	HeapSort(num, sizeof(num) / sizeof(int));

	printf("�����������ǣ�\n");

	for (i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}