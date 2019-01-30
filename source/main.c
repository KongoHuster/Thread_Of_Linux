#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "time.h"
#include <pthread.h>

#define MAX     1000         //整数范围 1 ～ MAX
#define N       20           //创建N 个子线程求和
#define AVE     (MAX/N)      //每个子线程处理的整数个数
long long     sum[N];        //保存各个子线程计算的结果

//求和子线程
void* sum_work(void* arg)
{

    int n = *((int*)arg);  //第n部分
    printf("n:%d\n",MAX);
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

int main(int argc, char const *argv[])
{     
    double t1,t2;
    pthread_t pthread_id[N]; //保存子线程id  
    int i = 0;
    long long result = 0;
    int indexes[N];
    t1 = get_time();
    printf("%f\n", t1);
    
  
    //创建N个子线程
    for(int i = 0; i < N; i++)
    {
        indexes[i] = i;
        int ret = pthread_create(&pthread_id[i], NULL, sum_work, (void *)&indexes[i]);
        printf("i的值为：%d\n", i);
    }

    for(i=0;i<N;i++)
    {
        //等待子线程结束，如果该子线程已经结束，则立即返回
        pthread_join(pthread_id[i],NULL);
        result += sum[i];
    }

    t2 = get_time();
    printf("result is : %lld\n",result);
    printf("runtime is %f\n",t2-t1);
    pthread_exit(0);
    return 0;
}
