#ifndef DATE_UTILS_H
#define DATE_UTILS_H

// Calculate which day it is using the Zeller's Congruence Algorithm. Goes from Saturday (0) to Friday (6).
const int get_day_of_week(int year, int month, int day);
// Checks if the current year is a leap year.
const bool leapday_chk(int year);
// Draws the calendar.
const int draw_cal(int yr, int mon, int cal[6][7]);
#endif // DATE_UTILS_H
