//
//  main.c
//  PAT 1030B
//
//  Created by ���� on 2018/9/12.
//  Copyright  2018�� wangji. All rights reserved.
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
    
    // ��������
    sort(a, a+N);
    
    int maxCount = 0;
    long mp;
    int temp = 0;
    int i = 0;
    
    for (int k=0; k<N; k++) {
        // ��k��Nѡȡ�������У������ĿΪN-k����N - k <= maxCount����û�м���ѡȡ������
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
