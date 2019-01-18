//
//  linklist.hpp
//  algorithm
//
//  Created by pbyi on 2019/1/18.
//  Copyright © 2019 pbyi. All rights reserved.
//

#ifndef linklist_hpp
#define linklist_hpp

#include <stdio.h>
typedef int ElemType;
typedef struct LNode {
    ElemType val;
    struct LNode *next; 
} LinkNode;


/**
 由L返回一个链表

 @param L 链表头
 */
void InitList(LinkNode *&L);
void DestroyList(LinkNode *&L);
bool ListEmpty(LinkNode *&L);
int ListLength(LinkNode *L);
void DispList(LinkNode *L);
bool GetElem(LinkNode *L,int i,ElemType &e);
int LocateElem(LinkNode *L,ElemType e);
/**
 操作结果是：e是L第i个节点
 
 @param L 链表头
 @param i 位置
 @param e 数字
 @return 操作是否成功
 */
bool ListInsert(LinkNode *&L,int i,ElemType e);
bool ListDelete(LinkNode *&L,int i,ElemType &e);
void CreateListHead(LinkNode *&L,ElemType a[],int n);
void CreateListTail(LinkNode *&L,ElemType a[],int n);
#endif /* linklist_hpp */
