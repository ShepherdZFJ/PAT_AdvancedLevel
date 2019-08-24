#include<iostream>
using namespace std;
void getDay(int d)
{
	switch(d)
    {
        case 1:printf("MON "); break;
        case 2:printf("TUE "); break;
        case 3:printf("WED "); break;
        case 4:printf("THU "); break;
        case 5:printf("FRI "); break;
        case 6:printf("SAT "); break;
        case 7:printf("SUN "); break;
        
    }
		
}
int main()
{
    int temp[3];
    int day,hour,min;
    int count=0;
    bool flag=false;
    char str1[100];
    char str2[100];
    char str3[100];
    char str4[100];
    scanf("%s",str1);
    scanf("%s",str2);
    scanf("%s",str3);
    scanf("%s",str4);
    for(int i=0;i<100;i++)
    {
        
        if(str1[i]==str2[i]) 
        {
           if(count==0 && str1[i]>='A' && str1[i]<='G'  )
           {
               temp[0]=str1[i]-'A'+1;
               count++; 
           }
           else 
           {
               if(count==1 && ((str3[i]>='A' &&str3[i]<='N')||(str3[i]>='0' &&str3[i]<='9')))
               {
               	if(str1[i]>='A' &&str1[i]<='N') temp[1]=str1[i]-'A'+10; 
               	else temp[1]=str1[i]-'0';
                    count++;
			    
			   }
               
           }
		   
        }
        if(count>1) break;
    }
    for(int j=0;j<100;j++)
    {
        if(str3[j]==str4[j]&&((str1[j]>='A' &&str1[j]<='Z') || (str1[j]>='a' &&str1[j]<='z')))
        {
            temp[2]=j;
            flag=true;
        }
        if(flag) break;
    }
   getDay(temp[0]);
   printf("%02d:",temp[1]);
   printf("%02d",temp[2]);





    return 0;
}


         