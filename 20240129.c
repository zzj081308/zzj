#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void  bubble_sort(int arr[], int gs);
int main()
{
	//数组
	//数组存放是连续的
	int ar[] = { 1,2,3 };
	printf("第一地址：%p\n第二地址：%p\n第三地址：%p\n", &ar[0], &ar[1], &ar[2]);
	//每个地址相差4个字节，即int大小
	//以下演示冒泡排序
	//9,8,7,6,5,4,3,2,1,0
	//8,9,7,6,5,4,3,2,1,0
	//8,7,9,6,5,4,3,2,1,0
	//......
	//8,7,6,5,4,3,2,1,0,9//往上冒
	//......
	//0,1,2,3,4,5,6,7,8,9
	//每趟冒泡确定一个数的位置，排序完需要9趟冒泡
	//10个数9趟，n个数n - 1趟
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int gs = sizeof(arr) / sizeof(arr[0]);//计算数组元素个数
	//注意，传数组名进函数是传数组首地址，但sizeof是例外，是整个数组
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
	int flag = 1;//有序标志
	for (i = 0; i < gs - 1; i++)//趟数是gs - 1
	{
		for (j = 0; j < gs - 1 - i; j++)//每趟次比较的次数递减9，8，7...
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;//如果开始交换，flag值改变，表示无序
			}
		}
		if (flag == 1)
		{
			break;//如果本来就有序，就直接跳出，节省时间
		}
	}
}