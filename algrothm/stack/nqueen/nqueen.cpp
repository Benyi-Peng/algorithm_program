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

    for (int i = 0; i < 8; i++) {
        QueenPos first;
        first.row = 0; first.col = i; first.last = -1;
        board[0][i] = 1;
        StackPush(s, &first);
        
        
        while (!StackEmpty(s)) {
            QueenPos top;
            StackGetTop(s, &top);
            
            if (s->loglen == 8) {
                allSolution++;
            }
            
            QueenPos next;
            next.row = s->loglen;
            next.col = top.last + 1;
            next.last = -1;
            
            // 判断是否找到可以放置的位置
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
                // 给栈顶元素设置回溯点 
                void *source = (char *)(s->elems) + (s->loglen - 1) *(s->elemSize);
                QueenPos *t = (QueenPos *)source;
                t->last = next.col;
                
                StackPush(s, &next);
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





bool canPlace(QueenPos next);
void printBoard(void);
int queen2(void) {
    Stack *s;
    StackNew(s, sizeof(QueenPos));
    
    int allSolution = 0;
    
    for (int i = 0; i < 8; i++) {
        
        QueenPos first;
        first.row = 0; first.col = i; first.last = -1;
        board[0][i] = 1;
        StackPush(s, &first);
        
        while (!StackEmpty(s)) {
            
            
            QueenPos top;
            StackGetTop(s, &top);
            
            QueenPos next;
            next.row = top.row + 1;
            next.col = top.last + 1;
            next.last = -1;
            
            while (next.col < 8) {
                if (canPlace(next)) {
                    
                    void *source = (char *)(s->elems) + (s->loglen - 1) *(s->elemSize);
                    QueenPos *t = (QueenPos *)source;
                    t->last= next.col;
                    
                    StackPush(s, &next);
                    board[next.row][next.col] = 1;
                    
                    if (next.row == 7) {
                        allSolution++;
                        printBoard();
                    }
                    
                    next.row = next.row + 1;
                    next.col = 0;
                    
                    
                } else {
                    next.col++;
                }
            }
            
            
            
            StackPop(s, &top);
            board[top.row][top.col] = 0;
        }
    }
    
    
    printf("all solution : %d\n\n", allSolution);
    return 1;
}

void printBoard(void) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

bool canPlace(QueenPos next) {
    bool find = true;
    if (next.row == 8 || next.col == 8) {
        return false; 
    }
    int i,j;
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
    
    return find;
}














int queenArr[9];

//数组初始化
void init() {
    memset(queenArr,0,9*sizeof(int));
}

//输出结果
void print() {
    for(int i=1; i<9; i++)
        printf("%d ", queenArr[i]);
    printf("\n");
}

//剪枝函数
bool canPlaceQueen(int k) {
    for(int i = 1; i < k; i++) {
        //判断是否处于同一列或同一斜线
        if(queenArr[i] == queenArr[k] || fabs(k-i) == fabs(queenArr[k]-queenArr[i])) return false;
    }
    return true;
}

//迭代方法求解八皇后过程
void eightQueen_1() {
    int allSolution = 0; int k = 1;
    while(k>=1) {
        while(queenArr[k]<=7) {
            queenArr[k] += 1;
//            if(k == 8 && canPlaceQueen(k)) {
//                allSolution++;
//                print();
//            } else if(canPlaceQueen(k)) {
//                k++;
//            }
            
            if (canPlaceQueen(k)) {
                if (k == 8) {
                    allSolution++;
                    print();
                }
                k++;
            }
        }
        queenArr[k] = 0;
        k--;
    }
    printf("all solution : %d\n", allSolution);
}
