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
    
    vector<int> x = {-3,14,-10,-1,12,13,-3,2,-6,4,13,7,-8,4,0,-13,11,-4,7,0,4,-3,12,11,5,-14,-8,8,3,-1,-8,-15,-2,-11,-9,-12,9,3,5,-11,-8,3,3,-9,-15,-12,-15,3,-9,0,-12,3,12,-14,-1,-6,-13,-2,-13,-3,12,-14,-3,-13,-9,3,-10,-15,13,2,11,13,-9,-1,11,13,-6,4,1,1,-11,5,-11,8,-2,-5,-12,-8,8,-10,4,-3,-8,-14,-1,-10,-4,-3,12,-14,14,9,6,12,-15,3,10,-13,-8,-11,3,-4,1,-1};
    vector<vector<int>> ret = Solution().threeSum(x);
    for (int i = 0; i < ret.size(); i ++) {
        vector<int> a1 = ret[i];
        for (int j = 0; j < a1.size(); j++) {
            printf("%d ", a1[j]);
        }
        printf("\n");
    }
}








