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
//    [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    int** a = (int**)malloc(sizeof(int*) * 4);
    int a1[4] = {1,2,3,4};
    a[0] = a1;
    
    int a2[4] = {5,6,7,8};
    a[1] = a2;

    int a3[4] = {9,10,11,12};
    a[2] = a3;
    
    int a4[4] = {13,14,15,16};
    a[3] = a4;
    
    int *b = spiralOrder(a, 4, 4);
    for (int i = 0; i < 4 * 4; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}








