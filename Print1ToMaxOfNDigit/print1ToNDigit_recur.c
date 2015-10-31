#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void Print(char *num)
{
	bool startPrint = false;
	size_t length = strlen(num);
	for(int i = 0;i < length;++i)
	{
		if(!startPrint && num[i] != '0')
			startPrint = true;
		if(startPrint)
			printf("%c",num[i]);
	}
	printf("  ");
}

void Print1ToMaxOfNDigit_r(char *num,int length,int index)
{
	if(index == length-1)
	{
		Print(num);
		return;
	}

	for(int i = 0;i < 10;++i)
	{
		num[index+1] = i + '0';
		Print1ToMaxOfNDigit_r(num,length,index+1);
	}
}

void Print1ToMaxOfNDigit(int n)
{
	if(n <= 0)
		return;
	char *number = malloc(sizeof(char)*n+1);
	number[n] = '\0';

	for(int i = 0;i < 10;++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigit_r(number,n,0);
	}
	free(number);
}

int main()
{
	int n;
	scanf("%d",&n);
	Print1ToMaxOfNDigit(n);
	printf("\n");
	return 0;
}
