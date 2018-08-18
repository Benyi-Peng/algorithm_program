//
//  nqueen.c
//  algorithm
//
//  Created by oe on 2018/8/18.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "nqueen.h"

#include "sqstack.h"

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
} QueenPos;


int queen(void) {
    Stack *s;
    StackNew(s, sizeof(QueenPos));
    
    int allSolution = 0;
    
    for (int i = 0; i < 8; i++) {
        
        QueenPos first;
        first.row = 0; first.col = i;
        board[0][i] = 1;
        StackPush(s, &first);
        
        int ret[8] = {i,0,0,0,0,0,0,0};
        
        
        
        while (!StackEmpty(s)) {
            QueenPos top;
            
            if (s->loglen == 8) {
                StackPop(s, &top);
                board[top.row][top.col] = 0;
                allSolution++;
            }
            
            // 判断是否找到可以放置的位置
            QueenPos next;
            bool find = false;
            next.row = s->loglen;
            next.col = ret[s->loglen - 1] + 1;
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
                ret[s->loglen - 1] = next.col;
                board[next.row][next.col] = 1;
            } else { // 如果没找到, 出栈当前top
                StackPop(s, &top);
                board[top.row][top.col] = 0;
            }
        }
    }
    
    
    printf("all solution : %d\n", allSolution);
    return 1; 
}


