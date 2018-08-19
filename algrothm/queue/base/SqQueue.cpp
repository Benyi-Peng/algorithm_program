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






void InitQueue(SqQueue *&q, int elemSize) {
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->data = malloc(sizeof(MaxSize * elemSize));
    q->elemSize = elemSize;
    q->front = q->rear = 0;
    q->allocLen = MaxSize;
}

void DestroyQueue(SqQueue *&q) {
    free(q);
}

bool QueueEmpty(SqQueue *q) {
    return(q->front==q->rear);
}

void QueueGrow(SqQueue *&q) {
    q->allocLen += 10;
    q->data = realloc(q->data, q->allocLen * q->elemSize);
}

bool enQueue(SqQueue *&q, void *e) {
    if (q->rear == q->allocLen) {
        QueueGrow(q);
    }
    void *rear = (char *)q->data + q->rear * q->elemSize;
    memcpy(rear, e, q->elemSize);
    q->rear = q->rear + 1;
    return true;
}

bool deQueue(SqQueue *&q, void *e) {
    if (q->front == q->rear)
        return false;
    void *front = (char *)q->data + q->front * q->elemSize;
    memcpy(e, front, q->elemSize);
    q->front = q->front + 1;
    return true;
}

bool queueGetElement(SqQueue *&q, int idx, void *e) {
    void *source = (char *)(q->data) + idx * (q->elemSize);
    memcpy(e, source, q->elemSize);
    return true;
}

// 循环队列队满判别：留出一个位置，用以区分队空。
bool enQueueLoop(SqQueue *&q, void *e) {
    if ((q->rear + 1) % MaxSize == q->front)
        return false;
    void *rear = (char *)q->data + q->rear * q->elemSize;
    memcpy(rear, e, q->elemSize);
    q->rear = (q->rear + 1) % MaxSize;
    return true;
}

bool deQueueLoop(SqQueue *&q,void *e) {
    if (q->front == q->rear)
        return false;
    void *front = (char *)q->data + q->front * q->elemSize;
    memcpy(e, front, q->elemSize);
    q->front = (q->front + 1) % MaxSize;
    return true;
}

void testQueue(void) {
    SqQueue *q;
    InitQueue(q, sizeof(int));
    
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 33;
    int e = 478;
    int f = 55;
    
    enQueue(q, &a);
    enQueue(q, &b);
    enQueue(q, &c);
    enQueue(q, &d);
    enQueue(q, &e);
    enQueue(q, &f);
    
    int t;
    deQueue(q, &t);
    printf("%d ", t);
    
    deQueue(q, &t);
    printf("%d ", t);
    
    deQueue(q, &t);
    printf("%d ", t);
    
    deQueue(q, &t);
    printf("%d ", t);
    
    deQueue(q, &t);
    printf("%d ", t);
    
    deQueue(q, &t);
    printf("%d\n ", t);
}
