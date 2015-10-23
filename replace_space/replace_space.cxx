#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(int argc,char **argv)
{
	char string[100] {0,};
	fgets(string,99,stdin);
	auto len = strlen(string);
	string[--len] = '\0';
	int space_num=0;
	for(auto e:string) if(e == ' ') {++space_num;}
	int first_p = len,second_p = len+space_num*2;
	cout<<"string:"<<string<<endl;
	while(first_p != second_p)
	{
		while(string[first_p] != ' ')
		{
			string[second_p--] = string[first_p--];
		}
		first_p--;
		string[second_p--] = '0';
		string[second_p--] = '2';
		string[second_p--] = '%';
	}
	cout<<"string:"<<string<<endl;
	return 0;
}
