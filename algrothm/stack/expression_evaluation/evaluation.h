//
//  evaluation.h
//  algorithm
//
//  Created by pbyi on 2018/8/15.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#ifndef evaluation_h
#define evaluation_h

#include <stdio.h>
#include <stdbool.h>


#define Maxsize 100 


#ifdef __cplusplus
extern "C" {
#endif
    
    
bool calculate(char *exp, double &ret);
    
    
#ifdef __cplusplus
}
#endif



#endif /* evaluation_h */
