#include <stdlib.h>
#include "list.h"

int main()
{
    t_list *list;
    list = NULL;

    list = add_link(list, "truc");
    list = add_link(list, "machin");
    list = add_link(list, "bidule");

    print_list(list);
    return (0);
}