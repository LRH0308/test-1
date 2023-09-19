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
	printf("    ��ӭʹ���������ϵͳ    \n");
	printf("============================\n");
	printf("       1.����               \n");
	printf("       2.����               \n");
	printf("       3.�ж�����ǿ�� ��F�� \n");
	printf("       4.�������� ��F��     \n");
	printf("       5.�˳�               \n");
	printf("============================\n");
	printf("��ѡ��");
}
int s_gets(char* input)
{
	printf("������Ҫ���ܵ����룺");
	scanf("%s", input);
	int num = 0; //��¼���������ָ���
	int low = 0; //��¼������Сд��ĸ����
	int upp = 0; //��¼�����д�д��ĸ����
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
		printf("���볤�ȳ���16λ��\n");
		return -1;
	}
	else if ((num + low + upp) != len)
	{
		printf("�������зǷ��ַ���\n");
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
	printf("���ܺ�����룺");
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
	printf("���ܺ�����룺");
	display(input);
	printf("\n");
}