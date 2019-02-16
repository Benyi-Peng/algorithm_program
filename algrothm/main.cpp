//
//  main.c
//  algorithm
//
//  Created by pbyi on 2018/6/10.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"
#include "solution1_100.h"


int main(int argc, const char * argv[]) {
    int a[4] = {1, 2, 3, 4};
    int b = 0;
    int **x = permute1(a, 4, &b);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}








