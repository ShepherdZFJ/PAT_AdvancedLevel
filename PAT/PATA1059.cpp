#include<iostream>
#include<vector>
#include<math.h>
const int MAX=100010;
int hashtable[MAX]={0};
using namespace std;
bool isPrime(int n)
{
    int m;
    bool flag=true;
    m=sqrt(n);
    for(int i=2;i<=m;i++)
    {
    	if(n<=1) return false;
        if(n%i==0)
        {
            flag=false;
            break;
        }
    }
    return flag;
}
int main()
{
    long int n;
    int m;
    vector<int>v;
    scanf("%d",&n);
    m=sqrt(n);
    printf("%d=",n);
    if(isPrime(n)) printf("%d",n);
    else
    {
    	for(int i=2;i<=m;i++)
       {
            int exp=0;
            bool flag=true;
            while(n%i==0)
            {
                flag=false;
                n=n/i;
                exp++;
            }
            if(!flag && isPrime(i))
            {
                //if(exp>1) printf("%d^%d*",i,exp);
                // else printf("%d*",i);
                v.push_back(i);
                hashtable[v.size()-1]=exp;
            } 
       }
       for(int j=0;j<v.size();j++)
       {
            if(j<v.size()-1)
            {
                if(hashtable[j]>1) printf("%d^%d*",v[j],hashtable[j]);
                else printf("%d*",v[j]);	
            }
            else
            {
                if(hashtable[j]>1) printf("%d^%d",v[j],hashtable[j]);
                else printf("%d",v[j]);	
            }
			
		
	   }
	}
    



    return 0;
}