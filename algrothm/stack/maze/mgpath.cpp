//
//  mgpath.c
//  algorithm
//
//  Created by pbyi on 2018/8/12.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "mgpath.h"

#include "sqstack.h"

#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};


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
            for (int i = 0; i < s->top; i++) {
                printf("(%d, %d)\n", s->data[i].i, s->data[i].j);
            }
            DestroyStack(s);
            return 1;
        } else {
            bool find = false;
            while (top.di < 4 && !find) {
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
                Pop(s, top);
                mg[top.i][top.j] = 0;
            }
        }
    }
    
    DestroyStack(s);
    return 0;
}





int mgpath_GenericStack(int xi, int yi, int xe, int ye) {
    Stack *s;
    StackNew(s, sizeof(Box));
    
    
    Box first;
    first.i = xi;
    first.j = yi;
    first.di = 0;
    
    int iNext = 0, jNext = 0, diNext = 0;
    
    StackPush(s, &first);
    
    mg[xi][yi] = -1;
    
    while (!StackEmpty(s)) {
        Box top;
        StackGetTop(s, &top);
        if (top.i == xe && top.j == ye) {
            printf("Find path:\n\n");
            for (int i = 0; i < s->loglen; i++) {
                Box b;
                StackGetElement(s, &b, i);
                
                printf("(%d, %d)\n", b.i, b.j);
            }
            StackDestroy(s); 
            return 1;
        } else {
            bool find = false;
            while (top.di < 4 && !find) {
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
                void *source = (char*)(s->elems) + (s->loglen - 1) *(s->elemSize);
                Box *t = (Box *)source;
                t->di = top.di; 
                
                Box next;
                next.i = iNext;
                next.j = jNext;
                next.di = 0;
                
                StackPush(s, &next);
                mg[iNext][jNext] = -1;
            } else {
                StackPop(s, &top);
                mg[top.i][top.j] = 0;
            }
        }
    }
    
    StackDestroy(s);
    return 0;
}

