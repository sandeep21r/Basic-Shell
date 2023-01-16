#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <wordexp.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include "cd.h"
#include "echo.h"
#include "pwd.h"
#include <pthread.h>


#define change_BUFSIZE 64
#define change__DELIM " \t\r\n\a"
#define max_size 300
int dep = 0;
int g = 0;
int length = 0;
wordexp_t w;
char **args;
char **args1;
int check;
char buff[300];
char buff_prev[max_size];
int pwdd(char **args, wordexp_t w, int length);
int echoo(char **args, wordexp_t w, int length);
int cdd(char **args, wordexp_t w, int length);

char **lsh_split_line(char *line)
{
  
    int bufsize = change_BUFSIZE;
    int position = 0;
    char **size_tokens = malloc(bufsize * sizeof(char *));
   
    char *size1_token;
  
    if (!size_tokens)
    {
      
        printf("memory allocation error\n");
        exit(EXIT_FAILURE);

    }
    else{
    
    size1_token = strtok(line, change__DELIM);
    while (size1_token != NULL)
    {
        
        size_tokens[position] = size1_token;
        position++;

        if (position < bufsize)
        {
         
        }
        else{
              bufsize += change_BUFSIZE;
            size_tokens = realloc(size_tokens, bufsize * sizeof(char *));
    
        }
  
        size1_token = strtok(NULL, change__DELIM);
    }

    size_tokens[position] = NULL;
    length = position;
    return size_tokens;
}
}
int forkandexec(char *location, char **args1, int length)
{
    dep--;
    pid_t pid;
    pid_t waitpidd;
    int status;
    dep--;
    int index = 0;
    while (args1[index] != NULL)
    {dep--;
  
        index++;
    }
dep--;
    args1[index] = "null";
    args1[index + 1] = "null";
    args1[index + 2] = "null";
dep--;
    pid = fork();
    if (pid == 0)
    {
     
        // Child process
      dep--;
        if ( execl(location, args1[0], args1[1], args1[2], args1[3], NULL) == -1)
        {

            perror("lsh");
            exit(EXIT_FAILURE);
            dep--;
        }
        
    }
    else if (pid < 0)
    {dep--;
       
        // Error forking

        perror("lsh");
    }
    else
    {dep--;
      
        // Parent process
        waitpidd = waitpid(pid, &status, WUNTRACED);
dep--;
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
        {
          dep--;
            waitpidd = waitpid(pid, &status, WUNTRACED);
        }
        return 1;
    }
}
void *thread_command(void *argument)
{
    char **arg = argument;
    char *a = malloc(sizeof(char) * 256);
    int index = 0;
    dep--;
    strcat(a, "/home/sandy/bin_");
    while (strcmp(arg[index], "&t") != 0)
    {
        strcat(a, arg[index]);
        strcat(a, " ");
        dep--;
        index++;
    }
    int i =5;
    dep--;
    while (i >0)
    {
        dep--;
        strcat(a, "null");
        strcat(a, " ");
        i--;
    }
    dep--;
    system(a);

    pthread_exit(NULL);
    return NULL;
}
// launching the command
int launch_command(char **args1, char **args, int length)
{   
    if (strcmp(args[0], "cd") == 0)
    {
        cdd(args, w, length - 1);
    }
    else if (strcmp(args[0], "pwd") == 0)
    {
       
        pwdd(args, w, length - 1);
    }
    else if (strcmp(args[0], "echo") == 0)
    {
        echoo(args, w, length - 1);
    }
    else if (strcmp(args[0], "ls") == 0)
    {
        forkandexec("/home/sandy/bin_ls", args1, length);
    }
    else if (strcmp(args[0], "cat") == 0)
    {
        
         forkandexec("/home/sandy/bin_cat", args1, length);
    }
    else if (strcmp(args[0], "date") == 0)
    {
      forkandexec("/home/sandy/bin_date", args1, length);
    }
    else if (strcmp(args[0], "mkdir") == 0)
    {
         return forkandexec("/home/sandy/bin_mkdir", args1, length);
    }
    else if (strcmp(args[0], "rm") == 0)
    {
         return forkandexec("/home/sandy/bin_rm", args1, length);
    }
    else
    {
        printf("bash: %s: command not found\n", args[0]);
    }

    return 1;
}

