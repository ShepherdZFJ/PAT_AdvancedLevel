#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    int n,m;
    stack<int>st,s;
    vector<int>v;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        getline(cin,str);
        //cin>>str;
        m=str.length();
        int number=0;
        if(m>3 && str[4]==' ')
        {
            for(int i=5;i<m;i++)
            {
                number+=str[i]-'0';
            }
           st.push(number);  
        }
        else
        {
            if(m<=3)
            {
                if(st.empty()) printf("invalid\n");
                else 
                {
                    printf("%d\n",st.top());
                    st.pop();
                }
            }
            else
            {
                s=st;
                if(s.empty()) printf("invalid\n");
                else
                {
                	while(!s.empty())
                    {
                    v.push_back(s.top());
                    s.pop();

                    }
                    if(v.size()%2==0) printf("%d\n",min(v[v.size()/2-1],v[v.size()/2]));
                    else printf("%d\n",v[v.size()/2]);
                    v.clear();
				}
                
            }
            
        }
        
    }



    return 0;
}