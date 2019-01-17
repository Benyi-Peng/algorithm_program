//
//  linkedlist.h
//  algorithm
//
//  Created by pbyi on 2019/1/16.
//  Copyright © 2019 pbyi. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LinkNode;

#ifdef __cplusplus
extern "C" {
#endif
    
    void CreateListF(LinkNode *L,ElemType a[],int n);
    void CreateListR(LinkNode *L,ElemType a[],int n);
    void InitList(LinkNode *L);
    void DestroyList(LinkNode *L);
    bool ListEmpty(LinkNode *L);
    int ListLength(LinkNode *L);
    void DispList(LinkNode *L);
    bool GetElem(LinkNode *L,int i,ElemType *e);
    int LocateElem(LinkNode *L,ElemType e);
    bool ListInsert(LinkNode *L,int i,ElemType e);
    bool ListDelete(LinkNode *L,int i,ElemType e);
    
#ifdef __cplusplus
}
#endif

#endif /* linkedlist_h */
