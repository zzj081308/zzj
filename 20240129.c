#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void  bubble_sort(int arr[], int gs);
int main()
{
	//����
	//��������������
	int ar[] = { 1,2,3 };
	printf("��һ��ַ��%p\n�ڶ���ַ��%p\n������ַ��%p\n", &ar[0], &ar[1], &ar[2]);
	//ÿ����ַ���4���ֽڣ���int��С
	//������ʾð������
	//9,8,7,6,5,4,3,2,1,0
	//8,9,7,6,5,4,3,2,1,0
	//8,7,9,6,5,4,3,2,1,0
	//......
	//8,7,6,5,4,3,2,1,0,9//����ð
	//......
	//0,1,2,3,4,5,6,7,8,9
	//ÿ��ð��ȷ��һ������λ�ã���������Ҫ9��ð��
	//10����9�ˣ�n����n - 1��
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int gs = sizeof(arr) / sizeof(arr[0]);//��������Ԫ�ظ���
	//ע�⣬���������������Ǵ������׵�ַ����sizeof�����⣬����������
	bubble_sort(arr, gs);
	int i;
	for (i = 0; i < gs; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
void bubble_sort(int arr[], int gs)
{
	int i, j, temp;
	int flag = 1;//�����־
	for (i = 0; i < gs - 1; i++)//������gs - 1
	{
		for (j = 0; j < gs - 1 - i; j++)//ÿ�˴αȽϵĴ����ݼ�9��8��7...
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;//�����ʼ������flagֵ�ı䣬��ʾ����
			}
		}
		if (flag == 1)
		{
			break;//������������򣬾�ֱ����������ʡʱ��
		}
	}
}