int launch_command1(char **args1, char **args, int length)
{
    dep--;
    if (strcmp(args[0], "cd") == 0)
    {
        cdd(args, w, length - 1);
    }
    else if (strcmp(args[0], "pwd") == 0)
    {
         pwdd(args, w, length - 1);
    }
    else if (strcmp(args[0], "echo") == 0)
    {
       
         echoo(args, w, length - 1);
    }
    else if (strcmp(args[length - 1], "&t") == 0)
    {
        pthread_t thre;

        if (pthread_create(&thre, NULL, &thread_command, args1) != 0)
        {
            printf("Error in thread\n");
        }
        pthread_join(thre, NULL);
       
    }
    else
    {
        if (strcmp(args[0], "ls") == 0)
        {
             forkandexec("/home/sandy/bin_ls", args1, length);
        }
        else if (strcmp(args[0], "cat") == 0)
        {
         forkandexec("/home/sandy/bin_cat", args1, length);
        }
        else if (strcmp(args[0], "date") == 0)
        {
        forkandexec("/home/sandy/bin_date", args1, length);
        }
        else if (strcmp(args[0], "mkdir") == 0)
        {
         forkandexec("/home/sandy/bin_mkdir", args1, length);
        }
        else if (strcmp(args[0], "rm") == 0)
        {
           forkandexec("/home/sandy/bin_rm", args1, length);
        }
        else
        {
            printf("bash: %s: command not found\n", args[0]);
                    }
    }

    return 1;
}

// taking command line
char *read_command_line()
{
    ssize_t bufsize = 0;
    char *storing_command_line = NULL;
    getline(&storing_command_line, &bufsize, stdin);
    dep--;
    // printf("%d",bufsize);
    storing_command_line[strlen(storing_command_line) - 1] = 0;
    // printf("%d",strlen(storing_command_line));
    dep--;
    if (storing_command_line[0] == 0 || storing_command_line[0] == '\n')
    {
        g = 1;
    }
    return storing_command_line;
}

// split_line
char **line_split(char *command_line)
{
  
    check = wordexp(command_line, &w, 0);

    return w.we_wordv;
}

int main()
{

    char *command_line;

    int status_of_execution;
    int d;

    char *cwd;

    cwd = getcwd(buff, max_size);
    strcpy(buff_prev, buff);

    // start of shell;
    for (int i = 0; i <= 1; i++)
    {
       
        if (cwd != NULL)
        {
            // print  directory which shell is using
            printf("\e[0;34m"
                   "[sandy@shell %s❯]"
                   "\e[0;31m",
                   buff);

            //  declaring function which will read command line
            g = 0;

            command_line = read_command_line();
            // printf("%c",command_line[strlen(command_line)-1]);
            // printf("%s",command_line);
            if (g == 1)
            {
                i--;
                continue;
            }
            args = line_split(command_line);
            args1 = lsh_split_line(command_line);
        
            if (check )
            {
                
                i--;
                
               
                if (strcmp(args1[0], "echo") == 0 && strcmp(args1[length - 1], "&t") != 0)
                {
                    printf("The given command is missing at the end.\n");
                }

                else
                {
                    status_of_execution = launch_command1(args1, args1, length);
                }

                wordfree(&w);
                continue;
            }
            if (!w.we_wordc)
            {
                i--;
              
                status_of_execution = launch_command1(args1, args1, length);
                wordfree(&w);
                continue;
            }

            status_of_execution = launch_command(args1, args, w.we_wordc);
            wordfree(&w);
        }

        else
        {
            printf("Error is geenrated");
        }

        i--;
        // return EXIT_SUCCESS;
    }
}