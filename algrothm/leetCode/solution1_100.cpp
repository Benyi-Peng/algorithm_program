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

#include <set>

#include <queue>

#pragma mark - Leetcode1 两数之和
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

#pragma mark - Leetcode2 两数相加
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

#pragma mark - Leetcode4 两个有序数组的中位数
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

#pragma mark - Leetcode5 最长回文子串
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
char* longestPalindrome2(char* s) {
    // 1. 得到s的长度
    int n = 0;
    char *p = s;
    while (*p != '\0') {
        p++;
        n++;
    }
    
    // 不包含虚拟节点的下标
    int start = 0;
    int end = 0;
    int maxLength = 0;
    
    int maxId = 0; // 当前最长回文的对称中心(此下标包含虚拟节点)
    int maxRight = 0; // 当前最长回文的最右边(此下标包含虚拟节点)
    int *lengArr = (int *)malloc(sizeof(int) * (2*n + 1));// 记录每个位置上字符的最长回文长度(此长度包含虚拟节点)
    for (int i = 0; i < (2*n + 1); i++) {
        lengArr[i] = 0;
    }
    
    for (int i = 0; i < 2*n + 1; i++) {
        int virtualL = i;
        int virtualR = i;
        if (i <= maxRight) {
            int l = lengArr[2 * i - maxId];
            virtualR = (i + l) < maxRight ? (i + l) : maxRight;
            virtualL = 2 * virtualR - i;
        }
        
        int l = (virtualL - 1) / 2;
        int r = virtualR / 2;
        
        int curMaxLength = 0;
        while (l >= 0 && l < n && r >= 0 && r < n) {
            if (s[l] == s[r]) {
                curMaxLength = r - l + 1;
                if (curMaxLength > maxLength) {
                    start = l;
                    end = r;
                    maxLength = curMaxLength;
                    
                    maxRight = 2 * (r + 1);
                    maxId = i;
                    lengArr[i] = maxRight - maxId;
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
    free(lengArr);
    return ret;
}

#pragma mark - Leetcode7 整数反转
int reverse(int x) {
    int ret = 0;
    // 加减判断标志位，乘法：除回来还是不是原来那个数
    while (x != 0) {
        int temp = ret;
        ret = ret * 10;
        if (ret / 10 != temp) {
            return 0;
        }
        
        int dig = x % 10;
        ret += dig;
        
        x = x / 10;
    }
    return ret;
}

int reverse1(int x) {
    int ret = 0;
    while (x != 0) {
        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && x > 7)) {
            return 0;
        }
        if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && x < -8)) {
            return 0;
        }
        ret = ret * 10;
        
        int dig = x % 10;
        ret += dig;
        
        x = x / 10;
    }
    return ret;
}

#pragma mark - Leetcode8 字符串转整数
int myAtoi(char* str) {
    char *first = str;
    while (*first == ' ') {
        first++;
    }
    if (*first != '+' && *first != '-' && (*first < '0' || *first > '9')) {
        return 0;
    }
    int f = 1;
    int ret = 0;
    
    if (*first == '-') {
        f = -1;
    } else if (*first != '+') {
        ret += (*first - '0');
    }
    
    char *p = ++first;
    while (*p != '\0' && (*p <= '9' && *p >= '0')) {
        if (f == 1 && (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && *p > '7'))) {
            return INT_MAX;
        }
        if (f == -1 && (ret > -(INT_MIN / 10) || (ret == -(INT_MIN / 10) && *p > '8'))) {
            return INT_MIN;
        }
        ret = ret * 10;
        
        ret += (*p - '0');
        
        p++;
    }
    return ret * f;
}

#pragma mark - Leetcode9 回文数
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int temp = x;
    int ret = 0;
    while (x != 0) {
        ret = ret * 10;
        
        int dig = x % 10;
        ret += dig;
        
        x = x / 10;
    }
    
    return temp == ret;
}

#pragma mark - Leetcode11 盛水最多的容器
int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1, maxA= 0;
    while (l < r) {
        int a = (r - l) * min(height[l], height[r]);
        maxA = max(maxA, a);
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return maxA;
}

