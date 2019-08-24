/*
 * @Author: MeiYing 
 * @Date: 2019-07-23 15:10:39 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-07-24 21:21:14
 */
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
bool isPoc_number(string str)
{
    bool flag=false;
    string temp;
    temp=str;
    reverse(str.begin(),str.end());
    if(temp==str) flag=true;
    return flag;
}
string add(string str1,string str2)
{
    int a,b,sum,j;
    bool flag=false;
    for(int i=str2.length()-1;i>=0;i--)
    {

        a=str1[i]-'0';
        b=str2[i]-'0';
        if(flag) sum=a+b+1;
        else sum=a+b;
        if(sum<10)
        {
            str1[i]='0'+sum;
            flag=false;
        }
        else
        {
            flag=true;
            sum=sum-10;
            if(i==0)
            {
                str1[i]='0'+sum;
                str1="1"+str1;
            }
            else
            {
                str1[i]='0'+sum;
            }
            /* 
            {
                if(str1[i-1]!='9')
                {
                    str1[i-1]=str1[i-1]+1;
                    str1[i]='0'+sum;
                }
                else
                {
                    bool flag=true;
                    j=i;
                    str1[i]='0'+sum;
                    
                    while(flag)
                    {
                        str1[j-1]='0';
                        j--;
                        if(j==0)
                        {
                            flag=false;
                            if(str1[j]=='9')
                            {
                                str1[j]='0';
                                str1="1"+str1;
                            }
                            else
                            {
                                str1[j]=str1[j]+1;
                            }   
                        }
                        {
                            if(str1[j-1]!='9')
                            {
                                flag=false;
                                str1[j-1]=str1[j-1]+1;    
                            } 
                        }  
                    }
                }    
            } 
            */
        }  
    }
    return str1;
}
/* 
int get_digs(long long n)
{
    int a=0;
    while(n!=0)
    {
        //a=n%10;
        n=n/10;
        a++;
        
    }
    return a;
}
long long reserve_number(long long n)
{
    long long number=0;
    int a,x;
    x=get_digs(n);
    while(n!=0)
    {
        a=n%10;
        n=n/10;
        number+=a*pow(10,x-1);
        x--;
    }
    return number;
}
*/
int main()
{
    string str,temp;
    int k;
    int count=0;
    bool flag=false;
    cin>>str;
    cin>>k;
    while(!flag)
    {
        temp=str;
        flag=isPoc_number(str);
        if(!flag)
        {
            reverse(str.begin(),str.end());
            str=add(temp,str);
            count++;
        }
        
        if(count>=k) flag=true;
    }
    cout<<str<<endl;
    cout<<count;
    return 0;
}