//
//  SqQueue.c
//  algorithm
//
//  Created by pbyi on 2018/8/16.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "SqQueue.h"


#include <stdio.h>

#include <stdlib.h>
#include <string.h>



#define MaxSize 100
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front,rear;
    int elemSize; 
} SqQueue;


void InitQueue(SqQueue *&q)
{    q=(SqQueue *)malloc (sizeof(SqQueue));
    q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
    free(q);
}
bool QueueEmpty(SqQueue *q)
{
    return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{    if ((q->rear+1)%MaxSize==q->front)
    return false;
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{    if (q->front==q->rear)
    return false;
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}