#pragma mark - Leetcode14 最长公共前缀
bool isEnd(char** ptrs, int ptrSize) {
    for (int i = 0; i < ptrSize; i++) {
        if (*ptrs[i] == '\0') {
            return true;
        }
    }
    return false;
}

void move(char** ptrs, int ptrSize) {
    for (int i = 0; i < ptrSize; i++) {
        ptrs[i]++;
    }
}

bool checkChar(char** ptrs, int ptrSize, char c) {
    for (int i = 0; i < ptrSize; i++) {
        if (*ptrs[i] != c) {
            return false;
        }
    }
    return true;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize < 1) {
        char *ret = (char *)malloc(sizeof(char));
        ret[0] = '\0';
        return ret;
    } else if (strsSize < 2) {
        return strs[0];
    }
    
    int leng = 0;
    char tar = *strs[0];
    
    char **ptrArr = (char **)malloc(sizeof(char *) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        ptrArr[i] = strs[i];
    }
    
    while (!isEnd(ptrArr, strsSize) && checkChar(ptrArr, strsSize, tar)) {
        move(ptrArr, strsSize);
        leng++;
        tar = strs[0][leng];
    }
    
    char *ret = (char *)malloc(sizeof(char) * leng + 1);
    for (int i = 0, j = 0; j < leng; i++,j++) {
        ret[j] = strs[0][i];
    }
    ret[leng] = '\0';
    free(ptrArr);
    return ret;
}

#pragma mark - Leetcode15 三数之和
// 双指针
vector<vector<int>> Solution::threeSum(vector<int> &nums) {
    vector<vector<int>> ret = vector<vector<int>>();
    if (nums.size() < 3) {
        return ret;
    }
    sort(nums.begin(), nums.end());
    if (nums.back() < 0 || nums.front() > 0) {
        return ret;
    }
    if (nums.back() == 0 && nums.front() == 0) {
        return {{0, 0, 0}};
    }
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int num1 = nums[i];
        size_t l = i + 1;
        size_t r = nums.size() - 1;
        while (l < r) {
            if (l > i + 1 && nums[l] == nums[l - 1]) {
                l++;
                continue;
            }
            int n = num1 + nums[l] + nums[r];
            if (n > 0) {
                r--;
            } else if (n < 0) {
                l++;
            } else {
                ret.push_back({num1, nums[l], nums[r]});
                l++;
            }
        }
    }
    return ret;
}

// 超时
vector<vector<int>> Solution::threeSum1(vector<int> &nums) {
    vector<vector<int>> ret = vector<vector<int>>();
    if (nums.size() < 3) {
        return ret;
    }
    bool allZero = true;
    for (int m = 0; m < nums.size(); m++) {
        if (nums[m] != 0) {
            allZero = false;
            break;
        }
    }
    if (allZero) {
        return {{0, 0, 0}};
    }
    vector<int> temp;
    temp.assign(nums.begin(), nums.end());
    
    for (int i = 0; i < temp.size(); i++) {
        int num1 = temp[i];
        temp.erase(temp.begin() + i);
        for (int j = 0; j < temp.size(); j++) {
            int num2 = temp[j];
            temp.erase(temp.begin() + j);
            std::set<int> s;
            for (const int &k : temp) {
                s.insert(k);
            }
            if (s.count(-(num1 + num2)) != 0) {
                bool flag = false;
                if (ret.size() > 0) {
                    for (int j = 0; j < ret.size(); j++) {
                        vector<int> temp = ret[j];
                        vector<int>::iterator it1 = std::find(temp.begin(), temp.end(), num1);
                        bool c1 = it1 != temp.end();
                        if (c1) {
                            temp.erase(it1);
                        }
                        
                        vector<int>::iterator it2 = std::find(temp.begin(), temp.end(), num2);
                        bool c2 = it2 != temp.end();
                        if (c2) {
                            temp.erase(it2);
                        }
                        
                        if (c1 && c2) {
                            flag = true;
                            break;
                        }
                    }
                }
                if (!flag) {
                    vector<int> v = vector<int>();
                    v.push_back(num1);
                    v.push_back(num2);
                    v.push_back(-(num1 + num2));
                    ret.push_back(v);
                }
            }
            temp.insert(temp.begin() + j, num2);
        }
        temp.insert(temp.begin() + i, num1);
    }
    return ret;
}

