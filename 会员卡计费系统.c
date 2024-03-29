#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define N 100
struct employee
{
	int num;
	char name[10];
	char sex;
	int age;
	char xueli[30];
	int wage;
	int xiao;
	int yu;
	char addr[30];
	long long int tel;
}em[100]; //结构体
void menu();
void input();
void save(int);
void display();
void del();
void add();
void search();
void search_num();
void search_tel();
void modify();
void up(int m);//各函数
void menu() //菜单函数
{
	printf(" ----------------------------------------------------菜单管理----------------------------------------------------\n");
	printf(" 1.新会员登记\n");
	printf(" 2统计功能\n");
	printf(" 3.会员消费结算\n");
	printf(" 4.会员退卡\n");
	printf(" 5.会员卡续费\n");
	printf(" 6会员信息修改\n");
	printf(" 7.退出\n");
	printf(" *************欢迎使用会员卡计费系统************\n");
	printf("\n");
	printf("\n");
	printf("\n");
}
int main()
{
	int n, flag;
	char a;
	char* s1;
	int b, j, flg = 0;
	menu(); //调用菜单函数
	{
		printf("请选择你需要操作的步骤(1--7):\n");
		scanf("%d", &n);
		if (n >= 1 && n <= 7)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			printf("您输入有误,请重新选择!");
		}
	}
	while (flag == 0);
	while (flag == 1)
	{
		switch (n)
		{
		case 1:printf(" ◆◆◆新会员登记◆◆◆\n"); printf("\n"); input(); break;
		case 2:printf(" ◆◆◆统计功能◆◆◆\n"); printf("\n"); display(); break;
		case 3:printf(" ◆◆◆会员消费结算◆◆◆\n"); printf("\n"); search(); break;
		case 4:printf(" ◆◆◆会员退卡◆◆◆\n"); printf("\n"); del(); break;
		case 5:printf(" ◆◆◆会员卡续费◆◆◆\n"); printf("\n"); add(); break;
		case 6:printf(" ◆◆◆会员信息修改◆◆◆\n"); printf("\n"); modify(); break;
		case 7:exit(0); break;
		default:break;
		}
		getchar();
		printf("\n");
		printf("是否继续进行(y or n):\n");
		scanf("%c", &a);
		if (a == 'y')
		{
			flag = 1;
			system("cls");//清屏
			menu(); //调用菜单函数
			printf("请再次选择你需要操作的步骤(1--7):\n");
			scanf("%d", &n);
			printf("\n");
		}
		else
			exit(0);
	}
}
void input() //录入函数
{
	int i, m;
	printf("请输入需要创建信息的会员人数(1--100):\n");
	printf("请一次性登记所有会员\n");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		printf("卡号：");
		srand((int)time(0));
		em[i].num = rand() % 100 + 20000000;
		if (em[i].num != em[i - 1].num)
			printf("%8d ", em[i].num);
		printf("\n");
		printf("请输入姓名: ");
		scanf("%s", em[i].name);
		getchar();
		printf("请输入性别(f--女，m--男): ");
		scanf("%c", &em[i].sex);
		getchar();
		printf("请输入年龄: ");
		scanf("%d", &em[i].age);
		getchar();
		printf("请输入学历: ");
		scanf("%s", em[i].xueli);
		getchar();
		printf("请输入缴费金额: ");
		scanf("%d", &em[i].wage);
		getchar();
		printf("请输入住址: ");
		scanf("%s", em[i].addr);
		getchar();
		printf("请输入电话: ");
		scanf("%lld", &em[i].tel);
		printf("\n");
	}
	printf("\n创建完毕!\n");
	save(m);
}
void save(int m) //保存文件函数
{
	int i;
	FILE* fp;
	if ((fp = fopen("zzj.txt", "a+")) == NULL)//创建文件并判断是否能打开 
	{
		printf("没有数据！\n");
		exit(0);
	}
	for (i = 0; i < m; i++) //将内存中会员的信息输出到磁盘文件中去
		if (fwrite(&em[i], sizeof(struct employee), 1, fp) != 1)
			printf("file write error\n");
	fclose(fp);
}
//
//
//
void up(int m) //更新文件函数
{
	int i;
	FILE* fp;
	if ((fp = fopen("zzj.txt", "w+")) == NULL)//创建文件并判断是否能打开 
	{
		printf("没有数据！\n");
		exit(0);
	}
	for (i = 0; i < m; i++) //将内存中会员的信息输出到磁盘文件中去
		if (fwrite(&em[i], sizeof(struct employee), 1, fp) != 1)
			printf("file write error\n");
	fclose(fp);
}
//
//
//
int load()//导入函数
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("zzj.txt", "r")) == NULL)
	{
		printf("没有数据\n");
		exit(0);
	}
	else
	{
		do
		{
			fread(&em[i], sizeof(struct employee), 1, fp);
			i++;
		} while (feof(fp) == 0);
	}
	fclose(fp);
	return(i - 1);
}
void display() //浏览函数
{
	int i;
	int m = load();
	printf("\n卡号\t姓名\t性别\t年龄\t学历\t缴费金额\t消费金额\t余额\t住址\t电话\n");
	for (i = 0; i < m; i++) //m为输入部分的会员人数
		printf("\n %d\t%s\t%c\t%d\t%s\t%d\t%d\t%d\t%s\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli, em[i].wage, em[i].xiao, em[i].yu, em[i].addr, em[i].tel);
}
void del() //删除函数
{
	int m = load();
	int i, j, n, t, flag;
	char name[20];
	printf("\n 原来的会员信息:\n");
	display(); //调用浏览函数
	printf("\n");
	printf("请输入要删除的会员的姓名:\n");
	scanf("%s", name);
	for (flag = 1, i = 0; flag && i < m; i++)
	{
		if (strcmp(em[i].name, name) == 0)
		{
			printf("\n已找到此人?原始记录为?\n");
			printf("\n卡号 姓名 性别 年龄 缴费金额 余额\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%d\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].yu);
			printf("\n确实要删除此人信息请按1,不删除请按0\n");
			scanf("%d", &n);
			if (n == 1) //如果删除?则其他的信息都往上移一行
			{
				for (j = i; j < m - 1; j++)
				{
					strcpy(em[j].name, em[j + 1].name);
					em[j].num = em[j + 1].num;
					em[j].sex = em[j + 1].sex;
					em[j].age = em[j + 1].age;
					em[j].wage = em[j + 1].wage;
					em[j].yu = em[j + 1].yu;
				}
				flag = 0;
			}
		}
	}
	if (!flag)
		m = m - 1;
	else
		printf("\n对不起，查无此人!\n");
	printf("\n 浏览删除后的所有会员信息:\n");
	up(m); //调用更新函数
	display(); //调用浏览函数
	printf("\n继续删除请按1不再删除请按0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:del(); break;
	case 0:break;
	default:break;
	}
}
void add()//续费函数
{

	FILE* fp;
	int num;
	int t;
	int i;
	int m = load();
	printf("\n 原来的会员信息:\n");
	display(); //调用浏览函数
	printf("\n");
	fp = fopen("zzj.txt", "a+");
	printf("请输入续费会员卡号:\n");
	scanf("%d", &num);
	for (i = 0; i < m; i++)
		if (num == em[i].num)
		{
			printf("\n已找到此人?其记录为?\n");
			printf("\n卡号\t姓名\t缴费金额\t消费金额\n");
			printf("\n%d\t%s\t%d\t%d\t%d\n", em[i].num, em[i].name, em[i].wage, em[i].xiao); printf("\n输入续费金额:\n");
			scanf("%d", &t);
			em[i].wage = em[i].wage + t;
			em[i].yu = em[i].yu + t;
			printf("\n续后金额:\t%d\n", em[i].yu);
			up(m);
		}
}
void search()//查询消费函数
{
	int t, flag;
	do
	{
		printf("\n按卡号查询请按1; 按电话号码查询请按3,进入主函数按4\n");
		scanf("%d", &t);
		if (t >= 1 && t <= 4)
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
			printf("您输入有误?请重新选择!");
		}
	} while (flag == 0);
	while (flag == 1)
	{
		switch (t)
		{
		case 1:printf("按卡号查询\n"); search_num(); break;
		case 3:printf("按电话号码查询\n"); search_tel(); break;
		case 4:main(); break;
		default:break;
		}
	}
}
void search_num()
{
	int num;
	int i, t;
	int m = load();
	printf("请输入要查找的会员卡号(20000001---20000100):\n");
	scanf("%d", &num);
	for (i = 0; i < m; i++)
		if (num == em[i].num)
		{
			printf("\n已找到此人，其记录为：\n");
			printf("\n卡号\t      姓名\t性别\t年龄\t缴费金额\t电话\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].tel);
			printf("\n该次消费为;\n");
			scanf("%d", &em[i].xiao);
			em[i].yu = em[i].wage - em[i].xiao;
			if (em[i].xiao >= 1000)
			{
				em[i].yu = em[i].wage - em[i].xiao * 0.9;
			}
			printf("\n卡号\t      姓名\t性别\t年龄\t缴费金额\t消费金额\t余额\t电话\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%d\t%d\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].xiao, em[i].yu, em[i].tel);
			up(m);
			break;
		}
	if (i == m)
		printf("\n对不起?查无此人\n");
	printf("\n");
	printf("返回查询函数请按1,继续查询卡号请按0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:search(); break;
	case 2: break;
	default:break;
	}
}
void search_tel()
{
	long long int tel;
	int i, t;
	int m = load();
	printf("请输入要查找的电话号码:\n");
	scanf("%lld", &tel);
	for (i = 0; i < m; i++)
		if (tel == em[i].tel)
		{
			printf("\n已找到此人，其记录为：\n");
			printf("\n卡号\t      姓名\t性别\t年龄\t缴费金额\t电话\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].tel);
			printf("\n该次消费为：\n");
			scanf("%d", &em[i].xiao);
			em[i].yu = em[i].wage - em[i].xiao;
			if (em[i].xiao >= 1000)
			{
				em[i].yu = em[i].wage - em[i].xiao * 0.9;
			}
			printf("\n卡号\t      姓名\t性别\t年龄\t缴费金额\t消费金额\t余额\t电话\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%d\t%d\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].xiao, em[i].yu, em[i].tel);
			up(m);
			break;
		}
	if (i == m)
		printf("\n对不起?查无此人\n");
	printf("\n");
	printf("返回查询函数请按1,继续查询电话号码请按0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:search(); break;
	case 2:break;
	default:break;
	}
}
void modify() //修改函数
{
	int num;
	char name[10];
	char sex;
	int age;
	char xueli[30];
	int wage;
	char addr[30];
	long long int tel;
	int b, c, i, n, t, flag;
	int m = load(); //导入文件内的信息
	printf("\n 原来的会员信息:\n");
	display(); //调用浏览函数
	printf("\n");
	printf("请输入要修改的会员的姓名:\n");
	scanf("%s", name);
	for (flag = 1, i = 0; flag && i < m; i++)
	{
		if (strcmp(em[i].name, name) == 0)
		{
			printf("\n已找到此人，原始记录为：\n");
			printf("\n卡号\t        姓名\t性别\t年龄\t学历\t缴费金额\t住址\t电话\n");
			printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli, em[i].wage, em[i].addr, em[i].tel);
			printf("\n确实要修改此人信息请按1; 不修改请按0\n");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("\n需要进行修改的选项\n 1.卡号2.姓名3.性别4.年龄5.学历6.缴费金额7.住址8.电话\n");
				printf("请输入你想修改的那一项序号:\n");
				scanf("%d", &c);
				if (c > 9 || c < 1)
					printf("\n选择错误?请重新选择!\n");
			}
			flag = 0;
		}
	}
	if (flag == 1)
		printf("\n对不起?查无此人!\n");
	do
	{
		switch (c) //因为当找到第i个会员时,for语句后i自加了,所以下面的应该把改后的信息赋值给第i-1个人
		{
		case 1:printf("卡号改为: ");
			scanf("%d", &num);
			em[i - 1].num = num;
			break;
		case 2:printf("姓名改为: ");
			scanf("%s", name);
			strcpy(em[i - 1].name, name);
			break;
		case 3:printf("性别改为: ");
			getchar();
			scanf("%c", &sex);
			em[i - 1].sex = sex;
			break;
		case 4:printf("年龄改为: ");
			scanf("%d", &age);
			em[i - 1].age = age;
			break;
		case 5:printf("学历改为: ");
			scanf("%s", xueli);
			strcpy(em[i - 1].xueli, xueli);
			break;
		case 6:printf("缴费金额改为: ");
			scanf("%d", &wage);
			em[i - 1].wage = wage;
			break;
		case 7:printf("住址改为: ");
			scanf("%s", addr);
			strcpy(em[i - 1].addr, addr);
			break;
		case 8:printf("电话改为: ");
			scanf("%lld", &tel);
			em[i - 1].tel = tel;
			break;
		}
		printf("\n");
		printf("\n是否确定所修改的信息?\n 是请按1; 不,重新修改请按2: \n");
		scanf("%d", &b);
	} while (b == 2);
	printf("\n浏览修改后的所有会员信息:\n");
	printf("\n");
	up(m);
	display();
	printf("\n继续修改请按1?不再修改请按0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:modify(); break;
	case 0:main();
	default:break;
	}
	getchar();
}
