#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));//分配内存的大小
	if (arr == NULL)
	{
		printf("内存分配失败");
	}
	//至此内存已经分配完毕，可以往数组里放变量
	//以下演示输出几个数字
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	free(arr);//释放内存
	arr = NULL;//给指针挪个位置，防止空指针
	return 0;
}
