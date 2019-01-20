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
    int a[1] = {1};
    int b[1] = {1};
    double x = findMedianSortedArrays(a, 1, b, 1);
    printf("ret : %f\n", x);
}








