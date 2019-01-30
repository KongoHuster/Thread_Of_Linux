#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

const static char *fileInput = "../input/input.txt";
const static char *fileOutput = "output.txt";

//获取input.txt文件中的N和M
void getInput(int * N, long * M)
{
      FILE *file;
      file = fopen(fileInput, "r");
      char string[20];
      if (file == NULL)
      {
            perror("Failed to open input.txt");
      }
      else
      {
            fseek(file, 2, SEEK_SET);
            if (fgets(string, 20, file) != NULL)
            {
                  *N = atoi(string);
                  printf("%d\n", N);
            }
            else
            {
                  perror("Failed to open input.txt");
            }

            fseek(file, ftell(file) + 2, SEEK_SET);
            if (fgets(string, 20, file) != NULL)
            {
                  *M = atol(string);
                  printf("%d\n", M);
            }
            else
            {
                  perror("Failed to open input.txt");
            }
      }

}