//
//  mgpath.c
//  agrothim
//
//  Created by pbyi on 2018/8/12.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include "mgpath.h"


#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2]=
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};


int mgpath() {
    return 1;
}
