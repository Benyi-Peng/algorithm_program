//
//  evaluation.c
//  algorithm
//
//  Created by pbyi on 2018/8/15.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "evaluation.h"

bool trans(char *exp, char postExp[]) {
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
