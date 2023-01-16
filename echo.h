#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <wordexp.h>

int echoo(char **args, wordexp_t w, int length)
{
    int flag = -1;
    int error = 0;
    size_t j = 2;
   
    if (length == 0)
    {
        printf("\n");
        return 1;
    }
    char *a = args[1];
   int x =0;
    if (strlen(a) == 2 && a[0] == '-')
    {
        if (a[1] == 'E')
        {
            flag = 1;
        }
        else if (a[1] == 'e')
        {
            flag = 2;
        }
        else if (a[1] == 'n')
        {
            flag = 0;
        }
    }

    if (flag == 2)
    {
        for (size_t i = 2; i <= length; i++)
        {
            char *a = args[i];
            char *b = args[i];

            for (size_t j = 0; j < strlen(a); j++)
            {
                x =1;
                
                if (j != strlen(a))
                {
                    if (a[j] == 92 && a[j + 1] == 'n')
                    {
                        printf("\n");
                        j++;
                    }
                    else if (a[j] == 92 && a[j + 1] == 'a')
                    {
                        printf("\a");
                        j++;
                    }
                    else if (a[j] == 92 && a[j + 1] == 92)
                    {
                        printf("\\");
                        j++;
                    }
               
                 
                
          
                    else if (a[j] == 92 && a[j + 1] == 'r')
                    {
                        printf("\r");
                        j++;
                    }
                    else if (a[j] == 92 && a[j + 1] == 't')
                    {
                        printf("\t");
                        j++;
                    }
                    else
                    {
                        printf("%c", a[j]);
                    }
                }
                else
                {
                    
                 
                    printf("%c", a[j]);
                }
            }
            if (i != length )
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
        if (x == 0)
        {
            printf("\n");
        }
        
    }
 
    else if (flag == -1 || flag == 1 || flag == 0)
    {   int n =0;
        if (flag == -1)
        {
            j = 1;
        }
        for (size_t i = j; i <= length; i++)
        {
            error = 1;
         
            printf("%s", args[i]);

            if (flag == 0)
            {
                if (i != length)
                {
                    printf(" ");
                }
            }
            else if (flag == 1 || flag == -1)
            {
                if (i == length)
                {   n =1;
                    printf("\n");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        if (n == 0 && flag == 1)  
        {
            printf("\n");
        }
        
    }
   
    return 1;
}
