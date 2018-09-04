//
//  queen_recursion.c
//  algorithm
//
//  Created by pbyi on 2018/9/4.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "queen_recursion.h"

#include <math.h>

int board2[8] = {0,0,0,0,0,0,0,0};


bool canPlaceQueen2(int k) {
    for(int i = 0; i < k; i++) {
        //判断是否处于同一列或同一斜线
        if(board2[i] == board2[k] || fabs(k-i) == fabs(board2[k]-board2[i]))
            return false;
    }
    return true;
}




int queen3(int row, int &allSolution) {
    for (int col = 0; col < 8; col++) {
        board2[row] = col;
        if (canPlaceQueen2(row)) {
            if (row == 7) {
                for (int i = 0; i < 8; i++) {
                    printf("%d ", board2[i]);
                }
                allSolution++;
                printf("\n");
            }
            queen3(row + 1, allSolution);
        }
    }
    board2[row] = 0;
    if (row == 0)
        printf("all solution : %d\n", allSolution);

    return 1;
}