void swap(int *a, int *b) {
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
    
    return;
}

void quicksort(int array[], int maxlen, int begin, int end) {
    int i, j;
    
    if(begin < end) {
        i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！
        j = end;        // array[end]是数组的最后一位
        
        while(i < j) {
            if(array[i] > array[begin]) {  // 如果比较的数组元素大于基准数，则交换位置。
                swap(&array[i], &array[j]);  // 交换两个数
                j--;
            } else {
                i++;  // 将数组向后移一位，继续与基准数比较。
            }
        }
        
        /* 跳出while循环后，i = j。
         * 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin]
         *                           -->  array[i+1] ~ array[end] > array[begin]
         * 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。
         * 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
         */
        
        if(array[i] >= array[begin]) {  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
            i--;
        }
        
        swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]
        
        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **ret = (int **)malloc(sizeof(int *));
    
    // 1.
    if (numsSize < 3) {
        *returnSize = 0;
        return ret;
    }
    quicksort(nums, numsSize, 0, numsSize - 1);
    if (nums[0] > 0 || nums[numsSize - 1] < 0) {
        *returnSize = 0;
        return ret;
    }
    if (nums[0] == 0 && nums[numsSize - 1] == 0) {
        int *r = (int *)malloc(sizeof(int) * 3);
        for (int i = 0; i < 3; i++) {
            r[i] = 0;
        }

        ret[0] = r;
        *returnSize = 1;
        return ret;
    }
    
    // 2.
    int size = 0;
    for (int i = 0; i < numsSize; i++) {
        
        int num1 = nums[i];
        int l = i + 1;
        int r = numsSize - 1;
        while (l < r) {
            int n = num1 + nums[l] + nums[r];
            if (n > 0) {
                r--;
            } else if (n < 0) {
                l++;
            } else {
                bool flag = false;
                if (size > 0) {
                    for (int j = 0; j < size; j++) {
                        if (ret[j][0] == num1 && ret[j][1] == nums[l] && ret[j][2] == nums[r]) {
                            flag = true;
                        }
                    }
                }
                if (!flag) {
                    size++;
                    ret = (int **)realloc(ret, sizeof(int *) * size);
                    int *arr = (int *)malloc(sizeof(int) * 3);
                    arr[0] = num1;
                    arr[1] = nums[l];
                    arr[2] = nums[r];
                    ret[size - 1] = arr;
                }
                l++;
                r--;
            }
        }
    }
    *returnSize = size;
    return ret;
}

#pragma mark - Leetcode16 最接近的三数之和
int Solution::threeSumClosest(vector<int> &nums, int target) {
    int tmp = 0, ret = 0;
    int delta = INT_MAX;
    if (nums.size() <= 3) {
        for (int i = 0; i < nums.size(); i++) {
            ret += nums[i];
        }
        return ret;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int num1 = nums[i];
        size_t l = i + 1;
        size_t r = nums.size() - 1;
        while (l < r) {
            if (l > i + 1 && nums[l] == nums[l - 1]) {
                l++;
                continue;
            }
            tmp = num1 + nums[l] + nums[r];
            
            if (abs(tmp - target) == 0) {
                return tmp;
            } else if (abs(tmp - target) < delta) {
                ret = tmp;
                delta = abs(tmp - target);
            } else {
                if (tmp > target) {
                    r--;
                } else if (tmp < target) {
                    l++;
                }
            }
        }
    }
    return ret;
}

#pragma mark - Leetcode20 有效的括号
bool isValid(char* s) {
    char *p = s;
    int top = 0;
    while (*p != '\0') {
        top++;
        p++;
    }
    if (top == 0)
        return true;
    char *stack = (char *)malloc(sizeof(char) * top);

    p = s;
    top = 0;
    while (*p != '\0' && top >= 0) {
        stack[top] = *p;

        if (*p == ')') {
            if (top > 0 && stack[top - 1] == '(') {
                top -= 2;
            }
        } else if (*p == ']') {
            if (top > 0 && stack[top - 1] == '[') {
                top -= 2;
            }
        } else if (*p == '}') {
            if (top > 0 && stack[top - 1] == '{') {
                top -= 2;
            }
        }


        top++;
        p++;
    }
    free(stack);
    return top == 0;
}


