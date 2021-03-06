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
    LinkNode* mergeTwoLists(LinkNode* l1, LinkNode* l2);
    bool isValid(char* s);
    int removeDuplicates(int* nums, int numsSize);
    int search(int* nums, int numsSize, int target);
    int** permute(int* nums, int numsSize, int* returnSize);
    int** permute1(int* nums, int numsSize, int* returnSize);
    int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize);
    int uniquePaths(int m, int n);
    
#ifdef __cplusplus
}
#endif

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    string longestPalindrome(string s);
    vector<vector<int>> threeSum(vector<int>& nums);
    vector<vector<int>> threeSum1(vector<int> &nums);
    int threeSumClosest(vector<int>& nums, int target);
    LinkNode* mergeKLists(vector<LinkNode*>& lists);
    vector<vector<int>> subsets(vector<int>& nums);
};

#endif /* solution1_100_h */
