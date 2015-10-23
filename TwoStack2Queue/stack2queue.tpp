#include"stack2queue.h"
#include<stack>
#include<cassert>

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

