#include "set.h"
void set_init(Set *set){
    dlist_init(set);
}

void set_destroy(Set *set){
    dlist_destroy(list);
}

int set_insert(Set *set, const dataType data){
    if (set_is_member(set, data))
        return 1;
    return dlist_insert_next(set, dlist_tail(set), data);
}

int set_remove(Set *set, const dataType data){
    SetElmt *elmt;
    for (elmt = set->head; elmt != NULL; elmt = elmt->next){
        if (elmt->data == data){
            return dlist_remove(set, elmt);
        }
    }
    return 0;
}
int set_union(Set *setu, const Set *set1, const Set *set2){
    dlist_init(setu);
    SetElmt elmt;
    for (elmt = set1->head; elmt != NULL; elmt = elmt->next){
        if (elmt != NULL)
        {
            if (!set_insert(setu, elmt->data)){
                set_destroy(setu);
                return -1;
            }
        }
    }
    for (elmt = set2->head; elmt != NULL; elmt = elmt->next){
        if (elmt != NULL)
        {
            if (!set_insert(setu, elmt->data)){
                set_destroy(setu);
                return -1;
            }
        }
    }
    return 1;
}
int set_intersection(Set *seti, const Set *set1, const Set *set2){
    dlist_init(seti);
    SetElmt *elmt;
    for (elmt = set1->head; elmt != NULL; elmt = elmt->next){
        if (set_is_member(set2, elmt->data))
            if (!set_insert(seti, elmt->data)){
                set_destroy(seti);
                return -1;
            }
    }
    return 1;
}
int set_difference(Set *setd, const Set *set1, const Set *set2){
    set_init(setd);
    SetElmt *elmt;
    for (elmt = set1->head; elmt != NULL; elmt = elmt->next){
        if (!set_is_member(set2, elmt->data)){
            if (!set_insert(setd, elmt->data)){
                set_destroy(setd);
                return -1;
            }
        }
    }
    return 1;
}
int set_is_member(const Set *set, const dataType data){
    SetElmt *elmt;
    for (elmt = set->head; elmt != NULL; elmt = elmt->next){
        if (elmt->data == data){
            return 1;
        }
    }
    return 0;
}
int set_is_subset(const Set *set1, const Set *set2){
    SetElmt *elmt;
    if (set1->size > set2->size)
        return 0;
    for (elmt = set1->head; elmt != NULL; elmt = elmt->next){
        if (set_)
    }
}
int set_is_equal(const Set *set1, const Set *set2);
int set_size(const Set *set);