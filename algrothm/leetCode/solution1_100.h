//
//  solution1_100.h
//  algorithm
//
//  Created by pbyi on 2019/1/16.
//  Copyright © 2019 pbyi. All rights reserved.
//

#ifndef solution1_100_h
#define solution1_100_h

#include <stdio.h>
#include "linklist.h"

#include <vector>
#include <string>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif
    
    int* twoSum(int* nums, int numsSize, int target);
    LinkNode* addTwoNumbers(LinkNode* l1, LinkNode* l2);
    double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
    char* longestPalindrome(char* s);
    int reverse(int x);
    int reverse1(int x);
    int myAtoi(char* str);
    bool isPalindrome(int x);
    int maxArea(int* height, int heightSize);
    char* longestCommonPrefix(char** strs, int strsSize);
    int** threeSum(int* nums, int numsSize, int* returnSize);
    LinkNode* reverseList(LinkNode* head);
    LinkNode* reverseListRecursive(LinkNode* head);
    
#ifdef __cplusplus
}
#endif

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    string longestPalindrome(string s);
    vector<vector<int>> threeSum(vector<int>& nums);
    vector<vector<int>> threeSum1(vector<int> &nums);
};

#endif /* solution1_100_h */
