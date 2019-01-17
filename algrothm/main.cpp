//
//  main.c
//  algorithm
//
//  Created by pbyi on 2018/6/10.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "linkedList/linkedlist.h"
#include "solution1_100.h"

void kmpSample(void);


int main(int argc, const char * argv[]) {
    
//    int x[4] = {2,7,11,15};
//    int *ret;
//    ret = twoSum(x, 4, 9);
//    for (int i = 0; i < 2; i++) {
//        printf("%d ", ret[i]);
//    }
//    free(ret);
    LinkNode *l1;
    InitList(l1);
    int a1[] = {2, 4, 3};
    CreateListR(l1, a1, 3);
    
    LinkNode *l2;
    InitList(l2);
    int a2[] = {4, 5, 6};
    CreateListR(l2, a2, 3);
    
    DispList(l1);
    DispList(l2);
    
}








