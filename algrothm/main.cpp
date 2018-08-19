//
//  main.c
//  algorithm
//
//  Created by pbyi on 2018/6/10.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include <stdio.h>

#include "kmp.h"

#include "mgpath.h"

#include "evaluation.h"

#include "SqQueue.h" 

#include "nqueen.h"

#include "mgpath_queue.h"

void kmpSample(void);


int main(int argc, const char * argv[]) {

//    kmpSample();
        
//    mgpath_GenericStack(1, 1, 8, 8);
//    printf("all solutions : %zd\n", mgpath_all(1, 1, 8, 8));
    
//    char *exp = "56 - 20 / (1 + 2 * 2)";
//    double ret;
//    calculate(exp, ret);
//    printf("%f\n", ret);
//    return 0;
    
//    queen();
//    eightQueen_1();
    
//    testQueue();
    
    maze_queue(1, 1, 8, 8);
}








