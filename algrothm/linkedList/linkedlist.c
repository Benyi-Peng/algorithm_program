//
//  linkedlist.c
//  algorithm
//
//  Created by pbyi on 2019/1/16.
//  Copyright © 2019 pbyi. All rights reserved.
//

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>



void CreateListF(LinkNode *L,ElemType a[],int n) {
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    for (int i=0;i<n;i++) {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
void CreateListR(LinkNode *L,ElemType a[],int n) {
    LinkNode *s,*r;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    r=L;
    for (int i=0;i<n;i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
void InitList(LinkNode *L)
{
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}
void DestroyList(LinkNode *L)
{
    LinkNode *pre=L,*p=pre->next;
    while (p!=NULL)
    {    free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}
bool ListEmpty(LinkNode *L)
{
    return(L->next==NULL);
}
int ListLength(LinkNode *L)
{
    LinkNode *p=L;int i=0;
    while (p->next!=NULL)
    {    i++;
        p=p->next;
    }
    return(i);
}
void DispList(LinkNode *L)
{
    LinkNode *p=L->next;
    while (p!=NULL)
    {    printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
bool GetElem(LinkNode *L,int i,ElemType *e)
{
    int j=0;
    LinkNode *p=L;
    if (i<=0) return false;
    while (j<i && p!=NULL)
    {    j++;
        p=p->next;
    }
    if (p==NULL)
        return false;
    else
    {    *e=p->data;
        return true;
    }
}
int LocateElem(LinkNode *L,ElemType e)
{
    LinkNode *p=L->next;
    int n=1;
    while (p!=NULL && p->data!=e)
    {    p=p->next;
        n++;
    }
    if (p==NULL)
        return(0);
    else
        return(n);
}
bool ListInsert(LinkNode *L,int i,ElemType e)
{
    int j=0;
    LinkNode *p=L,*s;
    if (i<=0) return false;
    while (j<i-1 && p!=NULL)
    {    j++;
        p=p->next;
    }
    if (p==NULL)
        return false;
    else
    {    s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}
bool ListDelete(LinkNode *L,int i,ElemType *e)
{
    int j=0;
    LinkNode *p=L,*q;
    if (i<=0) return false;
    while (j<i-1 && p!=NULL)
    {    j++;
        p=p->next;
    }
    if (p==NULL)
        return false;
    else
    {    q=p->next;
        if (q==NULL)
            return false;
        *e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}
