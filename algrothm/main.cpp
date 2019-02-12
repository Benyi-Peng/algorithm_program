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
    LinkNode *L = (LinkNode *)malloc(sizeof(LinkNode));
    int a[5] = {1, 2, 3, 4, 5};
    CreateListHead(L, a, 5);
    DispList(L);
    L->next = reverseListRecursive(L->next);
    DispList(L);
}








