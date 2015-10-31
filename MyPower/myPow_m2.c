/*  Formule:

      ---- a^(n/2) * a^(n/2)    (n is even number)
a^n = |
	  |
	  ---- a^((n-1)/2) * a^((n-1)/2) * a     (n is odd number)

*/

#include<stdio.h>
#include<stdbool.h>

double myPow_u(double base,unsigned int exponent)
{
	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;
	double result = myPow_u(base,exponent >> 1);
	result *= result;
	if((exponent & 1) == 1)    //Odd number
		result *= base;
	return result;
}

bool equal(double num1,double num2)
{
	if((num1-num2) > -0.0000001 && (num1-num2) < 0.0000001)
		return true;
	else
		return false;
}

double myPow(double base,int exponent)
{
	if(equal(base,0.0))
		return 0.0;
	bool expIsNeg = false;
	if(exponent < 0)
	{
		exponent = -exponent;
		expIsNeg = true;
	}
	double result = myPow_u(base,exponent);
	if(expIsNeg)
		result = 1 / result;
	return result;
}

int main()
{
	double base;
	int exp;
	scanf("%lf %d",&base,&exp);
	printf("%lf\n",myPow(base,exp));
	return 0;
}
