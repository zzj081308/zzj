#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
struct zzj
{
	char name[10];
	char sex[10];
	int age;
};
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	printf("%d\n", sizeof(arr));//这里输出数组所有元素字节总和，有六个整型4x6=24
	//波浪号~按二进制位取反符号，比如1010转0101
	int a = 1;
	int b = ~a;
	printf("%d\n", b);
	//这里输出为-2，是因为计算机补码有关
	//--和++号可前后放置，先写先变
	//(类型)强制转换类型
	int c = (int)3.14;//3.14转整型3
	printf("%d\n", c);
	//或与非跳过，真非0，假0
	//(语句)? 1:2，语句成立执行1，否则2
	//[]是下标引用，数组就是，从0开始
	//()函数调用
	//typedef是类型重定义，可以给指令改名
	//例如，unsigned int太长，不好看
	//用 typedef unsigned int uint
	//意为改为uint，typedef改名卡!
	//static，修饰局部变量，使得生命周期变长
	//例如
	// i = 0;
	// int a;
	// while(i < 3)
	//{
	//	a = 1;
	//	a++;
	//	printf("%d", a);
	//}
	//会输出2，2，2，因为每次循环a初始化1
	//如果int a改为static int a就变成静态局部变量，给a存档，防止出了循环后a初始化，会输出2，3，4
	//extern声明外部符号,改变变量作用域，声明其他源文件的全局变量，甚至函数
	//define还可以定义宏，类似于函数
	//例如
	// #define MAX(X, Y) (X > Y ? X : Y)
	//int a = 10, b = 20;
	//max = MAX (a, b)
	// 可以求较大值，类似函数
	///////////////////////////////////注意！前方非战斗人员立即撤离！////////////////////////////////
	///////////////////////////////////注意！前方非战斗人员立即撤离！////////////////////////////////
	///////////////////////////////////注意！前方非战斗人员立即撤离！////////////////////////////////
	//指针！！！！！
	//内存由地址组成
	//地址例如32位就有2^32个比特位，第一个地址是32个0，一个地址框是一字节
	int A = 114514;
	printf("A的地址%p\n", &A);//用取地址符号&取A地址，用%p输出可以看到A地址,这个地址里存着114514
	//指针变量用*解引用操作符定义，指针变量存地址
	int* p = &A;
	printf("p存的地址是%p\n", p);
	printf("解引用后*p的值是%d\n", *p);
	//如果改变*p的值，A的值也会改变
	*p = 100;
	printf("修改后A为%d\n", A);
	//p存的是地址，*p相当于根据地址找到A，*p找到了A，*p就等同于A
	//*p == A, 所以修改*p的值就等同于修改A的值
	//如果指针指向其他类型，例如字符类型就要改为char*
	////////////////////////////////////////////////////////////////////////////////////////////////
	//结构体：包含一些特征的复杂体系
	//由struct定义，格式：struct_名字{内容};放在主函数外，这里放在第4行
	//结构体变量是有多种类型的变量，种类往结构体内去取
	//调用结构体中的变量
	struct zzj hhh = { "周尊杰","男",18};//用结构体变量hhh调用结构体zzj
	printf("名字：%s\n", hhh.name);//以name中的char形式输出
	printf("性别：%s\n", hhh.sex);//以sex中的char形式输出
	printf("年龄：%d岁\n", hhh.age);//以age中的int形式输出
	//注意一定要按顺序一一对应！否则出现对应出错，姓名男，性别周尊杰，这种
	//结构体变量还可以修改，比如
	hhh.age = 19;//这里就把age改为19了
	//这里age是变量可以改，但name和sex不能轻易改，是数组！
	//要修改请引用头文件string,调用字符串拷贝函数strcpy
	strcpy(hhh.name, "杰哥");
	printf("%s\n", hhh.name);
	printf("一年后%d岁\n", hhh.age);
	//还可以用指针输出，当然指针就变成结构体变量类型
	struct zzj* P = &hhh;
	printf("*P名字：%s\n", (*P).name);//这里不加括号改为P->name也可以
	printf("P->名字：%s\n", P->name);//这里name不用加点
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
//至此，C语言已经概括完成，恭喜你已经入门。