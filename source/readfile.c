#include <stdio.h>
# include <stdlib.h>

const static char *fileInput = "../input/input.txt";
const static char *fileOutput = "output.txt";

int main()
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
                  printf("%d\n", atoi(string));
            }
            else
            {
                  perror("Failed to open input.txt");
            }

            fseek(file, ftell(file) + 2, SEEK_SET);
            if (fgets(string, 20, file) != NULL)
            {
                  printf("%d\n", atoi(string));
            }
            else
            {
                  perror("Failed to open input.txt");
            }
      }

}