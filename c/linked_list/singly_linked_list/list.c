#include "list.h"

void list_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_destroy(List *list){
    int ret;
    for (;list_size(list) >0;){
        ret = list_rem_next(list, NULL);
    }
    free(list);
}


int list_ins_next(List *list, ListElmt *element, dataType data) {
    ListElmt *newElement = (ListElmt*)(malloc(sizeof(ListElmt)));
    if (newElement == NULL) {
        return -1;
    }

    newElement->data = data;

    if (element == NULL){ // insert at head
        if (list_head(list) == NULL){
            newElement->next = NULL;
            list->head = newElement;
            list->tail = newElement;
        } else {
            newElement->next = list->head;
            list->head = newElement;
        }
    } else if (list_is_tail(list, element)){ // insert at tail
        newElement->next = NULL;
        element->next = newElement;

        list->tail = newElement;
    } else { //insert at middle
        newElement->next = element->next;
        element->next = newElement;
    }

    list->size++;
    return 0;
}

int list_rem_next(List *list, ListElmt *element){
    if (list->size <= 0){
        return -1;
    }

    ListElmt *tmp;
    if (element == NULL){ // remove head
        tmp = list->head;
        list->head = tmp->next;
    }
    else
    {  
        if (element->next == NULL){
            return -1;
        }
        tmp = element->next;
        element->next = tmp->next;
    }
    if (list_is_tail(list, tmp)){
        list->tail = element;
    }
    free(tmp);
    list->size--;
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

dataType list_data(List *list, ListElmt *element){
    return element->data;
}

ListElmt *list_next(List *list, ListElmt *element){
    return element->next;
}

void list_print(List *list){
    printf("printing list\n");
    ListElmt *elmt;
    for (elmt = list->head; elmt != NULL; elmt = elmt->next){
        printf("%d ", elmt->data);
    }
    printf("\n");
}

