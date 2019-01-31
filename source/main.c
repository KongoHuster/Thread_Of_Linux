#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "time.h"
#include "readwritefile.h"
#include "thread.h"

const static char *fileInputPath = "../input/input.txt";
const static char *fileOutputPath = "./output/output.txt";
static char *Path = "../input/input1.txt";

int main(int argc, char const *argv[])
{

    DIR *dir = opendir("./input");
    struct dirent *entry;
    char *txt;
    txt = "1212";

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
        char *path; 

        for(int i = 0; entry != NULL; i++)
        {
            entry = readdir(dir);
            strcmp(Path, fileInputPath);
            // run_thread(entry->d_name, fileOutputPath);
            printf("Path is %s\n", Path);
            printf("Path is %s\n", fileInputPath);
            printf("filename = %s\n", entry->d_name); //输出文件或者目录的名称
            printf("filetype = %d\n", entry->d_type);     //输出文件类型
        }
    
        closedir(dir);

        // run_thread(fileInputPath, fileOutputPath);
        return 0;
    }
}