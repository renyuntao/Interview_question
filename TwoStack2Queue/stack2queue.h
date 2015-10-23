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

template<typename T>
CQueue<T>::CQueue() {}
template<typename T>
CQueue<T>::~CQueue() {}

template<typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if(!stack2.empty())   //stack2 is not empty
	{
		T tmp = stack2.top();
		stack2.pop();
		return tmp;
	}
	else     //stack2 is empty
	{
		assert(!stack1.empty());
		while(!stack1.empty())
		{
			T tmp = stack1.top();
			stack1.pop();
			stack2.push(tmp);
		}
		T tmp = stack2.top();
		stack2.pop();
		return tmp;
	}
}
#endif
