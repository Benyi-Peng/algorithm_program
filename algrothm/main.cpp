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
    vector<int> x = {1,2,5,10,11};
    int ret = Solution().threeSumClosest(x, 12);
    printf("%d \n", ret);
}








