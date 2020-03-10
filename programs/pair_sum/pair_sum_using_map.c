#include <stdlib.h>
#include <ADTVector.h>
#include <ADTMap.h>
#include "pair_sum.h"

int compare_ints(Pointer a, Pointer b) {
    return *(int*)a - *(int*)b;
}

Pair pair_sum(int target, Vector numbers) {
	VectorNode node;
    Map map = map_create(compare_ints, free, free);
	Pair sol;
	sol = malloc(sizeof(struct pair));
	for (node = vector_first(numbers) ; node != VECTOR_EOF ; node = vector_next(numbers, node)) {
		map_insert(map, vector_node_value(numbers, node), vector_node_value(numbers, node));
	}
    for (node = vector_first(numbers) ; node != VECTOR_EOF ; node = vector_next(numbers, node)) {
        sol->first = *(int*)vector_node_value(numbers, node);
        sol->second = target - sol->first;
		if (map_find(map, &sol->second) != NULL) {
            return sol;
        }
	}
	return NULL;
}