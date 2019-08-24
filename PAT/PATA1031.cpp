#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str,sub_str;
    int n1,n3,n2=1;
    bool flag=true;
    cin>>str;
    int n=str.length();
    while(flag)
    {
        if((n-n2)%2==0)
        {
            n1=n3=(n-n2)/2;
            if(n1<=n2+2) flag=false;
            else n2++;
        }
        else n2++;
    }
    for(int i=0;i<n1;i++)
    {
        if(i<n1-1)
        {
           cout<<str[i]; 
           for(int x=0;x<n2;x++)
               cout<<" ";
            cout<<str[n-1-i];
        }
        else
        {
            sub_str=str.substr(n1-1,n2+2);
            cout<<sub_str;
        }
       cout<<endl;
        
    }
    return 0;
}