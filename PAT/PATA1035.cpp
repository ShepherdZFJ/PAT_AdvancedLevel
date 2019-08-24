#include<iostream>
#include<string>
#include<vector>
using namespace std;
class user
{
    public:
    string username;
    string password;
    void input();
};
void user::input()
{
    cin>>username>>password;
}
int main()
{
    int n;
    user u;
    vector<user>v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp=0;
        bool flag=false;
        u.input();
        for(int x=0;x<u.password.length();x++)
        {
            if(u.password[x]=='1' ||u.password[x]=='0' ||u.password[x]=='l' ||u.password[x]=='O') temp++;
            if(u.password[x]=='1') u.password[x]='@';
            if(u.password[x]=='0') u.password[x]='%';
            if(u.password[x]=='l') u.password[x]='L';
            if(u.password[x]=='O') u.password[x]='o';
        }
    if(temp>0) v.push_back(u);
    }
    if(v.size()==0)
    {
        if(n>1) cout<<"There are " <<n<<" accounts and no account is modified"<<endl;
        else cout<<"There is 1 account and no account is modified"<<endl;
    }
    else
    {
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].username<<" "<<v[i].password<<endl;
        }
    }
    
    return 0;
}