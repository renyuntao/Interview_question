#include<iostream>
using std::cout;
using std::endl;

// n is size of arr
// m is maximum of number of zeroes allowed to flip
void flipZeroes(int arr[],int n,int m)
{
	// Count of zeroes in current window
	int zeroCount = 0;

	// Size of the widest window and left index
	int bestWindow = 0,bestL = 0;

	// Left and right indexes of current window
	int wL = 0, wR = 0;

	// While right boundary of current window doesn't cross
	// right end
	while(wR < n)
	{
		// If zero count of current window is less than m,
		// widen the window toward right
		if(zeroCount <= m)
		{
			if(arr[wR] == 0)
				++zeroCount;
			++wR;
		}

		// If zero count of current window is more than m,
		// reduce the window from left
		if(zeroCount > m)
		{
			if(arr[wL] == 0)
				--zeroCount;
			++wL;
		}

		// Update widest window if this window size if more
		if(wR - wL > bestWindow)
		{
			bestWindow = wR - wL;
			bestL = wL;
		}
	}

	// Print position of zeroes in the widest window
	for(int i = 0; i < bestWindow; ++i)
	{
		if(arr[bestL+i] == 0)
			cout<<bestL+i<<" ";
	}
	cout<<endl;
}

// Driver program
int main()
{
	int arr[] = {1,0,0,1,1,0,1,0,1,1,1};
	int m = 2;
	int n = sizeof(arr)/sizeof(arr[0]);
	flipZeroes(arr,n,m);
	return 0;
}
