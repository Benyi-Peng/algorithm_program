//
//  solution1_100.c
//  algorithm
//
//  Created by pbyi on 2019/1/16.
//  Copyright © 2019 pbyi. All rights reserved.
//

#include "solution1_100.h"

#include <stdlib.h>

#include "linkedlist.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* ret = malloc(2 * sizeof(int));
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

long addTwoNumbers(LinkNode* l1, LinkNode* l2) {
    //    static struct ListNode ret;
    
    int weight;
    int mi = 0;
    int carry = 0;
    long sum = 0;
    
    while (l1->next && l2->next) {
        weight = pow(10, mi);
        
        int digSum = l1->data + l2->data + carry;
        carry = digSum > 10 ? 1 : 0;
        
        sum += (digSum % 10) * weight;
        
        l1 = l1->next;
        l2 = l2->next;
        mi++;
    }
    
    LinkNode *left; // 剩余的
    
    if (l1->next != NULL || l2->next != NULL) {
        if (l1->next == NULL) {
            left = l2->next;
        } else {
            left = l1->next;
        }
        do {
            weight = pow(10, mi);
            int digSum = left->data + carry;
            carry = digSum > 10 ? 1 : 0;
            
            sum += (digSum % 10) * weight;
            
            left = left->next;
            mi++;
        } while (left);
        
    }
    
    weight = pow(10, mi);
    sum += weight * carry;
    
    return sum;
    
    //    return &ret;
}
