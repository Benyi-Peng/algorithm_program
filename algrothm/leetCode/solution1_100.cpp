//
//  solution1_100.c
//  algorithm
//
//  Created by pbyi on 2019/1/16.
//  Copyright © 2019 pbyi. All rights reserved.
//

#include "solution1_100.h"

#include <stdlib.h>
#include <math.h>

#include <vector>
using namespace std;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* ret = (int*)malloc(2 * sizeof(int));
    ret[0] = -1;
    ret[1] = -1;
    for (int i = 0; i < numsSize; i++) {
        int t = target - nums[i];
        for (int j = 0; j < numsSize; j++) {
            if (j == i) continue;
            if (nums[j] == t) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}

LinkNode* addTwoNumbers(LinkNode* l1, LinkNode* l2) {
    LinkNode* ret, *s, *tail;
    ret = (LinkNode *)malloc(sizeof(LinkNode));
    tail = ret;
    
    l1 = l1->next;
    l2 = l2->next;

    int carry = 0;
    int digSum = 0;
    
    while (digSum != 0 || l2 != NULL || l1 != NULL) {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        
        int n1 = l1 == NULL ? 0 : l1->val;
        int n2 = l2 == NULL ? 0 : l2->val;
        
        digSum = n1 + n2 + carry;
        printf("%d + %d + %d = %d\n",n1 ,n2 ,carry , digSum);
        s->val = digSum % 10;
        s->next = NULL;
        carry = digSum >= 10 ? 1 : 0;
        
        if (digSum != 0 || l2 != NULL || l1 != NULL) {
            tail->next = s;
            tail = s;            
        }
        
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return ret->next;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        return 1.0;
    }
};
