#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <semaphore.h>
#include "time.h"
#include "readwritefile.h"

#define PERM S_IRUSR | S_IWUSR

long MAX; //整数范围 1 ～ MAX
int N;    //创建N 个子线程求和
int AVE;  //每个子线程处理的整数个数

typedef struct
{
    long number;
    long sum;
    sem_t signal;
} Process;

//求取最终的结果
long correct_answer()
{
    long answer = 0;
    for (int i = 0; i <= MAX; i++)
    {
        answer = answer + i;
    }
    return answer;
}

int run_thread(const char *fileInput, const char *fileOutput)
{
    getInput(&N, &MAX, fileInput);
    AVE = MAX / N;
    printf("Value of N is %d\n", N);
    printf("Value of M is %ld\n", MAX);

    if (N < 1 || N >= 100)
    {
        printf("N is out of 1 and 100.\n");
        return -1;
    }

    if (MAX < 0 || MAX >= 4294967296)
    {
        printf("M is out of 0 and 4294967296.\n");
        return -1;
    }

    double t1, t2; //先后时间
    // pthread_t pthread_id[N]; //保存子线程id
    long result = 0; //累加结果
    Process *pProcess;
    int share_memory_id;

    //分配共享内存空间
    int shm_id;
    Process *pProcess;

    printf("111  %d\n", PERM);
    if ((shm_id = shmget(IPC_PRIVATE, sizeof(Process), PERM)) == -1)
    {
        printf("Create Share Memory Error.\n");
        return -1;
    }

    pProcess = (Process *)shmat(share_memory_id, NULL, 0);
    pProcess->number = 0;
    pProcess->sum = 0;

    // //初始化信號量
    // sem_init(&pProcess->signal, 0, 1);
    // pid_t pid;
    // int status;

    // //获取时间
    // t1 = get_time();

    // for (int i = 0; i < N; i++)
    // {
    //     pid = fork();
    //     //返回子進程的id
    //     if (pid == 0 || pid == -1)
    //     {
    //         perror("Error happen!\n");
    //         break;
    //     }
    // }

    // if (pid == -1)
    // {
    //     printf("Fail to fork!\n");
    //     return -1;
    // }
    // else if (pid == 0)
    // {
    //     while (pProcess->number <= MAX)
    //     {

    //         // printf("S : %d\n", pProcess->S);
    //         sem_wait(&pProcess->signal);
    //         if (pProcess->number <= MAX)
    //         {
    //             pProcess->sum += pProcess->number++;
    //         }
    //         sem_post(&pProcess->signal);
    //         //  printf("S1 : %d\n", pProcess->S);
    //     }
    // }
    // else
    // {
    //     wait(&status);

    //     sem_destroy(&pProcess->signal);
    //     t2 = get_time();

    //     long answer = correct_answer();
    //     printf("Result is %ld\n", result);
    //     printf("Correct answer is %ld\n", answer);
    //     if (result == answer)
    //     {
    //         printf("Thread alculation is right\n");
    //     }
    //     else
    //     {
    //         printf("Thread alculation is wrong\n");
    //     }

    //     printf("Run time is %f\n", t2 - t1);
    //     setOutput(result, fileOutput);
    // }

    // pthread_exit(0);
    return 0;
}