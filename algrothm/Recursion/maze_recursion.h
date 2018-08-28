//
//  maze_recursion.h
//  algorithm
//
//  Created by pbyi on 2018/8/19.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#ifndef maze_recursion_h
#define maze_recursion_h

#include <stdio.h>

#define MaxSize 100

typedef struct {
    int row;
    int col;
} RBox;

typedef struct {
    RBox p[MaxSize];
    int length;
} RPath;


#ifdef __cplusplus
extern "C" {
#endif
    
    int maze_recursion(int xi, int yi, int xe, int ye, RPath path);
    int maze_recursion2(int xi, int yi, int xe, int ye, RPath path);
    
#ifdef __cplusplus
}
#endif



#endif /* maze_recursion_h */
