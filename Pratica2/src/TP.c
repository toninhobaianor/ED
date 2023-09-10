#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/TP.h"

int fatorial_rec(int x){
    if(x == 1 || x == 0){
        return 1;
    }
    else{
        return fatorial_rec(x - 1) * x;
    }
}

int fatorial_ite(int x){
    int res = 1;
    for(int i = 1; i <= x;i++){
        res *= i;
    }
    return res;
}

int fibonaci_rec(int x){
    if(x == 1 || x == 0){
        return 1;
    }
    else{
        return (fibonaci_rec(x - 1) + fibonaci_rec(x - 2));
    }
}

int fibonaci_ite(int x){
    int pri = 1;
    int seg = 1;
    int res = 0;
    if(x == 1 || x == 2){
        return 1;
    }
    for(int i = 1;i <= x-1;i++){
        res = pri + seg;
        pri = seg;
        seg = res;
    }
    return res;
}