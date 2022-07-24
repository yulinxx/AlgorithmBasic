
/*********************************************************************
*                          哈希表算法实现
*                       (c)copyright 2013,jdh
*                         All Right Reserved
*文件名:main.c
*程序员:jdh
**********************************************************************/

#include <stdio.h>  
#include <stdlib.h>  

/*********************************************************************
*                           宏定义
**********************************************************************/

/*********************************************************************
*                           数据类型重定义
**********************************************************************/

#define uint8_t unsigned char  
#define uint16_t unsigned short  
#define uint32_t unsigned long  

/*********************************************************************
*                           哈希表长度
**********************************************************************/

#define HASH_TABLE_LEN  100  

/*********************************************************************
*                           数据结构
**********************************************************************/
//链表节点  
typedef struct _Link_Node
{
	uint16_t id;
	uint16_t data;
	struct _Link_Node* next;
}Link_Node, * Link_Node_Ptr;

//哈希表头  
typedef struct _Hash_Header
{
	struct _Link_Node* next;
}Hash_Header, * Hash_Header_Ptr;

/*********************************************************************
*                           全局变量
**********************************************************************/

//哈希表  
Hash_Header_Ptr Hash_Table[HASH_TABLE_LEN];

/*********************************************************************
*                           函数
**********************************************************************/

/*********************************************************************
*                           哈希表函数
*说明:
*1.用哈希函数生成id对应的哈希表中的位置
输入:id
返回:位置
**********************************************************************/

uint8_t hash_func(uint16_t id)
{
	uint8_t pos = 0;

	pos = id % HASH_TABLE_LEN;

	return pos;
}

/*********************************************************************
*                           初始化节点
*返回:结点指针
**********************************************************************/

Link_Node_Ptr init_link_node(void)
{
	Link_Node_Ptr node;

	//申请节点  
	node = (Link_Node_Ptr)malloc(sizeof(Link_Node));
	//初始化长度为0  
	node->next = NULL;

	return node;
}

/*********************************************************************
*                           初始化哈希表头结点
*返回哈希表头结点指针
**********************************************************************/

Hash_Header_Ptr init_hash_header_node(void)
{
	Hash_Header_Ptr node;

	//申请节点  
	node = (Hash_Header_Ptr)malloc(sizeof(Hash_Header));
	//初始化长度为0  
	node->next = NULL;

	return node;
}


/*********************************************************************
*                           哈希表初始化
*说明:
*1.初始化哈希表Hash_Table
*2.哈希表长度最大不能超过256
**********************************************************************/

void init_hash_table(void)
{
	uint8_t i = 0;

	for (i = 0; i < HASH_TABLE_LEN; i++)
	{
		Hash_Table[i] = init_hash_header_node();
		Hash_Table[i]->next = NULL;
	}
}

/*********************************************************************
*                           在哈希表增加节点
*说明:
*1.在哈希表的某个链表末增加数据
输入:new_node:新节点
**********************************************************************/

void append_link_node(Link_Node_Ptr new_node)
{
	Link_Node_Ptr node;
	uint8_t pos = 0;

	//新节点下一个指向为空  
	new_node->next = NULL;

	//用哈希函数获得位置  
	pos = hash_func(new_node->id);

	//判断是否为空链表  
	if (Hash_Table[pos]->next == NULL)
	{
		//空链表  
		Hash_Table[pos]->next = new_node;
	}
	else
	{
		//不是空链表  
		//获取根节点  
		node = Hash_Table[pos]->next;

		//遍历  
		while (node->next != NULL)
		{
			node = node->next;
		}

		//插入  
		node->next = new_node;
	}
}

/*********************************************************************
*                           在哈希表查询节点
*说明:
*1.知道在哈希表某处的单链表中,并开始遍历.
*2.返回的是查询节点的前一个节点指针.这么做是为了做删除操作.
输入:pos:哈希表数组位置,从0开始计数
	 id:所需要查询节点的id
	 root:如果是根节点,则*root = 1,否则为0
返回:所需查询的节点的前一个节点指针,如果是根节点则返回根节点,失败返回0
**********************************************************************/

Link_Node_Ptr search_link_node(uint16_t id, uint8_t* root)
{
	Link_Node_Ptr node;
	uint8_t pos = 0;

	//用哈希函数获得位置  
	pos = hash_func(id);

	//获取根节点  
	node = Hash_Table[pos]->next;

	//判断单链表是否存在  
	if (node == NULL)
	{
		return 0;
	}

	//判断是否是根节点  
	if (node->id == id)
	{
		//是根节点  
		*root = 1;
		return node;
	}
	else
	{
		//不是根节点  
		*root = 0;
		//遍历  
		while (node->next != NULL)
		{
			if (node->next->id == id)
			{
				return node;
			}
			else
			{
				node = node->next;
			}
		}

		return 0;
	}
}

/*********************************************************************
*                           在哈希表删除节点
*说明:
*1.删除的不是当前节点,而是当前节点后的一个节点
输入:node:删除此节点后面的一个节点
	 new_node:新节点
**********************************************************************/

void delete_link_node(Link_Node_Ptr node)
{
	Link_Node_Ptr delete_node;

	//重定向需要删除的前一个节点  
	delete_node = node->next;
	node->next = delete_node->next;

	//删除节点  
	free(delete_node);
	delete_node = NULL;
}

/*********************************************************************
*                           在哈希表删除根节点
输入:node:根节点
**********************************************************************/

