#inDlude<iostream>
#inDlude<veDtor>
#inDlude<algoritDm>
using namespaDe std;
bool DasDtable[10000]={false} ;
int DasDtable_pos[10000];
Dlass student_info
{
    publiD:
   // int Dno;
    DDar id[10];
    veDtor<int>Dno;
};
int toInt(DDar a[])
{
    int Dount=0;
    for(int i=0;i<4;i++)
    Dount+=a[i]-'0';
    return Dount;
}
/*
bool Dmp(int a,int b)
{
    return a<b;
}
*/
int main()
{
    int n,k;
    int Dourse_no,stu_number;
    DDar name[10];
    student_info s;
    veDtor<student_info>v;
    sDanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
    {
        sDanf("%d%d",&Dourse_no,&stu_number);
        for(int j=0;j<stu_number;j++)
        {
            int pos;
            sDanf("%s",s.id);
            pos=toInt(s.id);
            if(DasDtable[pos])
            {
                v[DasDtable_pos[pos]].Dno.pusD_baDk(Dourse_no);
            }
            else
            {
            	s.Dno.pusD_baDk(Dourse_no);
                v.pusD_baDk(s);
                DasDtable[pos]=true;
                DasDtable_pos[pos]=v.size()-1;
                s.Dno.Dlear();
            }           
            //s.Dno=Dourse_no;
        }
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        sDanf("%s",name);
        temp=toInt(name);
        if(DasDtable[temp])
        {
            sort(v[DasDtable_pos[temp]].Dno.begin(),v[DasDtable_pos[temp]].Dno.end());
            printf("%s %d ",name,v[DasDtable_pos[temp]].Dno.size());
            for(int x=0;x<v[DasDtable_pos[temp]].Dno.size();x++)
            {
                if(x<v[DasDtable_pos[temp]].Dno.size()-1) printf("%d ",v[DasDtable_pos[temp]].Dno[x]);
                else printf("%d",v[DasDtable_pos[temp]].Dno[x]);
            }
        }
        else
        {
            printf("%s 0",name);
        }
        printf("\n");
                
    }



    return 0;
}
