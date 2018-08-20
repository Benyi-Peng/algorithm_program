//
//  nqueen.c
//  algorithm
//
//  Created by oe on 2018/8/18.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "nqueen.h"

#include "sqstack.h"

#include <string.h>
#include <cmath>

int board[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
};

typedef struct {
    int row;
    int col;
    int last;
} QueenPos;


int queen(void) {
    Stack *s;
    StackNew(s, sizeof(QueenPos));

    int allSolution = 0;

    QueenPos first;
    first.row = 0; first.col = 0; first.last = 0;
    board[0][0] = 1;
    StackPush(s, &first);
    
    
    while (!StackEmpty(s)) {
        
//        while (ret[s->loglen] < 8) {
//
//            ret[s->loglen]++;
//
//            if (s->loglen == 8) {
//                // success
//            } else {
//
//            }
//            if (1) {
//
//            }
//        }
        
        QueenPos top;
        StackGetTop(s, &top);
        
//        while (s->loglen < 8) {
//
//        }

        if (s->loglen == 8) {
            StackPop(s, &top);
            board[top.row][top.col] = 0;
            allSolution++;
        }

        // 判断是否找到可以放置的位置
        QueenPos next;
        next.row = s->loglen;
        next.col = top.last + 1;
        next.last = 0; 
        bool find = false;
        while (!find && next.col < 8) {
            int i,j;
            find = true;
            for (i = 0; i < next.row; i++) { // up
                if (board[i][next.col] == 1)
                    find = false;
            }
            for (i = next.row + 1; i < 8; i++) { // down
                if (board[i][next.col] == 1)
                    find = false;
            }
            for (i = 0; i < next.col; i++) { // left
                if (board[next.row][i] == 1)
                    find = false;
            }
            for (i = next.col + 1; i < 8; i++) { // right
                if (board[next.row][i] == 1)
                    find = false;
            }
            for (i = next.row - 1, j = next.col - 1; i >= 0 && j >= 0; i--,j--) { // left + up
                if (board[i][j] == 1)
                    find = false;
            }
            for (i = next.row + 1, j = next.col + 1; i < 8 && j < 8; i++,j++) { // right + down
                if (board[i][j] == 1)
                    find = false;
            }
            for (i = next.row + 1, j = next.col - 1; i < 8 && j >= 0; i++,j--) { // left + down
                if (board[i][j] == 1)
                    find = false;
            }
            for (i = next.row - 1, j = next.col + 1; i >= 0 && j < 8; i--,j++) { // right + up
                if (board[i][j] == 1)
                    find = false;
            }

            if (!find) {
                next.col++;
            }
        }

        if (find) { // 如果找到了, 入栈找到的点
            
            StackPush(s, &next);
            board[next.row][next.col] = 1;
        } else { // 如果没找到, 出栈当前top
            
            void *source = (char *)(s->elems) + (s->loglen - 1) *(s->elemSize);
            QueenPos *p = (QueenPos *)source;
            p->last = next.col;
            
            StackPop(s, &top);
            board[top.row][top.col] = 0;
        }
    }


    printf("all solution : %d\n", allSolution);
    
    
    
    return 1;
}






















int queenArr[9];

//数组初始化
void init()
{
    memset(queenArr,0,9*sizeof(int));
}

//输出结果
void print()
{
    for(int i=1; i<9; i++)
        printf("%d ", queenArr[i]);
    printf("\n");
}

//剪枝函数
bool canPlaceQueen(int k)
{
    for(int i = 1; i < k; i++)
    {
        //判断是否处于同一列或同一斜线

        if(queenArr[i] == queenArr[k] || fabs(k-i) == fabs(queenArr[k]-queenArr[i])) return false;
    }
    return true;
}
//迭代方法求解八皇后过程
void eightQueen_1()
{
    int k = 1;
    while(k>=1)
    {
        while(queenArr[k]<=7)
        {
            queenArr[k] += 1;
            if(k == 8 && canPlaceQueen(k))
            {
                print();
            }
            else if(canPlaceQueen(k))
            {
                k++;
            }
        }
        queenArr[k] = 0;
        k--;
    }
}

void test() {
    
}
