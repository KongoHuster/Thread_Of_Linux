#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>
#include <pthread.h>
#include "time.h"
#include "readwritefile.h"
#include "process.h"

const static char *fileInputPath = "./input/";
const static char *fileOutputPath = "./output/output";

int main(int argc, char const *argv[])
{

    DIR *dir = opendir("./input/");
    struct dirent *entry;


    if (dir == NULL)
    {
        printf("opendir failed!");
        return -1;
    }
    else
    {
        //跳过..
        entry = readdir(dir);
        entry = readdir(dir);
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
        
            sprintf(outPath, "%s%d%s", fileOutputPath, i, ".txt");
            sprintf(inputPath, "%s%s", fileInputPath, entry->d_name);
            run_thread(inputPath, outPath); 
            printf("\n\n");
            // printf("Path is %s\n", outPath);
            // printf("Path is %s\n", inputPath);
            // printf("filename = %s\n", entry->d_name); //输出文件或者目录的名称
            // printf("filetype = %d\n\n\n", entry->d_type);     //输出文件类型
        }

        return 0;
    }
}

