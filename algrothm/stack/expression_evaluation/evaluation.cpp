//
//  evaluation.c
//  algorithm
//
//  Created by pbyi on 2018/8/15.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "evaluation.h"

#include "sqstack.h"

#include <string.h>

bool trans(char *exp, char postExp[]) {
    Stack *s;
    StackNew(s, sizeof(char));
    
    int postIndex = 0;
    while (*exp != '\0') {
        switch (*exp) {
            case '(':
                StackPush(s, exp++);
                break;
            case ')':
                char top;
                StackGetTop(s, &top);
                while (top != '(') {
                    StackPop(s, &top);
                    postExp[postIndex++] = top;
                    
                    StackGetTop(s, &top);
                }
                StackPop(s, &top);
                exp++;
                break;
            case '+':
            case '-':
                StackGetTop(s, &top);
                while (!StackEmpty(s) && top != '(') {
                    StackPop(s, &top);
                    postExp[postIndex++] = top;
                    
                    StackGetTop(s, &top);
                }
                StackPush(s, exp++);
                break;
            case '*':
            case '/':
                StackGetTop(s, &top);
                while (!StackEmpty(s) && top != '(' && top != '+' && top != '-') {
                    StackPop(s, &top);
                    postExp[postIndex++] = top;
                    
                    StackGetTop(s, &top);
                }
                StackPush(s, exp++);
                break;
            default:
                if (*exp == ' ') {
                    exp++; 
                    continue;
                }
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
    
    while (!StackEmpty(s)) {
        char top;
        StackPop(s, &top);
        postExp[postIndex++] = top;
    }
    postExp[postIndex] = '\0';
    StackDestroy(s);
    return true;
}

bool calculatePostExep(char postExp[], double &ret) {
    Stack *op;
    StackNew(op, sizeof(double));

    double op1 = 0, op2 = 0, end = 0;
    while (*postExp != '\0') {
        switch (*postExp) {
            case '+':
                StackPop(op, &op1);
                StackPop(op, &op2);
                end = op1 + op2;
                StackPush(op, &end);
                break;
            case '-':
                StackPop(op, &op1);
                StackPop(op, &op2);
                end = op2 - op1;
                StackPush(op, &end);
                break;
            case '*':
                StackPop(op, &op1);
                StackPop(op, &op2);
                end = op1 * op2;
                StackPush(op, &end);
                break;
            case '/':
                StackPop(op, &op1);
                StackPop(op, &op2);
                end = op2 / op1;
                StackPush(op, &end);
                break;
            default:
                double d = 0;
                while (*postExp <= '9' && *postExp >= '0') {
                    d = 10 * d + *postExp - '0';
                    postExp++;
                }
                StackPush(op, &d);
                break;
        }
        printf("%c\n", *postExp);
        postExp++;
    }
    
    StackGetTop(op, &ret);
    StackDestroy(op);
    return true;
}

bool calculate(char *exp, double &ret) {
    char postExp[Maxsize];
    memset(postExp, 0, MaxSize);
    trans(exp, postExp);
    printf("%s\n", postExp);
    calculatePostExep(postExp, ret);
    
    
    return true;
}
