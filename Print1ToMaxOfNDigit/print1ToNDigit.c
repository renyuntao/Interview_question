#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*
 * Add 1
 */
bool add1(char *num)
{
	bool overFlow = false;
	int carry = 0;    // Carry flag
	size_t length = strlen(num);

	for(int i = length-1;i >= 0;--i)
	{
		int sum = num[i] - '0' + carry;
		if(i == length-1)
			++sum;
		// Need carry
		if(sum >= 10)   
		{
			if(i == 0)
				overFlow = true;
			else
			{
				sum -= 10;
				carry = 1;
				num[i] = '0' + sum;
			}
		}
		else   // Don't need to carry
		{
			num[i] = '0' + sum;
			break;
		}
	}
	return overFlow;
}

/*
 * Print number
 */
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

/*
 *	 Print 1 to max of n-digit number
 *	 For solve big number problem,use array
 *	 to store number
 */
void Print1ToMaxOfNDigit(int n)
{
	if(n <= 0)
		return;
	char *number = (char*)malloc(sizeof(char)*n+1);
	memset(number,'0',n);
	number[n] = '\0';

	while(!add1(number))
	{
		Print(number);
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
