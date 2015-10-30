#include<stdio.h>
#include<stdbool.h>

bool equal(double num1,double num2)
{
	if((num1-num2) < 0.0000001 && (num1-num2) > -0.0000001)	
		return true;
	else
		return false;
}

double myPow(double base,int exponent)
{
	printf("%lf   %d\n",base,exponent);
	if(equal(base,0.0))
		return 0.0;
	bool expIsNeg = false;
	if(exponent < 0)
	{
		expIsNeg = true;
		exponent = -exponent;
	}
	double res = 1.0;
	for(int i = 0;i < exponent;++i)
		res *= base;
	if(expIsNeg)
		res = 1.0/res;
	return res;
}

int main()
{
	double base;
	int exponent;
	scanf("%lf",&base);
	scanf("%d",&exponent);
	printf("%lf\n",myPow(base,exponent));
	return 0;
}

