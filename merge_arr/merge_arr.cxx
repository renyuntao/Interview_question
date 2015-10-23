#include<iostream>
using namespace std;
void merge_arr(int arr1[],int arr1_len,int arr2[],int arr2_len)
{
	int len1 = arr1_len;
	int len2 = arr2_len;
	int a,b,p;
	p = (len1-1) + len2;
	while(len1 != 0 && len2 != 0)
	{
		a = arr1[len1-1];
		b = arr2[len2-1];
		if(a >= b)
		{
			arr1[p--] = a;
			--len1;
		}
		else
		{
			arr1[p--] = b;
			--len2;
		}
	}
	if(len1 != 0)
		for(int i = len1;i > 0;--i) arr1[p--] = arr1[i-1];
	else
		for(int i = len2;i > 0;--i) arr1[p--] = arr2[i-1];
}
/*************** Example ***************/
int main(int argc,char **argv)
{
	int arr1[10] {-1,1,5,7};
	int arr2[] {-2,0,2,4,6};
	merge_arr(arr1,4,arr2,5);
	for(auto e:arr1)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}	
