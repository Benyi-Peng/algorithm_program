//
//  tree_basis.c
//  algorithm
//
//  Created by pbyi on 2018/9/8.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "tree_basis.h"

#define MaxSize 100

typedef char ElemType;
typedef struct node {
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

void CreateBTree(BTNode *&b, char *str) {
    BTNode *St[MaxSize], *p;
    char ch;
    ch = str[0];
    while (ch != '\0') {
        switch (ch) {
            case '(':
                break;                
            default:
                break;
        }
    }
}
