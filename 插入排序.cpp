#include <stdio.h>
#include <iostream>

using namespace std;

void print(int a[], int n, int i)
{
	cout << i << ":";
	for (int j = 0; j < 8; j++)
	{
		cout << a[j] << " ";
	}
	cout << endl;
}


void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{	// ����i��Ԫ�ش���i-1Ԫ�أ�ֱ�Ӳ��롣С�ڵĻ����ƶ����������  
			int j = i - 1;
			int x = a[i];        // ����Ϊ�ڱ������洢������Ԫ��  
			a[i] = a[i - 1];           // �Ⱥ���һ��Ԫ��  
			while (x < a[j])
			{	// �����������Ĳ���λ��  
				a[j + 1] = a[j];
				j--;         // Ԫ�غ���  
			}
			a[j + 1] = x;      // ���뵽��ȷλ��  
		}
		print(a, n, i);           // ��ӡÿ������Ľ��  
	}

}

int main()
{
	int a[8] = { 3,1,5,7,2,4,9,6 };
	InsertSort(a, 8);
	print(a, 8, 8);
	return 0;
}