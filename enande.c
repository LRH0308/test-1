//
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define max 16
void interface();
int s_gets(char* input);
void display(char* input);
void encryption();
void decryption();
int main()
{
	int choose;
	
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
int s_gets(char* input)
{
	printf("请输入要加密的密码：");
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
void display(char* input)
{
	printf("%s", input);
}
void encryption()
{
	char input[100];
	int n = s_gets(input);
	while ( n == -1)
	{
		n = s_gets(input);
	}
	for (int i = 0;i < 16;i++)
	{
		if (48 <= input[i] && input[i] <= 57)
		{
			input[i] = input[i] + 3;
			if (input[i] > 57)
			{
				input[i] = input[i] - 8;
			}
		}
		if (97 <= input[i] && input[i] <= 122)
		{
			input[i] = input[i] + 3;
			if (input[i] > 122)
			{
				input[i] = input[i] - 25;
			}
		}
		if (65 <= input[i] && input[i] <= 90)
		{
			input[i] = input[i] + 3;
			if (input[i] > 90)
			{
				input[i] = input[i] - 25;
			}
		}
	}
	printf("加密后的密码：");
	display(input);
	printf("\n");
}
void decryption()
{
	char input[100];
	int n = s_gets(input);
	while (n == -1)
	{
		n = s_gets(input);
	}
	for (int i = 0;i < 16;i++)
	{
		if (48 <= input[i] && input[i] <= 57)
		{
			input[i] = input[i] - 3;
			if (input[i] < 48)
			{
				input[i] = input[i] + 8;
			}
		}
		if (97 <= input[i] && input[i] <= 122)
		{
			input[i] = input[i] - 3;
			if (input[i] < 97)
			{
				input[i] = input[i] + 25;
			}
		}
		if (65 <= input[i] && input[i] <= 90)
		{
			input[i] = input[i] - 3;
			if (input[i] < 65)
			{
				input[i] = input[i] + 25;
			}
		}
	}
	printf("解密后的密码：");
	display(input);
	printf("\n");
}