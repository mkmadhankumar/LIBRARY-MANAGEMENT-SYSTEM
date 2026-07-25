#include "library.h"

void issued_list(void)
{
    ISSUE *temp;
    BOOK *btemp;
    char today[20];
    double price;
    long days_left;
    char status[40];

    if(ihead == NULL)
    {
        printf("\nNo Issued Books...\n");
        return;
    }

    get_today_date(today);

    printf("\n( Checked On : %s )\n\n", today);

    temp = ihead;

    printf("=====================================================================================================================================\n");

    printf("%-8s %-8s %-8s %-20s %-12s %-12s %-14s %-30s %-10s\n",
           "IssueID",
           "BookID",
           "UserID",
           "User Name",
           "Issue Date",
           "Due Date",
           "Return Date",
           "Status",
           "Fine");

    printf("=====================================================================================================================================\n");

    while(temp)
    {
        if(strcmp(temp->return_date, "NotReturned") == 0)
        {
            /* Still with the borrower: recalculate live against today's date */
            days_left = days_between(today, temp->due_date);

            /* Find the book's price */
            price = 0;
            btemp = head;

            while(btemp)
            {
                if(btemp->id == temp->book_id)
                {
                    price = btemp->price;
                    break;
                }

                btemp = btemp->next;
            }

            if(days_left >= 0)
            {
                temp->fine = 0;
                sprintf(status, "%ld Day(s) Remaining", days_left);
            }
            else
            {
                temp->fine = calculate_fine(temp->due_date, today, price);
                sprintf(status, "OVERDUE by %ld Day(s)", -days_left);
            }
        }
        else
        {
            /* Already returned: fine was fixed at return time */
            strcpy(status, "Returned");
        }

        printf("%-8d %-8d %-8d %-20s %-12s %-12s %-14s %-30s Rs.%8.2f\n",
               temp->issue_id,
               temp->book_id,
               temp->user_id,
               temp->user_name,
               temp->issue_date,
               temp->due_date,
               temp->return_date,
               status,
               temp->fine);

        temp = temp->next;
    }
}
