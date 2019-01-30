#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time()
{
    struct timeval t;
    gettimeofday(&t,NULL);
    return t.tv_sec + t.tv_usec/1000000.0;
}


int main(int argc, char const *argv[])
{     
      double t1,t2;
      t1 = get_time();
      printf("%f", t1);

      for(int i = 0; i < 10000; i++)
      {
            printf("");
      }
      t2 = get_time();
      printf("runtime is %f\n",t2-t1);

      return 0;
}
