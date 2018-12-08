#include"list.h"
#include<stdlib.h>
#include<stdio.h>

List * newList(){
	List * list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->index = 0;
	list->insert = insertList;
	list->read = readData;
	list->remove = removeData;
	list->delete = delete;
	return list;
}
 
void insertList(List * list, int index, Data value){
		 
	if(list->index == 0){
		Node * currNode = malloc(sizeof(Node));
		currNode -> data = value;
		list -> head = currNode;
		list -> tail = currNode;
		list -> head -> prev = NULL;
		list -> tail -> next = NULL;
		list -> index = list->index + 1;
	}
	else if(list->index <= index){
		Node * currNode = malloc(sizeof(Node));
		currNode -> data = value;
		list -> tail -> next = currNode;
		currNode -> prev = list -> tail;
		currNode -> next = NULL;
		list -> tail = currNode;
		list -> index = list -> index+1;

		}
	
}

void removeData(List * list, int index){
	Node * currNode=NULL;
	int i=0;
	if(index >= list->index)
		return;
	if(list -> index == 0)
		return;
	
	else{
		if(list->head == list->tail){
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
			return;
		}else if(index == (list->index - 1)){
			currNode = list->tail;
			list->tail->prev->next = NULL;
			list->tail = list->tail->prev;
			list->index = list->index - 1;
			return;
		}
		else if(index == 0)
		{
			currNode = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			list->index = list->index - 1;
			return;
		}
		
		else if(index > 0){
			currNode = list->head;
			while(i != index)
			{
				currNode = currNode->next;
				i++;
			}
			currNode->next->prev = currNode->prev;
			currNode->prev->next = currNode->next;
			list->index = list->index - 1;
			return;
		}
	}
	free(currNode);
	currNode = NULL;
}


Data * readData(List * list, int index){
	if(index > list->index)
		return NULL;
	else{
	  	Node * currNode = list->head;
        	int i = 0;
        	while(currNode -> next != NULL && i < index )
        	{
			currNode -> next -> prev = currNode;
                	currNode = currNode -> next;
			i++;
        	}
        	return &currNode -> data;
        }
}



void * delete(List * list){
	free(list -> head);
	free(list -> tail);	
	free(list);
	list=NULL;
  }
	

