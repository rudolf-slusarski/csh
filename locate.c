#include "main.h"

char *locate(char *command)
{
    char *path, *path_copy, *path_token;
    size_t cmd_len;
    struct stat buffer;
    path = getenv("PATH");

    if (path)
    {
        path_copy = strdup(path);
        cmd_len = strlen(command);
        path_token = strtok(path_copy, ":");

        while (path_token != NULL)
        {
            size_t dir_len = strlen(path_token);
            char *file_path = malloc(cmd_len + dir_len + 2);

            strcat(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            if (stat(file_path, &buffer) == 0)
            {
                free(path_copy);
                return file_path;
            }
            else
            {
                free(file_path);
                path_token = strtok(NULL, ":");
            }
        }
    }

    free(path_copy);

    if (stat(path, &buffer) == 0)
    {
        free(path_copy);
        return command;
    }

    return NULL;
}