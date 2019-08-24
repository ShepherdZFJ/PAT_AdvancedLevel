#include<iostream>
#include<vector>
using namespace std;
vector <int> toConvert(int n,int b)
{
    vector<int>v;
    int m;
    while(n!=0)
    {
        m=n%b;
        n=n/b;
        v.push_back(m);
    }
    return v;   
}
bool isPalindromicNumber(vector<int>v)
{
    bool flag=true;
    for(int i=0;i<v.size()/2;i++)
    {
       if(v[i]!=v[v.size()-1-i])
       {
           flag=false;
           break;
       }
    }
    return flag;
}
int main()
{
    int n,b;
    bool flag;
    cin>>n>>b;
    vector<int>v;
    v=toConvert(n,b);
    // for(int i=0;i<v.size();i++)
    //  cout<<v[i]<<" ";
    flag=isPalindromicNumber(v);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(i!=0) cout<<v[i]<<" ";
        else cout<<v[i];
    }


    return 0;
}