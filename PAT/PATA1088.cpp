/*
 * @Author: MeiYing 
 * @Date: 2019-08-10 15:07:10 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-08-12 18:00:02
 */
#include<iostream>
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
void print(long long a2,long long b2)
{
    long long max_gys,value;
    if(b2<0)
    {
        b2=-b2;
        a2=-a2;
    }
    max_gys=get_MaxGys(a2,b2);
    if(max_gys<0) max_gys=-max_gys;
    a2=a2/max_gys;
    b2=b2/max_gys;
    value=a2/b2;
    a2=a2-value*b2;
    if(value!=0)
    {
        if(value<0) 
        {
            a2=-a2;
            printf("(%lld",value);
            if(a2!=0)
            {
                printf(" %lld/%lld)",a2,b2);
            }
            else
            {
                printf(")");
            }   
        }
        else
        {
            if(a2!=0) printf("%lld %lld/%lld",value,a2,b2);
            else printf("%lld",value);
        }
    }
    else
    {
        if(a2<0) printf("(%lld/%lld)",a2,b2);
        else 
        {
            if(a2!=0) printf("%lld/%lld",a2,b2);
            else printf("0");
        }
        
    }
    
        
    

}

int main()
{
    long long  a1,b1,a2,b2;
    long long ans_num1,ans_num2,ans_den,value,number;
    long long ans_num3, ans_num4, ans_den2,ans_den3;
    char c;
    scanf("%lld%c%lld %lld%c%lld",&a1,&c,&b1,&a2,&c,&b2);
    ans_den=get_MinGbs(b1,b2);
    ans_num1=a1*(ans_den/b1)+a2*(ans_den/b2); //加法
    ans_num2=a1*(ans_den/b1)-a2*(ans_den/b2); //减法
    print(a1,b1);
    printf(" + ");
    print(a2,b2);
    printf(" = ");
    print(ans_num1,ans_den);
    printf("\n");

    print(a1,b1);
    printf(" - ");
    print(a2,b2);
    printf(" = ");
    print(ans_num2,ans_den);
    printf("\n");

    print(a1,b1);
    printf(" * ");
    print(a2,b2);
    printf(" = ");
    print(a1*a2,b1*b2);
    printf("\n");

    print(a1,b1);
    printf(" / ");
    if(a2!=0)
    {
        print(a2,b2);
        printf(" = ");
        print(a1*b2,a2*b1);
    }
    else
    {
        printf("0 = Inf");
    }
    
    
   


    


    




    return 0;
}