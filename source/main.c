#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "common.h"
#include "thread.h"

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
