#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>
#include <pthread.h>
#include "time.h"
#include "readwritefile.h"
#include "thread.h"

const static char *fileInputPath = "./input/";
const static char *fileOutputPath = "./output/output";
const static char *fileTimePath = "./timeresult/time";

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

        char *timePath = (char *)malloc(strlen(fileTimePath) + strlen(".txt") + 2); 
        char *outPath = (char *)malloc(strlen(fileOutputPath) + strlen(".txt") + 2); 
        char *inputPath = (char *)malloc(strlen(fileInputPath) + strlen("input.txt") + 2);
        int Q = -1;
        for(int i = 0; entry != NULL; i++)
        {
            entry = readdir(dir);

            //判断是否entry为空
            if (entry == NULL) {

                printf("运行结束\n"); 
                closedir(dir);
                break;
            }
        
            sprintf(timePath, "%s%s", fileTimePath, entry->d_name);
            sprintf(outPath, "%s%s", fileOutputPath, entry->d_name);
            sprintf(inputPath, "%s%s", fileInputPath, entry->d_name);

            printf("%d : %s\n", i, timePath);
            printf("%d : %s\n", i, outPath);
            printf("%d : %s\n", i, inputPath);

            if(strcmp(inputPath, "./input/.") != 0 & strcmp(inputPath, "./input/..") != 0)
            {
                run_thread(inputPath, outPath, timePath);
                printf("\n\n");
            }

        }

        return 0;
    }
}

