//
//  kmp.h
//  algorithm
//
//  Created by oe on 2018/8/13.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#ifndef kmp_h
#define kmp_h

#include <stdio.h>

#define Maxsize 100

typedef struct sq {
    char data[Maxsize];
    int length;
} SqString;

int kmpMatch(SqString s, SqString p);
#endif /* kmp_h */
