//
//  recursion_other.c
//  algorithm
//
//  Created by pbyi on 2018/9/4.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "recursion_other.h"

#include <string.h>

void knap(int i, int curW, int curV, int curRet[]);

//1. 高效求解 X的n次方 2logN
double expx(double x, int n) {
    if (n == 1)
        return x;
    else if (n % 2 == 0)
        return expx(x, n/2) * expx(x, n/2);
    else
        return x * expx(x, (n - 1)/2) * expx(x, (n - 1)/2);
}

// 2. 01背包问题
#define MaxN 20
int maxv = 0;
int maxw = 40000;
int ret[MaxN];

int W = 7; // limit weight
int N = 4; // limit kinds
int w[] = {5, 3, 2, 1};
int v[] = {4, 4, 3, 1};

void knap(int i, int curW, int curV, int curRet[]) {
    if (i >= N) {
        if (curW <= W && curV >= maxv) { // 判定条件太粗心，浪费了40分钟
            maxv = curV;
            maxw = curW;
            for (int j = 0; j < N; j++) {
                ret[j] = curRet[j];
            }
            for (int k = 0; k < MaxN; k++) {
                printf("%d ",curRet[k]);
            }
            printf("\n");
        }
    } else {
        curRet[i] = 1;
        knap(i + 1, curW + w[i], curV + v[i], curRet);
        curRet[i] = 0;
        knap(i + 1, curW, curV, curRet);
    }
}

void displayRet(int x[]) {
    for (int i = 0; i < N; i++) {
        if (x[i] == 1) {
            printf("%d 物品\n", i);
        }
    }
    printf("总重量: %d   总价值: %d\n", maxw, maxv);
}

void bag(void) {
    int temp[MaxN];
    int i;
    for (i = 0; i < MaxN; i++) {
        temp[i] = 0;
        ret[i] = 0;
    }
    
    knap(0, 0, 0, temp);
    displayRet(ret);
}