#pragma mark - Leetcode21 合并两个有序链表
LinkNode* mergeTwoLists(LinkNode* l1, LinkNode* l2) {
    LinkNode *head = NULL;
    LinkNode *cur = NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    
    cur = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }
    }
    
    if (l1) {
        cur->next = l1;
    } else if (l2) {
        cur->next = l2;
    }
    
    return head;
}

#pragma mark - Leetcode23 合并K个有序链表
struct cmp{
    bool operator()(const LinkNode* p1,const LinkNode* p2){
        return p1->val>p2->val;
    }
};
LinkNode* Solution::mergeKLists(vector<LinkNode *> &lists) {
    if (lists.empty())
        return NULL;
    priority_queue<LinkNode*, vector<LinkNode*>, cmp> heap;
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL)
            heap.push(lists[i]);
    }
    LinkNode *newHead = NULL;
    LinkNode *top = NULL;
    LinkNode *cur = NULL;
    while (!heap.empty()) {
        top = heap.top();
        heap.pop();
        if (newHead == NULL) {
            newHead = top;
        } else {
            cur->next = top;
        }
        cur = top;
        
        if (top->next != NULL) {
            heap.push(top->next);
        }
    }
    return newHead;
}

#pragma mark - Leetcode26 删除排序数组中的重复项
int removeDuplicates(int* nums, int numsSize) {
    int cur = 0, p = 0;
    while(p < numsSize) {
        nums[cur] = nums[p];
        while(p < numsSize && nums[cur] == nums[p]) {
            p++;
        }
        cur++;
    }
    return cur;
}

#pragma mark - Leetcode33 搜索旋转排序数组
int search(int* nums, int numsSize, int target) {
    if (numsSize == 0) {
        return -1;
    }
    
    int ret = -1;
    int l = 0;
    int r = numsSize - 1;
    int mid = 0;
    
    if (nums[r] < nums[l]) {
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[l] < nums[mid]) {
                l = mid;
            } else {
                r = mid;
            }
            
        }
        mid = l;
        
        if (target < nums[0]) {
            l = mid + 1;
            r = numsSize - 1;
        } else {
            l = 0;
            r = mid;
        }
    }
    
    
    while(l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            ret = mid;
            break;
        }
    }
    
    
    return ret;
}