void delete_link_root_node(Link_Node_Ptr node)
{
	uint8_t pos = 0;

	//用哈希函数获得位置  
	pos = hash_func(node->id);

	//哈希表头清空  
	if (node != NULL)
	{
		Hash_Table[pos]->next = node->next;
		//删除节点  
		free(node);
		node = NULL;
	}
}

/*********************************************************************
*                           获得哈希表中所有节点数
输入:node:根节点
**********************************************************************/

uint16_t get_node_num(void)
{
	Link_Node_Ptr node;
	uint16_t i = 0;
	uint16_t num = 0;

	//遍历  
	for (i = 0; i < HASH_TABLE_LEN; i++)
	{
		//获取根节点  
		node = Hash_Table[i]->next;
		//遍历  
		while (node != NULL)
		{
			num++;
			node = node->next;
		}
	}

	return num;
}

/*********************************************************************
*                           从哈希表中获得对应序号的节点
*参数:index:序号.从1开始,最大值为节点总数值
*     root:如果是根节点,则*root = 1,否则为0
返回:所需查询的节点的前一个节点指针,如果是根节点则返回根节点,失败返回0
**********************************************************************/

Link_Node_Ptr get_node_from_index(uint16_t index, uint8_t* root)
{
	Link_Node_Ptr node;
	uint16_t i = 0;
	uint16_t num = 0;

	//遍历  
	for (i = 0; i < HASH_TABLE_LEN; i++)
	{
		//获取根节点  
		node = Hash_Table[i]->next;
		//判断单链表是否存在  
		if (node == NULL)
		{
			continue;
		}

		//根节点  
		num++;
		if (num == index)
		{
			//是根节点  
			*root = 1;
			return node;
		}

		//遍历  
		while (node->next != NULL)
		{
			num++;
			if (num == index)
			{
				//不是根节点  
				*root = 0;
				return node;
			}
			node = node->next;
		}
	}

	return 0;
}

/*********************************************************************
*                           删除hash表中所有节点
**********************************************************************/

void drop_hash()
{
	Link_Node_Ptr node;
	uint16_t i = 0;
	Link_Node_Ptr node_next;

	//遍历  
	for (i = 0; i < HASH_TABLE_LEN; i++)
	{
		//获取根节点  
		node = Hash_Table[i]->next;

		while (1)
		{
			//判断单链表是否存在  
			if (node == NULL)
			{
				//不存在  
				Hash_Table[i]->next = NULL;
				break;
			}

			//根节点下一个节点  
			node_next = node->next;
			//删除根节点  
			free(node);
			//重指定根节点  
			node = node_next;
		}
	}
}

/*********************************************************************
*                           输出所有节点
**********************************************************************/

void printf_hash()
{
	Link_Node_Ptr node;
	uint8_t root = 0;
	uint8_t i = 0;
	uint8_t num = 0;

	printf("-------------打印hash表-------------\n");

	num = get_node_num();
	for (i = 1; i <= num; i++)
	{
		node = get_node_from_index(i, &root);
		if (node != 0)
		{
			if (root)
			{
				printf("根节点:节点号%d,id为%d\n", i, node->id);
			}
			else
			{
				printf("普通节点:节点号%d,id为%d\n", i, node->next->id);
			}
		}
	}
}


/*********************************************************************
*                           主函数
*说明:实现对哈希表的新建,建立节点,查询及增加,删除节点的操作
**********************************************************************/

int main()
{
	printf("哈希表排序\n\n");
	
	Link_Node_Ptr node;
	uint8_t temp = 0;
	uint8_t root = 0;
	uint8_t i = 0;

	init_hash_table();

	//插入数据id = 1,data = 2;  
	node = init_link_node();
	node->id = 1;
	node->data = 2;
	append_link_node(node);

	//查询节点数  
	printf("1节点数为%d\n", get_node_num());

	node = init_link_node();
	node->id = 100;
	node->data = 101;
	append_link_node(node);

	node = init_link_node();
	node->id = 1002;
	node->data = 1001;
	append_link_node(node);

	node = init_link_node();
	node->id = 10000;
	node->data = 10001;
	append_link_node(node);

	node = init_link_node();
	node->id = 1000;
	node->data = 10001;
	append_link_node(node);

	node = init_link_node();
	node->id = 2;
	node->data = 10001;
	append_link_node(node);

	//查询节点数  
	printf("2节点数为%d\n", get_node_num());

	//查询id = 1000;  
	node = search_link_node(100, &temp);
	if (node != 0)
	{
		if (temp == 0)
		{
			printf("删除普通节点:所需查询id的值为%d,数据为%d\n", node->next->id, node->next->data);

			//删除  
			delete_link_node(node);
		}
		else
		{
			//根节点  
			printf("删除根节点所需查询id的值为%d,数据为%d\n", node->id, node->data);

			//删除  
			delete_link_root_node(node);
		}
	}
	else
	{
		printf("查询失败\n");
	}

	//查询id = 1000;  
	node = search_link_node(1001, &temp);
	if (node != 0)
	{
		if (temp == 0)
		{
			printf("所需查询id的值为%d\n", node->next->data);
		}
		else
		{
			//根节点  
			printf("所需查询id的值为%d\n", node->data);
		}
	}
	else
	{
		printf("查询失败\n");
	}

	//查询节点数  
	printf("节点数为%d\n", get_node_num());

	printf_hash();


	getchar();
	return 0;
}