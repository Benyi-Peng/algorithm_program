//
//  main.c
//  algorithm
//
//  Created by pbyi on 2018/6/10.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include <stdio.h>

#include "kmp.h"

//#include "mgpath.h"





int main(int argc, const char * argv[]) {

    
    
    return 0;
}







//void kmpSample(void) {
//    int ret;
//
//    SqString s;
//    char target[24] = "BBC ABCDAB ABCDABCDABDE";
//    for (int i = 0; i < 24; i++) {
//        s.data[i] = target[i];
//    }
//    s.length = 24;
//
//    SqString p;
//    char pattern[7] = "ABCDABD";
//    for (int i = 0; i < 7; i++) {
//        p.data[i] = pattern[i];
//    }
//    p.length = 7;
//
//
//    if ((ret = kmpMatch(s, p)) == -1) {
//        printf("Cannot find %s\n", p.data);
//    } else {
//        printf("Find at : %d\n", ret);
//    }
//}
