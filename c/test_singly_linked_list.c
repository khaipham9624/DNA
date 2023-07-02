#include "linked_list/singly_linked_list/list.h"
#include <stdio.h>


int main(int argc, char **argv){
    List *list = (List *)malloc(sizeof(List));
    list_init(list);
    list_ins_next(list, list_tail(list), 1);
    list_ins_next(list, list_tail(list), 2);
    list_ins_next(list, list_tail(list), 3);
    list_ins_next(list, list_tail(list), 4);
    list_ins_next(list, list_tail(list), 5);
    list_print(list);

    list_rem_next(list, list_tail(list));
    list_print(list);

    list_rem_next(list, list_head(list));
    list_print(list);

    list_rem_next(list, NULL);
    list_print(list);

    list_destroy(list);
}
