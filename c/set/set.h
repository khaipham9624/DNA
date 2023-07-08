#ifndef SET_H
#define SET_H
#include "dlist.h"
typedef Dlist Set;
typedef DlistElmt SetElmt;
void set_init(Set *set);
void set_destroy(Set *set);
int set_insert(Set *set, const dataType data);
int set_remove(Set *set, const dataType data);
int set_union(Set *setu, const Set *set1, const Set *set2);
int set_intersection(Set *seti, const Set *set1, const Set *set2);
int set_difference(Set *setd, const Set *set1, const Set *set2);
int set_is_member(const Set *set, const dataType data);
int set_is_subset(const Set *set1, const Set *set2);
int set_is_equal(const Set *set1, const Set *set2);
int set_size(const Set *set);
#endif