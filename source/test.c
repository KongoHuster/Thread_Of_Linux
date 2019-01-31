#include <stdio.h>
#include "thread.h"

const static char *fileInputPath = "../input/input.txt";
const static char *fileOutputPath = "../output/output.txt";

int main(int argc, char const *argv[])
{
    run_thread(fileInputPath, fileOutputPath);
    printf("hello");
    return 0;
}
