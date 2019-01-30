#include <pthread.h>
#include "common.h"

//求和子线程
void* sum_work(void* arg)
{

    int n = *((int*)arg);  //第n部分
    printf("n:%d\n",n);
    long long      start = n*AVE+1;
    long long      end = start + AVE -1;
    printf("start：%lld\n", start);
    printf("end：%lld\n", end);
    long long      i;
    sum[n] = 0;
    //计算start ~ end 范围的整数和
    for(i = start; i <= end;i++)
    {
        printf("%lld\n",i);
        sum[n] = sum[n] + i;
    }
    printf("第%d组所求和为：%lld\n", n, sum[n]);
    pthread_exit(NULL);
}