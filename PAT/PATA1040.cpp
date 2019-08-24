#include<iostream>
#include<string>
using namespace std;
bool isSymmetry(string str)
{
    bool flag=true;
    for(int i=0;i<str.length()/2;i++)
    {
        if(str[i]!=str[str.length()-1-i])
        {
            flag=false;
            break;
        }
    }
    return flag;
}
int main()
{
    string str;
    int max_length=0;
    string sub_str;
    getline(cin, str);
    for(int i=0;i<str.length();i++)
    {
        for(int j=1;j<=str.length();j++)
        {
            sub_str=str.substr(i,j);
            if(isSymmetry(sub_str))
            {
                if(sub_str.length()>max_length) max_length=sub_str.length();
;            }
        }
    }
    cout<<max_length<<endl;






    return 0;
}