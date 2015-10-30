#include<iostream>
using std::cout;
using std::endl;

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
	cout<<numOf1(15)<<endl;
	return 0;
}
