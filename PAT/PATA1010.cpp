#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
long long toNumber(string str,long long radix)
{
    long long m=0;
    int temp;
	int exp=0;
    for(int i=str.length()-1;i>=0;i--)
    {
        
        if(str[i]>='a'&&str[i]<='z')  temp=10+str[i]-97;
        else temp=str[i]-'0';
        m+=temp*pow(radix,exp);
        exp++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    }
    return m;
}
int to_findMAX(string str)
{
    int MAX=0;
    for(int i=str.length()-1;i>=0;i--)
    {
        int temp;
        if(str[i]>='a'&&str[i]<='z')  temp=10+str[i]-97;
        else temp=str[i]-'0';
        if(temp>MAX) MAX=temp;
    }
    return MAX;
}
int main()
{
    string n1,n2;
    string str;
    long long tag,radix;
    long long tag_number;
    int ans;
    long long  low,high;
    
    bool flag=false;
    //scanf("%d%d%d%d",&n1,&n2,&tag,&radix);
    cin>>n1>>n2;
    cin>>tag>>radix;
    if(tag==1)
    {
        tag_number=toNumber(n1,radix);
        str=n2;

    } 
    else
    {
        tag_number=toNumber(n2,radix);
        str=n1;
    }
     low=to_findMAX(str)+1;
     high=max(low,tag_number)+1;
     /* 
    for(int i=a+1;i<b+1;i++)
    {
        if(tag_number==toNumber(str,i))
        {
            flag=true;
            ans=i;
            break;
        }
        if(tag_number<toNumber(str,i)) break;
    }
    */
   while(low<=high)
   {
       long long mid;
       mid=(low+high)/2;
       if(toNumber(str,mid)==tag_number)
       {
           flag=true;
            ans=mid;
            break;
       }
       else if((toNumber(str,mid)>tag_number)||toNumber(str,mid)<0)
       {
           high=mid-1;
       }
       else
       {
           low=mid+1;
       }
       
   }
    if(flag) cout<<ans<<endl;
    else cout<<"Impossible"<<endl;

    return 0;
}