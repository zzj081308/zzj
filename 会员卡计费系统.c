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
}em[100]; //�ṹ��
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
void up(int m);//������
void menu() //�˵�����
{
	printf(" ----------------------------------------------------�˵�����----------------------------------------------------\n");
	printf(" 1.�»�Ա�Ǽ�\n");
	printf(" 2ͳ�ƹ���\n");
	printf(" 3.��Ա���ѽ���\n");
	printf(" 4.��Ա�˿�\n");
	printf(" 5.��Ա������\n");
	printf(" 6��Ա��Ϣ�޸�\n");
	printf(" 7.�˳�\n");
	printf(" *************��ӭʹ�û�Ա���Ʒ�ϵͳ************\n");
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
	menu(); //���ò˵�����
	{
		printf("��ѡ������Ҫ�����Ĳ���(1--7):\n");
		scanf("%d", &n);
		if (n >= 1 && n <= 7)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			printf("����������,������ѡ��!");
		}
	}
	while (flag == 0);
	while (flag == 1)
	{
		switch (n)
		{
		case 1:printf(" �������»�Ա�Ǽǡ�����\n"); printf("\n"); input(); break;
		case 2:printf(" ������ͳ�ƹ��ܡ�����\n"); printf("\n"); display(); break;
		case 3:printf(" ��������Ա���ѽ��������\n"); printf("\n"); search(); break;
		case 4:printf(" ��������Ա�˿�������\n"); printf("\n"); del(); break;
		case 5:printf(" ��������Ա�����ѡ�����\n"); printf("\n"); add(); break;
		case 6:printf(" ��������Ա��Ϣ�޸ġ�����\n"); printf("\n"); modify(); break;
		case 7:exit(0); break;
		default:break;
		}
		getchar();
		printf("\n");
		printf("�Ƿ��������(y or n):\n");
		scanf("%c", &a);
		if (a == 'y')
		{
			flag = 1;
			system("cls");//����
			menu(); //���ò˵�����
			printf("���ٴ�ѡ������Ҫ�����Ĳ���(1--7):\n");
			scanf("%d", &n);
			printf("\n");
		}
		else
			exit(0);
	}
}
void input() //¼�뺯��
{
	int i, m;
	printf("��������Ҫ������Ϣ�Ļ�Ա����(1--100):\n");
	printf("��һ���ԵǼ����л�Ա\n");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		printf("���ţ�");
		srand((int)time(0));
		em[i].num = rand() % 100 + 20000000;
		if (em[i].num != em[i - 1].num)
			printf("%8d ", em[i].num);
		printf("\n");
		printf("����������: ");
		scanf("%s", em[i].name);
		getchar();
		printf("�������Ա�(f--Ů��m--��): ");
		scanf("%c", &em[i].sex);
		getchar();
		printf("����������: ");
		scanf("%d", &em[i].age);
		getchar();
		printf("������ѧ��: ");
		scanf("%s", em[i].xueli);
		getchar();
		printf("������ɷѽ��: ");
		scanf("%d", &em[i].wage);
		getchar();
		printf("������סַ: ");
		scanf("%s", em[i].addr);
		getchar();
		printf("������绰: ");
		scanf("%lld", &em[i].tel);
		printf("\n");
	}
	printf("\n�������!\n");
	save(m);
}
void save(int m) //�����ļ�����
{
	int i;
	FILE* fp;
	if ((fp = fopen("zzj.txt", "a+")) == NULL)//�����ļ����ж��Ƿ��ܴ� 
	{
		printf("û�����ݣ�\n");
		exit(0);
	}
	for (i = 0; i < m; i++) //���ڴ��л�Ա����Ϣ����������ļ���ȥ
		if (fwrite(&em[i], sizeof(struct employee), 1, fp) != 1)
			printf("file write error\n");
	fclose(fp);
}
//
//
//
void up(int m) //�����ļ�����
{
	int i;
	FILE* fp;
	if ((fp = fopen("zzj.txt", "w+")) == NULL)//�����ļ����ж��Ƿ��ܴ� 
	{
		printf("û�����ݣ�\n");
		exit(0);
	}
	for (i = 0; i < m; i++) //���ڴ��л�Ա����Ϣ����������ļ���ȥ
		if (fwrite(&em[i], sizeof(struct employee), 1, fp) != 1)
			printf("file write error\n");
	fclose(fp);
}
//
//
//
int load()//���뺯��
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("zzj.txt", "r")) == NULL)
	{
		printf("û������\n");
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
void display() //�������
{
	int i;
	int m = load();
	printf("\n����\t����\t�Ա�\t����\tѧ��\t�ɷѽ��\t���ѽ��\t���\tסַ\t�绰\n");
	for (i = 0; i < m; i++) //mΪ���벿�ֵĻ�Ա����
		printf("\n %d\t%s\t%c\t%d\t%s\t%d\t%d\t%d\t%s\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli, em[i].wage, em[i].xiao, em[i].yu, em[i].addr, em[i].tel);
}
void del() //ɾ������
{
	int m = load();
	int i, j, n, t, flag;
	char name[20];
	printf("\n ԭ���Ļ�Ա��Ϣ:\n");
	display(); //�����������
	printf("\n");
	printf("������Ҫɾ���Ļ�Ա������:\n");
	scanf("%s", name);
	for (flag = 1, i = 0; flag && i < m; i++)
	{
		if (strcmp(em[i].name, name) == 0)
		{
			printf("\n���ҵ�����?ԭʼ��¼Ϊ?\n");
			printf("\n���� ���� �Ա� ���� �ɷѽ�� ���\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%d\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].yu);
			printf("\nȷʵҪɾ��������Ϣ�밴1,��ɾ���밴0\n");
			scanf("%d", &n);
			if (n == 1) //���ɾ��?����������Ϣ��������һ��
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
		printf("\n�Բ��𣬲��޴���!\n");
	printf("\n ���ɾ��������л�Ա��Ϣ:\n");
	up(m); //���ø��º���
	display(); //�����������
	printf("\n����ɾ���밴1����ɾ���밴0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:del(); break;
	case 0:break;
	default:break;
	}
}
void add()//���Ѻ���
{

	FILE* fp;
	int num;
	int t;
	int i;
	int m = load();
	printf("\n ԭ���Ļ�Ա��Ϣ:\n");
	display(); //�����������
	printf("\n");
	fp = fopen("zzj.txt", "a+");
	printf("���������ѻ�Ա����:\n");
	scanf("%d", &num);
	for (i = 0; i < m; i++)
		if (num == em[i].num)
		{
			printf("\n���ҵ�����?���¼Ϊ?\n");
			printf("\n����\t����\t�ɷѽ��\t���ѽ��\n");
			printf("\n%d\t%s\t%d\t%d\t%d\n", em[i].num, em[i].name, em[i].wage, em[i].xiao); printf("\n�������ѽ��:\n");
			scanf("%d", &t);
			em[i].wage = em[i].wage + t;
			em[i].yu = em[i].yu + t;
			printf("\n������:\t%d\n", em[i].yu);
			up(m);
		}
}
void search()//��ѯ���Ѻ���
{
	int t, flag;
	do
	{
		printf("\n�����Ų�ѯ�밴1; ���绰�����ѯ�밴3,������������4\n");
		scanf("%d", &t);
		if (t >= 1 && t <= 4)
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
			printf("����������?������ѡ��!");
		}
	} while (flag == 0);
	while (flag == 1)
	{
		switch (t)
		{
		case 1:printf("�����Ų�ѯ\n"); search_num(); break;
		case 3:printf("���绰�����ѯ\n"); search_tel(); break;
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
	printf("������Ҫ���ҵĻ�Ա����(20000001---20000100):\n");
	scanf("%d", &num);
	for (i = 0; i < m; i++)
		if (num == em[i].num)
		{
			printf("\n���ҵ����ˣ����¼Ϊ��\n");
			printf("\n����\t      ����\t�Ա�\t����\t�ɷѽ��\t�绰\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].tel);
			printf("\n�ô�����Ϊ;\n");
			scanf("%d", &em[i].xiao);
			em[i].yu = em[i].wage - em[i].xiao;
			if (em[i].xiao >= 1000)
			{
				em[i].yu = em[i].wage - em[i].xiao * 0.9;
			}
			printf("\n����\t      ����\t�Ա�\t����\t�ɷѽ��\t���ѽ��\t���\t�绰\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%d\t%d\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].xiao, em[i].yu, em[i].tel);
			up(m);
			break;
		}
	if (i == m)
		printf("\n�Բ���?���޴���\n");
	printf("\n");
	printf("���ز�ѯ�����밴1,������ѯ�����밴0\n");
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
	printf("������Ҫ���ҵĵ绰����:\n");
	scanf("%lld", &tel);
	for (i = 0; i < m; i++)
		if (tel == em[i].tel)
		{
			printf("\n���ҵ����ˣ����¼Ϊ��\n");
			printf("\n����\t      ����\t�Ա�\t����\t�ɷѽ��\t�绰\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].tel);
			printf("\n�ô�����Ϊ��\n");
			scanf("%d", &em[i].xiao);
			em[i].yu = em[i].wage - em[i].xiao;
			if (em[i].xiao >= 1000)
			{
				em[i].yu = em[i].wage - em[i].xiao * 0.9;
			}
			printf("\n����\t      ����\t�Ա�\t����\t�ɷѽ��\t���ѽ��\t���\t�绰\n");
			printf("\n%d\t%s\t%c\t%d\t%d\t%d\t%d\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].wage, em[i].xiao, em[i].yu, em[i].tel);
			up(m);
			break;
		}
	if (i == m)
		printf("\n�Բ���?���޴���\n");
	printf("\n");
	printf("���ز�ѯ�����밴1,������ѯ�绰�����밴0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:search(); break;
	case 2:break;
	default:break;
	}
}
void modify() //�޸ĺ���
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
	int m = load(); //�����ļ��ڵ���Ϣ
	printf("\n ԭ���Ļ�Ա��Ϣ:\n");
	display(); //�����������
	printf("\n");
	printf("������Ҫ�޸ĵĻ�Ա������:\n");
	scanf("%s", name);
	for (flag = 1, i = 0; flag && i < m; i++)
	{
		if (strcmp(em[i].name, name) == 0)
		{
			printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
			printf("\n����\t        ����\t�Ա�\t����\tѧ��\t�ɷѽ��\tסַ\t�绰\n");
			printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%lld\n", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].xueli, em[i].wage, em[i].addr, em[i].tel);
			printf("\nȷʵҪ�޸Ĵ�����Ϣ�밴1; ���޸��밴0\n");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("\n��Ҫ�����޸ĵ�ѡ��\n 1.����2.����3.�Ա�4.����5.ѧ��6.�ɷѽ��7.סַ8.�绰\n");
				printf("�����������޸ĵ���һ�����:\n");
				scanf("%d", &c);
				if (c > 9 || c < 1)
					printf("\nѡ�����?������ѡ��!\n");
			}
			flag = 0;
		}
	}
	if (flag == 1)
		printf("\n�Բ���?���޴���!\n");
	do
	{
		switch (c) //��Ϊ���ҵ���i����Աʱ,for����i�Լ���,���������Ӧ�ðѸĺ����Ϣ��ֵ����i-1����
		{
		case 1:printf("���Ÿ�Ϊ: ");
			scanf("%d", &num);
			em[i - 1].num = num;
			break;
		case 2:printf("������Ϊ: ");
			scanf("%s", name);
			strcpy(em[i - 1].name, name);
			break;
		case 3:printf("�Ա��Ϊ: ");
			getchar();
			scanf("%c", &sex);
			em[i - 1].sex = sex;
			break;
		case 4:printf("�����Ϊ: ");
			scanf("%d", &age);
			em[i - 1].age = age;
			break;
		case 5:printf("ѧ����Ϊ: ");
			scanf("%s", xueli);
			strcpy(em[i - 1].xueli, xueli);
			break;
		case 6:printf("�ɷѽ���Ϊ: ");
			scanf("%d", &wage);
			em[i - 1].wage = wage;
			break;
		case 7:printf("סַ��Ϊ: ");
			scanf("%s", addr);
			strcpy(em[i - 1].addr, addr);
			break;
		case 8:printf("�绰��Ϊ: ");
			scanf("%lld", &tel);
			em[i - 1].tel = tel;
			break;
		}
		printf("\n");
		printf("\n�Ƿ�ȷ�����޸ĵ���Ϣ?\n ���밴1; ��,�����޸��밴2: \n");
		scanf("%d", &b);
	} while (b == 2);
	printf("\n����޸ĺ�����л�Ա��Ϣ:\n");
	printf("\n");
	up(m);
	display();
	printf("\n�����޸��밴1?�����޸��밴0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:modify(); break;
	case 0:main();
	default:break;
	}
	getchar();
}
