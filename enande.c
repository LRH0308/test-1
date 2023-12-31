// 密码管理系统
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define max 16
void interface();//界面
int s_gets(char* input);//密码输入，以及部分出错提示
void Display(char* input);//显示
void encryption();//加密
void decryption();//解密
int main()
{
	int choose;
	//利用循环while，进行多次交互
	//多选语句switch，完成功能选项
          //if-else和break，完成退出功能
	while (1)
	{
		interface();
		scanf("%d", &choose);
		if (1 > choose || choose > 5)
		{
			continue;
		}

		if (choose != 5)
		{
			switch (choose)
			{
			case 1:encryption();
				   break;
			case 2:decryption();
				   break;
			case 3:break;
			case 4:break;
			default:break;
			}
		}
		else
		{
			break;
		}
		
	}
	
	return 0;
}
//界面
void interface()
{
	printf("============================\n");
	printf("    欢迎使用密码管理系统    \n");
	printf("============================\n");
	printf("       1.加密               \n");
	printf("       2.解密               \n");
	printf("       3.判断密码强度 （F） \n");
	printf("       4.密码生成 （F）     \n");
	printf("       5.退出               \n");
	printf("============================\n");
	printf("请选择：");
}
//输入密码
//利用for循环语句和if语句，来对大小写字母和数字进行计数
//利用strlen函数和if语句，完成对密码长度、输入是否正确的判别
int s_gets(char* input)
{
	printf("请输入密码：");
	scanf("%s", input);
	int num = 0; //记录密码中数字个数
	int low = 0; //记录密码中小写字母个数
	int upp = 0; //记录密码中大写字母个数
	int len = strlen(input);
	for (int j = 0; j < len; j++)
	{
		if (48 <= input[j] && input[j] <= 57)  
			num++;
		if (97 <= input[j] && input[j] <= 122) 
			low++;
		if (65 <= input[j] && input[j] <= 90)  
			upp++;
	}
	if (len > 16)
	{
		printf("密码长度超过16位！\n");
		return -1;
	}
	else if ((num + low + upp) != len)
	{
		printf("密码中有非法字符！\n");
		return -1;
	}
	else
	{
		return 1;
	}
}
//加密
//利用s_gets函数和while，完成密码的正确输入
//该函数完成了：
//(1)将每个字符的ASCII码加上它在字符串中的位置(1开始)和偏移值3
//(2)将字符串的第一位和最后一位调换顺序
//(3)将字符串反转输出
void encryption()
{
	char input[50];
	int i;

	int n = s_gets(input);
	while ( n == -1)
	{
		n = s_gets(input);
	}

	for (i = 0;i < strlen(input);i++)
	{
		if (48 <= input[i] && input[i] <= 57)
		{
			input[i] = input[i] + (i + 1) + 3;
			if (input[i] > 57)
			{
				input[i] = input[i] - 8;
			}
		}
		if (97 <= input[i] && input[i] <= 122)
		{
			input[i] = input[i] + (i + 1) + 3;
			if (input[i] > 122)
			{
				input[i] = input[i] - 25;
			}
		}
		if (65 <= input[i] && input[i] <= 90)
		{
			input[i] = input[i] + (i + 1) + 3;
			if (input[i] > 90)
			{
				input[i] = input[i] - 25;
			}
		}
	}

	char o = input[0];
	input[0] = input[i-1];
	input[i-1] = o;
	
	printf("加密后的密码：");
	Display(input);
	printf("\n");
}
//解密
//利用s_gets函数和while，完成密码的正确输入
//该函数完成了：
//(1)将字符串的第一位和最后一位调换顺序
//(2)将每个字符的ASCII码减去它在字符串中的位置(1开始)和偏移值3
//(3)将字符串反转输出
void decryption()
{
	char input[50];
	int i;

	int n = s_gets(input);
	while (n == -1)
	{
		n = s_gets(input);
	}

	char o = input[0];
	input[0] = input[strlen(input) - 1];
	input[strlen(input) - 1] = o;

	for (i = 0;i < strlen(input);i++)
	{
		if (48 <= input[i] && input[i] <= 57)
		{
			input[i] = input[i] - (strlen(input) - i) - 3;
			if (input[i] < 48)
			{
				input[i] = input[i] + 8;
			}
		}
		if (97 <= input[i] && input[i] <= 122)
		{
			input[i] = input[i] - (strlen(input) - i) - 3;
			if (input[i] < 97)
			{
				input[i] = input[i] + 25;
			}
		}
		if (65 <= input[i] && input[i] <= 90)
		{
			input[i] = input[i] - (strlen(input) - i) - 3;
			if (input[i] < 65)
			{
				input[i] = input[i] + 25;
			}
		}
	}
	printf("解密后的密码：");
	Display(input);
	printf("\n");
}
//显示
//字符串逆转输出
void Display(char* input)
{
	for (int m = strlen(input) - 1;m >= 0;m--)
	{

		printf("%c", input[m]);
	}
}
