#include "push_swap.h"

void    create(t_list *head, t_list *dummy, int val)
{
    head->value = val;
    head->next = dummy;
    head->prev = dummy;
    dummy->is_dummy = TRUE_A;
    dummy->next = head;
    dummy->prev = head;
}

void    b_dummy_set(t_list  *dummy)
{
    dummy->is_dummy = TRUE_B;
    dummy->next = dummy;
    dummy->prev = dummy;
}

void    append(t_list *dummy, int val)
{
    t_list  *new = malloc(sizeof(t_list));
    t_list  *tail;

    tail = dummy->prev;
    new->value = val;
    new->next = dummy;
    new->prev = tail;
    dummy->prev = new;
    tail->next = new;
}

void    set_status(t_list   *list)
{
    t_list  *cur = list;

    cur->sort_status = UNKNOWN;
    cur = cur->next;
    while(cur != list)
    {
        cur->sort_status = UNKNOWN;
        cur = cur->next;
    }
}

void    set_sort_status(t_list *a, t_list *b)
{
    set_status(a);
    set_status(b);
}

void    swap(t_list *list)
{
    t_list *next;
    long    esc;

    next = list->next;

    esc = list->value;
    list->value = next->value;
    next->value = esc;

    esc = list->sort_status;
    list->sort_status = next->sort_status;
    next->sort_status = esc;
    if(list->is_dummy = TRUE_A)
        write(1,"sa\n",3);
    else
        write(1,"sb\n",3);
}

void    sa(t_list *a_stack)
{
    write(1,"sa\n",3);
    swap(a_stack);
}

void    sb(t_list *b_stack)
{
    write(1,"sb\n",3);
    swap(b_stack);
}

void    cut(t_list *a, t_list *c)
{
    a->next = c;
    c->prev = a;
}

void    insert(t_list *a, t_list *b, t_list *c)
{
    a->next = b;
    c->prev = b;
    b->next = c;
    b->prev = a;
}

void    push(t_list *a_dummy, t_list *b_dummy)
{
    t_list *a1 = a_dummy->next;
    t_list *a2 = a1->next;
    t_list *b1 = b_dummy->next;

    cut(a_dummy, a2);
    insert(b_dummy, a1, b1);
    // write(1,"p\n",2);
}

void    pa(t_list *a_stack, t_list *b_stack)
{
    write(1,"pa\n",3);
    push(b_stack, a_stack);
}

void    pb(t_list *a_stack, t_list *b_stack)
{
    write(1,"pb\n",3);
    push(a_stack, b_stack);
}

void    rotate(t_list *dum)
{
    t_list *cur = dum->next;
    int init = cur->value;
    int init_save;
    int status = cur->sort_status;
    int status_save;

    cur = dum->prev;

    init_save = cur->value; 
    status_save = cur->sort_status;

    cur->value = init;
    cur->sort_status = status;

    cur = cur->prev;

    while(cur->is_dummy == FALSE)
    {
        init = cur->value;
        status = cur->sort_status;
    
        cur->value = init_save;
        cur->sort_status = status_save;
    
        init_save = init;
        status_save = status;
    
        cur = cur->prev;
    }
    write(1,"r\n",2);
}

void    ra(t_list *a_stack)
{
    write(1,"ra\n",3);
    rotate(a_stack);
}

void    rb(t_list *b_stack)
{
    write(1,"rb\n",3);
    rotate(b_stack);
}

void   r_rotate(t_list *dum)
{
    t_list *cur = dum->prev;
    int init = cur->value;
    int save;

    int init_status = cur->sort_status;
    int save_status;

    cur = dum->next;

    save = cur->value; 
    save_status = cur->sort_status;
    cur->value = init;
    cur->sort_status = init_status;

    cur = cur->next;

    while(cur->is_dummy == FALSE)
    {
        init = cur->value;
        init_status = cur->sort_status;
        cur->value = save;
        cur->sort_status = save_status;
        save = init;
        save_status = init_status;    
        cur = cur->next;
    }
    write(1,"rr\n",3);
}

void    rra(t_list *a_stack)
{
    write(1,"rra\n",3);
    r_rotate(a_stack);
}

void    rrb(t_list *b_stack)
{
    write(1,"rrb\n",3);
    r_rotate(b_stack);
}