
/*********************************************************************
*                          ��ϣ���㷨ʵ��
*                       (c)copyright 2013,jdh
*                         All Right Reserved
*�ļ���:main.c
*����Ա:jdh
**********************************************************************/

#include <stdio.h>  
#include <stdlib.h>  

/*********************************************************************
*                           �궨��
**********************************************************************/

/*********************************************************************
*                           ���������ض���
**********************************************************************/

#define uint8_t unsigned char  
#define uint16_t unsigned short  
#define uint32_t unsigned long  

/*********************************************************************
*                           ��ϣ����
**********************************************************************/

#define HASH_TABLE_LEN  100  

/*********************************************************************
*                           ���ݽṹ
**********************************************************************/
//����ڵ�  
typedef struct _Link_Node
{
	uint16_t id;
	uint16_t data;
	struct _Link_Node* next;
}Link_Node, * Link_Node_Ptr;

//��ϣ��ͷ  
typedef struct _Hash_Header
{
	struct _Link_Node* next;
}Hash_Header, * Hash_Header_Ptr;

/*********************************************************************
*                           ȫ�ֱ���
**********************************************************************/

//��ϣ��  
Hash_Header_Ptr Hash_Table[HASH_TABLE_LEN];

/*********************************************************************
*                           ����
**********************************************************************/

/*********************************************************************
*                           ��ϣ����
*˵��:
*1.�ù�ϣ��������id��Ӧ�Ĺ�ϣ���е�λ��
����:id
����:λ��
**********************************************************************/

uint8_t hash_func(uint16_t id)
{
	uint8_t pos = 0;

	pos = id % HASH_TABLE_LEN;

	return pos;
}

/*********************************************************************
*                           ��ʼ���ڵ�
*����:���ָ��
**********************************************************************/

Link_Node_Ptr init_link_node(void)
{
	Link_Node_Ptr node;

	//����ڵ�  
	node = (Link_Node_Ptr)malloc(sizeof(Link_Node));
	//��ʼ������Ϊ0  
	node->next = NULL;

	return node;
}

/*********************************************************************
*                           ��ʼ����ϣ��ͷ���
*���ع�ϣ��ͷ���ָ��
**********************************************************************/

Hash_Header_Ptr init_hash_header_node(void)
{
	Hash_Header_Ptr node;

	//����ڵ�  
	node = (Hash_Header_Ptr)malloc(sizeof(Hash_Header));
	//��ʼ������Ϊ0  
	node->next = NULL;

	return node;
}


/*********************************************************************
*                           ��ϣ���ʼ��
*˵��:
*1.��ʼ����ϣ��Hash_Table
*2.��ϣ��������ܳ���256
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
*                           �ڹ�ϣ�����ӽڵ�
*˵��:
*1.�ڹ�ϣ���ĳ������ĩ��������
����:new_node:�½ڵ�
**********************************************************************/

void append_link_node(Link_Node_Ptr new_node)
{
	Link_Node_Ptr node;
	uint8_t pos = 0;

	//�½ڵ���һ��ָ��Ϊ��  
	new_node->next = NULL;

	//�ù�ϣ�������λ��  
	pos = hash_func(new_node->id);

	//�ж��Ƿ�Ϊ������  
	if (Hash_Table[pos]->next == NULL)
	{
		//������  
		Hash_Table[pos]->next = new_node;
	}
	else
	{
		//���ǿ�����  
		//��ȡ���ڵ�  
		node = Hash_Table[pos]->next;

		//����  
		while (node->next != NULL)
		{
			node = node->next;
		}

		//����  
		node->next = new_node;
	}
}

/*********************************************************************
*                           �ڹ�ϣ���ѯ�ڵ�
*˵��:
*1.֪���ڹ�ϣ��ĳ���ĵ�������,����ʼ����.
*2.���ص��ǲ�ѯ�ڵ��ǰһ���ڵ�ָ��.��ô����Ϊ����ɾ������.
����:pos:��ϣ������λ��,��0��ʼ����
	 id:����Ҫ��ѯ�ڵ��id
	 root:����Ǹ��ڵ�,��*root = 1,����Ϊ0
����:�����ѯ�Ľڵ��ǰһ���ڵ�ָ��,����Ǹ��ڵ��򷵻ظ��ڵ�,ʧ�ܷ���0
**********************************************************************/

