#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//if_else选择语句就近执行真语句，多分支只执行一条，多if同时进行，else就近对应
	//switch多分支语句，多情况，多case执行，break跳出，case情况之外的用default执行提示
	//三大循环while，dowhile，for
	//getchar输入字符函数
	printf("请输入字符：");
	int ch = getchar();
	//注意getchar不获取字符，获取是单个字符ascll码
	printf("putchar:");
	putchar(ch);
	printf("\n");
	printf("打印的%c\n", ch);
	int c = 0;
	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}
	//这里EOF是-1，但c永远不为-1，所以停不下来，用ctrl+Z回车停下
	//EOF - End Of File -文件结束标志
	//输入缓冲区演示
	int ret = 0;
	char mima[20] = { 0 };
	printf("请输入密码：\n");
	scanf("%s", &mima);
	//这里输入密码按回车
	//缓冲区：密码\n
	//密码被scanf拿走，剩下\n被getchar看到直接读取不为Y，结束为放弃
	//所以先加一个空的getchar()把\n弄走
	getchar();
	printf("请确认密码(Y/N)：");
	ret = getchar();
	if (ret == 'Y')
	{
		printf("确认");
	}
	else
	{
		printf("放弃");
	}
	//如果输入密码带空格，空格不被scanf读取，被getchar()读取空格后的又不是Y，被getchar读取又是放弃
	//所以将中间的getchar()改为以下形式
	//while((C = getchar()) != '\n')
	//{
		//;//空语句
	//}
	//只要不读到回车，就一直读
	//比较两个字符串密码是否相等，用strcmp(password, "正确密码")
	//引用头文件<string.h>
	//执行暂停函数,sleep(1000),括号里是毫秒，引用头文件<windows.h>
	//清屏函数system("cls"),<stdlib.h>
	return 0;
}