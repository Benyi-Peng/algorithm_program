//
//  main.c
//  agrothim
//
//  Created by pbyi on 2018/6/10.
//  Copyright © 2018年 pbyi. All rights reserved.
//

#include <stdio.h>

#include <fcntl.h>

#include <unistd.h>
#include <limits.h>

#include <sys/stat.h>

#include "mgpath.h"

void fun(int n) {
    if (n == 1) {
        printf("a:%d\n", n);
    } else {
        printf("b:%d\n", n);
        fun(n-1);
        printf("c:%d\n", n);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    
//    openat(AT_FDCWD, <#const char *#>, <#int, ...#>)
//    open(<#const char *#>, <#int, ...#>)
    
//    _POSIX_V7_ILP32_OFF32;
//    sysconf(<#int#>)

//    struct stat ta;
//    stat("dev/fd", &ta);
//
//    ta.st_mode;
//    S_ISSOCK(ta.st_mode);
//
//    S_TYPEISSEM(&ta);
    fun(5);
    
    
    return 0;
}