Link_Node_Ptr search_link_node(uint16_t id, uint8_t* root)
{
	Link_Node_Ptr node;
	uint8_t pos = 0;

	//�ù�ϣ�������λ��  
	pos = hash_func(id);

	//��ȡ���ڵ�  
	node = Hash_Table[pos]->next;

	//�жϵ������Ƿ����  
	if (node == NULL)
	{
		return 0;
	}

	//�ж��Ƿ��Ǹ��ڵ�  
	if (node->id == id)
	{
		//�Ǹ��ڵ�  
		*root = 1;
		return node;
	}
	else
	{
		//���Ǹ��ڵ�  
		*root = 0;
		//����  
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
*                           �ڹ�ϣ��ɾ���ڵ�
*˵��:
*1.ɾ���Ĳ��ǵ�ǰ�ڵ�,���ǵ�ǰ�ڵ���һ���ڵ�
����:node:ɾ���˽ڵ�����һ���ڵ�
	 new_node:�½ڵ�
**********************************************************************/

void delete_link_node(Link_Node_Ptr node)
{
	Link_Node_Ptr delete_node;

	//�ض�����Ҫɾ����ǰһ���ڵ�  
	delete_node = node->next;
	node->next = delete_node->next;

	//ɾ���ڵ�  
	free(delete_node);
	delete_node = NULL;
}

/*********************************************************************
*                           �ڹ�ϣ��ɾ�����ڵ�
����:node:���ڵ�
**********************************************************************/

void delete_link_root_node(Link_Node_Ptr node)
{
	uint8_t pos = 0;

	//�ù�ϣ�������λ��  
	pos = hash_func(node->id);

	//��ϣ��ͷ���  
	if (node != NULL)
	{
		Hash_Table[pos]->next = node->next;
		//ɾ���ڵ�  
		free(node);
		node = NULL;
	}
}

/*********************************************************************
*                           ��ù�ϣ�������нڵ���
����:node:���ڵ�
**********************************************************************/

uint16_t get_node_num(void)
{
	Link_Node_Ptr node;
	uint16_t i = 0;
	uint16_t num = 0;

	//����  
	for (i = 0; i < HASH_TABLE_LEN; i++)
	{
		//��ȡ���ڵ�  
		node = Hash_Table[i]->next;
		//����  
		while (node != NULL)
		{
			num++;
			node = node->next;
		}
	}

	return num;
}

/*********************************************************************
*                           �ӹ�ϣ���л�ö�Ӧ��ŵĽڵ�
*����:index:���.��1��ʼ,���ֵΪ�ڵ�����ֵ
*     root:����Ǹ��ڵ�,��*root = 1,����Ϊ0
����:�����ѯ�Ľڵ��ǰһ���ڵ�ָ��,����Ǹ��ڵ��򷵻ظ��ڵ�,ʧ�ܷ���0
**********************************************************************/

Link_Node_Ptr get_node_from_index(uint16_t index, uint8_t* root)
{
	Link_Node_Ptr node;
	uint16_t i = 0;
	uint16_t num = 0;

	//����  
	for (i = 0; i < HASH_TABLE_LEN; i++)
	{
		//��ȡ���ڵ�  
		node = Hash_Table[i]->next;
		//�жϵ������Ƿ����  
		if (node == NULL)
		{
			continue;
		}

		//���ڵ�  
		num++;
		if (num == index)
		{
			//�Ǹ��ڵ�  
			*root = 1;
			return node;
		}

		//����  
		while (node->next != NULL)
		{
			num++;
			if (num == index)
			{
				//���Ǹ��ڵ�  
				*root = 0;
				return node;
			}
			node = node->next;
		}
	}

	return 0;
}

/*********************************************************************
*                           ɾ��hash�������нڵ�
**********************************************************************/

void drop_hash()
{
	Link_Node_Ptr node;
	uint16_t i = 0;
	Link_Node_Ptr node_next;

	//����  
	for (i = 0; i < HASH_TABLE_LEN; i++)
	{
		//��ȡ���ڵ�  
		node = Hash_Table[i]->next;

		while (1)
		{
			//�жϵ������Ƿ����  
			if (node == NULL)
			{
				//������  
				Hash_Table[i]->next = NULL;
				break;
			}

			//���ڵ���һ���ڵ�  
			node_next = node->next;
			//ɾ�����ڵ�  
			free(node);
			//��ָ�����ڵ�  
			node = node_next;
		}
	}
}

/*********************************************************************
*                           ������нڵ�
**********************************************************************/

void printf_hash()
{
	Link_Node_Ptr node;
	uint8_t root = 0;
	uint8_t i = 0;
	uint8_t num = 0;

	printf("-------------��ӡhash��-------------\n");

	num = get_node_num();
	for (i = 1; i <= num; i++)
	{
		node = get_node_from_index(i, &root);
		if (node != 0)
		{
			if (root)
			{
				printf("���ڵ�:�ڵ��%d,idΪ%d\n", i, node->id);
			}
			else
			{
				printf("��ͨ�ڵ�:�ڵ��%d,idΪ%d\n", i, node->next->id);
			}
		}
	}
}

/*********************************************************************
*                           ������
*˵��:ʵ�ֶԹ�ϣ����½�,�����ڵ�,��ѯ������,ɾ���ڵ�Ĳ���
**********************************************************************/

int main()
{
	Link_Node_Ptr node;
	uint8_t temp = 0;
	uint8_t root = 0;
	uint8_t i = 0;

	init_hash_table();

	//��������id = 1,data = 2;  
	node = init_link_node();
	node->id = 1;
	node->data = 2;
	append_link_node(node);

	//��ѯ�ڵ���  
	printf("1�ڵ���Ϊ%d\n", get_node_num());

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

	//��ѯ�ڵ���  
	printf("2�ڵ���Ϊ%d\n", get_node_num());

	//��ѯid = 1000;  
	node = search_link_node(100, &temp);
	if (node != 0)
	{
		if (temp == 0)
		{
			printf("ɾ����ͨ�ڵ�:�����ѯid��ֵΪ%d,����Ϊ%d\n", node->next->id, node->next->data);

			//ɾ��  
			delete_link_node(node);
		}
		else
		{
			//���ڵ�  
			printf("ɾ�����ڵ������ѯid��ֵΪ%d,����Ϊ%d\n", node->id, node->data);

			//ɾ��  
			delete_link_root_node(node);
		}
	}
	else
	{
		printf("��ѯʧ��\n");
	}

	//��ѯid = 1000;  
	node = search_link_node(1001, &temp);
	if (node != 0)
	{
		if (temp == 0)
		{
			printf("�����ѯid��ֵΪ%d\n", node->next->data);
		}
		else
		{
			//���ڵ�  
			printf("�����ѯid��ֵΪ%d\n", node->data);
		}
	}
	else
	{
		printf("��ѯʧ��\n");
	}

	//��ѯ�ڵ���  
	printf("�ڵ���Ϊ%d\n", get_node_num());

	printf_hash();


	getchar();
	return 0;
}