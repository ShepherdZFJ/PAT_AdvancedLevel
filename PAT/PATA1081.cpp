/*
 * @Author: MeiYing 
 * @Date: 2019-08-01 10:15:30 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-08-01 13:52:24
 */
#include<iostream>
#include<algorithm>
using namespace std;
long long get_MaxGys(long long m,long long n)
{
    long long temp;
    if(m<n) swap(m,n);
    while(n!=0)
    {
        temp=m%n;
        m=n;
        n=temp;
    }
    return m;
}
long long get_MinGbs(long long m,long long n)
{
    long long sum,temp;
    sum=m*n;
    temp=get_MaxGys(m,n);
    return sum/temp;
}
int main()
{
    int n;
    long long a,b,x,y,value,number,ans;
    char c;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%c%lld",&a,&c,&b);
        if(i==0)
        {
            x=a;
            y=b;
        }
        else
        {
            value=get_MinGbs(y,b);
            x=x*(value/y)+a*(value/b);
            y=value;
        }
    }
    number=get_MaxGys(x,y);
    if(number!=1)
    {
        x=x/number;
        y=y/number;
    }
    if(x/y>0)
    {
        ans=x/y;
        x=x-ans*y;
        if(x==0) printf("%lld",ans);
        else printf("%lld %lld/%lld",ans,x,y);
    }
    else
    {
        if(x==0) printf("0");
        else printf("%lld/%lld",x,y);
    }
    
    return 0;
}