#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "date_utils.h"
#define RESET "\033[0m"
#define WHITE "\033[37m"
#define GRAY "\033[90m"
#define BLACK "\033[30m"
#define WHITE_BG "\033[47m"
int get_day_of_week(int year, int month, int day)
{
    int j, k, h;
    if (month == 1 || month == 2)
    {
        year--;
        month += 12;
    }
    j = (int)floor(year / 100);
    k = year % 100;
    h = (day + (int)floor(((month + 1) * 13) / 5) + k + (int)floor(k / 4) + (int)floor(j / 4) + 5 * j) % 7;
    return h;
}
bool leapday_chk(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
        return false;
}
int draw_cal(int yr, int mon, int cal[6][7])
{
    char *days[] = {
        "S",
        "D",
        "L",
        "M",
        "M",
        "J",
        "V"};
    char *months[] =
        {
            "Enero",
            "Febrero",
            "Marzo",
            "Abril",
            "Mayo",
            "Junio",
            "Julio",
            "Agosto",
            "Septiembre",
            "Octubre",
            "Noviembre",
            "Diciembre"};
    int finaldays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j;
    bool leapday;

    leapday = leapday_chk(yr);
    if (leapday)
    {
        finaldays[1] = 29;
    }
    int prevmonth = (mon == 1) ? 12 : mon - 1;
    int prevmonthdays = finaldays[prevmonth - 1];
    int startday = get_day_of_week(yr, mon, 1);
    int daycount = 1;
    // clear calendar matrix
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            cal[i][j] = 0;
        }
    }
    for (i = 0; i < 6; i++)
    {
        for (j = (i == 0 ? startday : 0); j < 7; j++)
        {
            if (daycount <= finaldays[mon - 1])
            {
                cal[i][j] = daycount++;
            }
        }
    }
    for (j = startday - 1; j >= 0; j--)
    {
        cal[0][j] = prevmonthdays--;
    }
    int nextmonthday = 1;

    for (int j = 0; j < 7; j++)
    {
        if (cal[4][j] == 0)
        {
            cal[4][j] = nextmonthday++;
        }
    }
    for (int j = 0; j < 7; j++)
    {
        if (cal[5][j] == 0)
        {
            cal[5][j] = nextmonthday++;
        }
    }
    char titlearray[45];
    snprintf(titlearray, sizeof(titlearray), "%d %s                                                               ", yr, months[mon - 1]);
    printf("    " WHITE_BG BLACK "%s\n" RESET, titlearray);

    for (i = 0; i < 7; i++)
    {
        printf("%6s ", days[i]);
    }
    printf("\n\n");
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if ((i == 0 && cal[i][j] > 7) || (i >= 4 && cal[i][j] < 13))
            {
                printf(GRAY "%6d " RESET, cal[i][j]);
            }
            else
            {
                printf(WHITE "%6d " RESET, cal[i][j]);
            }
        }
        printf("\n");
    }
}
