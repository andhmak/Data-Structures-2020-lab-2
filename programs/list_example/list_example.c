#include <stdlib.h>
#include <stdio.h>

#include "ADTList.h"

int* create_int(int i) {
	int* p = malloc(sizeof(int));
	*p = i;
	return p;
}

int main() {
	List list = list_create(free);

	// προσθήκη των αριθμών από το 0 έως 9 στη λίστα
	for (int i = 0; i < 10; i++)
		list_insert_next(list, list_last(list), create_int(i));

	// εκτύπωση των περιεχομένων της λίστας
	
	for (ListNode node = list_first(list) ; node != LIST_EOF ; node = list_next(list, node)) {
		printf("%d\n", *(int*)list_node_value(list, node));
	}
	list_destroy(list);
} 