//
//  maze_recursion.c
//  algorithm
//
//  Created by pbyi on 2018/8/19.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "maze_recursion.h"


//#define MaxSize 100
#define M 8
#define N 8
int mg2[M+2][N+2] = {
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



// 问题：1. next(试探点)的row,col不是在path栈顶元素的基础上变化，而是在xi,yi上变化 \
        2. path参数不能加&符号，为什么 
int maze_recursion(int xi, int yi, int xe, int ye, RPath path) {
    if (xi == xe && yi == ye) {
        path.p[path.length].row = xi;
        path.p[path.length].col = yi;
        path.length++;
        for (int i = 0; i < path.length; i++) {
            printf("(%d, %d)\n", path.p[i].row, path.p[i].col);
        }
        printf("\n\n");
    } else {
        if (mg2[xi][yi] == 0) {
            RBox next;
            int di = 0;
            while (di < 4) {
                next.row = xi;
                next.col = yi;
                path.p[path.length] = next;
                path.length++;
                switch (di) {
                    case 0:
                        next.row = xi - 1;
                        next.col = yi;
                        break;
                    case 1:
                        next.row = xi;
                        next.col = yi + 1;
                        break;
                    case 2:
                        next.row = xi + 1;
                        next.col = yi;
                        break;
                    case 3:
                        next.row = xi;
                        next.col = yi - 1;
                        break;
                    default:
                        break;
                }
                mg2[xi][yi] = -1;
                maze_recursion(next.row, next.col, xe, ye, path);
                mg2[xi][yi] = 0;
                path.length--;
                di++;
            }
        }
    }
    return 1;
}

int maze_recursion2(int xi, int yi, int xe, int ye, RPath path) {
    int di, k, i = 0, j = 0;
    if (xi == xe && yi == ye) {
        path.p[path.length].row = xi;
        path.p[path.length].col = yi;
        path.length++;
        for (k = 0; k < path.length; k++) {
            printf("(%d, %d)\n", path.p[k].row, path.p[k].col);
        }
        printf("\n\n");
    } else {
        if (mg2[xi][yi] == 0) {
            di = 0;
            while (di < 4) {
                path.p[path.length].row = xi;
                path.p[path.length].col = yi;
                path.length++;
                switch (di) {
                    case 0:
                        i = xi - 1;
                        j = yi;
                        break;
                    case 1:
                        i = xi;
                        j = yi + 1;
                        break;
                    case 2:
                        i = xi + 1;
                        j = yi;
                        break;
                    case 3:
                        i = xi;
                        j = yi - 1;
                        break;
                }
                mg2[xi][yi] = -1;
                maze_recursion2(i, j, xe, ye, path);
                mg2[xi][yi] = 0;
                path.length--;
                di++;
            }
        }
    }
    return 1;
}