#pragma mark - Leetcode43 字符串相乘
char* multiply(char* num1, char* num2) {
    if (*num1 == '0' || *num2 == '0' ) {
        return "0";
    }
    char *p1 = num1, *p2 = num2;
    int *tmp;
    int len1 = 0, len2 = 0;
    while(*p1 != '\0') {
        len1++;
        p1++;
    }
    while(*p2 != '\0') {
        len2++;
        p2++;
    }
    
    tmp = (int*)malloc(sizeof(int) * (len1 + len2));
    for(int i = 0; i < len1 + len2; i++) {
        tmp[i] = 0;
    }
    for(int i = len1 - 1; i >= 0; i--) {
        for(int j = len2 - 1; j >= 0; j--) {
            tmp[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for(int i = len1 + len2 - 1; i >= 0; i--) {
        if (i > 0)
            tmp[i-1] += tmp[i] / 10;
        tmp[i] = tmp[i] % 10;
    }
    
    
    int len = len1 + len2;
    int* t1 = tmp;
    if (tmp[0] == 0) {
        len = len1 + len2 - 1;
        tmp++;
    }
    char *ret = (char*)malloc(sizeof(char) * (len + 1));
    ret[len] = '\0';
    
    for(int i = 0; i < len; i++) {
        ret[i] = tmp[i] + '0';
    }
    
    free(t1);
    return ret;
}

#pragma mark - Leetcode46 全排列
// 非递归1
void Swap(int *a ,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int* getArrange(int* nums, int numsSize) {
    int *ret = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        ret[i] = nums[i];
    }
    return ret;
}
int** permute(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 1;
        return NULL;
    }
    int all = 1;
    int num = numsSize;
    while (num > 0) {
        all *= num;
        num--;
    }
    *returnSize = all;
    
    int** ret = (int **)malloc(sizeof(int*) * all);
    
    int* istack = (int*)malloc(sizeof(int) * numsSize);
    int* startStack = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        istack[i] = i;
        startStack[i] = i;
    }
    
    int retIdx = 0;
    int top = numsSize - 1;
    int direct = 0; // 0 top往下(栈底)走   1 top往上(栈顶)走
    while (top >= 0) {
        if (startStack[top] == numsSize - 1) {
            ret[retIdx] = getArrange(nums, numsSize);
            retIdx++;
            top--;
            if (top >= 0) {
                Swap(nums + startStack[top], nums + istack[top]);
            } else {
                break;
            }
            direct = 0;
        } else {
            if (istack[top] == numsSize - 1) {
                top--;
                if (top >= 0) {
                    Swap(nums + startStack[top], nums + istack[top]);
                } else {
                    break;
                }
                direct = 0;
            } else {
                if (direct == 0) {
                    istack[top]++;
                }
                Swap(nums + startStack[top], nums + istack[top]);
                top++;
                direct = 1;
                istack[top] = top;
                startStack[top] = top;
            }
        }
    };
    
    free(startStack);
    free(istack);
    return ret;
}

void getPermute_R(int* nums, int start, int numsSize, int** ret, int* retIdx) {
    if (start == numsSize - 1) {
        ret[*retIdx] = getArrange(nums, numsSize);
        *retIdx += 1;
    } else {
        for (int i = start; i < numsSize; i++) {
            Swap(nums + start, nums + i);
            getPermute_R(nums, start + 1, numsSize, ret, retIdx);
            Swap(nums + start, nums + i);
        }
    }
}

int** permute1(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 1;
        return NULL;
    }
    int all = 1;
    int num = numsSize;
    while (num > 0) {
        all *= num;
        num--;
    }
    *returnSize = all;
    
    int** ret = (int **)malloc(sizeof(int*) * all);
    
    int retIdx = 0;
    getPermute_R(nums, 0, numsSize, ret, &retIdx);
    
    return ret;
}

#pragma mark - Leetcode53 最大子序和
int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int sum = nums[0];
    int max = nums[0];
    for(int i = 1; i < numsSize; i++) {
        if (sum < 0)
            sum = nums[i];
        else
            sum += nums[i];
        if (sum > max)
            max = sum;
    }
    return max;
}

#pragma mark - Leetcode 54 螺旋矩阵
void spiralOrder_R(int** matrix, int rowStart, int colStart ,int matrixRowSize, int matrixColSize, int *ret, int start) {
    if (matrixRowSize <= 0 || matrixColSize <= 0) {
        return;
    }
    for (int i = 0; i < matrixColSize; i++) {
        ret[start] = matrix[rowStart][i + colStart];
        start++;
    }
    
    if (matrixRowSize > 1) {
        for (int i = 1; i < matrixRowSize; i++) {
            ret[start] = matrix[i + rowStart][matrixColSize - 1 + colStart];
            start++;
        }
        
        if (matrixColSize > 1) {
            for (int i = matrixColSize - 2; i >= 0; i--) {
                ret[start] = matrix[matrixRowSize - 1 + rowStart][i + colStart];
                start++;
            }
            
            if (matrixRowSize > 2) {
                for (int i = matrixRowSize - 2; i >= 1; i--) {
                    ret[start] = matrix[i + rowStart][colStart];
                    start++;
                }
            }
        }
    }
    
    if (matrixRowSize > 2 && matrixColSize > 2) {
        spiralOrder_R(matrix, rowStart + 1, colStart + 1, matrixRowSize - 2, matrixColSize - 2, ret, start);
    }
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *ret = (int*)malloc(sizeof(int) * matrixColSize * matrixRowSize);
    spiralOrder_R(matrix, 0, 0, matrixRowSize, matrixColSize, ret, 0);
    return ret;
}

