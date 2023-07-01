#include "list.h"



void list_init(List *list, void (*destroy)(void *data)) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->destroy = destroy;
    list->match = NULL; // TODO
}

void list_destroy(List *list){
    ListElmt *elmt;
    int ret = 0;
    for (elmt = list->head; elmt != NULL;){
        ret = list_rem_next(list, NULL, elmt->data);
    }
    list->destroy = NULL;
    list->match = NULL;
}


int list_ins_next(List *list, ListElmt *element, const void *data) {
    ListElmt *newElement = (ListElmt*)(malloc(sizeof(ListElmt)));
    newElement->data = data;

    if (element == NULL){
        if (list_head(list) == NULL){
            newElement->next = NULL;
            list_tail(list) = ;
        }
        else {
            newElement->next = list_head(list)->next;
        }

        list->head = newElement;
    }

    if (list_is_tail(list, element)){

    }

    list->size++;
    return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data){
    if (element == NULL){

    }
    return 0;
}

int list_size(List *list){
    return list->size;
}

ListElmt* list_head(List *list){
    return list->head;
}

ListElmt* list_tail(List *list){
    return list->tail;
}

int list_is_head(List *list, ListElmt *element){
    return list->head == element;
}

int list_is_tail(List *list, ListElmt *element){
    return list->tail == element;
}

void *list_data(List *list, ListElmt *element){
    return element->data;
}
ListElmt *list_next(List *list, ListElmt *element){
    return element->next;
}
