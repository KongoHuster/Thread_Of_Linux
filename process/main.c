#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>    
#include <sys/wait.h>
#include <pthread.h>
#include "time.h"
#include "readwritefile.h"
#include "process.h"

const static char *fileInputPath = "./input/";
const static char *fileOutputPath = "./output/output0_0.txt";

int main(int argc, char const *argv[])
{

    DIR *dir = opendir("./input/");
    struct dirent *entry;

    if (dir == NULL)
    {
        printf("Opendir failed!\n");
        return -1;
    }
    else
    {
        //跳过..
        // entry = readdir(dir);
        // entry = readdir(dir);
        char *outPath = (char *)malloc(strlen(fileOutputPath) + strlen(".txt") + 2);
        char *inputPath = (char *)malloc(strlen(fileInputPath) + strlen("input.txt") + 2);
        int status;

        for (int i = 0; entry != NULL; i++)
        {
            entry = readdir(dir);

            //判断是否entry为空
            if (entry == NULL)
            {

                // printf("运行结束\n");
                closedir(dir);
                exit(0);
            }

            
            sprintf(inputPath, "%s%s", fileInputPath, entry->d_name);

            if(strcmp(inputPath, "./input/.") != 0 & strcmp(inputPath, "./input/..") != 0)
            {
                sprintf(outPath, "%s", fileOutputPath);

                run_proccess(inputPath, outPath);
                wait(&status);
            }else{
                i -=1;
            }

        }

    }

    return 0;
}
