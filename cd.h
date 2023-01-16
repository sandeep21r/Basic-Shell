#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <wordexp.h>

extern char buff[300];
extern char buff_prev[300];
int cdd(char **args, wordexp_t w, int length)
{

    int flag = -1;
    int cmp = 0;
    char *a = "~";
    if (length == 0)
    {
        chdir("/home/sandy");
        getcwd(buff, 300);
        strcpy(buff_prev, buff);
        return 1;
    }
    else if (length >= 2 && args[1][0] == '-' && args[2][0] == '-')
    {

        if (args[1][0] != '-' && args[2][0] != '-')
        {
            printf("bash: cd: too many arguments\n");
            return 1;
        }
        
        else if (args[1][0] != 'L' || args[1][0] != 'P')
        {
            printf("bash: cd: %s: invalid option\n", args[1]);
            printf("cd: usage: cd [-L|-P] [dir]\n");
            return 1;
        }
        else if (args[2][0] != 'P' || args[2][0] != 'L')
        {
            printf("bash: cd: %s: invalid option\n", args[2]);
            printf("cd: usage: cd [-L|-P] [dir]\n");
            return 1;
        }
    }
    else if (length == 1)
    {
        char *a = args[1];
        if (strcmp(a, "-P") == 0 || strcmp(a, "-L") == 0)
        {
            cmp = chdir("/home/sandy");
            if (cmp == 0)
            {
                getcwd(buff, 300);
                strcpy(buff_prev, buff);
            }
            return 1;
        }
        else if ((a[1] == 'L' && a[2] == 'P') || (a[2] == 'L' && a[1] == 'P'))
        {
           cmp = chdir("/home/sandy");
            if (cmp == 0)
            {
                getcwd(buff, 300);
                strcpy(buff_prev, buff);
            }
            return 1;
        }
        
        else
        {
            cmp = chdir(args[1]);
            if (cmp == 0)
            {
                getcwd(buff, 300);
                strcpy(buff_prev, buff);
            }
            else
            {
                char *b = args[1];
                if (b[0] == '-')
                {
                    printf("bash: cd: %s: invalid option\n", args[1]);
                    printf("cd: usage: cd [-L|-P] [dir]\n");
                }
                else
                {
                    printf("bash: cd: %s: No such file or directory\n", args[1]);
                }
            }
            return 1;
        }
    }
    else
    {

        if (length > 2)
        {
            printf("bash: cd: too many arguments\n");
            return 1;
        }
        else
        {

            if (strcmp(args[1], "-P") == 0)
            {
                cmp = chdir(args[2]);
                if (cmp == 0)
                {
                    getcwd(buff, 300);
                    strcpy(buff_prev, buff);
                }
                else
                {
                    printf("bash: cd: %s: No such file or directory\n", args[2]);
                }
                return 1;
            }
            else if (strcmp(args[1], "-L") == 0)
            {

                cmp = chdir(args[2]);
                if (cmp == 0)
                {
                    getcwd(buff, 300);
                    strcpy(buff_prev, buff);
                }
                else
                {
                    printf("bash: cd: %s: No such file or directory\n", args[2]);
                }
                return 1;
            }
            else
            {
                char *b = args[1];
                if (b[0] == '-')
                {
                    printf("bash: cd: %s: invalid option\n", args[1]);
                    printf("cd: usage: cd [-L|-P] [dir]\n");
                }
                else
                {
                    printf("bash: cd: too many arguments\n");
                }
            }
            return 1;
        }
    }
    return 1;
}
