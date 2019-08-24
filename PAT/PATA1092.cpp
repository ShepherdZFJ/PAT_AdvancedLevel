/*
 * @Author: MeiYing 
 * @Date: 2019-07-26 10:15:30 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-07-26 10:33:14
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int hashtable[200]={0};
    bool hashtable1[200]={false};
    string str;
    string s;
    int x;
    int count=0;
    bool flag=true;
    cin>>str>>s;
    for(int i=0;i<str.length();i++)
    {
        x=str[i];
        hashtable[x]++;
        hashtable1[x]=true;
    }
    for(int i=0;i<s.length();i++)
    {
        x=s[i];
        if(hashtable1[x])
        {
            hashtable[x]--;
            if(hashtable[x]==0) hashtable1[x]=false;
        }
        else
        {
            flag=false;
            count++;
        }   
    }
    if(flag)
    {
        cout<<"Yes"<<" "<<str.length()-s.length();
    }
    else
    {
        cout<<"No"<<" "<<count;
    }
    




    return 0;
}