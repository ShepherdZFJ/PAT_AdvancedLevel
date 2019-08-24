/*
 * @Author: MeiYing 
 * @Date: 2019-07-30 14:30:27 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-07-30 14:39:41
 */
#include<iostream>
using namespace std;
const int MAX=100010;
int main()
{
    double sum[MAX];
    int n;
    double temp;
    double ans=0;
    double number;
    double value=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&number);
        value+=number;
        sum[i]=value;
        ans+=value;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            temp=sum[j]-sum[i];
            ans+=temp;
        }
    }
    printf("%.2lf",ans);




    return 0;
}