#include<iostream>
using std::endl;
using std::cout;

int Fibonacci(unsigned int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
	cout<<Fibonacci(10)<<endl;
	return 0;
}
