#include<iostream>
using std::cout;
using std::endl;

bool equal(double num1,double num2)
{
	if((num1-num2) < 0.0000001 && (num1-num2) > -0.0000001)
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
		expIsNeg = true;
		exponent = -exponent;
	}
	double res = 1.0;
	for(int i = 0;i < exponent;++i)
		res *= base;
	if(expIsNeg)
		res = 1.0 / res;
	return res;
}

int main()
{
	double base;
	int exponent;
	std::cin>>base>>exponent;
	cout<<myPow(base,exponent)<<endl;;
	return 0;
}
