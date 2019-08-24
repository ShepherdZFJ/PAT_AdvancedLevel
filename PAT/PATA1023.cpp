/*
 * @Author: MeiYing 
 * @Date: 2019-07-25 19:19:36 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-07-25 19:40:20
 */
#include<iostream>
#include<string>
using namespace std;
string double_number(string str)
{
    int sum;
    bool flag=false;
    for(int i=str.length()-1;i>=0;i--)
    {
        if(flag) sum=(str[i]-'0')*2+1;
        else sum=(str[i]-'0')*2;
        if(sum<10)
        {
            str[i]='0'+sum;
            flag=false;
        }
        else
        {
            flag=true;
            sum=sum-10;
            if(i==0)
            {
                str[i]='0'+sum;
                str="1"+str;
            }
            else
            {
                str[i]='0'+sum;
            }   
        }
    }
    return str;
}
int main()
{
    string str;
    string temp;
    int x;
    bool flag=true;
    int hashtable1[10]={0};
    int hashtable2[10]={0};
    cin>>str;
    temp=double_number(str);
    for(int i=0;i<str.length();i++)
    {
        x=str[i]-'0';
        hashtable1[x]++;
    }
    for(int i=0;i<temp.length();i++)
    {
        x=temp[i]-'0';
        hashtable2[x]++;
    }
    for(int i=0;i<10;i++)
    {
        if(hashtable1[i]!=hashtable2[i])
        {
            flag=false;
            break;
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    cout<<temp;





    return 0;

}