#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int cat_command(char *one, char *two)
{
    int index = 0;
    int line_no = 1;
    char *a;
    char **aaa;
    int flag = 0;
    int rem = 0;
    int postion_1 = 0;
    int postion_2 = 0;
    int E_flag = 0;

    if (strcmp(one, "null") == 0 && strcmp(two, "null") == 0)
    {
        int time = 1800;
        //   printf("%s %s" ,one,two);
        while (time != 0)
        {
            scanf("%[^\n]%*c", &a);
            printf("%s\n", &a);
            time -= 1;
        }
        return 1;
    }
    else
    {

        if (strlen(one) >= 2 && one[0] == '-')
        {
            for (size_t i = 1; i < strlen(one); i++)
            {

                if (one[i] == 'n')
                {
                    flag = 1;
                    rem = 1;
                }
                else if (one[i] == 'E')
                {
                    flag = 2;
                    E_flag = 1;
                }
                else
                {
                    printf("cat: invalid option -- %c\n", one[i]);
                    return 1;
                }
            }
        }
        else
        {
            if (strcmp(one, "null") != 0)
            {
                postion_1 = 1;
            }
        }

        if (strlen(two) >= 2 && two[0] == '-')
        {
            for (size_t i = 1; i < strlen(two); i++)
            {

                if (two[i] == 'n')
                {
                    flag = 1;
                    rem = 1;
                }
                else if (two[i] == 'E')
                {
                    flag = 2;
                    E_flag = 1;
                }
                else
                {
                    printf("cat: invalid option -- %c\n", two[i]);
                    return 1;
                }
            }
        }
        else
        {
            if (strcmp(two, "null") != 0)
            {
                postion_2 = 1;
            }
        }
        if (postion_2 == 1 && postion_1 == 1)
        {

            char *buffer = malloc(sizeof(char) * 1024000);
            const char *filename = one;

            int file_descriptor = open(filename, O_RDONLY);
            if (file_descriptor < 0)
            {
                printf("cat: %s: No such file or directory", one);
                printf("\n");
            }
            else
            {
                read(file_descriptor, buffer, 1024000);

                while (buffer[index] != 0)
                {

                    printf("%c", buffer[index]);

                    index++;
                }

                close(file_descriptor);
            }

            index = 0;
            char *buffer1 = malloc(sizeof(char) * 1024000);
            const char *filename1 = two;

            int file_descriptor1 = open(filename1, O_RDONLY);
            if (file_descriptor1 < 0)
            {
                printf("cat: %s: No such file or directory", two);
                printf("\n");
            }
            else
            {
                read(file_descriptor1, buffer1, 1024000);

                while (buffer1[index] != 0)
                {

                    printf("%c", buffer1[index]);
                    index++;
                }

                close(file_descriptor1);
            }
        }
        else if (flag == 1 || rem == 1)
        {

            if (postion_2 == 1)
            {
                char *buffer = malloc(sizeof(char) * 1024000);
                const char *filename = two;

                int file_descriptor = open(filename, O_RDONLY);
                if (file_descriptor < 0)
                {
                    printf("cat: %s: No such file or directory", two);
                    printf("\n");
                }
                else
                {
                    read(file_descriptor, buffer, 1024000);

                    while (buffer[index] != 0)
                    {
                        if (index == 0)
                        {
                            printf("%d  ", line_no);
                        }
                        if (buffer[index] == 10 && E_flag == 1)
                        {
                            printf("&");
                        }
                        printf("%c", buffer[index]);
                        if (buffer[index] == 10 && buffer[index] != 0)
                        {
                            line_no++;
                            printf("%d  ", line_no);
                        }

                        index++;
                    }

                    close(file_descriptor);
                }
            }
            else if (postion_1 == 1)
            {
                char *buffer = malloc(sizeof(char) * 1024000);
                const char *filename = one;

                int file_descriptor = open(filename, O_RDONLY);
                if (file_descriptor < 0)
                {
                    printf("cat: %s: No such file or directory", one);
                    printf("\n");
                }
                else
                {
                    read(file_descriptor, buffer, 1024000);

                    while (buffer[index] != 0)
                    {
                        if (index == 0)
                        {
                            printf("%d  ", line_no);
                        }
                        if (buffer[index] == 10 && E_flag == 1)
                        {
                            printf("&");
                        }
                        printf("%c", buffer[index]);
                        if (buffer[index] == 10 && buffer[index] != 0)
                        {
                            line_no++;
                            printf("%d  ", line_no);
                        }

                        index++;
                    }

                    close(file_descriptor);
                }
            }
            else
            {
                int time = 1800;
                int inde = 1;

               
                while (time != 0)
                {
                    scanf("%[^\n]%*c", &a);

                    printf("\t%d   %s", inde, &a);
                    if (E_flag == 1)
                    {
                        printf("$\n");
                    }
                    else
                    {
                        printf("\n");
                    }

                    inde++;
                    time -= 1;
                }
            }
        }

        else if (flag == 2 && rem == 0)
        {

            if (postion_2 == 1)
            {
                char *buffer = malloc(sizeof(char) * 1024000);
                const char *filename = two;

                int file_descriptor = open(filename, O_RDONLY);
                if (file_descriptor < 0)
                {
                    printf("cat: %s: No such file or directory", two);
                    printf("\n");
                }
                else
                {
                    read(file_descriptor, buffer, 1024000);

                    while (buffer[index] != 0)
                    {
                        if (buffer[index] == 10)
                        {
                            printf("&");
                        }

                        printf("%c", buffer[index]);

                        index++;
                    }

                    close(file_descriptor);
                }
            }
            else if (postion_1 == 1)
            {
                char *buffer = malloc(sizeof(char) * 1024000);
                const char *filename = one;

                int file_descriptor = open(filename, O_RDONLY);
                if (file_descriptor < 0)
                {
                    printf("cat: %s: No such file or directory", one);
                    printf("\n");
                }
                else
                {
                    read(file_descriptor, buffer, 1024000);

                    while (buffer[index] != 0)
                    {
                        if (buffer[index] == 10)
                        {

                            printf("&");
                        }
                        printf("%c", buffer[index]);

                        index++;
                    }

                    close(file_descriptor);
                }
            }

            else
            {
                int time = 1800;

                //   printf("%s %s" ,one,two);
                while (time != 0)
                {
                    scanf("%[^\n]%*c", &a);
                    if (a == "^C")
                    {
                        return 1;
                    }

                    printf("%s$\n", &a);
                    time -= 1;
                }
            }
        }
        else
        {
            char *buffer = malloc(sizeof(char) * 1024000);
            const char *filename = one;

            int file_descriptor = open(filename, O_RDONLY);
            if (file_descriptor < 0)
            {
                printf("cat: %s: No such file or directory", one);
                printf("\n");
            }
            else
            {
                read(file_descriptor, buffer, 1024000);

                while (buffer[index] != 0)
                {
                    printf("%c", buffer[index]);
                    index++;
                }

                close(file_descriptor);
            }
        }
    }
}
int main(int argc, char *argv[])
{
   printf("");
    cat_command(argv[1], argv[2]);

    return 1;
}