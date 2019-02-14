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
    LinkNode *l1 = (LinkNode*)malloc(sizeof(LinkNode));
    int a1[3] = {1,4,5};
    CreateListHead(l1, a1, 3);
    
    vector<LinkNode*> lists = {l1};
    
    Solution().mergeKLists(lists);
}








