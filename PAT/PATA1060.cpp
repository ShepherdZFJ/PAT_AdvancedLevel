#include<iostream>
#include<string>
using namespace std;
int search(string str)
{
	int pos=-1;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!='0' && str[i]!='.')
		{
			pos=i;
			break;
		}
	}
	return pos;

}
int main()
{
	int n;
	int pos_str1,pos_str2; 
	int position_dot1,position_dot2;
	int exponent1,exponent2;
	string str1,str2;
	string sub_str1,sub_str2;
	string exp_str1,exp_str2;
	cin>>n;
	cin>>str1;
	cin>>str2;
	pos_str1=search(str1);
    pos_str2=search(str2);
	//sub_str1=str1.substr(0,n);
	//sub_str2=str2.substr(0,n);
	position_dot1=str1.find(".");
	position_dot2=str2.find(".");
	//exp_str1="0."+sub_str1+"*10^";
	//exp_str2="0."+sub_str2+"*10^";
	if(pos_str1!=0 && pos_str1>position_dot1 ) str1=str1.substr(pos_str1);
	if(pos_str2!=0 && pos_str2>position_dot2) str2=str2.substr(pos_str2);
	if(pos_str1!=-1)
	{
		if(position_dot1!=string::npos) 
		{
			if((position_dot1-pos_str1) >0 && (position_dot1-pos_str1) <n )
			{
				sub_str1=str1.substr(pos_str1,position_dot1-pos_str1);
				sub_str1=sub_str1+str1.substr(position_dot1+1,n-(position_dot1-pos_str1));
				exponent1=position_dot1-pos_str1;
			}
			else 
			{
				sub_str1=str1.substr(pos_str1,n);
				if(pos_str1>position_dot1) exponent1=-(pos_str1-position_dot1-1);
				else exponent1=position_dot1;
			}
		}
		else 
		{
			sub_str1=str1.substr(0,n);
			exponent1=str1.length();
		}
     }
	if(pos_str2!=-1) 
	{
			if(position_dot2!=string::npos) 
		{
			if((position_dot2-pos_str2) >0 && (position_dot2-pos_str2) <n )
			{
				sub_str2=str2.substr(pos_str2,position_dot2-pos_str2);
				sub_str2=sub_str2+str2.substr(position_dot2+1,n-(position_dot2-pos_str2));
				exponent2=position_dot2-pos_str2;
			}
			else 
			{
				sub_str2=str2.substr(pos_str2,n);
				if(pos_str2>position_dot2) exponent2=-(pos_str2-position_dot2-1);
				else exponent2=position_dot2;
			}
		}
		else 
		{
			sub_str2=str2.substr(0,n);
			exponent2=str2.length();
		}
	}
	
	exp_str1="0."+sub_str1+"*10^";
	exp_str2="0."+sub_str2+"*10^";
    if(pos_str1==-1&&pos_str2==-1)
	{
		cout<<"YES ";
		cout<<"0.";
		for(int i=0;i<n;i++)
		cout<<"0";
		cout<<"*10^0";
		//-pos_str1cout<<n;
	}
	else
	{
			if(sub_str1==sub_str2 && exponent1==exponent2) 
		{
			cout<<"YES ";
			cout<<exp_str1;
			cout<<exponent1;	
		}
		else 
		{
			cout<<"NO ";
			cout<<exp_str1;
			cout<<exponent1<<" ";
			cout<<exp_str2;
			cout<<exponent2;
		}	
	}	
	return 0;
}
 