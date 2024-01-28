#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include"Add.h"
void fun(int zzj);//数的拆分重组函数
int jiecheng(int n);//阶乘函数
int fib(int n);//递归斐波那契函数
long long int Fib(int n);//循环斐波那契函数
int main()
{
	//strcpy字符串拷贝函数
	char arr1[] = "bit";
	char arr2[] = "########";
	strcpy(arr2, arr1);//后复制替换前
	printf("%s\n", arr2);
	//memset内存设置函数
	char arr3[] = "hello world";
	memset(arr3, '*', 5);//前五个替换为*号
	printf("%s\n", arr3);
	//声明放头文件默认在主函数之上
	int a = 10, b = 20;
	//Add加法函数
	int sum = Add(a, b);//这里Add函数原型在另一个源文件Add.c里，声明在头文件Add,h里
	printf("%d\n", sum);
	//函数递归：自己调用自己
	//如果这里调用主函数，把注释打开
	//就会把前面的东西无限循环，因为无法停止，所以造成栈溢出
	//main();
	//以下将演示递归法拆分数字，123拆开为1 2 3
	int zzj = 123;
	fun(zzj);//拆分函数
	//把123一个个除掉，除到1再输出，再回溯每阶段按10取余输出个位，以1 2 3顺序输出
	//下面还有逆序输出
	printf("\n");
	//以下演示递归求阶乘
	int N;
	printf("输入（）的阶乘：");
	scanf("%d", &N);
	int ret;
	if (N >= 1)
	{
		ret = jiecheng(N);
		printf("%d", ret);
	}
	else
	{
		printf("输入有误！");
	}
	printf("\n");
	//以下演示递归斐波那契数列
	int N1;
	printf("斐波那契数列的前多少位：");
	scanf("%d", &N1);
	int i;
	for (i = 1; i <= N1; i++)
	{
		printf("第%d位斐波那契数是%d\n",i, fib(i));
	}
	//递归虽然看起来简单，但运算复杂，时间长，不信你去算算第五十个数看久不久
	//所以该循环还是循环
	//演示新的算法
	printf("新的斐波那契数列：\n");
	int N2;
	printf("再输入斐波那契数列的前多少位：");
	scanf("%d", &N2);
	for (i = 1; i <= N2; i++)
	{
		printf("第%d位斐波那契数是%lld\n", i, Fib(i));
	}
	//快啊，很快啊！数有点大，用的long long int
	return 0;
}
void fun(int zzj)//数的拆分重组函数
{
	//if (zzj > 9)//如果大于一位数
	//{
	//	fun(zzj / 10);//就除去个位再调用
	//}
	//printf("%d ", zzj % 10);//取个位
	//////////////////////////////////////////////////////////////////////////
	if (zzj > 0)//除到最后会为0
	{
		printf("%d ", zzj % 10);//先输出个位
		fun(zzj / 10);//再去除个位，再输出新的个位
	}
}
int jiecheng(int n)
{
	if (n >= 1)
	{
		return n * jiecheng(n - 1);//逐渐减一于之前的相乘
	}
}
int fib(int n)//斐波那契函数
{
	int i;
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
long long int Fib(int n)//循环斐波那契函数
{
	long long int a = 1;
	long long int b = 1;
	long long int c = 1;
	while (n > 2)
	{
		c = a + b;//后项等于前两项相加
		a = b;
		b = c;
		//再移位循环
		n--;
	}
	return c;
}