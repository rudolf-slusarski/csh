#include "main.h"

char *locate(char *command)
{
    char *path, *path_copy;
    size_t cmd_len;

    path = getenv("PATH");
    path_copy = strdup(path);

    cmd_len = strlen(command);
    char *path_tokens = strtok(path_copy, ":");

    while (path_tokens != NULL)
    {

        size_t dir_len = strlen(path_tokens);
        char *file_path = malloc(cmd_len + dir_len + 2);

        strcat(file_path, path_tokens);
        strcat(file_path, "/");
        strcat(file_path, command);
        strcat(file_path, "\0");
    }
}