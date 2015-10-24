#ifndef QUEUE2STACK_H
#define QUEUE2STACK_H
#include<queue>

template<typename T>
class MyStack
{
	public:
		MyStack();
		~MyStack();
		int size();
		void push(T val);
		T pop();
	private:
		std::queue<T> queue1;
		std::queue<T> queue2;
};

#include"queue2stack.tpp"
#endif
