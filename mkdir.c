#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int mkdir_command(char *arg1, char *arg2, char *arg3)
{
   int file1_postion = 0;
    int file2_postion = 0;
    int file3_postion = 0;

    int flag_v = 0;
    int flag_m = 0;
    int ind = 0;
    int ind1 =0;
    if (strcmp(arg1, "null") == 0 && strcmp(arg2, "null") == 0)
    {
        printf("mkdir: missing operand\n");
    }

 

    if (arg1[0] == '-')
    {
        for (size_t i = 1; i < strlen(arg1); i++)
        {
        
            if (arg1[i] == 118)
            {
                flag_v = 1;
                ind1 =1;
            }
            else if (arg1[i] == 109 && ind == 0 && ind1 ==0)
            {
                flag_m = 1;
                ind = 1;
            }
            else
            {
                printf("mmkdir: invalid option -- %c\n",arg1[i]);
                return 1;
            }
        }
       
    }
   
    if (flag_v == 0 && flag_m == 0)
    {
        if (strcmp(arg1, "null") != 0 && arg1[0] != '-')
        {
            int ret = 0;
            ret = mkdir(arg1, 0755);
            if (ret == 0)
            {
            }
            else
            {
                printf("Unable to create directory: %s \n", arg1);
            }
        }
        else if (arg1[0] == '-')
        {
            printf("(Assemption)::: unable to create directory : use - is invalid at position 1\n");
        }
        if (strcmp(arg2, "null") != 0 && arg2[0] != '-')
        {
            int ret1 = 0;
            ret1 = mkdir(arg2, 0755);
            if (ret1 == 0)
            {
            }
            else
            {
                printf("Unable to create directory: %s \n", arg2);
            }
        }
        else if (arg2[0] == '-')
        {
            printf("(Assemption)::: unable to create directory : use - is invalid at position 2\n");
        }
        if (strcmp(arg3, "null") != 0 && arg3[0] != '-')
        {
            int ret2 = 0;
            ret2 = mkdir(arg3, 0755);
            if (ret2 == 0)
            {
            }
            else
            {
                printf("Unable to create directory: %s \n", arg3);
            }
        }
        else if (arg3[0] == '-')
        {
            printf("(Assemption)::: unable to create directory : use - is invalid at position 3\n");
        }
    }
    else if (flag_v == 1)
    {
        if (strcmp(arg2, "null") != 0)
        {
            if (strcmp(arg2, "null") != 0 && arg2[0] != '-')
            {
                int ret1 = 0;
                ret1 = mkdir(arg2, 0755);
                if (ret1 == 0)
                {
                    printf("mkdir: created directory %s\n", arg2);
                }
                else
                {
                    printf("Unable to create directory: %s \n", arg2);
                }
            }
            else if (arg2[0] == '-')
            {
                printf("(Assemption)::: unable to create directory : use - is invalid at position 2\n");
            }
            if (strcmp(arg3, "null") != 0 && arg3[0] != '-')
            {
                int ret2 = 0;
                ret2 = mkdir(arg3, 0755);
                if (ret2 == 0)
                {
                    printf("mkdir: created directory %s\n", arg3);
                }
                else
                {
                    printf("Unable to create directory: %s \n", arg3);
                }
            }
            else if (arg3[0] == '-')
            {
                printf("(Assemption)::: unable to create directory : use - is invalid at position 3\n");
            }
        }
        else
        {
            printf("mkdir: missing operand\n");
        }
    }
    else if (flag_m == 1)
    {
        if (strcmp(arg2, "null") == 0)
        {
            printf("mkdir: option requires an argument -- 'm'\n");
        }
        else if (strcmp(arg3, "null") == 0)
        {
            printf("mkdir: missing operand\n");
           
        }
        else if (strlen(arg2) > 4)
        {
            printf("mkdir: invalid mode %s\n", arg2);
        }
        else
        {
            for (size_t i = 0; i < strlen(arg2); i++)
            {
                if (arg2[i] >= 48 && arg2[i] <= 55)
                {
                    continue;
                }
                else
                {
                    printf("mkdir: invalid mode %s\n", arg2);
                    return 1;
                }
            }
            int value = atoi(arg2);
            if (strcmp(arg3, "null") != 0 && arg3[0] != '-')
            {
                int ret2 = 0;
                ret2 = mkdir(arg3, value);
                if (ret2 == 0)
                {
                    
                }
                else
                {
                    printf("Unable to create directory: %s \n", arg3);
                }
            }
            else if (arg3[0] == '-')
            {
                printf("(Assemption)::: unable to create directory : use - is invalid at position 3\n");
            }
        }
      
    }

    return 1;
}
int main(int argc, char *argv[])
{
    printf("");
    mkdir_command(argv[1], argv[2], argv[3]);

    return 0;
}