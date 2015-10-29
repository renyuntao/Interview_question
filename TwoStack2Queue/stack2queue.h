#ifndef STACK2QUEUE_H
#define STACK2QUEUE_H
#include<stack>
#include<cassert>

template<typename T>
class CQueue
{
	public:
		CQueue();
		~CQueue();

		void appendTail(const T& node);
		T deleteHead();
		int length()
		{
			return (stack1.size()+stack2.size());
		}
	private:
		std::stack<T> stack1;
		std::stack<T> stack2;
};

#include"stack2queue.tpp"
#endif
