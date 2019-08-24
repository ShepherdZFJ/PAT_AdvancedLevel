/*
 * @Author: MeiYing 
 * @Date: 2019-07-21 21:46:56 
 * @Last Modified by:   MeiYing 
 * @Last Modified time: 2019-07-21 21:46:56 
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,count=0;
    int min_len=300;
    string str;
    string temp;
    string s;
    bool flag=false;
    vector<string>v;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        getline(cin,str);
        reverse(str.begin(),str.end());
        v.push_back(str);
        if(str.length()<min_len) 
        {
            min_len=str.length();
            temp=str;
        }
        
    }
    for(int i=0;i<min_len;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[j][i]!=temp[i])
            {
                flag=true;
                break;
            }   
        }
        if(flag) break;
            count++;
        //printf("%c",temp[i]);
        s=s+temp[i];
    }
    if(count==0) printf("nai");
    else 
    {
        reverse(s.begin(),s.end());
        cout<<s;
    }
    return 0;
}