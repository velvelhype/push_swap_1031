#include "push_swap.h"

void baka_sort(t_list   *a_dummy)
{
    t_list  *one_list;
    t_list  *two_list;
    int     stock;

    one_list = a_dummy;
    one_list = one_list->next;
    two_list = one_list->next;

    while (one_list->is_dummy == FALSE)
    {
        while (two_list->is_dummy == FALSE)
        {
            if (one_list->value > two_list->value)
            {
                stock = one_list->value;
                one_list->value = two_list->value;
                two_list->value = stock;
            }
            two_list = two_list->next;
        }
        one_list = one_list->next;
        two_list = one_list->next;
    }
}

void    two_sort(t_list *dum)
{
    t_list  *one;
    t_list  *two;
    int     save;

    one = dum->next;
    two = one->next;

    if(one->value > two->value)
    {
        save = one->value;
        one->value = two->value;
        two->value = save;
    }
}

void    three_sort(t_list *dum)
{
    t_list  *one;
    t_list  *two;
    t_list  *three;

    one = dum->next;
    two = one->next;
    three = two->next;

    if(is_sorted(dum) != 1)
    {
        if(one->value > two->value)
        {
            if(two->value > three->value)
                {
                    swap(one);
                    r_rotate(dum);
                }
            else if (one->value < three->value)
                swap(one);
            else
                rotate(dum);
        }
        else if (one->value < three->value)
            {
                swap(one);
                rotate(dum);
            }
        else
            r_rotate(dum);
    }
}

void    finish_list(t_list  *a, t_list  *b, int lists_number)
{
    // printf("lets finish\n");
    t_list  *init = b->next;
    init->sort_status = SORTED;
    if(count_list(b) == 2)
        two_sort(b);
    if(count_list(b) == 3)
        three_sort(b);
    lists_number = count_list(b);
    while(lists_number--)
    {
        push(b,a);
        rotate(a);
    }
    if((a->next)->sort_status != SORTED)
    {
        push(a,b);
        while((a->next)->sort_status == UNKNOWN)
            push(a,b);
        // printf("go next rec\n");
        // stack_check(a,b);
        // read(1,NULL,1);
        sort_rec_b(a,b);
    }
}