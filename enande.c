//not modified 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define max 16
void interface();
int s_gets(char* input);
void Display(char* input);
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
	printf("���������룺");
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
	
	printf("���ܺ�����룺");
	Display(input);
	printf("\n");
}
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
	printf("���ܺ�����룺");
	Display(input);
	printf("\n");
}
void Display(char* input)
{
	for (int m = strlen(input) - 1;m >= 0;m--)
	{

		printf("%c", input[m]);
	}
}
