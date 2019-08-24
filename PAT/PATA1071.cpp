#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int a=0;
    bool space=true;
	map<string,int>m;
    string str,word;
    int start,end;
    getline(cin,str);
    while(space)
    {
        if(str[a]!=' ') space=false;
        else a++;
    }
    start=a;
    end=str.length();
    int max=0;
    string temp;
    while(start<=end)
    {
        int pos;
        bool flag=true;
        bool flag1=true;
        bool flag2=true;
        pos=str.find(' ',start);
        if(pos==string::npos) pos=end;
        word=str.substr(start,pos-start);
        int x=0;
        while(flag1)
        {
        	if((word[x]>='a'&&word[x]<='z')||(word[x]>='A'&&word[x]<='Z')||(word[x]>='0'&&word[x]<='9')) flag1=false;
        	else x++;
            
		}
        word=word.substr(x);
        int p;
        p=word.length()-1;
        while(flag2)
        {
        	if((word[p]>='a'&&word[p]<='z')||(word[p]>='A'&&word[p]<='Z')||(word[p]>='0'&&word[p]<='9')) flag2=false;
        	else p--;
            
		}
       
        word=word.substr(0,p+1);
        

        while(flag)
        {
            if((str[pos+1]>='a'&&str[pos+1]<='z')||(str[pos+1]>='A'&&str[pos+1]<='Z')||(str[pos+1]>='0'&&str[pos+1]<='9'))
            {
            	flag=false;
			}
			else pos++;
        }
        start=pos+1;
        //if((word[0]>='A'&&word[0]<='Z') && !(word[1]>='A'&&word[1]<='Z')) word[0]=word[0]+32;
        for(int i=0;i<word.length();i++)
        {
        	if(word[i]>='A'&&word[i]<='Z') word[i]=word[i]+32;
		}
        if(m.count(word)>0) m[word]++;
        else m[word]=1;
        if(m[word]>max) 
        {
        	max=m[word];
        	temp=word;
		}
		else if(m[word]==max)
		{
			if(word<temp) temp=word;
		}
		
      


    }
    cout<<temp<<" "<<max<<endl;



    return 0;

}