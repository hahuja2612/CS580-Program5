#include"data.h"
#ifndef LIST_H
#define LIST_H

typedef struct node{
	Data data;
	struct node * next;
	struct node * prev;
}Node;

typedef struct list{
	int index;
	Node * head, *tail; 
	void (*insert)(struct list *, int, Data);
	Data * (*read)(struct list *, int);
	void (*remove)(struct list  *, int);
	void (*delete)(struct list *);
}List;

List * newList();
void insertList(List * list, int index, Data value);

void removeData(List * list, int index);

Data * readData(List * list, int index);

void * delete(List * list);

#endif
