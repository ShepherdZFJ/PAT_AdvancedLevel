#include<iostream>
#include<string>
const int MAX=100010;
using namespace std;
int main()
{
	string str;
	int count_P=0,count_T=0,sum_PAT;
	int array_left_P[MAX],array_right_T[MAX];
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='P') count_P++;
		array_left_P[i]=count_P;
	}
	for(int i=str.length()-1;i>=0;i--)
	{
		if(str[i]=='T') count_T++;
		array_right_T[i]=count_T;
	}
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='A') sum_PAT=sum_PAT+array_left_P[i]*array_right_T[i];
	}
	sum_PAT=sum_PAT%1000000007;
	cout<<sum_PAT<<endl;
	return 0;
}
