#include<iostream>
#include<string>
using namespace std;
const int MAX=100010;
bool hashtable[MAX]={false};
int main()
{
	string str_error;
	string str_input;
	int temp;
	int m;
	bool flag=false;
	bool sign=true;
	cin>>str_error>>str_input;
	for(int i=0;i<str_error.length();i++)
	{
	
	temp=int(str_error[i]);
	hashtable[temp]=true;
	if(temp>=65 && temp<=90) hashtable[temp+32]=true;
	if(temp>=97 && temp<=122) hashtable[temp-32]=true;
	if (temp==43) flag=true; 
	//cout<<hashtable[temp]<<endl;
   }
  //cout<<endl;
	for(int i=0;i<str_input.length();i++)
	{
		m=int(str_input[i]);
	//	cout<<hashtable[m]<<endl;
		if(flag)
		{
			if((m<65 || m>90) && ! hashtable[m])
			{
			  if(i<str_input.length()-1) cout<<str_input[i];
			  else	cout<<str_input[i]<<endl;
			  sign=false;
			}
				
		}
		else
		{
				if(! hashtable[m])
			{
			  if(i<str_input.length()-1) cout<<str_input[i];
			  else	cout<<str_input[i]<<endl;
			  sign=false;
			}
		}
	//	cout<<m<<endl;
	}
	//cout<<str_error<<" "<<str_input<<endl;
	if(sign) cout<<endl;
	return 0;
}
