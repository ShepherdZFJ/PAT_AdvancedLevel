/*
 * @Author: MeiYing 
 * @Date: 2019-07-13 13:19:35 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-07-21 22:14:05
 */
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include<string>
using namespace std;
//string earth[13]={" ","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
//string mar[13]={" ","tam","hel","maa","huh","tot","kes","hei","elo","syy","lok","mer","jou"};
int toNumber(string str)
{
    int number=0;
    int value;
    for(int i=str.length()-1;i>=0;i--)
    {
        value=str[i]-'0';
        number+=value*pow(10,str.length()-i-1);
    }
    return number;
}
void translate(string str,int value)
{
    map<int,string> m_earth,m_mar;
    map<int,string>::iterator it;
    m_earth[0]="tret";m_mar[0]="tret";
    m_earth[1]="jan";m_earth[2]="feb";m_earth[3]="mar";m_earth[4]="apr";
    m_earth[5]="may";m_earth[6]="jun";m_earth[7]="jly";m_earth[8]="aug";
    m_earth[9]="sep";m_earth[10]="oct";m_earth[11]="nov";m_earth[12]="dec";
    m_mar[1]="tam";m_mar[2]="hel";m_mar[3]="maa";m_mar[4]="huh";
    m_mar[5]="tou";m_mar[6]="kes";m_mar[7]="hei";m_mar[8]="elo";
    m_mar[9]="syy";m_mar[10]="lok";m_mar[11]="mer";m_mar[12]="jou";
    
    int number,a;
    int sum=0;
    if(value==2)
    {
        number=toNumber(str);
        if(number<=12)
        {
            cout<<m_earth[number]<<endl;
        }
        else
        {
            a=number%13;
            number=number/13;
            cout<<m_mar[number];
            if(a!=0)  cout<<" "<<m_earth[a];
            cout<<endl;
        }
    }
    else
    {
        if(str.find(" ")==string::npos)
        {
            for(it=m_mar.begin();it!=m_mar.end();it++)
            {
                if(it->second==str) 
                {
                    
                    sum=it->first*13;
                    cout<<sum<<endl;
                    break;
                }     
            }
            for(it=m_earth.begin();it!=m_earth.end();it++)
            {
                if(it->second==str) 
                {
                    sum+=it->first;
                    cout<<sum<<endl;
                    break;
                }     
            }
            
        }
        else 
        {
            int pos;
            int start=0;
            string str1,str2;
            pos=str.find(" ");
            str1=str.substr(start,pos);
            str2=str.substr(pos+1);
            for(it=m_mar.begin();it!=m_mar.end();it++)
            {
                if(it->second==str1) 
                {
                    sum=it->first*13;
                    break;
                }     
            }
            for(it=m_earth.begin();it!=m_earth.end();it++)
            {
                if(it->second==str2) 
                {
                    sum+=it->first;
                    cout<<sum<<endl;
                    break;
                }     
            }

        }
    }
}
int main()
{
    int n;
    string str;
    //string array_str[100];
    int value;
    map<string,int>m;
    map<string,int>::iterator it;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        getline(cin,str);
         //cout<<str<<endl;
        //array_str[i]=str;
        if(str[0]>=65)
        {
            value=1;
        }
        else
        {
            value=2;
        }
        if(str=="tret") cout<<"0"<<endl;
        else translate(str,value);
    }
    /* 
    for(it=m.begin();it!=m.end();it++)
    {
        string s;
        int value;
        s=it->first;
        value=it->second;
        translate(s,value);
    }
    */
    return 0;
}