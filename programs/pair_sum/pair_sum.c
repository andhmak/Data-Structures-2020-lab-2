#include <stdlib.h>
#include <ADTVector.h>
#include "pair_sum.h"


Pair pair_sum(int target, Vector numbers) {
	VectorNode node1, node2;
	Pair sol;
	sol = malloc(sizeof(struct pair));
	for (node1 = vector_first(numbers) ; node1 != vector_last(numbers) ; node1 = vector_next(numbers, node1)) {
		for (node2 = vector_next(numbers, node1) ; node2 != VECTOR_EOF ; node2 = vector_next(numbers, node2)) {
			if (target == (*(int*)vector_node_value(numbers, node1) + *(int*)vector_node_value(numbers, node2))) {
				sol->first = *(int*)vector_node_value(numbers, node1);
				sol->second = *(int*)vector_node_value(numbers, node2);
				return sol;
			}
		}
	}

	return NULL;
}