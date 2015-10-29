#include<iostream>
#include<cassert>
using std::cout;
using std::endl;

template<typename T>
T findMin(T arr[],int length)
{
	assert(arr != NULL && length > 0);
	int ptr1 = 0;
	int ptr2 = length - 1;
	int middle = (ptr1+ptr2) / 2;
	while(ptr2 - ptr1 != 1)
	{
		if(arr[ptr1] == arr[middle] && arr[ptr1] == arr[ptr2])
		{
			int min = arr[ptr1];
			for(int i = ptr1+1;i <= ptr2;++i)
			{
				if(min > arr[i])  
					min = arr[i];
			}
			return min;
		}
		else if(arr[middle] >= arr[ptr1])    //at first range
		{
			ptr1 = middle;
		}
		else if(arr[middle] < arr[ptr2])   //at second range
		{
			ptr2 = middle;
		}
		middle = (ptr1+ptr2) / 2;
	}
	return arr[ptr2];
}

int main()
{
	int arr[] = {1,0,1,1,1};
	//char arr[] = {'c','d','e','f','g','g','a','b'};
	int length = sizeof(arr)/sizeof(arr[0]);
	cout<<findMin(arr,length)<<endl;
	return 0;
}