#pragma mark - Leetcode 59 螺旋矩阵2
int** generateMatrix(int n) {
    int **ret = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        int* a = (int*)malloc(sizeof(int) * n);
        ret[i] = a;
    }
    
    int matrixRowSize = n;
    int matrixColSize = n;
    int rowStart = 0;
    int colStart = 0;
    int num = 1;
    
    while (matrixRowSize > 0 && matrixColSize > 0) {
        for (int i = 0; i < matrixColSize; i++) {
            ret[rowStart][i + colStart] = num;
            num++;
        }
        
        if (matrixRowSize > 1) {
            for (int i = 1; i < matrixRowSize; i++) {
                ret[i + rowStart][matrixColSize - 1 + colStart] = num;
                num++;
            }
            
            if (matrixColSize > 1) {
                for (int i = matrixColSize - 2; i >= 0; i--) {
                    ret[matrixRowSize - 1 + rowStart][i + colStart] = num;
                    num++;
                }
                
                if (matrixRowSize > 2) {
                    for (int i = matrixRowSize - 2; i >= 1; i--) {
                        ret[i + rowStart][colStart] = num;
                        num++;
                    }
                }
            }
        }
        
        matrixRowSize -= 2;
        matrixColSize -= 2;
        rowStart++;
        colStart++;
    }
    
    return ret;
}

LinkNode* rotateRight(LinkNode* head, int k) {
    
    return NULL;
}

#pragma mark - Leetcode62 不同路径
int uniquePaths(int m, int n) {
    int** pathes = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        int *a = (int*)malloc(sizeof(int) * n);
        if (i == 0) {
            for (int j = 0; j < n; j++) {
                a[j] = 1;
            }
        }
        a[0] = 1;
        pathes[i] = a;
    }
    if (m == 1 || n == 1) {
        return 1;
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            pathes[i][j] = pathes[i - 1][j] + pathes[i][j - 1];
        }
    }
    int ret = pathes[m - 1][n - 1];
    free(pathes);
    return ret;
}

#pragma mark - Leetcode78 子集
void subset_R(vector<int> &nums, vector<int> curSet,int start, vector<vector<int>> ret) {
    for (int i = start; i < nums.size(); i++) {
        curSet.push_back(nums[i]);
        ret.push_back(curSet);
        subset_R(nums, curSet, i + 1, ret);
        curSet.pop_back();
    }
}

vector<vector<int>> Solution::subsets(vector<int> &nums) {
    vector<vector<int>> ret;
    vector<int> curSet;
    ret.push_back(curSet);
    subset_R(nums, curSet, 0, ret);
    return ret;
}

#pragma mark - Leetcode 146 LRU缓存机制


#pragma mark - Leetcode 124 二叉树中最大路径和
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int calculate(struct TreeNode* root, int *Max) {
    if (root == NULL)
        return 0;
    
    int tmp = root->val;
    int leftMax = calculate(root->left, Max);
    int rightMax = calculate(root->right, Max);
    
    if (leftMax > 0) {
        tmp += leftMax;
    }
    
    if (rightMax > 0) {
        tmp += rightMax;
    }
    
    if (tmp > *Max) {
        *Max = tmp;
    }
    
    int ret = root->val;
    ret = max(ret, root->val + leftMax);
    ret = max(ret, root->val + rightMax);
    ret = max(ret, root->val + leftMax + rightMax);
    return ret;
}

int maxPathSum(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    
    int Max = INT_MIN;
    calculate(root, &Max);
    return Max;
}

int Max(int a,int b){
    return a>b?a:b;
}
int FindMax(struct TreeNode* root,int* max){
    if(root==NULL)
        return 0;
    int left=Max(0,FindMax(root->left,max));
    int right=Max(0,FindMax(root->right,max));
    *max=Max(*max,left+right+root->val);
    return Max(left,right)+root->val;
}
int maxPathSum1(struct TreeNode* root) {
    int max=INT_MIN;
    FindMax(root,&max);
    return max;
}

#pragma mark - Leetcode 206 反转链表
LinkNode* reverseList(LinkNode* head) {
    LinkNode *pre = NULL;
    LinkNode *cur;
    LinkNode *tmp;

    cur = head->next;

    while (cur) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }

    head->next = pre;
    return head;
}

LinkNode* reverseListRecursive(LinkNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    LinkNode *tmp = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return tmp;
}

