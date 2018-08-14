//
//  sqstack.h
//  algorithm
//
//  Created by pbyi on 2018/8/13.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#ifndef sqstack_h
#define sqstack_h

#include <stdio.h>

#define MaxSize 100

typedef struct {
    int i, j, di;
} Box;

typedef Box ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *&s);
void DestroyStack(SqStack *&s);
bool StackEmpty(SqStack *s);
bool Push(SqStack *&s,ElemType e);
bool Pop(SqStack *&s,ElemType &e);
bool GetTop(SqStack *s,ElemType &e);


#endif /* sqstack_h */
