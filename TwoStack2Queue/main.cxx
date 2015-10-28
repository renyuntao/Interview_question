#include"stack2queue.h"
#include<iostream>
using std::endl;
using std::cout;

int main()
{
	CQueue<int> queue;
	queue.appendTail(5);
	cout<<"queue size:"<<queue.length()<<endl;
	queue.deleteHead();
	cout<<"queue size:"<<queue.length()<<endl;
	return 0;
}
