//
//  main.c
//  PAT 1030B
//
//  Created by 王基 on 2018/9/12.
//  Copyright  2018年 wangji. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[MAXN];
    
    long N,p;
    scanf("%ld%ld",&N,&p);
    //if (N <=0 || p <= 0) exit(1);
    
    // input
    for (int i=0; i<N; i++) {
        scanf("%d",&a[i]);
    }
    
    // 递增排序
    sort(a, a+N);
    
    int maxCount = 0;
    long mp;
    int temp = 0;
    int i = 0;
    
    for (int k=0; k<N; k++) {
        // 从k～N选取完美数列，最大数目为N-k，若N - k <= maxCount，则没有继续选取的意义
        if (N - k <= maxCount || i == N) break;
        mp = a[k]*p;
        
        while (a[i] <= mp && i < N) {
            temp++;
            i++;
        }
        
        if (temp > maxCount) {
            maxCount = temp;
        }
        temp--;
    }
    
    printf("%d\n",maxCount);
    
    
    
    
    
    return 0;
}
