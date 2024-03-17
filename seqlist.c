#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct Table
{
	int* head;//��̬����
	int length;//�Ѵ��볤��
	int size;//�ܹ����볤��
}table;
#define Size 10
table initTable() //�����������ֵ�ǡ�table���е���������,�����ܴ���
{
	table t;
	t.head = (int*)malloc(Size * sizeof(int));//����̬����head����ռ�
	if (!t.head)
	{
		printf("��ʼ��ʧ��");
		exit(0);
	}
	else
	{
		t.length = 0;//��ʼ��
		t.size = Size;//10
		printf("�����ɹ�");
		printf("\n");
	}
	return t;//���ص��ǽṹ�����t,��t���������ͣ�����head, length, size
}
void displayTable(table t)
{
	int i;
	for (i = 0; i < t.length; i++)
	{
		printf("%d ", t.head[i]);
	}
	printf("\n");
}
table delTable(table t)
{
	printf("������Ҫɾ���������:");
	int n;
	scanf("%d", &n);
	n--;//��Ϊ�±�
	//�ж�λ�úϷ���
	if (n < 0 || n >= t.length)
	{
		printf("λ�÷Ƿ�");
		exit(0);
	}
	int i;
	for (i = n; i < t.length; i++)
	{
		t.head[i] = t.head[i + 1];
	}
	t.length--;
	printf("ɾ����\n");

	return t;
}
table addTable(table t)
{
	int n;
	printf("��Ҫ�����ڼ���λ�ã�");
	scanf("%d", &n);
	n--;//���
	if (n < 0 || n >= t.length)
	{
		printf("λ�÷Ƿ�");
		exit(0);
	}
	if (t.length == t.size)
	{
		printf("˳���ռ䲻��");
		exit(0);
	}
	int e;
	printf("��Ҫ���룺");
	scanf("%d", &e);
	int i;
	for (i = t.length; i >= n; i--)
	{
		t.head[i + 1] = t.head[i];
	}
	t.head[n] = e;
	t.length++;
	printf("�����\n");
	return t;
}
void selectTable(table t)
{
	int e;
	printf("��Ҫ���ң�");
	scanf("%d", &e);
	int i;
	for (i = 0; i < t.length; i++)
	{
		if (e == t.head[i])
		{
			printf("���ҵ���λ�ã�%d\n", i + 1);
			break;
		}
	}
	if (i == t.length)
	{
		printf("�Ҳ���");
	}
}
table amendTable(table t)
{
	int n;
	printf("�޸���һ����");
	scanf("%d", &n);
	n--;
	if (n < 0 || n >= t.length)
	{
		printf("λ�÷Ƿ�");
		exit(0);
	}
	printf("��%d��Ϊ��", t.head[n]);
	int e;
	scanf("%d", &e);
	t.head[n] = e;
	printf("�޸ĺ�\n");
	return t;
}
int main()
{
	//��������ʼ��˳���
	table t = initTable();
	int i;
	//��˳���д��1��2��3��4��5
	for (i = 1; i <= 5; i++)
	{
		t.head[i - 1] = i;//�±�0��1
		t.length++;
	}
	printf("ԭ˳���\n");
	displayTable(t);
	//ɾ������
	t = delTable(t);
	displayTable(t);
	//��������
	t = addTable(t);
	displayTable(t);
	//��������
	selectTable(t);
	//�޸�����
	t = amendTable(t);
	displayTable(t);
	return 0;
}