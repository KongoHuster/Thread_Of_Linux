#include <stdio.h>

long long correct_answer()
{
    long long answer=0;
//     for(int i = 0; i < 62; i++)
//     {
//           answer = 2*answer;
//     }
    
    for (long i = 0; i <= 4294967295; i++)
    {
        answer = answer + i;
        printf("%ld\n", i);
    }

    printf("answer is %lld\n", answer);
    return answer;
}


int main()
{
      correct_answer();
      return 0;
}