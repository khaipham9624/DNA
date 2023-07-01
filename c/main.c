#include "c/linked_list/singly_linked_list/list.h"
#include <stdio.h>

typedef int dataType;

void destroy(void* data){
    free(data);
}


int match(const void *key1, const void *key2){

}

int main(){
    List list;
    list_init(&list, destroy);
}
