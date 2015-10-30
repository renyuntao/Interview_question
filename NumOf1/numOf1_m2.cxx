#include<iostream>
using std::cout;
using std::endl;

int numOf1(int num)
{
	int detect = 1;
	int count = 0;
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
	cout<<numOf1(15)<<endl;
	return 0;
}
