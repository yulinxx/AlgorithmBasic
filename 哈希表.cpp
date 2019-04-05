/* 1.txt 内容如下:
12
19 14 23 1 68 20 84 27 55 11 10 79
*/


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct keyNum* hash[100];

struct keyNum* insertHash(struct keyNum*, int);//关键字插入链表

int searchHash(struct keyNum*, int m);//查找链表中是否存在值为m的整数

void print(struct keyNum*);//打印链表



struct keyNum
{
	int key;//关键字
	struct keyNum* next;
};


int main()
{
	printf("关键字列表保存在2.txt文件中，其中第一个值为关键字的个数\n其他值为具体的关键字，各个关键字之间用空格隔开\n");
	int i, k, m, n, num, flag, l, j;
	FILE* p;
	struct keyNum* head = NULL;

	//关键字列表保存在2.txt文件中，其中第一个值为关键字的个数
	//其他值为具体的关键字，各个关键字之间用空格隔开
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
		fscanf(p, "%d", &k);  //获取关键字
		m = k % (num + 1);    //计算得到关键字的哈希值

		hash[m] = insertHash(hash[m], k);//将关键字k插入到哈希值为m的链表中
	}

	printf("-----------------------------------------------\n请选择要进行的操作：\n1、打印采用链地址法得到的哈希表\n");
	printf("2、进行关键字查找\n3、退出\n------------------------------------------------\n");
	scanf("%d", &flag);

	while ((flag == 1) || (flag == 2))
	{
		if (flag == 1)//打印哈希表
		{
			printf("采用链地址法得到的哈希表为：\n");
			for (i = 0; i < num + 1; i++)
			{
				printf("第%d行：", i);
				print(hash[i]);
				printf("\n");
			}
		}
		else //查找
		{
			printf("请输入要查找的整数值：\n");
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
				printf("整数值%d在哈希表中，位置为链表%d\n", n, j);
			else 
				printf("整数值%d不在哈希表中！\n", n);
		}
		printf("-----------------------------------------------\n请选择要进行的操作：\n1、打印采用链地址法得到的哈希表\n");
		printf("2、进行关键字查找\n3、退出\n------------------------------------------------\n");
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
	p0 = temp;//要插入的节点（值为m);
	if (head == NULL)//1，原来的链表为空，插入到head后
	{
		head = p0;
		p0->next = NULL;
	}
	else//原来的链表不为空
	{
		while ((p0->key > p1->key) && (p1->next != NULL))//移动到适当位置
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->key <= p1->key)
		{
			if (head == p1)
				head = p0;	//2，插入到第一个节点之前
			else 
				p2->next = p0;	//3,插入到p2指向的节点之后
			p0->next = p1;
		}
		else//4,插入到结尾处
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	return(head);
}


int searchHash(struct keyNum * head, int m)//查找链表head中是否存在m
{
	int k = 0;
	struct keyNum* p;
	p = head;
	if (head != NULL)
		do
		{
			if (p->key == m) //存在m
			{
				k = 1;
				break;
			}
			p = p->next;
		} while (p != NULL);
		return(k);//存在m值则返回1，否则返回0；
}

void print(struct keyNum * head)//打印链表head
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

