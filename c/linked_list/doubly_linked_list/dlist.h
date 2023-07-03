#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>
#include <malloc.h>

typedef int dataType;
typedef struct DlistElmt_{
    dataType data;
    struct DlistElmt_ *next;
    struct DlistElmt_ *prev;
} DlistElmt;

typedef struct Dlist_{
    DlistElmt *head;
    DlistElmt *tail;
    int size;
    int (*match)(const DlistElmt *elmt1, const DlistElmt *elmt2);
} Dlist;

void dlist_init(Dlist *list);
void dlist_destroy(Dlist *list);
int dlist_insert_next(Dlist *list, DlistElmt *elmt, const dataType data);
int dlist_insert_prev(Dlist *list, DlistElmt *elmt, const dataType data);
int dlist_remove(Dlist *list, DlistElmt *elmt);
int dlist_size(Dlist *list);
DlistElmt* dlist_head(Dlist *list);
DlistElmt* dlist_tail(Dlist *list);
int dlist_is_head(Dlist* list, const DlistElmt *elmt);
int dlist_is_tail(Dlist* list, const DlistElmt *elmt);
DlistElmt* dlist_prev(const DlistElmt *elmt);
DlistElmt* dlist_next(const DlistElmt *elmt);
void dlist_print(Dlist *list);
#endif