#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
bool cmp(string a,string b)
{
    /*
    int x=0;
    bool flag=true;
    while(flag)
    {
        if(a[x] !=b[x])
        {
          flag=false;
          return a[x]<b[x];
        }
        else x=x+1;
    }
    
   string sub_a,sub_b;
   int number_a=0,number_b=0;
   if(a.length()>b.length())
   {
       sub_a=a.substr(0,b.length());
       if(sub_a==b)
       {
           for(int i=0;i<b.length();i++)
           {
               number_b+=b[i]-'0';
           }
           for(int i=b.length();i<b.length()*2;i++)
           {
               number_a+=a[i]-'0';
           }
           if(number_a<number_b) return true;
           else return false;
       }
       return strcmp(a.c_str(),b.c_str()) < 0;
   }
   else
   {
        if(a.length()<b.length())
   {
       sub_b=b.substr(0,a.length());
       if(sub_b==a)
       {
           for(int i=0;i<a.length();i++)
           {
               number_a+=a[i]-'0';
           }
           for(int i=a.length();i<a.length()*2;i++)
           {
               number_b+=b[i]-'0';
           }
           if(number_a<number_b) return true;
           else return false;
       }
       return strcmp(a.c_str(),b.c_str()) < 0;
   }
    return strcmp(a.c_str(),b.c_str()) < 0;
   }
   */
return a+b<b+a;
}
int main()
{
    int n;
    string str;
    vector<string>v;
    bool temp=true;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        v.push_back(str);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        if(temp)
        {
            bool flag=false;
            for(int j=0;j<v[i].length();j++)
            {
                if(v[i][j]!='0'|| flag) 
                {
                    flag=true;
                    cout<<v[i][j];
                }
            }
            if(flag) temp=false;
        }
        else cout<<v[i];
    }
     if(temp) cout<<"0";

    return 0;
}