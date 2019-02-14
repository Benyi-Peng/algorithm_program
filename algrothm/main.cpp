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
    int a[3] = {1, 1, 2};
    int n = removeDuplicates(a, 3);
    for (int i = 0; i < n; i++) {
        printf("%d \n", a[i]);
    }
    
    printf("%d \n", n);
}








