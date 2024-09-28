#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "date_utils.h"
void cleanScreen();
int main()
{

    int i, j;

    bool exit = false;
    bool monthstatus = true;
    int cal[6][7] = {0};
    char inputs;

    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int year = local->tm_year + 1900;
    int actualyear = year;
    int month = local->tm_mon + 1;
    int actualmonth = month;
    int day = local->tm_mday;

    do
    {
        if (month == actualmonth && (year == actualyear))
        {
            monthstatus = true;
        }
        else
        {
            monthstatus = false;
        }

        cleanScreen();
        draw_cal(year, month, day, monthstatus, cal);
        inputs = _getch();
        if (inputs == -32)
        {
            inputs = _getch();
            switch (inputs)
            {
            case 'K': // Left Arrow
                month--;
                if (month < 1)
                {
                    month = 12;
                    year--;
                }
                break;
            case 'M': // Right Arrow
                month++;
                if (month > 12)
                {
                    month = 1;
                    year++;
                }
                break;
            case 'H':
                year++;
                break;
            case 'P':
                year--;
                break;
            }
        }
        cleanScreen();
        if ((inputs == 'q' || inputs == 'Q'))
        {
            exit = true;
        }

    } while (exit == false);
    draw_cal(year, month, day, monthstatus, cal);
    // TODO: Implement a tasks system
}
// Function to clear screen depending on OS
void cleanScreen()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#elif __APPLE__
    system("clear");
#else
    printf("system too obscure...");
#endif
}