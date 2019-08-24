#include<iostream>
#include<string>
#include<vector>
using namespace std;
void num_to_english(int x);
int main()
{
	//long long n;
	//scanf(%)
	string str;
	int sum=0;
	int temp;
	vector<int>v;
	//num_to_english(int x);
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		
		sum+=int(str[i])-48;
	}
	if(sum==0) cout<<"zero";
	else
	{
		while(sum!=0)
		{
			temp= sum%10;
			v.push_back(temp);
			sum=sum/10;
		}
	//for(int i=v.size()-1;i>=0;i--)
	//cout<<v[i]<<" "<<endl;
		for(int i=v.size()-1;i>=0;i--)
		{
			num_to_english(v[i]);
			if(i>0) cout<<" ";
		}
    }
	return 0;
}
void num_to_english(int x)
{
	string print;
	switch (x)
	{
		case 0 :cout<<"zero";break;
		case 1: cout<<"one";break;
		case 2: cout<<"two";break;
		case 3: cout<<"three";break;
		case 4: cout<<"four";break;
		case 5: cout<<"five";break;
		case 6: cout<<"six";break;
		case 7: cout<<"seven";break;
		case 8: cout<<"eight";break;
		case 9: cout<<"nine";break;
	}
}
