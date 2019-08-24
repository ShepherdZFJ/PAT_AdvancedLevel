#include<iostream>
#include<string>
using namespace std;
const int MAX=100000;
bool hashtable[MAX]={false};
int main()
{
    string str1,str2;
    getline(cin,str1);
     getline(cin,str2);
    for(int i=0;i<str2.length();i++)
    {
        int pos;
        pos= int(str2[i]);
        hashtable[pos]=true;
    }
    for(int i=0;i<str1.length();i++)
    {
        if(!hashtable[int(str1[i])]) cout<<str1[i];
    }


    return 0;
}