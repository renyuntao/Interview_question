#include<stdio.h>

int numOf1(int n)
{
	int count = 0;
	while(n)
	{
		n = n & (n-1);
		++count;
	}
	return count;
}

int main()
{
	printf("%d\n",numOf1(15));
	return 0;
}
