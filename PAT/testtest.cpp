#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<map>
#include<cmath>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
   // vector<int> list1(n);
    //vector<int> list2(n);
    int list1[110],list2[110];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list2[i]);
    }

    int pos ;
    for (int i = 1; i < n; i++)
    {
        if (list2[i] < list2[i - 1])
        {
            pos = i;
            break;
        }
    }
    bool flag = true;
    for (int i = pos; i < n; i++)
    {
        if (list1[i] != list2[i])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        printf("Insertion Sort\n");
        sort(list2, list2+ pos + 1);
        for (int i = 0; i < n - 1; i++)
            printf("%d ", list2[i]);
        printf("%d\n", list2[n - 1]);
    }
    else
    {
        printf("Merge Sort\n");
        int interval = pos;
        for (int i = pos; i >= 1; i--)
        {
            flag = true;
            for (int j = 0; j * i < n; j++)
            {
                for (int u = i * j + 1; u < i * (j + 1) && u < n; u++)
                {
                    if (list2[u] < list2[u - 1])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag)
            {
                interval = i; 
                break;
            }
        }

        interval *= 2;
        for (int i = 0; i * interval < n; i++)
        {
            if((i + 1) * interval < n)
                sort(list2+ i * interval, list2 + (i + 1) * interval);
            else
                sort(list2 + i * interval, list2);
        }

        for (int i = 0; i < n - 1; i++)
            printf("%d ", list2[i]);
        printf("%d\n", list2[n - 1]);
    }
    return 0;
}