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

//LinkNode* addTwoNumbers(LinkNode* l1, LinkNode* l2) {
//    LinkNode* ret;
//    InitList(ret);
//
//    l1 = l1->next;
//    l2 = l2->next;
//
//    long weight; // 第二次错：weight使用int，数据溢出
//    int mi = 0;
//    int carry = 0;
//    long sum = 0;
//
//    while (l1 && l2) {
//        weight = pow(10, mi);
//
//        int digSum = l1->val + l2->val + carry;
//        printf("%d + %d + %d = %d\n",l1->val ,l2->val ,carry , digSum);
//        carry = digSum >= 10 ? 1 : 0;
//
//        sum += (digSum % 10) * weight;
//
//        l1 = l1->next;
//        l2 = l2->next;
//        mi++;
//    }
//
//    LinkNode *left; // 剩余的
//
//    if (l1 != NULL || l2 != NULL) {
//        if (l1 == NULL) {
//            left = l2;
//        } else {
//            left = l1;
//        }
//        do {
//            weight = pow(10, mi);
//            int digSum = left->val + carry;
//            printf("%d + %d = %d\n",left->val ,carry , digSum);
//            carry = digSum >= 10 ? 1 : 0; // 第一次错: 漏掉了等于号
//
//            sum += (digSum % 10) * weight;
//
//            left = left->next;
//            mi++;
//        } while (left);
//
//    }
//
//    weight = pow(10, mi);
//    sum += weight * carry;
//
//
//    do {
//        int x = sum % 10;
//        mi = ListLength(ret);
//        ListInsert(ret, mi, x);
//        sum = (sum - x) / 10;
//    } while (sum != 0);
//    DispList(ret);
//
//    return ret;
//}

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
    DispList(ret);
    return ret->next;
}
