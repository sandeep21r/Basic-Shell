#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

#include <sys/types.h>
// #define st_mtime st_mtim.tv_sec;
int date_command(char *arg1, char *arg2)
{
    int flag_ufound = 0;
    int flag_min = 0;
    int flag_rfound = 0;
    int flag_utcfound = 0;
    int flag_universalfound = 0;
    char *universall = "universal";
    char *uttc = "utc";
    if (strcmp(arg1, "--") == 0 || (strcmp(arg1, "null") == 0 && strcmp(arg2, "null") == 0))
    {
        if (strcmp(arg2, "null") != 0)
        {
            printf("date: invalid date %s\n", arg2);
            return 1;
        }

        time_t t;
        char result[50];
        char hour[50];
        char min[50];
        char sec[50];
        char yea[50];

        t = time(NULL);
        char dest[40];
        struct tm tm = *localtime(&t);
        char b;
        char *a = ctime(&t);
        int m = tm.tm_mon + 1;
        int i = 0;
        while (i < 3)
        {
            b = a[i];

            strncat(dest, &b, 1);

            i++;
        }

        printf(" ");
        if (m == 1)
        {
            strcat(dest, " Jan ");
        }
        else if (m == 2)
        {
            strcat(dest, " Feb ");
        }
        else if (m == 3)
        {
            strcat(dest, " Mar ");
        }
        else if (m == 4)
        {
            strcat(dest, " Apr ");
        }
        else if (m == 5)
        {
            strcat(dest, " May ");
        }
        else if (m == 6)
        {
            strcat(dest, " June ");
        }
        else if (m == 7)
        {
            strcat(dest, " July ");
        }
        else if (m == 8)
        {
            strcat(dest, " Aug ");
        }
        else if (m == 9)
        {
            strcat(dest, " Sep ");
        }
        else if (m == 10)
        {
            strcat(dest, " Oct ");
        }
        else if (m == 11)
        {
            strcat(dest, " Nov ");
        }
        else if (m == 12)
        {
            strcat(dest, " Dec ");
        }
        sprintf(result, "%d", tm.tm_mday);

        strcat(dest, result);

        if (tm.tm_hour >= 12)
        {
            sprintf(hour, "%d", tm.tm_hour);
            sprintf(min, "%d", tm.tm_min);
            sprintf(sec, "%d", tm.tm_sec);
            strcat(dest, " ");
            strcat(dest, hour);
            strcat(dest, ":");
            strcat(dest, min);
            strcat(dest, ":");
            strcat(dest, sec);
            strcat(dest, " ");
            strcat(dest, "PM IST ");
        }
        else
        {
            sprintf(hour, "%d", tm.tm_hour);
            sprintf(min, "%d", tm.tm_min);
            sprintf(sec, "%d", tm.tm_sec);
            strcat(dest, " ");
            strcat(dest, hour);
            strcat(dest, ":");
            strcat(dest, min);
            strcat(dest, ":");
            strcat(dest, sec);
            strcat(dest, " ");
            strcat(dest, "AM IST");
            strcat(dest, " ");
        }

        tm.tm_year = tm.tm_year + 1900;
        sprintf(yea, "%d", tm.tm_year);
        strcat(dest, yea);

        printf("%s\n", dest);
        return 1;
    }
    if (strcmp(arg1, "null") != 0)
    {
        if (arg1[0] == '-')
        {

            if (arg1[1] != '-')
            {

                for (size_t i = 1; i < strlen(arg1); i++)
                {

                    if (arg1[i] == 'u')

                    {

                        flag_ufound = 1;
                    }
                    else if (arg1[i] == 'r')

                    {

                        flag_rfound = 1;
                    }
                    else
                    {
                        printf("date: invalid option -- %c\n", arg1[i]);
                        return 1;
                    }
                }
            }
            else
            {
                flag_min = 1;
                int index_universal = 1;
                int index_utc = 1;
                int f =0;
                for (size_t i = 3; i < strlen(arg1); i++)
                {f = 1;
                    if (arg1[2] == 'u')
                    {
                        if (arg1[i] == universall[index_universal])
                        {
                            flag_universalfound = 1;
                            index_universal++;
                        }
                        else if (arg1[i] == uttc[index_utc])
                        {
                            index_utc++;
                            flag_utcfound = 1;
                        }
                        else
                        {
                            printf("%c", arg1[i]);
                            printf("date: unrecognized option %s\n", arg1);
                            return 1;
                        }
                    }
                   
                    else
                    {
                        printf("date: unrecognized option %s\n", arg1);
                    }
                }
                if (arg1[2] == 'u'){
                    flag_universalfound = 1;
                }
                else if (f  == 0)
                    {
                        printf("date: unrecognized option %s\n", arg1);
                    }
                    
            }
        }
        else
        {
            if (strcmp(arg2, "null") != 0)
            {
                printf("date: extra operand %s\n", arg2);
                return 1;
            }
            else
            {
                printf("date: invalid date %s\n", arg1);
                return 1;
            }
        }
    }

    if ((flag_ufound == 1 || flag_universalfound == 1 || flag_utcfound == 1) && strcmp(arg2, "null") == 0)
    {
        time_t t;

        char result[50];
        char hour[50];
        char min[50];
        char sec[50];
        char yea[50];
        t = time(NULL);
        char dest[40];
        struct tm tm = *localtime(&t);
        char b;
        char *a = ctime(&t);
        int m = tm.tm_mon + 1;
        int i = 0;
        while (i < 3)
        {
            b = a[i];

            strncat(dest, &b, 1);

            i++;
        }

        printf(" ");
        if (m == 1)
        {
            strcat(dest, " Jan ");
        }
        else if (m == 2)
        {
            strcat(dest, " Feb ");
        }
        else if (m == 3)
        {
            strcat(dest, " Mar ");
        }
        else if (m == 4)
        {
            strcat(dest, " Apr ");
        }
        else if (m == 5)
        {
            strcat(dest, " May ");
        }
        else if (m == 6)
        {
            strcat(dest, " June ");
        }
        else if (m == 7)
        {
            strcat(dest, " July ");
        }
        else if (m == 8)
        {
            strcat(dest, " Aug ");
        }
        else if (m == 9)
        {
            strcat(dest, " Sep ");
        }
        else if (m == 10)
        {
            strcat(dest, " Oct ");
        }
        else if (m == 11)
        {
            strcat(dest, " Nov ");
        }
        else if (m == 12)
        {
            strcat(dest, " Dec ");
        }
        sprintf(result, "%d", tm.tm_mday);

        strcat(dest, result);
     
        tm.tm_hour = tm.tm_hour - 5;
        
       
        if (tm.tm_min <= 30)
        {
            sprintf(hour, "%d", tm.tm_hour - 1);
            sprintf(min, "%d", tm.tm_min + 30);
            sprintf(sec, "%d", tm.tm_sec);
            strcat(dest, " ");
            strcat(dest, hour);
            strcat(dest, ":");
            strcat(dest, min);
            strcat(dest, ":");
            strcat(dest, sec);
            strcat(dest, " ");
            if (tm.tm_hour >= 12)
            {
                strcat(dest, "PM UTC ");
            }

            else
            {
                strcat(dest, "AM UTC ");
            }
        }
        else
        {
            sprintf(hour, "%d", tm.tm_hour);
            sprintf(min, "%d", tm.tm_min - 30);
            sprintf(sec, "%d", tm.tm_sec);
            strcat(dest, " ");
            strcat(dest, hour);
            strcat(dest, ":");
            strcat(dest, min);
            strcat(dest, ":");
            strcat(dest, sec);
            strcat(dest, " ");
            if (tm.tm_hour >= 12)
            {
                strcat(dest, "PM UTC");
            }

            else
            {
                strcat(dest, "AM UTC");
            }
            strcat(dest, " ");
        }

        tm.tm_year = tm.tm_year + 1900;
        sprintf(yea, "%d", tm.tm_year);
        strcat(dest, yea);
      
        printf("%s\n", dest);
    }
    else if ((flag_ufound == 1 || flag_universalfound == 1 || flag_utcfound == 1) && strcmp(arg2, "null") != 0)
    {
        printf("date: invalid date %s\n", arg2);
    }
    else if (flag_rfound == 1 && strcmp(arg2, "null") != 0)
    {

        char *an;
        struct stat b;
        struct tm tmm;
        char resultt[50];
        char hourr[50];
        char minn[50];
        char secc[50];
        char yeaa[50];
        char destt[40];
        char bb;

        if (!stat(arg2, &b))
        {
            tmm = *localtime(&b.st_mtime);
            char *an = ctime(&b.st_mtime);
            int m = tmm.tm_mon + 1;
            int i = 0;
            while (i < 3)
            {
                bb = an[i];

                strncat(destt, &bb, 1);
                i++;
            }
            printf(" ");
            if (m == 1)
            {
                strcat(destt, " Jan ");
            }
            else if (m == 2)
            {
                strcat(destt, " Feb ");
            }
            else if (m == 3)
            {
                strcat(destt, " Mar ");
            }
            else if (m == 4)
            {
                strcat(destt, " Apr ");
            }
            else if (m == 5)
            {
                strcat(destt, " May ");
            }
            else if (m == 6)
            {
                strcat(destt, " June ");
            }
            else if (m == 7)
            {
                strcat(destt, " July ");
            }
            else if (m == 8)
            {
                strcat(destt, " Aug ");
            }
            else if (m == 9)
            {
                strcat(destt, " Sep ");
            }
            else if (m == 10)
            {
                strcat(destt, " Oct ");
            }
            else if (m == 11)
            {
                strcat(destt, " Nov ");
            }
            else if (m == 12)
            {
                strcat(destt, " Dec ");
            }
            sprintf(resultt, "%d", tmm.tm_mday);

            strcat(destt, resultt);
               if (tmm.tm_hour >= 12)
        {
            sprintf(hourr, "%d", tmm.tm_hour);
            sprintf(minn, "%d", tmm.tm_min);
            sprintf(secc, "%d", tmm.tm_sec);
            strcat(destt, " ");
            strcat(destt, hourr);
            strcat(destt, ":");
            strcat(destt, minn);
            strcat(destt, ":");
            strcat(destt, secc);
            strcat(destt, " ");
            strcat(destt, "PM IST ");
        }
        else
        {
            sprintf(hourr, "%d", tmm.tm_hour);
            sprintf(minn, "%d", tmm.tm_min);
            sprintf(secc, "%d", tmm.tm_sec);
            strcat(destt, " ");
            strcat(destt, hourr);
            strcat(destt, ":");
            strcat(destt, minn);
            strcat(destt, ":");
            strcat(destt, secc);
            strcat(destt, " ");
            strcat(destt, "AM IST");
            strcat(destt, " ");
        }

        tmm.tm_year = tmm.tm_year + 1900;
        sprintf(yeaa, "%d", tmm.tm_year);
        strcat(destt, yeaa);

        printf("%s\n", destt);
        // printf("\nLast modified date and time = %s\n", );
        }
        else
        {
            printf("date: no such %s file exit.\n",arg2);
        }
    }
    else if (flag_rfound == 1 && strcmp(arg2, "null") == 0)
    {
        printf("date: option requires an argument -- 'r'\n");
    }
}

int main(int argc, char *argv[])
{ 
    printf("");
    date_command(argv[1], argv[2]);
    return 1;
}