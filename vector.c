#include "vector.h"
#include"data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector * newVector(){
	Vector * vect = malloc(sizeof(Vector));
	vect -> data = NULL;
	vect -> current_size = 0;
	vect -> max_size = 0;
	vect -> index = NULL;
	vect -> insert = insertVector;
	vect -> read = readVector;
	vect -> remove = removeVector;
	vect -> delete = deleteVector;
	return vect;	
}

void insertVector(Vector * array, int index, Data value){
	if(array -> max_size <= index) {
		array -> max_size = index * 2 + 1;
		Vector * new_array = malloc(sizeof(Data) * array -> max_size);
		Vector * new_index_array = malloc(sizeof(int) * array -> max_size);

		memset(new_array, -1, sizeof(Data) * array -> max_size);
		memset(new_index_array, -1, sizeof(int) * array -> max_size);

		memcpy(new_array, array -> data, sizeof(Data) * array -> current_size);
		memcpy(new_index_array, array ->index, sizeof(int) * array -> current_size);

		free(array -> data);
		free(array -> index);

		array->data = NULL;
		array->index = NULL;

		array->data=new_array;
		array->index=new_index_array;
	}
		
	array -> index[index] = index;
	int offset = array -> index[index];
	array -> data[offset] = value;

	if(array -> current_size <= index) {
		array -> current_size = index+1;
	}
}

Data * readVector(Vector * array, int index){
	if(index >= array -> max_size)
		return NULL;

	index = array -> index[index];
	if (index>=0 && index < array -> current_size) {
		return array -> data + index;
	}

	return array -> data+(array -> max_size - 1);

}

void removeVector(Vector * array, int index){
	if (index < array -> current_size) {
		int i = index;
		for(; i < array -> current_size - 1; i++) {
			array -> index[i] = array -> index[i+1];
		}
		array -> current_size = array -> current_size - 1;
	}
}

void * deleteVector(Vector * array){
	free(array->data);
	free(array->index);
	free(array);
	array = NULL;
}
