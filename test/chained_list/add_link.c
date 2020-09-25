#include "list.h"
#include <stdlib.h>

t_list *add_link(t_list *list, char *str){
    t_list *temp_list;

    temp_list = (t_list*)malloc(sizeof(t_list));
    if(temp_list) {
        temp_list->str = str;
        temp_list->next = list;
    }

    return (temp_list);
}