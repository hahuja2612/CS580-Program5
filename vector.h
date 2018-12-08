#include"data.h"
#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector{
	Data *data;
	unsigned int current_size;
	unsigned int max_size;
	int *index;
	void (*insert)(struct vector * array, int , Data);
	Data * (*read)(struct vector * array, int index);
	void (*remove)(struct vector * array, int index);
	void (*delete)(struct vector * array);
}Vector;

Vector *newVector();
void insertVector(Vector * array, int index, Data value);
Data * readVector(Vector * array, int index);
void removeVector(Vector * array, int index);
void * deleteVector(Vector * array);
#endif
