//
//  recursion_other.c
//  algorithm
//
//  Created by pbyi on 2018/9/4.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "recursion_other.h"

//1. 高效求解 X的n次方
double expx(double x, int n) {
    if (n == 1)
        return x;
    else if (n % 2 == 0)
        return expx(x, n/2) * expx(x, n/2);
    else
        return x * expx(x, (n - 1)/2) * expx(x, (n - 1)/2);
}
