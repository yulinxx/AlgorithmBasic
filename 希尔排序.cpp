/**
 * ϣ������C ����
 *
 * @author skywang
 * @date 2014/03/11
 */

//��������ϣ������Shell`s Sort��
// ϣ��������1959 ����D.L.Shell ������ģ����ֱ�������нϴ�ĸĽ���ϣ�������ֽ���С��������

//����˼�룺
// �Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ�������
// �����������еļ�¼����������ʱ���ٶ�ȫ���¼��������ֱ�Ӳ�������

#include <stdio.h>

 // ���鳤��
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

/*
 * ϣ������
 *
 * ����˵����
 *     a -- �����������
 *     n -- ����ĳ���
 */
 //int a[] = {80,30,60,40,20,10,50,70};
 //int ilen = LENGTH(a);
void shell_sort1(int a[], int n)
{
	int i, j, gap;

	// gapΪ������ÿ�μ�Ϊԭ����һ�롣
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		// ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < n; j += gap)
			{
				// ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
				if (a[j] < a[j - gap])
				{
					int tmp = a[j];
					int k = j - gap;
					while (k >= 0 && a[k] > tmp)
					{
						a[k + gap] = a[k];
						k -= gap;
					}
					a[k + gap] = tmp;
				}
			}
		}

	}
}

/*
 * ��ϣ�������еĵ������������
 *
 * ����˵����
 *     a -- �����������
 *     n -- �����ܵĳ���
 *     i -- �����ʼλ��
 *     gap -- ��Ĳ���
 *
 *  ����"��i��ʼ�������gap���ȵ�����ȡ��"����ɵģ�
 */
void group_sort(int a[], int n, int i, int gap)
{
	int j;

	for (j = i + gap; j < n; j += gap)
	{
		// ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
		if (a[j] < a[j - gap])
		{
			int tmp = a[j];
			int k = j - gap;
			while (k >= 0 && a[k] > tmp)
			{
				a[k + gap] = a[k];
				k -= gap;
			}
			a[k + gap] = tmp;
		}
	}
}

/*
 * ϣ������
 *
 * ����˵����
 *     a -- �����������
 *     n -- ����ĳ���
 */
void shell_sort2(int a[], int n)
{
	int i, gap;

	// gapΪ������ÿ�μ�Ϊԭ����һ�롣
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		// ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
		for (i = 0; i < gap; i++)
		{
			group_sort(a, n, i, gap);
		}
	}
}


int main()
{
	int i;
	int a[] = { 80,30,60,40,20,10,50,70 };
	int ilen = LENGTH(a);

	printf("before sort:");
	for (i = 0; i < ilen; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	shell_sort1(a, ilen);
	//shell_sort2(a, ilen);

	printf("after  sort:");
	for (i = 0; i < ilen; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}