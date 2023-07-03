#include "dlist.h"

int match(const DlistElmt* elmt1, const DlistElmt* elmt2){
    return elmt1->data == elmt2->data;
}

void dlist_init(Dlist *list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void dlist_destroy(Dlist *list){
    while (list->size > 0){
        dlist_remove(list, list->head);
    }
    free(list);
}

int dlist_insert_next(Dlist *list, DlistElmt *elmt, const dataType data){
    DlistElmt *newElmt = (DlistElmt*)malloc(sizeof(DlistElmt));
    if (newElmt == NULL){
        return -1;
    }
    newElmt->data = data;

    if (elmt == NULL){
        if(dlist_size(list) == 0){
            newElmt->next = NULL;
            newElmt->prev = NULL;
        } else {
            newElmt->next = list->head;
            newElmt->prev = NULL;
            list->head->prev = newElmt;
        }
        list->head = newElmt;
    } else{
        newElmt->next = elmt->next;
        newElmt->prev = elmt;

        if(!dlist_is_tail(list, elmt)){
            elmt->next->prev = newElmt;
            elmt->next = newElmt;
        } else {
            list->tail = newElmt;
        }
    }

    list->size++;
    return 0;
}

int dlist_insert_prev(Dlist *list, DlistElmt *elmt, const dataType data){
    DlistElmt *newElmt = (DlistElmt*)malloc(sizeof(DlistElmt));
    if (newElmt == NULL){
        return -1;
    }
    newElmt->data = data;

    newElmt->next = elmt;
    newElmt->prev = elmt->prev;

    elmt->prev->next = newElmt;
    elmt->prev = newElmt;

    list->size++;
    return 0;
}

int dlist_remove(Dlist *list, DlistElmt *elmt){
    if (elmt == NULL) 
        return -1;
    
    if (list->size <= 0)
        return -1;

    DlistElmt *oldElmt = elmt;

    elmt->next->prev = elmt->prev;
    elmt->prev->next = elmt->next;

    if (dlist_is_head(list, oldElmt)){
        list->head = elmt->next;
    }
    if (dlist_is_tail(list, oldElmt)){
        list->tail = elmt->prev;
    }

    free(oldElmt);
    list->size--;
    return 0;
}

int dlist_size(Dlist *list) {
    return list->size;
}

DlistElmt* dlist_head(Dlist *list){
    return list->head;
}

DlistElmt* dlist_tail(Dlist *list){
    return list->tail;
}

int dlist_is_head(Dlist* list, const DlistElmt *elmt){
    return elmt == list->head;
}

int dlist_is_tail(Dlist* list, const DlistElmt *elmt){
    return elmt == list->tail;
}

DlistElmt* dlist_prev(const DlistElmt *elmt){
    return elmt->prev;
}

DlistElmt* dlist_next(const DlistElmt *elmt){
    return elmt->next;
}

void dlist_print(Dlist *list){
    printf("printing dlist...\n");
    DlistElmt *elmt;
    for (elmt = list->head; elmt != NULL; elmt = elmt->next){
        printf("%d ", elmt->data);
    }
    printf("\n");
}