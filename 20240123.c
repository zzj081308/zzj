#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//if_elseѡ�����ͽ�ִ������䣬���ִֻ֧��һ������ifͬʱ���У�else�ͽ���Ӧ
	//switch���֧��䣬���������caseִ�У�break������case���֮�����defaultִ����ʾ
	//����ѭ��while��dowhile��for
	//getchar�����ַ�����
	printf("�������ַ���");
	int ch = getchar();
	//ע��getchar����ȡ�ַ�����ȡ�ǵ����ַ�ascll��
	printf("putchar:");
	putchar(ch);
	printf("\n");
	printf("��ӡ��%c\n", ch);
	int c = 0;
	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}
	//����EOF��-1����c��Զ��Ϊ-1������ͣ����������ctrl+Z�س�ͣ��
	//EOF - End Of File -�ļ�������־
	//���뻺������ʾ
	int ret = 0;
	char mima[20] = { 0 };
	printf("���������룺\n");
	scanf("%s", &mima);
	//�����������밴�س�
	//������������\n
	//���뱻scanf���ߣ�ʣ��\n��getchar����ֱ�Ӷ�ȡ��ΪY������Ϊ����
	//�����ȼ�һ���յ�getchar()��\nŪ��
	getchar();
	printf("��ȷ������(Y/N)��");
	ret = getchar();
	if (ret == 'Y')
	{
		printf("ȷ��");
	}
	else
	{
		printf("����");
	}
	//�������������ո񣬿ո񲻱�scanf��ȡ����getchar()��ȡ�ո����ֲ���Y����getchar��ȡ���Ƿ���
	//���Խ��м��getchar()��Ϊ������ʽ
	//while((C = getchar()) != '\n')
	//{
		//;//�����
	//}
	//ֻҪ�������س�����һֱ��
	//�Ƚ������ַ��������Ƿ���ȣ���strcmp(password, "��ȷ����")
	//����ͷ�ļ�<string.h>
	//ִ����ͣ����,sleep(1000),�������Ǻ��룬����ͷ�ļ�<windows.h>
	//��������system("cls"),<stdlib.h>
	return 0;
}