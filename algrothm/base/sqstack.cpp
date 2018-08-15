//
//  sqstack.c
//  algorithm
//
//  Created by pbyi on 2018/8/13.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "sqstack.h"

#include <stdlib.h>
#include <string.h>

void InitStack(SqStack *&s) {
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

void DestroyStack(SqStack *&s) {
    free(s);
}

bool StackEmpty(SqStack *s) {
    return(s->top==-1);
}

bool Push(SqStack *&s,ElemType e) {
    if (s->top==MaxSize-1)
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}

bool Pop(SqStack *&s,ElemType &e) {
    if (s->top==-1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s,ElemType &e) {
    if (s->top==-1)
        return false;
    e=s->data[s->top];
    return true;
}








typedef struct {
    void *elems;    //栈底指针
    int loglen;       //已经使用的长度
    int alloclen;    //已经申请的长度
    int elemSize;   //单个元素的长度
} stack;

static void StackGrow(stack *s);

void StackNew(stack *s, int elemSize) {
    s->elemSize = elemSize;
    s->loglen = 0;
    s->alloclen = 4;
    s->elems = malloc(4 *elemSize);
}

void StackPush(stack *s, void *elemAdd) {
    //栈满则采用加倍策略增长
    if (s->loglen == s->alloclen) {
        StackGrow(s);
    }
    
    void *target = (char *)(s->elemSize) + s->loglen * (s->elemSize);
    memcpy(target, elemAdd, s->elemSize);
    s->loglen++;
}

static void StackGrow(stack *s) {
    s->alloclen *= 2;
    s->elems = realloc(s->elems, (s->alloclen) * (s->elemSize));
}

void StackPop(stack *s,  void *elempop) {
    //获取栈顶元素指针
    void *source = (char*)(s->elems) + (s->loglen - 1 ) *(s->elemSize);
    memcpy(elempop, source, s->elemSize);
    s->loglen--;
}
