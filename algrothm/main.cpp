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

#include "hanioTower.h"

#include "maze_recursion.h"

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
    
//    maze_queue(1, 1, 8, 8);
    
//    tower(4, 'x', 'y', 'z');
//    printf("\n\n\n");
//    tower_stack(4, 'x', 'y', 'z');
    
    RPath path;
    maze_recursion(1, 1, 8, 8, path); 
}








