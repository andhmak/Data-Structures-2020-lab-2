#include <stdlib.h>
#include <stdio.h>

#include "ADTList.h"



int main() {
	List list = list_create(NULL);

	// προσθήκη των αριθμών από το 0 έως 9 στη λίστα
	for (int i = 0; i < 10; i++)
		list_insert_next(list, list_last(list), &i);

	// εκτύπωση των περιεχομένων της λίστας
	//
	// for (...) {
	// 	...
	// }
} 