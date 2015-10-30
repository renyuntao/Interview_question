#include<stdio.h>

int numOf1(int num)
{
	unsigned int count = 0;
	int detect = 1;
	while(detect)
	{
		if(num & detect)
			++count;
		detect <<= 1;
	}
	return count;
}

int main()
{
	printf("%d\n",numOf1(15));
	return 0;
}
