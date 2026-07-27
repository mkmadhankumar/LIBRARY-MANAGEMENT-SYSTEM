#include "library.h"
#include <time.h>

/* Writes today's date into buf as dd/mm/yyyy */
void get_today_date(char *buf)
{
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    sprintf(buf, "%02d/%02d/%04d",
            tm_info->tm_mday,
            tm_info->tm_mon + 1,
            tm_info->tm_year + 1900);
}

/* Converts a dd/mm/yyyy date string into a whole-day count since a fixed epoch */
static long date_to_days(const char *date)
{
    int day, month, year;
    struct tm tm_date;

    memset(&tm_date, 0, sizeof(tm_date));

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    tm_date.tm_mday = day;
    tm_date.tm_mon  = month - 1;
    tm_date.tm_year = year - 1900;
    tm_date.tm_hour = 12; /* midday avoids daylight-saving edge cases */

    return (long)(mktime(&tm_date) / 86400);
}

/* Number of days from `from` to `to` (positive if `to` is later, negative if earlier) */
long days_between(const char *from, const char *to)
{
    return date_to_days(to) - date_to_days(from);
}

/* Fine for a book returned/checked after its due date. Rs.5 per late day. */
double calculate_fine(const char *due_date, const char *return_date, double price)
{
    long late_days = days_between(due_date, return_date);

    (void)price; /* reserved for price-based fine models in the future */

    if(late_days <= 0)
        return 0.0;

    return late_days * 5.0;
}
