#include"queue2stack.h"
#include<iostream>
#include<cassert>

template<typename T>
MyStack<T>::MyStack() {}
template<typename T>
MyStack<T>::~MyStack() {}

template<typename T>
int MyStack<T>::size()
{
	return (queue1.size()+queue2.size());
}

template<typename T>
void MyStack<T>::push(T val)
{
	if(queue1.empty() && queue2.empty())
	{
		queue1.push(val);
	}
	else if(queue1.empty())
	{
		queue2.push(val);
	}
	else
	{
		queue2.push(val);
	}
}

template<typename T>
T MyStack<T>::pop()
{
	assert(!queue1.empty() || !queue2.empty());
	if(queue1.empty())
	{
		while(queue2.size() != 1)
		{
			T tmp = queue2.front();
			queue2.pop();
			queue1.push(tmp);
		}
		T tmp = queue2.front();
		queue2.pop();
		return tmp;
	}
	else     //queue2 is empty
	{
		while(queue1.size() != 1)
		{
			T tmp = queue1.front();
			queue1.pop();
			queue2.push(tmp);
		}
		T tmp = queue1.front();
		queue1.pop();
		return tmp;
	}
}
