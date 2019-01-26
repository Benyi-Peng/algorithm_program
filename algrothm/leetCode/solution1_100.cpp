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
#include <string.h>


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

// 添加虚拟#号 https://blog.csdn.net/hk2291976/article/details/51107778
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t n = nums1.size();
    size_t m = nums2.size();
    if (n + m == 0) return 0;
    if (n == 0) {
        if (m & 0x1) { // 奇数
            return nums2[m / 2];
        } else {
            return (nums2[(m/2)] + nums2[(m/2) - 1]) / 2.0;
        }
    } else if (m == 0) {
        if (n & 0x1) { // 奇数
            return nums1[n / 2];
        } else {
            return (nums1[(n/2)] + nums1[(n/2) - 1]) / 2.0;
        }
    }
    if (n > m) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int l1,l2,r1,r2;
    size_t c1,c2,low = 0, high = 2 * n;
    while (low <= high) {
        c1 = (low + high) / 2;
        c2 = (m + n) - c1;
        l1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2];
        r1 = c1 == 2*n ? INT_MAX : nums1[c1 / 2];
        l2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2];
        r2 = c2 == 2*m ? INT_MAX : nums2[c2 / 2];
        
        if (l1 > r2) {
            high = c1 - 1;
        } else if (l2 > r1) {
            low = c1 + 1;
        } else
            break;
    }
    
    return (max(l1, l2) + min(r1,r2)) / 2.0;
}

// 递归求解 https://blog.csdn.net/yutianzuijin/article/details/11499917
double findKth(int* n1, int n1Size, int* n2, int n2Size, int k) {
    if (n1Size > n2Size) {
        return findKth(n2, n2Size, n1, n1Size, k);
    }
    if (n1Size == 0) {
        return n2[k - 1];
    }
    if (k == 1) {
        return min(n1[0], n2[0]);
    }
    int pa = min(k >> 1, n1Size);
    int pb = k - pa;
    printf("pa: %d\npb: %d\n", pa, pb);
    if (n1[pa - 1] < n2[pb - 1]) {
        return findKth(n1 + pa, n1Size - pa, n2, n2Size, k - pa);
    } else if (n1[pa - 1] > n2[pb - 1]) {
        return findKth(n1, n1Size, n2 + pb, n2Size - pb, k - pb);
    } else {
        return n1[pa - 1];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if (total & 0x1) {
        return findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
    } else {
        int p1 = findKth(nums1, nums1Size, nums2, nums2Size, total / 2);
        int p2 = findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
        return (p1 + p2) / 2;
    }
    return 0;
}

// 1. 暴力
bool check(string s, size_t low, size_t high) {
    while (low <= high) {
        if (s.at(low) == s.at(high)) {
            low++;
            high--;
        } else {
            return false;
        }
    }
    return true;
}
string Solution::longestPalindrome(string s) {
    for (size_t size = s.size(); size > 0; size--) {
        for (size_t low = 0, high = low + size - 1; high < s.size(); low++, high++) {
            if (check(s, low, high)) {
                return s.substr(low, high - low + 1);
            }
        }
    }
    return "a";
}

// 2. 中心扩展
char* longestPalindrome(char* s) {
    // 1. 得到s的长度
    int n = 0;
    char *p = s;
    while (*p != '\0') {
        p++;
        n++;
    }

    // 2. 得到填充#后的串temp
    char *temp = (char *)malloc(sizeof(char) * (2 * n + 1));
    memset(temp, '#', 2*n + 1);

    for (int i = 0; i < 2*n + 1; i += 2) {
        temp[i + 1] = s[i / 2];
    }
    printf("%s\n", temp);

    int start = 0;
    int end = 0;
    int maxLength = 0;

    for (int i = 0; i < 2*n + 1; i++) {
        int l = (i - 1) / 2;
        int r = i / 2;
        int curMaxLength = 0;
        while (l >= 0 && l < n && r >= 0 && r < n) {
            if (s[l] == s[r]) {
                curMaxLength = r - l + 1;
                if (curMaxLength > maxLength) {
                    start = l;
                    end = r;
                    maxLength = curMaxLength;
                }
                l--;
                r++;
            } else
                break;
        }
    }

    int leng = end - start + 1;
    char *ret = (char *)malloc(sizeof(char) * leng + 1);
    for (int i = start, j = 0; j < leng; i++,j++) {
        ret[j] = s[i];
    }
    ret[leng] = '\0';
    return ret;
}

// 3. Manacher
//char* longestPalindrome(char* s) {
//    
//}
