#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <pthread.h>
#include "time.h"
#include "readwritefile.h"

long MAX;  //整数范围 1 ～ MAX
int N;     //创建N 个子线程求和
int AVE;   //每个子线程处理的整数个数
long *sum; //保存各个子线程计算的结果

//求取最终的结果
long correct_answer(){
    long answer = 0;
    for(int i = 0; i <= MAX; i++)
    {
        answer = answer + i;
    }
    return answer;
}

//求和子线程
void *sum_work(void *arg)
{
    int n = *((int *)arg); //第n部分
    long long start = n * AVE + 1;
    long long end;
    if (n < N -1)
    {
        end = start + AVE - 1;
    }
    else
    {
        end = MAX;
    }

    int i;
    sum[n] = 0;
    //计算start ~ end 范围的整数和
    for (i = start; i <= end; i++)
    {
        sum[n] = sum[n] + i;
    }
    // printf("第%d组所求和为：%ld\n", n, sum[n]);
    pthread_exit(NULL);
}

int run_thread(const char *fileInput, const char *fileOutput)
{
    getInput(&N, &MAX, fileInput);
    AVE = MAX / N;
    sum = (long *)malloc(N * sizeof(long));
    printf("Value of N is %d\n", N);
    printf("Value of M is %ld\n", MAX);
    double t1, t2;           //先后时间
    pthread_t pthread_id[N]; //保存子线程id
    long result = 0;         //累加结果
    int indexes[N];          //暂存n

    //获取时间
    t1 = get_time();

    //创建N个子线程
    for (int i = 0; i < N; i++)
    {
        indexes[i] = i;
        int ret = pthread_create(&pthread_id[i], NULL, sum_work, (void *)&indexes[i]);
        // printf("i的值为：%d\n", i);
    }

    for (int i = 0; i < N; i++)
    {
        //等待子线程结束，如果该子线程已经结束，则立即返回
        pthread_join(pthread_id[i], NULL);
        result += sum[i];
    }

    t2 = get_time();
    printf("Result is %ld\n", result);
    printf("Correct answer is %ld\n", correct_answer());
    if (result == correct_answer()) {
        printf("Thread alculation is right\n");
    }else
    {
        printf("Thread alculation is wrong\n");
    }
    
    
    printf("Run time is %f\n", t2 - t1);
    setOutput(result, fileOutput);
    // pthread_exit(0);
    return 0;
}

