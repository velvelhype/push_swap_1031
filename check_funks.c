#include "push_swap.h"

int    is_sorted(t_list *a)
{
    t_list *cur;
    t_list *nxt;

    cur = a->next;
    nxt = cur->next;
    while(cur->value < nxt->value && cur->is_dummy == FALSE)
    {
        cur = cur->next;
        nxt = nxt->next;
        if (nxt->is_dummy == TRUE)
            return 1;
    }
    return 0;
};

void    print_sort_status(t_list *list)
{
    if(list->sort_status != UNKNOWN)
        {
            if(list->sort_status == SORTED)
                printf("S");
            else if(list->sort_status == CHUNK)
                printf("C");
        }
    else
        printf("U");
}

void    stack_check(t_list *a_dummy, t_list *b_dummy)
{
    printf("===========================\n");
    printf("a\t\tb\t\n");
    printf("===========================\n");
    a_dummy = a_dummy->next;
    b_dummy = b_dummy->next;
    int a_end = FALSE;
    int b_end = FALSE;
    while(a_dummy->is_dummy == FALSE || b_dummy == FALSE)
    {
        if(a_dummy->is_dummy != FALSE)
            a_end = TRUE;
        if(b_dummy->is_dummy != FALSE)
            b_end = TRUE;
        if(a_end == FALSE)
        {
            printf("%d\t",a_dummy->value);
            print_sort_status(a_dummy);
            printf("\t");
            a_dummy = a_dummy->next;
        }
        if(b_end == FALSE)
        {
            printf("%d\t",b_dummy->value);
            print_sort_status(a_dummy);
            printf("\n");
            b_dummy = b_dummy->next;
        }
        else
            printf("\n");
    }
    printf("\n");
    read(1,NULL,1);
}

void illegal_stack_check(t_list *a_dummy)
{
    a_dummy = a_dummy->next;
    while(a_dummy->is_dummy == FALSE)
    {
        printf("%d\n",a_dummy->value);
        a_dummy = a_dummy->next;
    }
}
