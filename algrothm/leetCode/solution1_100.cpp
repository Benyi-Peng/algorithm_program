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

LinkNode* addTwoNumbers(LinkNode* l1, LinkNode* l2) {
    LinkNode* ret;
    InitList(ret);

    l1 = l1->next;
    l2 = l2->next;

    int weight;
    int mi = 0;
    int carry = 0;
    long sum = 0;

    while (l1 && l2) {
        weight = pow(10, mi);

        int digSum = l1->val + l2->val + carry;
        printf("%d + %d + %d = %d\n",l1->val ,l2->val ,carry , digSum);
        carry = digSum >= 10 ? 1 : 0;

        sum += (digSum % 10) * weight;

        l1 = l1->next;
        l2 = l2->next;
        mi++;
    }

    LinkNode *left; // 剩余的

    if (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            left = l2;
        } else {
            left = l1;
        }
        do {
            weight = pow(10, mi);
            int digSum = left->val + carry;
            carry = digSum >= 10 ? 1 : 0;

            sum += (digSum % 10) * weight;

            left = left->next;
            mi++;
        } while (left);

    }

    weight = pow(10, mi);
    sum += weight * carry;


    do {
        int x = sum % 10;
        mi = ListLength(ret);
        ListInsert(ret, mi, x);
        sum = (sum - x) / 10;
    } while (sum != 0);
    DispList(ret);

    return ret;
}

//LinkNode* addTwoNumbers(LinkNode* l1, LinkNode* l2) {
//    LinkNode* ret;
//    ret = (LinkNode *)malloc(sizeof(LinkNode));
//
//    int weight;
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
//            carry = digSum > 10 ? 1 : 0;
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
//    LinkNode *p, *tail;
//    tail = ret;
//    do {
//        p = (LinkNode *)malloc(sizeof(LinkNode));
//        int x = sum % 10;
//        p->val = x;
//        p->next = NULL;
//
//        tail->next = p;
//        tail = p;
//
//        sum = (sum - x) / 10;
//    } while (sum != 0);
//
//    return ret->next;
//}
