#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include"Add.h"
void fun(int zzj);//���Ĳ�����麯��
int jiecheng(int n);//�׳˺���
int fib(int n);//�ݹ�쳲���������
long long int Fib(int n);//ѭ��쳲���������
int main()
{
	//strcpy�ַ�����������
	char arr1[] = "bit";
	char arr2[] = "########";
	strcpy(arr2, arr1);//�����滻ǰ
	printf("%s\n", arr2);
	//memset�ڴ����ú���
	char arr3[] = "hello world";
	memset(arr3, '*', 5);//ǰ����滻Ϊ*��
	printf("%s\n", arr3);
	//������ͷ�ļ�Ĭ����������֮��
	int a = 10, b = 20;
	//Add�ӷ�����
	int sum = Add(a, b);//����Add����ԭ������һ��Դ�ļ�Add.c�������ͷ�ļ�Add,h��
	printf("%d\n", sum);
	//�����ݹ飺�Լ������Լ�
	//��������������������ע�ʹ�
	//�ͻ��ǰ��Ķ�������ѭ������Ϊ�޷�ֹͣ���������ջ���
	//main();
	//���½���ʾ�ݹ鷨������֣�123��Ϊ1 2 3
	int zzj = 123;
	fun(zzj);//��ֺ���
	//��123һ��������������1��������ٻ���ÿ�׶ΰ�10ȡ�������λ����1 2 3˳�����
	//���滹���������
	printf("\n");
	//������ʾ�ݹ���׳�
	int N;
	printf("���루���Ľ׳ˣ�");
	scanf("%d", &N);
	int ret;
	if (N >= 1)
	{
		ret = jiecheng(N);
		printf("%d", ret);
	}
	else
	{
		printf("��������");
	}
	printf("\n");
	//������ʾ�ݹ�쳲���������
	int N1;
	printf("쳲��������е�ǰ����λ��");
	scanf("%d", &N1);
	int i;
	for (i = 1; i <= N1; i++)
	{
		printf("��%dλ쳲���������%d\n",i, fib(i));
	}
	//�ݹ���Ȼ�������򵥣������㸴�ӣ�ʱ�䳤��������ȥ�������ʮ�������ò���
	//���Ը�ѭ������ѭ��
	//��ʾ�µ��㷨
	printf("�µ�쳲��������У�\n");
	int N2;
	printf("������쳲��������е�ǰ����λ��");
	scanf("%d", &N2);
	for (i = 1; i <= N2; i++)
	{
		printf("��%dλ쳲���������%lld\n", i, Fib(i));
	}
	//�찡���ܿ찡�����е���õ�long long int
	return 0;
}
void fun(int zzj)//���Ĳ�����麯��
{
	//if (zzj > 9)//�������һλ��
	//{
	//	fun(zzj / 10);//�ͳ�ȥ��λ�ٵ���
	//}
	//printf("%d ", zzj % 10);//ȡ��λ
	//////////////////////////////////////////////////////////////////////////
	if (zzj > 0)//��������Ϊ0
	{
		printf("%d ", zzj % 10);//�������λ
		fun(zzj / 10);//��ȥ����λ��������µĸ�λ
	}
}
int jiecheng(int n)
{
	if (n >= 1)
	{
		return n * jiecheng(n - 1);//�𽥼�һ��֮ǰ�����
	}
}
int fib(int n)//쳲���������
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
long long int Fib(int n)//ѭ��쳲���������
{
	long long int a = 1;
	long long int b = 1;
	long long int c = 1;
	while (n > 2)
	{
		c = a + b;//�������ǰ�������
		a = b;
		b = c;
		//����λѭ��
		n--;
	}
	return c;
}