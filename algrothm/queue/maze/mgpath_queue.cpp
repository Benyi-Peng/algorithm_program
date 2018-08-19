//
//  mgpath_queue.c
//  algorithm
//
//  Created by pbyi on 2018/8/19.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "mgpath_queue.h"

#include "SqQueue.h"



#define MaxSize 100
#define M 8
#define N 8
int mg1[M+2][N+2] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

int maze_queue(int xi, int yi, int xe, int ye) {
    SqQueue *q;
    InitQueue(q, sizeof(QBox));
    
    QBox first;
    first.i = xi;
    first.j = yi;
    first.pre = -1;
    
    mg1[xi][yi] = -1;
    
    enQueue(q, &first);
    
    while (!QueueEmpty(q)) {
        QBox point;
        deQueue(q, &point);
        
        if (point.i == xe && point.j == ye) {
            while (point.i != xi || point.j != yi) {
                printf("(%d, %d)\n", point.i, point.j);
                queueGetElement(q, point.pre, &point); 
            }
            printf("\n\n\n");
            DestroyQueue(q);
            return true;
        }
        
        for (int k = 0; k < 4; k++) {
            int nexti = 0, nextj = 0;
            switch (k) {
                case 0:
                    nexti = point.i - 1; nextj = point.j;
                    break;
                case 1:
                    nexti = point.i; nextj = point.j + 1;
                    break;
                case 2:
                    nexti = point.i + 1; nextj = point.j;
                    break;
                case 3:
                    nexti = point.i; nextj = point.j - 1;
                    break;
                default:
                    break;
            }
            
            if (mg1[nexti][nextj] == 0) {
                QBox next;
                next.i = nexti;
                next.j = nextj;
                next.pre = q->front - 1;
                enQueue(q, &next); 
                mg1[nexti][nextj] = -1;
            }
        }
    }
    
    DestroyQueue(q);
    return 1;
}
