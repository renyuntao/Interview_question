#include"queue2stack.h"

int main()
{
	MyStack<int> stack;
	stack.push(10);
	std::cout<<"length of stack:"<<stack.size()<<std::endl;
	std::cout<<"pop a element:"<<stack.pop()<<std::endl;
	std::cout<<"length of stack:"<<stack.size()<<std::endl;
	return 0;
}
