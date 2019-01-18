//
//  main.c
//  algorithm
//
//  Created by pbyi on 2018/6/10.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"
#include "solution1_100.h"


int main(int argc, const char * argv[]) {
    LinkNode *L;
    int a[1] = {1};
    CreateListHead(L, a, 1);
    DispList(L);
    
    LinkNode *L2;
    int b[2] = {9, 9};
    CreateListHead(L2, b, 2);
    DispList(L2);
    
    addTwoNumbers(L, L2);
    
    printf("hello world!\n");
}








