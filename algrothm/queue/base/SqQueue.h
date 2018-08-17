//
//  SqQueue.h
//  algorithm
//
//  Created by pbyi on 2018/8/16.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#ifndef SqQueue_h
#define SqQueue_h

#include <stdio.h>

#define MaxSize 100

typedef struct {
    void *data;
    int front,rear;
    int elemSize;
} SqQueue;

void InitQueue(SqQueue *&q, int elemSize);
void DestroyQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q,void *e);
bool deQueue(SqQueue *&q,void *e);

#endif /* SqQueue_h */
