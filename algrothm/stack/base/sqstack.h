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




typedef struct {
    void *elems;    //栈底指针
    int loglen;       //已经使用的长度
    int alloclen;    //已经申请的长度
    int elemSize;   //单个元素的长度
} Stack;


void StackNew(Stack *&s, int elemSize);
void StackDestroy(Stack *&s);
bool StackEmpty(Stack *&s);
bool StackPush(Stack *&s, void *elemAdd);
bool StackPop(Stack *&s,  void *elemPop);
bool StackGetTop(Stack *&s, void *elemTop);
bool StackGetElement(Stack *&s, void *elemTop, int index); 

#endif /* sqstack_h */
