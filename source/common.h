#ifndef COMMON.H
#define COMMON.H

#define MAX     1000         //整数范围 1 ～ MAX
#define N       20           //创建N 个子线程求和
#define AVE     (MAX/N)      //每个子线程处理的整数个数
long long     sum[N];        //保存各个子线程计算的结果

#endif