#include "linked_list/doubly_linked_list/dlist.h"
#include <stdio.h>


int main(int argc, char **argv){
    Dlist *list = (Dlist *)malloc(sizeof(Dlist));
    dlist_init(list);
    dlist_insert_next(list, dlist_tail(list), 1);
    dlist_insert_next(list, dlist_tail(list), 2);
    dlist_insert_next(list, dlist_tail(list), 3);
    dlist_insert_next(list, dlist_tail(list), 4);
    dlist_insert_next(list, dlist_tail(list), 5);
    dlist_print(list);

    dlist_remove(list, dlist_tail(list));
    dlist_print(list);

    dlist_remove(list, dlist_head(list));
    dlist_print(list);

    dlist_remove(list, NULL);
    dlist_print(list);

    dlist_destroy(list);
}
