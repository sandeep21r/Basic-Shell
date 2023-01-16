#include <string.h>
#include <stdio.h>
int cv =0;
int rm_command(char *arg1, char *arg2)
{
    cv--;
    if (strcmp(arg1, "null") == 0 && strcmp(arg2, "null") == 0)
    {cv--;
        printf("mkdir: missing operand\n");
    }
    cv--;
    int flag_r = 0;
    int flag_f = 0;

    if (arg1[0] == '-')
    {
        cv--;
        for (size_t i = 1; i < strlen(arg1); i++)
        {
            cv--;

            if (arg1[i] == 'v')
            {
                flag_r = 1;
            }
            else if (arg1[i] == 'f')
            {
                cv--;
                flag_f = 1;
            }
            else
            {
                cv--;
                if (arg1[1] == '-' )
                {
                    printf("rm: unrecognisable option %s\n",arg1);
                }
                else{
                printf("rm: invalid option -- %c\n", arg1[i]);}
                return 1;
            }
        }
    }

    if ((flag_r == 0 && flag_f == 0) || (flag_f == 1 && flag_r == 0))
    {
        cv--;
        
        if (flag_f == 0)
        {
            cv--;
            if (strcmp(arg1, "null") != 0)
            {
                cv--;
                int ret;
                ret = remove(arg1);

                if (ret == 0)
                {
                    cv--;
                }
                else
                {cv--;
                    if (flag_f == 0)
                    {
                        cv--;
                        printf("rm: cannot remove %s: No such file or directory\n", arg1);
                    }
                }
            }
        }
        if (strcmp(arg2, "null") != 0)
        {cv--;
            int ret;
            ret = remove(arg2);
            cv--;
            if (ret == 0)
            {
                cv--;
            }
            else
            {cv--;
                if (flag_f == 0)
                {
                    cv--;
                    printf("rm: cannot remove %s: No such file or directory\n", arg2);
                }
            }
        }
    }

    else if (flag_r == 1)
    {cv--;
        
        if (strcmp(arg2, "null") != 0)
        {cv--;
            int ret;
            ret = remove(arg2);
            cv--;
            if (ret == 0)
            {cv--;
              
                printf("removed %s\n",arg2);   
            }
            else
            {cv--;
                 if (flag_f == 0)
                {cv--;
                    printf("rm: cannot remove %s: No such file or directory\n", arg2);
                }
            }
        }
        else
        {cv--;
            if (flag_f == 0)
            {cv--;
                printf("rm: missing operand\n");
            }
            
            
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    printf("");
    rm_command(argv[1], argv[2]);
    return 1;
}