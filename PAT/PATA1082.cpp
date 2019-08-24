/*
 * @Author: MeiYing 
 * @Date: 2019-08-03 13:50:50 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-08-03 15:50:15
 */
#include<iostream>
#include<string>
using namespace std;
void translate(int n)
{
    switch (n)
    {
        case 1:cout<<"yi";break;
        case 2:cout<<"er";break;
        case 3:cout<<"san";break;
        case 4:cout<<"si";break;
        case 5:cout<<"wu";break;
        case 6:cout<<"liu";break;
        case 7:cout<<"qi";break;
        case 8:cout<<"ba";break;
        case 9:cout<<"jiu";break;
    }
}
void print_unit(int m)
{
    switch(m)
    {
        case 4: cout<<"Qian";break;
        case 3: cout<<"Bai";break;
        case 2: cout<<"Shi";break;
    }
}
int main()
{
    string str,str1,str2,str3;
    char c;
    int len;
    int value;
    int x;
    int temp;
    cin>>str;
    len=str.length();
    if(str[0]=='-')
    {
        str=str.substr(1);
        len=len-1;
        cout<<"Fu ";

    }
    temp=str.find('0');
    if(temp==0)
    {
        cout<<"ling";
        return 0;
    }
    if(len>8)
    {
         bool flag=false;
        str1=str.substr(len-4,4);
        str2=str.substr(len-8,4);
        c=str[0];
        value=c-'0';
        translate(value);
        if(str1=="0000" && str2=="0000")
        {
            cout<<" Yi";
            return 0;
        } 
        else cout<<" Yi ";
        x=4;
        if(str2!="0000")
        {
            for(int i=0;i<str2.length();i++)
            {
                value=str2[i]-'0';
                if(value!=0)
                {
                    translate(value);
                    cout<<" ";
                    if(i==str2.length()-1 )
                    {
                        if(str1=="0000") cout<<"Wan";
                        else cout<<"Wan ";
                    }
                    else
                    {
                        print_unit(x);
                        cout<<" ";
                    }     
            }
                else
                {
                    if(i<str2.length()-1 && str2[i+1]!='0')
                    {
                        cout<<"ling";
                        cout<<" ";
                    }
                    else
                    {
                        if(i==str2.length()-1)
                        {
                            if(str1=="0000")
                            {
                                cout<<"Wan";
                            }
                            else
                            {
                                cout<<"Wan ";
                                cout<<"ling ";
                                flag=true;
                            }
                        }
                        
                    }
                }
            x--;
            }
        }
        x=4;
        int p1;
        for(int i=0;i<str1.length();i++)
        {
            value=str1[i]-'0';
            if(value!=0)
            {
                translate(value);
                flag=false;
                if(i<str1.length()-1) cout<<" ";
                if(i==str1.length()-1) continue;
                else
                {
                    p1=i+1;
                    print_unit(x);
                    while(p1<4)
                    {
                        if(str1[p1]!='0')
                        {
                            cout<<" ";
                            break;
                        }
                        else
                        {
                            p1++;
                        }
                        
                    }
                }     
            }
            else
            {
                if(i<str1.length()-1 && str1[i+1]!='0')
                {
                    if(flag) 
                    {
                        x--;
                        continue;
                    }
                    cout<<"ling";
                    cout<<" ";
                }
                
            }
        x--;
        }
    }
    else
    {
        if(len>4)
        {
            bool flag1=false;
            str1=str.substr(len-4,4);
            str2=str.substr(0,len-4);
            x=str2.length();
            for(int i=0;i<str2.length();i++)
            {
                value=str2[i]-'0';
                if(value!=0)
                {
                    translate(value);
                    cout<<" ";
                    if(i==str2.length()-1) cout<<"Wan ";
                    else
                    {
                        print_unit(x);
                        cout<<" ";
                    }     
                }
                else
                {
                    if(i<str2.length()-1 && str2[i+1]!='0')
                    {
                        cout<<"ling";
                        cout<<" ";
                    }
                    else
                    {
                        if(i==str2.length()-1)
                        {
                            if(str1=="0000")
                            {
                                cout<<"Wan";
                            }
                            else
                            {
                                flag1=true;
                                cout<<"Wan ";
                                cout<<"ling ";
                            }
                            
                            
                        }

                    }
                }
            x--;
            }
            x=4;
            int p2;
            for(int i=0;i<str1.length();i++)
            {
                value=str1[i]-'0';
                if(value!=0)
                {
                    translate(value);
                    flag1=false;
                    if(i<str1.length()-1) cout<<" ";
                    if(i==str1.length()-1) continue;
                    else
                    {
                        p2=i+1;
                        print_unit(x);
                        while(p2<4)
                        {
                            if(str1[p2]!='0')
                            {
                                cout<<" ";
                                break;
                            }
                            else
                            {
                                p2++;
                            }
                            
                        }
                    }     
                }
                else
                {
                    if(i<str1.length()-1 && str1[i+1]!='0')
                    {
                        if(flag1) 
                        {
                            x--;
                            continue;
                        }
                        cout<<"ling";
                        cout<<" ";
                    }
                    
                }
            x--;
            }
            
        }
        else
        {
            x=len;
            int pos;
            for(int i=0;i<str.length();i++)
            {
                value=str[i]-'0';
                if(value!=0)
                {
                    pos=i+1;
                    translate(value);
                    if(i<str.length()-1) cout<<" ";
                    if(i==str.length()-1) continue;
                    else
                    {
                        print_unit(x);
                        while(pos<len)
                        {
                            if(str[pos]!='0')
                            {
                                cout<<" ";
                                break;
                            }
                            else
                            {
                                pos++;
                            }
                            
                        }
                    }     
                }
                else
                {
                    if(i<str.length()-1 && str[i+1]!='0')
                    {
                        cout<<"ling";
                        cout<<" ";
                    }
                    
                }
            x--;
            }
        }
        

    }
  //  cout<<"over";
    
     


    return 0;
}