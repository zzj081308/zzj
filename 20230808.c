#include <stdio.h>//���ú��� ����std��Ӧstandard(��׼) i��Ӧinput(����) o��Ӧoutput(���)
int main()//main�����������ҽ���һ��) int�����ͣ���main���������÷���һ������ֵ
{
	printf("��ã����磡\n");//���е�\n�ǻ���
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	char z = 'Z';//�涨z����Z,Z��z��ֵ��char�ƺ��Ǹ�ֵ��ֵֻ������ĸ���ַ����޷������֣�������ֵ��z�������Ǻ��֣�������δ֪��������xyzabcd���ұ���
	//char �ַ��������� ֻ�����һλ����zzjֻ���z��114514ֻ���1
	printf("z = %c\n", z);//���е�%c��˼������ַ���ʽz������Z��������Ӷ��ţ�����z����ʾ��z�Ľ�����
	int nyt = 4294967296;//int���ͣ�����������,�������������18.2ֻ�����18������������������С�����һ�ɲ���
	printf("nyt = %d\n", nyt);//%d��˼�����ʮ�������ڵ����������ճ��������ܼ�������
	short yjx = 65536;//short,���������֣�ֻ��������
	printf("yjx = %d\n", yjx);
	long zzj = 4294967296;//����������
	printf("zzj = %d\n", zzj);
	long long ZZJ = 18446744073709551615;//�������������֣�����û��long long long...�ˣ�Ҳû��short short��ע��long֮���пո�
	printf("ZZJ = %d\n", ZZJ);
	float yyl = 3.1415926;//����������� ��С��������ౣ��С�������λ������λ�ɵ���λ��������õ�
	printf("yyl = %f\n", yyl);//%f��Ϊ���С��
	double hmh = 5.2013140;//double,˫���ȸ�������
	printf("hmh = %lf\n", hmh);//����˫���ȣ���׼��Ӧ��ʹ��%lf����%fҲ����,���Ǳ��õĺ�
	printf("char = %d\n", sizeof(char));//1
	printf("short = %d\n", sizeof(short));//2
	printf("int = %d\n", sizeof(int));//4
	printf("long = %d\n", sizeof(long));//4
	printf("long long = %d\n", sizeof(long long));//8
	printf("float = %d\n", sizeof(float));//4
	printf("double = %d\n", sizeof(double));//8
	//sizeof,������ʾ��С�����������Ϊ�������͵��ֽ�
	//�����ֽڣ�
	//bit ����λ   byte�ֽ�   kb   mb   gb   tb   pb   ...
	// 1bite=8bit   1kb=1024bite   ������1024����
	//��Դ�ڼ����Ӳ��ͨ�������źţ�0�����磩��1�����磩������һ�������ź�ʹ��1bit
	// ʮ���������ö����Ʊ�ʾҲ��һһ��Ӧ�ģ�����4��Ӧ11����Ҫ��������λ��6��Ӧ101����Ҫ��������λ
	//����int��long����4�ֽڣ�����4*8=32����λ���ܱ�ʾ0��2^32=4294967296������short�������ֽڣ�2*8=16����λ���ܱ�ʾ0��65536����
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//��������C�����У�int,float,char�ȵȶ��Ƕ������
	//��ʽ�ǣ���������_������_=_����;
	//������Ϊ�ֲ���������ȫ�ֱ������������´���
//#include <stdio.h>
//int zzj = 262610;��ȫ�ֱ������������ڴ����֮�⣬��main֮�⣩
//int main()
//{
	//int hmh = 081308;���ֲ��������������ڴ����{}֮�ڣ�
	//return 0;
//}
	//ע�⣬���ֲ�������ȫ�ֱ���ͬ��ʱ����������ֲ����������ǽ���ֲ�������ȫ�ֱ������ֲ�Ҫ��ͬ�����bug
	//�ֲ������ġ��ֲ������֣�
//#includ <stdio.h>
//int main()
//{
   //{
   //int zzj = 262610;���ѱ�������һ���������������棩
   //}
   //printf("%d\n",zzj);(��ӡ����λ�������⣩
   //return 0;
//}
   //��ʱ��Ĵ����޷����У�����ľֲ�������zzj��������ġ��ֲ������޷�������ġ�printf�����
//������������
	{	
	int zzj = 3;
	int hmh = 5;
	scanf_s("%d%d", &zzj, &hmh);//scanf_s���������������ǽ������Ѿ���ֵ�ı���zzj��hmh��Ӧ���������棩&��ȡ��ַ����,�ƺ�ֻ������ʱʹ��
	int yyl = zzj + hmh;
	printf("yyl = %d\n", yyl);//�涨����������������Ϊ���������Ϊǰ�����������Ϊ�Ա����������������á�printf�������ǰ���yyl = ���Բ���,������ʹ�ã����ñȽ����
	//�����Ѹ�ֵ���Ա����������к󣬰��գ��Ա���1_�Ա���2 enter���ո�ֵ��������
	//���Բ��ø��Ա�����ֵ��������ֵ���������к��գ�ֵ1_ֵ2 enter���Ա�����ֵ����������
	}//��һ��Ҫ�ڼ�һ�������ţ�������������printfʱ���к��޷�������������
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�����򣺳���������õĲ���
//#incude <stdio.h>
//int main()
//{
//	{
//		int zzj = 262610; ������zzj��������λ����������
//	}
//	printf("zzj = %d\n", zzj);�������λ��������֮�⣬�޷����
//	return 0;
//}
//#incude <stdio.h>
//int main()
// {
// 	   int zzj = 262610; ����������������һ����������֮�ڣ������������
//     {
//	printf("zzj = %d\n", zzj);
//	return 0;
// 	   }
//}
//��ȫ�ֱ���λ��main������֮�⣬���������������������������ڶ�����ʹ�ã�������Դ�ļ���������Ŀ��Ҳ���ã�ֻ����Ҫ��int��char��float֮����������������ʹ�á�exturn������
//��ʽ��extern int (�������� = ��ֵ��;Ȼ��Ϳ�������
//�������ڣ������Ӵ�����ʼ�����ٽ�����ȫ�ֱ����������������������򣬾ֲ��������������ھֲ�������֮��
	return 0;//��������0
}//�������ڴ˽���