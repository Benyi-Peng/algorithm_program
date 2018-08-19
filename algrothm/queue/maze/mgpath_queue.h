//
//  mgpath_queue.h
//  algorithm
//
//  Created by pbyi on 2018/8/19.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#ifndef mgpath_queue_h
#define mgpath_queue_h

#include <stdio.h>

typedef struct {
    int i;
    int j;
    int pre;
} QBox;

#ifdef __cplusplus
extern "C" {
#endif
    
    int maze_queue(int xi, int yi, int xe, int ye);
    
#ifdef __cplusplus
}
#endif

#endif /* mgpath_queue_h */
