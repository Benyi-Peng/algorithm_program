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




int maze_recursion(int xi, int yi, int xe, int ye, RPath &path) {
    mg2[xi][yi] = -1;
    if (xi == xe && yi == ye) {
        for (int i = 0; i < path.length; i++) {
            printf("(%d, %d)\n", path.p[i].row, path.p[i].col);
        }
        printf("\n\n");
    } else {
        if (mg2[xi][yi] == 0) {
            RBox current = path.p[path.length - 1];
            RBox next;
            int di = 0;
            while (di < 4) {
                switch (di) {
                    case 0:
                        next.row = current.row - 1;
                        next.col = current.col;
                        break;
                    case 1:
                        next.row = current.row;
                        next.col = current.col + 1;
                        break;
                    case 2:
                        next.row = current.row + 1;
                        next.col = current.col;
                        break;
                    case 3:
                        next.row = current.row;
                        next.col = current.col - 1;
                        break;
                    default:
                        break;
                }
                di++;
                path.p[path.length] = next;
                path.length++;
                maze_recursion(next.row, next.col, xe, ye, path);
                mg2[next.row][next.col] = 0;
                path.length--;
            }
        }
    }
    
    return 1;
}
