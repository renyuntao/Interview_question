#include<iostream>
using std::cout;
using std::endl;

int fibonacci_iter(unsigned int n)
{
	if(n <= 0)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		int first = 0;
		int second = 1;
		int tmp;
		for(int i = n - 2;i >= 0;--i)
		{
			tmp = first + second;
			first = second;
			second = tmp;
		}
		return tmp;
	}
}


int main()
{
	cout<<fibonacci_iter(10)<<endl;
	return 0;
}
