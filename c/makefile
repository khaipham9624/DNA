all: test_singly_linked_list test_doubly_linked_list test_stack test_queue
test_singly_linked_list: test_singly_linked_list.c linked_list/singly_linked_list/list.c linked_list/singly_linked_list/list.h
	gcc -g -o test_singly_linked_list test_singly_linked_list.c linked_list/singly_linked_list/list.c -I linked_list/singly_linked_list/

test_doubly_linked_list: test_doubly_linked_list.c linked_list/doubly_linked_list/dlist.c linked_list/doubly_linked_list/dlist.h
	gcc -g -o test_doubly_linked_list test_doubly_linked_list.c linked_list/doubly_linked_list/dlist.c -I linked_list/doubly_linked_list/

# test_circular_linked_list: test_circular_linked_list.c linked_list/circular_linked_list/clist.c linked_list/circular_linked_list/clist.h
# 	gcc -g -o test_circular_linked_list test_circular_linked_list.c linked_list/circular_linked_list/clist.c -I linked_list/circular_linked_list/

test_stack: test_stack.c stack_and_queue/stack/stack.h stack_and_queue/stack/stack.c
	gcc -g -o test_stack test_stack.c stack_and_queue/stack/stack.c linked_list/singly_linked_list/list.c -I stack_and_queue/stack/ -I linked_list/singly_linked_list/


test_queue: test_queue.c stack_and_queue/queue/queue.h stack_and_queue/queue/queue.c
	gcc -g -o test_queue test_queue.c stack_and_queue/queue/queue.c linked_list/singly_linked_list/list.c -I stack_and_queue/queue/ -I linked_list/singly_linked_list/