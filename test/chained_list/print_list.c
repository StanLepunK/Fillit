#include "list.h"
#include <stdio.h>

void print_list(t_list *list)
{
    while(list)
    {
        printf("%s\n",list->str);
        list = list->next;
    }
}