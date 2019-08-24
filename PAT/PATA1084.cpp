/*
 * @Author: MeiYing 
 * @Date: 2019-08-05 14:21:16 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-08-05 14:51:24
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
    bool hashtable[1000]={false};
    bool hashtable1[1000]={false};
    string str_input,str_print;
    int value,pos;
    char c;
    cin>>str_input>>str_print;
    for(int i=0;i<str_print.length();i++)
    {
        value=str_print[i];
        hashtable[value]=true;
        if(value>=65 && value<=90) hashtable[value+32]=true;
        if(value>=97 && value <=122) hashtable[value-32]=true;
    }
    for(int i=0;i<str_input.length();i++)
    {
        value=str_input[i];
        if(! hashtable[value])
        {
            if(value>=97 && value<=122) 
            {
                c=str_input[i]-32;
                pos=c;
            }
            else
            {
                c=str_input[i];
                pos=value;
            }
            if(!hashtable1[pos])
            {
                hashtable1[pos]=true;
                cout<<c;
            }
            

        }
    }

    return 0;
}