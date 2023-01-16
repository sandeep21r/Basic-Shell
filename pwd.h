#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <wordexp.h>

extern char buff[300];

int pwdd(char **args,wordexp_t w,int length){
    char *a;
    int flag = 0;
    if(length == 0){
        printf("%s\n",buff);
        return 1;
    }

    for (size_t i = 1; i <= length; i++)
    {
        a = args[i];
        if (strlen(a) > 1 && a[0] == '-' )
        {
            for (size_t i = 1; i < strlen(a); i++)
            {
                if (a[i] == 'P')
                {
                    flag =1;
                }

                else if (a[i] == 'L')
                {
                    flag =0;
                }
                else{
                    printf("bash: pwd: -%c: invalid option\n",a[i]);
                    printf("pwd: usage: pwd [-LP]\n");
                    return 1;
                }

                    }

        }
    }
    if(flag == 1){
         printf("%s\n",buff);
    }
    else if (flag == 0)
    {
        printf("%s\n",buff);
    }
        return 1;
}