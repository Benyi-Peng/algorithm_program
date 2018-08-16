//
//  evaluation.c
//  algorithm
//
//  Created by pbyi on 2018/8/15.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "evaluation.h"

#include "sqstack.h" 

bool trans(char *exp, char postExp[]) {
    Stack *s;
    StackNew(s, sizeof(char));
    
    int postIndex = 0;
    while (*exp != '\0') {
        switch (*exp) {
            case '(':
                StackPush(s, exp);
                break;
            case ')':
                
                break;
            case '+':
                
                break;
            case '-':
                
                break;
            case '*':
                
                break;
            case '/':
                
                break;
            default:
                //非法字符
                if (*exp > '9' || *exp < '0') {
                    return false;
                }
                while (*exp <= '9' && *exp >= '0') {
                    postExp[postIndex] = *exp;
                    exp++;
                    postIndex++;
                }
                postExp[postIndex++] = '#';
                break;
        }
    }
    
    return true;
}

bool calculatePostExep(char postExp[], double &ret) {
    return true;
}

bool calculate(char *exp, double &ret) {
    char postExp[Maxsize];
    
    trans(exp, postExp);
    calculatePostExep(postExp, ret);
    
    return true;
}
