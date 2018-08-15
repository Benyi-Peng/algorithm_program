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












void StackNew(Stack *&s, int elemSize) {
    s = (Stack *)malloc(sizeof(Stack));
    s->elemSize = elemSize;
    s->loglen = 0;
    s->alloclen = 4;
    s->elems = malloc(4 * elemSize);
}

void StackDestroy(Stack *&s) {
    free(s);
}

bool StackEmpty(Stack *&s) {
    return s->loglen == 0;
}

static void StackGrow(Stack *&s) {
    s->alloclen += 4;
    s->elems = realloc(s->elems, (s->alloclen) * (s->elemSize));
}

bool StackPush(Stack *&s, void *elemAdd) {
    //栈满则采用加倍策略增长
    if (s->loglen == s->alloclen) {
        StackGrow(s);
    }
    
    void *target = (char *)(s->elems) + s->loglen * (s->elemSize);
    memcpy(target, elemAdd, s->elemSize);
    s->loglen++;
    
    return true;
}



bool StackPop(Stack *&s,  void *elemPop) {
    //获取栈顶元素指针
    void *source = (char*)(s->elems) + (s->loglen - 1) *(s->elemSize);
    memcpy(elemPop, source, s->elemSize);
    s->loglen--;
    
    return true;
}

bool StackGetTop(Stack *&s, void *elemTop) {
    void *source = (char*)(s->elems) + (s->loglen - 1) *(s->elemSize);
    memcpy(elemTop, source, s->elemSize);
    
    return true;
}

bool StackGetElement(Stack *&s, void *elemTop, int index) {
    void *source = (char*)(s->elems) + index *(s->elemSize);
    memcpy(elemTop, source, s->elemSize);
    
    return true;
}
