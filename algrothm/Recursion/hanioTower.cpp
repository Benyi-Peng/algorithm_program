//
//  hanioTower.c
//  algorithm
//
//  Created by pbyi on 2018/8/22.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "hanioTower.h"

#include "sqstack.h" 

typedef struct {
    char from;
    char helper;
    char to;
    
    bool canMove;

    int n;
} Problem;

// X -> Z
void tower(int n, char from, char helper, char to) {
    if (n == 1) {
        printf("move No.%d plate from %c to %c\n", n, from, to);
    } else {
        tower(n-1, from, to, helper);
        printf("move No.%d plate from %c to %c\n", n, from, to);
        tower(n-1, helper, from, to);
    }
    return;
}

void tower_stack(int n, char from, char helper, char to) {
    Stack *s;
    StackNew(s, sizeof(Problem));
    
    Problem first;
    first.from = from;
    first.helper = helper;
    first.to = to;
    first.canMove = false;
    first.n = n;
    
    Problem p1, p2, p3;
    
    StackPush(s, &first);
    
    while (!StackEmpty(s)) {
        Problem top;
        StackPop(s, &top);
        
        if (top.canMove) {
            printf("move No.%d plate from %c to %c\n", top.n, top.from, top.to);
        } else {
            p1.from = top.helper;
            p1.to = top.to;
            p1.helper = top.from;
            p1.n = top.n-1;
            p1.canMove = p1.n == 1;
            StackPush(s, &p1);
            
            p2.from = top.from;
            p2.to = top.to;
            p2.helper = top.helper;
            p2.n = top.n;
            p2.canMove = true;
            StackPush(s, &p2); 
            
            p3.from = top.from;
            p3.to = top.helper;
            p3.helper = top.to;
            p3.n = top.n-1;
            p3.canMove = p3.n == 1;
            StackPush(s, &p3);
        }
    }
    
    return;
}
