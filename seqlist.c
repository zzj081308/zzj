#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct Table
{
	int* head;//动态数组
	int length;//已存入长度
	int size;//总共申请长度
}table;
#define Size 10
table initTable() //这个函数返回值是“table”中的所有类型,不接受传参
{
	table t;
	t.head = (int*)malloc(Size * sizeof(int));//给动态数组head申请空间
	if (!t.head)
	{
		printf("初始化失败");
		exit(0);
	}
	else
	{
		t.length = 0;//初始化
		t.size = Size;//10
		printf("创建成功");
		printf("\n");
	}
	return t;//返回的是结构体变量t,是t中所有类型，比如head, length, size
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
	printf("请输入要删除数的序号:");
	int n;
	scanf("%d", &n);
	n--;//改为下标
	//判断位置合法性
	if (n < 0 || n >= t.length)
	{
		printf("位置非法");
		exit(0);
	}
	int i;
	for (i = n; i < t.length; i++)
	{
		t.head[i] = t.head[i + 1];
	}
	t.length--;
	printf("删除后：\n");

	return t;
}
table addTable(table t)
{
	int n;
	printf("您要插入在几号位置？");
	scanf("%d", &n);
	n--;//序号
	if (n < 0 || n >= t.length)
	{
		printf("位置非法");
		exit(0);
	}
	if (t.length == t.size)
	{
		printf("顺序表空间不足");
		exit(0);
	}
	int e;
	printf("您要插入：");
	scanf("%d", &e);
	int i;
	for (i = t.length; i >= n; i--)
	{
		t.head[i + 1] = t.head[i];
	}
	t.head[n] = e;
	t.length++;
	printf("插入后：\n");
	return t;
}
void selectTable(table t)
{
	int e;
	printf("您要查找：");
	scanf("%d", &e);
	int i;
	for (i = 0; i < t.length; i++)
	{
		if (e == t.head[i])
		{
			printf("已找到，位置：%d\n", i + 1);
			break;
		}
	}
	if (i == t.length)
	{
		printf("找不到");
	}
}
table amendTable(table t)
{
	int n;
	printf("修改哪一个？");
	scanf("%d", &n);
	n--;
	if (n < 0 || n >= t.length)
	{
		printf("位置非法");
		exit(0);
	}
	printf("把%d改为？", t.head[n]);
	int e;
	scanf("%d", &e);
	t.head[n] = e;
	printf("修改后：\n");
	return t;
}
int main()
{
	//创建并初始化顺序表
	table t = initTable();
	int i;
	//给顺序表写入1，2，3，4，5
	for (i = 1; i <= 5; i++)
	{
		t.head[i - 1] = i;//下标0赋1
		t.length++;
	}
	printf("原顺序表：\n");
	displayTable(t);
	//删除数据
	t = delTable(t);
	displayTable(t);
	//插入数据
	t = addTable(t);
	displayTable(t);
	//查找数据
	selectTable(t);
	//修改数据
	t = amendTable(t);
	displayTable(t);
	return 0;
}