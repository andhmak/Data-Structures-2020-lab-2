#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ADTPriorityQueue.h>
#include <ADTSet.h>

int compare_ints(Pointer a, Pointer b) {
    return *(int*)a - *(int*)b;
}

int* create_int(int i) {
	int* p = malloc(sizeof(int));
	*p = i;
	return p;
}

int main(void) {
    PriorityQueue pqueue = pqueue_create(compare_ints, free, NULL);
    int randnum, i;
    srand(time(NULL));
    for (i = 0 ; i < 20 ; i++) {
        randnum = rand();
        pqueue_insert(pqueue, create_int(randnum));
    }
    while (pqueue_size(pqueue)) {
        printf("%d\n", *(int*)pqueue_max(pqueue));
        pqueue_remove_max(pqueue);
    }
    printf("\n\n\n\n\n\n");
    Set set = set_create(compare_ints, free);
    for (i = 0 ; i < 20 ; i++) {
        randnum = rand();
        set_insert(set, create_int(randnum));
    }
    for (SetNode node = set_first(set); node != SET_EOF ; node = set_next(set, node)) {
        printf("%d\n", *(int*)set_node_value(set, node));
    }
    return 0;
}