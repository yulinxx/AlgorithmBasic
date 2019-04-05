/* 1.txt ��������:
12
19 14 23 1 68 20 84 27 55 11 10 79
*/


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct keyNum* hash[100];

struct keyNum* insertHash(struct keyNum*, int);//�ؼ��ֲ�������

int searchHash(struct keyNum*, int m);//�����������Ƿ����ֵΪm������

void print(struct keyNum*);//��ӡ����



struct keyNum
{
	int key;//�ؼ���
	struct keyNum* next;
};


int main()
{
	printf("�ؼ����б�����2.txt�ļ��У����е�һ��ֵΪ�ؼ��ֵĸ���\n����ֵΪ����Ĺؼ��֣������ؼ���֮���ÿո����\n");
	int i, k, m, n, num, flag, l, j;
	FILE* p;
	struct keyNum* head = NULL;

	//�ؼ����б�����2.txt�ļ��У����е�һ��ֵΪ�ؼ��ֵĸ���
	//����ֵΪ����Ĺؼ��֣������ؼ���֮���ÿո����
	// 12
	//19 14 23 1 68 20 84 27 55 11 10 79
	p = fopen("1.txt", "r");
	if (p == NULL)
	{
		printf("cannot open file 2.txt");
		exit(0);
	}

	fscanf(p, "%d", &num);

	for (i = 0; i < num; i++)
	{
		hash[i] = NULL;
	}


	for (i = 0; i < num; i++)
	{
		fscanf(p, "%d", &k);  //��ȡ�ؼ���
		m = k % (num + 1);    //����õ��ؼ��ֵĹ�ϣֵ

		hash[m] = insertHash(hash[m], k);//���ؼ���k���뵽��ϣֵΪm��������
	}

	printf("-----------------------------------------------\n��ѡ��Ҫ���еĲ�����\n1����ӡ��������ַ���õ��Ĺ�ϣ��\n");
	printf("2�����йؼ��ֲ���\n3���˳�\n------------------------------------------------\n");
	scanf("%d", &flag);

	while ((flag == 1) || (flag == 2))
	{
		if (flag == 1)//��ӡ��ϣ��
		{
			printf("��������ַ���õ��Ĺ�ϣ��Ϊ��\n");
			for (i = 0; i < num + 1; i++)
			{
				printf("��%d�У�", i);
				print(hash[i]);
				printf("\n");
			}
		}
		else //����
		{
			printf("������Ҫ���ҵ�����ֵ��\n");
			scanf("%d", &n);
			for (i = 0; i < num + 1; i++)
			{
				l = searchHash(hash[i], n);
				if (l == 1)
				{
					j = i;
					break;
				}
			}
			if (l == 1)
				printf("����ֵ%d�ڹ�ϣ���У�λ��Ϊ����%d\n", n, j);
			else 
				printf("����ֵ%d���ڹ�ϣ���У�\n", n);
		}
		printf("-----------------------------------------------\n��ѡ��Ҫ���еĲ�����\n1����ӡ��������ַ���õ��Ĺ�ϣ��\n");
		printf("2�����йؼ��ֲ���\n3���˳�\n------------------------------------------------\n");
		scanf("%d", &flag);
	}
	return 0;
}


struct keyNum* insertHash(struct keyNum * head, int m)
{
	struct keyNum* p0 = nullptr, * p1 = nullptr, * p2 = nullptr, * temp = nullptr;
	temp = (struct keyNum*)malloc(sizeof(struct keyNum));
	temp->key = m;
	p1 = head;
	p0 = temp;//Ҫ����Ľڵ㣨ֵΪm);
	if (head == NULL)//1��ԭ��������Ϊ�գ����뵽head��
	{
		head = p0;
		p0->next = NULL;
	}
	else//ԭ��������Ϊ��
	{
		while ((p0->key > p1->key) && (p1->next != NULL))//�ƶ����ʵ�λ��
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->key <= p1->key)
		{
			if (head == p1)
				head = p0;	//2�����뵽��һ���ڵ�֮ǰ
			else 
				p2->next = p0;	//3,���뵽p2ָ��Ľڵ�֮��
			p0->next = p1;
		}
		else//4,���뵽��β��
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	return(head);
}


int searchHash(struct keyNum * head, int m)//��������head���Ƿ����m
{
	int k = 0;
	struct keyNum* p;
	p = head;
	if (head != NULL)
		do
		{
			if (p->key == m) //����m
			{
				k = 1;
				break;
			}
			p = p->next;
		} while (p != NULL);
		return(k);//����mֵ�򷵻�1�����򷵻�0��
}

void print(struct keyNum * head)//��ӡ����head
{
	struct keyNum* p;
	p = head;
	if (head != NULL)
	{
		do
		{
			printf(" -> %d ", p->key);
			p = p->next;
		} while (p != NULL);
	}
	else
		printf("null");
}

