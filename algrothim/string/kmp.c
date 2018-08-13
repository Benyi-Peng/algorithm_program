//
//  kmp.c
//  algorithm
//
//  Created by oe on 2018/8/13.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "kmp.h"

int getNext(SqString p, int next[]) {
    int j = 0, k = -1;
    next[0] = -1;
    while (j < p.length - 1) {
        if (k == -1 || p.data[j] == p.data[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
    return 1;
}

// 所谓的改进版KMP算法，就是改进了获得next数组的方法
int getNext2(SqString p, int next[]) {
    int j = 0, k = -1;
    next[0] = -1;
    while (j < p.length - 1) {
        if (k == -1 || p.data[j] == p.data[k]) {
            j++;
            k++;
            // 改动在下面这行 
            next[j] = k;
        } else {
            k = next[k];
        }
    }
    return 1;
}

int kmpMatch(SqString s, SqString p) {
    int next[p.length];
    for (int i = 0; i < p.length; i++) {
        next[i] = 0;
    }
    
    getNext(p, next);
    
    int i = 0, j = 0;
    
    while (i < s.length && j < p.length) {
        if (j == -1 || s.data[i] == p.data[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    
    if (j == p.length) {
        return i - j + 1;
    } else {
        return -1;
    }
}
