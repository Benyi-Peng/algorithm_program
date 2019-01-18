//
//  linklist.cpp
//  algorithm
//
//  Created by pbyi on 2019/1/18.
//  Copyright © 2019 pbyi. All rights reserved.
//

#include "linklist.h"

#include <stdlib.h>

void InitList(LinkNode *&L) {
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->val = 0;
    L->next = NULL;
}

void DestroyList(LinkNode *&L) {
    LinkNode *p = L, *q = p->next;
    while (q != NULL) {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}

bool ListEmpty(LinkNode *&L) {
    return L->next == NULL;
}

int ListLength(LinkNode *L) {
    LinkNode *p = L;
    int i = 0;
    while (p != NULL && p->next!=L) {
        i++;
        p=p->next;
    }
    return(i);
}

void DispList(LinkNode *L) {
    LinkNode *p=L->next;
    while (p!=NULL) {
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}

bool GetElem(LinkNode *L,int i,ElemType &e) {
    int j = 0;
    LinkNode *p = L;
    if (i <= 0 || ListEmpty(L))
        return false;
    while (j < i) {
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false;
    } else {
        e = p->val;
        return true;
    }
}

int LocateElem(LinkNode *L,ElemType e) {
    int i = 1;
    LinkNode *p = L->next;
    while (p->val != e && p != NULL) {
        p = p->next;
        i++;
    }
    return p == NULL ? 0 : i;
}

/**
 操作结果是：e是L第i个节点, 初始节点的序号是 1

 @param L 链表头
 @param i 位置
 @param e 数字
 @return 操作是否成功
 */
bool ListInsert(LinkNode *&L,int i,ElemType e) {
    int j = 0;
    LinkNode *p = L, *s;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL) // 未找到第i个节点
        return false;
    else {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->val = e;
        s->next = p->next;
        p->next = s;
    }
    return true;
}

bool ListDelete(LinkNode *&L,int i,ElemType &e) {
    int j = 0;
    LinkNode *p = L, *q;
    if (i <= 0) return false;
    while (j < i -1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL) // 未找到第i-1个节点
        return false;
    else {
        if (p->next == NULL) // 未找到第i个节点
            return false;
        q = p->next;
        e = q->val;
        p->next = q->next;
        free(q);
        return true;
    }
}

void CreateListHead(LinkNode *&L,ElemType a[],int n) {
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->val = 0;
    L->next = NULL;
    
    int i;
    LinkNode *s;
    for (i = 0; i < n; i++) {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->val = a[i];
        s->next = L->next;
        L->next = s;
    }
}

void CreateListTail(LinkNode *&L,ElemType a[],int n) {
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->val = 0;
    L->next = NULL;
    
    int i;
    LinkNode *s, *tail = L;
    for (i = 0; i < n; i++) {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->val = a[i];
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
}
