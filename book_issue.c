#include "library.h"

/* Returns 1 if the given year is a leap year, else 0 */
static int is_leap_year(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;

    return 0;
}

/* Returns number of days in the given month/year */
static int days_in_month(int month, int year)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(month == 2 && is_leap_year(year))
        return 29;

    return days[month - 1];
}

/*
 * Takes an issue date string (dd/mm/yyyy), adds `add_days` days to it,
 * and writes the resulting date into `result` (dd/mm/yyyy).
 */
static void calculate_due_date(const char *issue_date, int add_days, char *result)
{
    int day, month, year;

    sscanf(issue_date, "%d/%d/%d", &day, &month, &year);

    day += add_days;

    while(day > days_in_month(month, year))
    {
        day -= days_in_month(month, year);
        month++;

        if(month > 12)
        {
            month = 1;
            year++;
        }
    }

    sprintf(result, "%02d/%02d/%04d", day, month, year);
}

void book_issue(void)
{
    BOOK *btemp;
    ISSUE *new, *temp;
    int book_id;

    if(head == NULL)
    {
        printf("\nNo Books Available...\n");
        return;
    }

    printf("\nEnter Book ID : ");
    scanf("%d", &book_id);

    /* Search Book */
    btemp = head;

    while(btemp)
    {
        if(btemp->id == book_id)
        {
            break;
        }

        btemp = btemp->next;
    }

    if(btemp == NULL)
    {
        printf("\nBook Not Found...\n");
        return;
    }

    if(btemp->quantity == 0)
    {
        printf("\nBook Not Available...\n");
        return;
    }

    /* Create Issue Record */
    new = (ISSUE *)malloc(sizeof(ISSUE));

    if(new == NULL)
    {
        printf("\nMemory Allocation Failed...\n");
        return;
    }

    /* Generate Issue ID */
    new->issue_id = 1;

    temp = ihead;

    while(temp)
    {
        if(temp->issue_id >= new->issue_id)
            new->issue_id = temp->issue_id + 1;

        temp = temp->next;
    }

    new->book_id = btemp->id;

    printf("Enter User ID : ");
    scanf("%d", &new->user_id);

    printf("Enter User Name : ");
    scanf(" %[^\n]", new->user_name);

    printf("Enter Issue Date (dd/mm/yyyy) : ");
    scanf("%s", new->issue_date);

    /* Due Date is automatically set to 6 days after the Issue Date */
    calculate_due_date(new->issue_date, 6, new->due_date);

    printf("Due Date (auto-calculated) : %s\n", new->due_date);

    strcpy(new->return_date, "Not Returned");

    new->fine = 0;
    new->next = NULL;

    /* Reduce Book Quantity */
    btemp->quantity--;

    /* Insert Issue Record */
    if(ihead == NULL)
    {
        ihead = new;
    }
    else
    {
        temp = ihead;

        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = new;
    }

    printf("\nBook Issued Successfully...\n");
}
