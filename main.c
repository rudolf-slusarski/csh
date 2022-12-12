#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "please do $ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    __ssize_t nchars;
    const char *delim = " \n";
    (void)ac;
    int num_tokens;
    int i;

    while (1)
    {

        printf("%s", prompt);
        nchars = getline(&lineptr, &n, stdin);

        if (nchars == -1)
        {
            printf("exiting\n");
            return -1;
        }

        lineptr_copy = malloc(sizeof(char) * nchars);
        if (lineptr_copy == NULL)
        {
            perror("memory allocation error");
            return -1;
        }

        strcpy(lineptr_copy, lineptr);

        char *tokens = strtok(lineptr, delim);
        while (tokens != NULL)
        {
            num_tokens++;
            tokens = strtok(NULL, delim);
        }
        num_tokens++;

        argv = malloc(sizeof(char *) * num_tokens);
        tokens = strtok(lineptr_copy, delim);

        for (i = 0; tokens != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(tokens));
            strcpy(argv[i], tokens);

            tokens = strtok(NULL, delim);
        }

        argv[i] = NULL;
        execmd(argv);
    }
    
    free(lineptr_copy);
    free(lineptr);
    return 0;
}
