//
//  mgpath.c
//  algorithm
//
//  Created by pbyi on 2018/8/12.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "mgpath.h"

#include "sqstack.h"


int mgpath_stack(int xi, int yi, int xe, int ye) {
    SqStack *s;
    InitStack(s);
    
    Box first;
    first.i = xi;
    first.j = yi;
    first.di = 0;
    
    int iNext = 0, jNext = 0, diNext = 0;
    
    Push(s, first);
    
    mg[xi][yi] = -1;
    
    while (!StackEmpty(s)) {
        Box top;
        GetTop(s, top); 
        if (top.i == xe && top.j == ye) {
            printf("Find path:\n\n");
            for (int i = 0; i < M + 2; i++) {
                for (int j = 0; j < N + 2; j++) {
                    if (j == 9)
                        printf("\n");
                    printf("%d ", mg[i][j]);
                }
            }
        } else {
            bool find = false;
            while (top.di < 4) {
                switch (top.di) {
                    case 0:
                        iNext = top.i - 1;
                        jNext = top.j;
                        diNext = 0;
                        break;
                    case 1:
                        iNext = top.i;
                        jNext = top.j + 1;
                        diNext = 0;
                        break;
                    case 2:
                        iNext = top.i + 1;
                        jNext = top.j;
                        diNext = 0;
                        break;
                    case 3:
                        iNext = top.i;
                        jNext = top.j - 1;
                        diNext = 0;
                        break;
                    default:
                        break;
                }
                find = mg[iNext][jNext] == 0;
                top.di++;
            }
            if (find) {
                s->data[s->top].di = top.di;
                Box next;
                next.i = iNext;
                next.j = jNext;
                next.di = 0;
                Push(s, next);
                mg[iNext][jNext] = -1;
            } else {
                Box top;
                Pop(s, top);
                mg[top.i][top.j] = 0;
            }
        }
    }
    
    
    
    
    return 1; 
}
