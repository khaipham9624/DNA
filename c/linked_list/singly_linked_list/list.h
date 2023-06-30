#ifndef LIST_H 
#define LIST_H 

#include <stdio.h>
#include <stdlib.h>

typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
    int size;
    int (*match) (const void * key1, const void * key2);
    void (*destroy) (void *data);
    ListElmt *head;
    ListElmt *tail;
} List;

/**
 * @brief initialize the list
 * @param list the list to initialize
 * @param destroy the function to destroy the list
*/
void list_init(List *list, void (*destroy)(void *data));

/**
 * @brief destroy the list
 * @param list the list to destroy
*/
void list_destroy(List *list);

/**
 * @brief insert the new element next to the *element in the list. If the element is NULL, the element will be inserted
 * at the head of the list
 * @param list the list to insert
 * @param data the data to be inserted
 * @param element pointer to the element
 * @return 0 if successful, or -1 otherwise
 * **/
int list_ins_next(List *list, ListElmt *element, const void *data);

/**
 * @brief remove the data next the element in the list. If the element is NULL, the element will be removed
 * at the head of the list
 * @param list the list to remove the element from
 * @param data the data to be returned
 * @return 0 if removing the element is successful, or –1 otherwise
*/
int list_rem_next(List *list, ListElmt *element, void **data);

/**
 * @brief return the number of elements in the list
*/
int list_size(List *list);

/**
 * @brief return the head of list
*/
ListElmt* list_head(List *list);

/**
 * @brief return the tail of list
*/
ListElmt* list_tail(List *list);

/**
 * @brief check if element is head of list
 * @return 0 if false, 1 if true
*/
int list_is_head(List *list, ListElmt *element);

/**
 * @brief check if element is tail of list
 * @return 0 if false, 1 if true
*/
int list_is_tail(List *list, ListElmt *element);

/**
 * @brief return data of element
*/
void *list_data(List *list, ListElmt *element);

/**
 * @brief return next element
*/
ListElmt *list_next(List *list, ListElmt *element);

#endif