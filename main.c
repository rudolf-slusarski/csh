#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "please do $ ";
    char *lineptr;
    size_t n = 0;
    ssize_t nchars;

    (void)ac;
    (void)argv;

    while (1)
    {
        printf("%s", prompt);
        nchars = getline(&lineptr, &n, stdin);

        if (nchars == -1)
        {
            printf("exiting\n");
            return -1;
        }

        printf("%s", lineptr);
        free(lineptr);
    }

    return 0;
}