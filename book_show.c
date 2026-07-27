#include "library.h"

void book_show(void)
{
    BOOK *temp;

    if(head == NULL)
    {
        printf("\nNo Books Available...\n");
        return;
    }

    temp = head;

    printf("\n==============================================================================\n");
    printf("ID\tTITLE\t\t\tAUTHOR\t\t\tQUANTITY\tPRICE\n");
    printf("==============================================================================\n");

    while(temp)
    {
        printf("%d\t%-20s\t%-20s\t%d\t\tRs.%.2f\n",
                temp->id,
                temp->title,
                temp->author,
                temp->quantity,
                temp->price);

        temp = temp->next;
    }

    printf("==============================================================================\n");
}
