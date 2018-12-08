#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "vector.h"
#include "list.h"

Stacklist * newStacklist(){
    Stacklist * s=malloc(sizeof(Stacklist));
    s->data=newList();
    s->peek=peekstacklist;
    s->pop=popstacklist;
    s->push=pushstacklist;
    s->clear=clearstacklist;
    s->delete=deletestacklist;
    return s;
}
Data peekstacklist(Stacklist * s){
    Node * l=s->data->head;
    int index=0;
    while(l->next!=NULL){
        l=l->next;
        index++;
    }
    return *(s->data->read(s->data,index));
}
Data popstacklist(Stacklist * s){
    Node * l=s->data->head;
    int index=0;
    while(l!=NULL){
        l=l->next;
        index++;
    }
    Data d=*(s->data->read(s->data,index));
    s->data->remove(s->data,index);
    return d;
}

void pushstacklist(Stacklist * s,Data d){
    List * l = s->data;
    int index=1;
    if(l->head==NULL){
	    index=0;
	}
    else{
	Node * n=l->head;
    	while(n->next!=NULL){
        	n=n->next;
        	index++;
    	}
    }
    s->data->insert(l,index,d);
}

void deletestacklist(Stacklist * s){
	free(s->data);
	free(s);
}
void clearstacklist(Stacklist * s){
    Node * l=s->data->head;
    int index=0;
    while(l!=NULL){
        l=l->next;
        index++;
    }
    while(index!=-1){
        popstacklist(s);
        index--;
    }
}
Stackvector * newStackvector(){
    Stackvector * s=malloc(sizeof(Stackvector));
    s->data=newVector();
    s->peek=peekStackvector;
    s->pop=popStackvector;
    s->push=pushStackvector;
    s->clear=clearStackvector;
    s->delete=deletestackvector;
    return s;
}
void pushStackvector(struct Stackvector * s, Data d){
    int top=s->data->current_size;
    top--;
    s->data->insert(s->data,top,d);
}
Data popStackvector(struct Stackvector * s){
    int top=s->data->current_size;
    top--;
    Data d;
    if(top==-1){
	    return (Data){-1};
    }
    d= *(s->data->read(s->data,top));
    s->data->remove(s->data,top);
    return d;
}
Data peekStackvector(struct Stackvector * s){
    int top=s->data->current_size;
    top--;
    Data d= *(s->data->read(s->data,top));
    return d;
}
void deletestackvector(Stackvector * s){
	free(s->data);
	free(s);
}
void clearStackvector(struct Stackvector * s){
    int top=s->data->current_size;
    top--;
    while(top!=0){
        top--;
        popStackvector(s);
    }
}




