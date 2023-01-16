#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/syscall.h>
#include <dirent.h>

int ls_command(char *one, char *two)
{
   
    int flag_1_remember = 0;
    int one_a_flag = 0;

    int one_m_flag = 0;
    int t1 = 0;

    int flag_2_remember = 0;
    int two_a_flag = 0;
   
    int two_m_flag = 0;
    int t2 = 0;
   
    int flag_ = 0;

    struct dirent *d;

    int index = 1;
   
    if (strlen(one) >= 2 && one[0] == '-')
    {
        flag_1_remember = 1;
    
        for (size_t i = 1; i < strlen(one); i++)
        {

            if (one[i] == 'a')
            {
             
                one_a_flag = 1;
            }
            else if (one[i] == 'm')
            {
         
                one_m_flag = 1;
            }
            else
            {
           
                printf("ls: invalid option -- %c\n", one[i]);
                return 1;
            }
        }
    }
    if (strlen(two) >= 2 && two[0] == '-')
    {
  
        flag_2_remember = 1;

        for (size_t i = 1; i < strlen(two); i++)
        {
           
            if (two[i] == 'a')
            {
                two_a_flag = 1;
            }
            else if (two[i] == 'm')
            {
               
                two_m_flag = 1;
            }
            else
            {
          
                printf("ls: invalid option -- %c\n", two[i]);
                return 1;
            }
        }
    }
 
    if (strcmp(one, "null") == 0 || (flag_1_remember == 1 && flag_2_remember == 1))
    {
       
    
        DIR *dir = opendir(".");
        if (!dir)
        {
        
            printf("ls: cannot access %s: No such file or directory\n", ".");
            return 1;
        }
        while ((d = readdir(dir)) != NULL)
        {
            
            if (strcmp(one, "null") == 0)
            {
               
                if (d->d_name[0] != '.')
                {
                  
                    printf("%s   ", d->d_name);
                }
            }
            else
            {
          
                if ((one_a_flag == 1 && one_m_flag == 1) || (two_a_flag == 1 && two_m_flag == 1))
                {
                 
                    printf("%s", d->d_name);
                    if (d->d_name != NULL)
                    {
                       
                        printf(",   ");
                    }
                }
                else if (one_a_flag == 1 && two_a_flag == 1)
                {
               
                    printf("%s  ", d->d_name);
                }

                else if (one_m_flag == 1 && two_m_flag == 1)
                {
                    if (d->d_name[0] != '.')
                    {
                        
                        printf("%s", d->d_name);
                        if (d->d_name != NULL)
                        {
                         
                            printf(",  ");
                        }
                    }
                  
                }

                else if ((one_a_flag == 1 || one_m_flag == 1) && (two_a_flag == 1 || two_m_flag == 1))
                {
                
                    printf("%s", d->d_name);
                    if (d->d_name != NULL)
                    {
                    
                        printf(",   ");
                    }
                
                }
            }
        }
        printf("\n");
       return 1;
    }
    else if (flag_1_remember == 1)
    {
        if (strcmp(two, "null") == 0)
        {
           
            two = ".";
        }
        DIR *dir = opendir(two);

        if (!dir)
        {
    
            printf("ls: cannot access %s: No such file or directory\n", two);
            return 1;
        }

        while ((d = readdir(dir)) != NULL)
        {
           
            if (one_a_flag == 1 && one_m_flag == 1)
            {
              
                printf("%s", d->d_name);
                if (d->d_name != NULL)
                {
                    
                    printf(",   ");
                }
                
            }

            else if (one_a_flag == 1)
            {
                
                printf("%s  ", d->d_name);
            }

            else if (one_m_flag == 1)
            {
       
                if (d->d_name[0] != '.')
                {
                  
                    printf("%s", d->d_name);
                    if (d->d_name != NULL)
                    {
                       
                        printf(",  ");
                    }
                }
              
            }

            else
            {
           
                if (d->d_name[0] != '.')
                {
                   
                    printf("%s  ", d->d_name);
                }
            }
        }
        printf("\n");
        return 1;
    }

    else if (flag_2_remember == 1)
    {

        if (strcmp(one, "null") == 0)
        {
            
            one = ".";
        }
        DIR *dir = opendir(one);

        if (!dir)
        {
           
            printf("ls: cannot access %s: No such file or directory\n", one);
            return 1;
        }

        while ((d = readdir(dir)) != NULL)
        {
           
            if (two_a_flag == 1 && two_m_flag == 1)
            {
             
                printf("%s", d->d_name);
                if (d->d_name != NULL)
                {
                
                    printf(",   ");
                }
            }

            else if (two_a_flag == 1)
            {
                
                printf("%s  ", d->d_name);
            }

            else if (two_m_flag == 1)
            {
                
                if (d->d_name[0] != '.')
                {
           
                    printf("%s", d->d_name);
                    if (d->d_name != NULL)
                    {
                 
                        printf(",  ");
                    }
                }
            }

            else
            {
           
                if (d->d_name[0] != '.')
                {
          
                    printf("%s  ", d->d_name);
                }
            }
        }
        printf("\n");
        return 1;
    }

    else
    {
        if (strcmp(two,"null") == 0)
        {
                DIR *dir1 = opendir(one);
             if (!dir1)
            {
                
                printf("ls: cannot access %s: No such file or directory\n", one);
                return 1;
            }

            while ((d = readdir(dir1)) != NULL)
            {
              
                if (d->d_name[0] != '.')
                {
                   
                    printf("%s   ", d->d_name);
                }
            }
            printf("\n");
            return 1;
        }
        
       else{
    
        DIR *dir1 = opendir(one);
        DIR *dir2 = opendir(two);

        if (!dir1)
        {
   
             printf("ls: cannot access %s: No such file or directory\n", one);
            if (!dir2)
            {
               
                printf("ls: cannot access %s: No such file or directory\n", two);
                return 1;
            }

            while ((d = readdir(dir2)) != NULL)
            {
               
                if (d->d_name[0] != '.')
                {
                   
                    printf("%s   ", d->d_name);
                }
            }
            printf("\n");
            return 1;
        }

        if (!dir2)
        {
        
             printf("ls: cannot access %s: No such file or directory\n", two);
            while ((d = readdir(dir1)) != NULL)
            {
               
                if (d->d_name[0] != '.')
                {
                   
                    printf("%s   ", d->d_name);
                }
             
            }
            printf("\n");
            return 1;
        }

        while ((d = readdir(dir1)) != NULL)
        {
       
            if (d->d_name[0] != '.')
            {
            

                printf("%s   ", d->d_name);
            }
         
        }
        printf("\n");

        while ((d = readdir(dir2)) != NULL)
        {
            
            if (d->d_name[0] != '.')
            {
               
                printf("%s   ", d->d_name);
            }
           
        }
        printf("\n");
       
       
    }
    return 1;
    }
   
    return 1;
}

int main(int argc, char *argv[])
{
  
    ls_command(argv[1], argv[2]);
    return 1;
}