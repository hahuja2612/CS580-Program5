#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queuelist * newQueuelist(){
	    Queuelist * s=malloc(sizeof(Queuelist));
	        s->head->data=NULL;
		    s->tail->data=NULL;
		        s->peek=&peekQueuelist;
			    s->pop=&enqueueQueuelist;
			        s->push=&dequeueQueuelist;
				    s->clear=&clearQueuelist;
				        s->delete=&deleteQueuelist;
					    return s;
}

List * newQueue(Data d,Node * h,Node *t){
	    List *q=malloc(sizeof(Queue));
	        q->d=d;
		    q->head=h;
		        q->tail=t;
			    return n;
}


void enqueueQueuelist(struct queuelist * l, Data d){
	    if(l->head==NULL){
		            List * q = newQueue(d,NULL,NULL);
			            q->d=d;
				            q->head=q->tail;
					        }
	        else{
			        Node * p = l->head;
				        Node * e = newQueue(d,NULL,NULL);
					        p->prev= e;
						        e->next = p;
							        l->head=e;
								    }
}

Data dequeueQueuelist(struct queuelist * l){
	    if(l->head==NULL){
		            return -1;
			        }
	        else if(l->head->next == NULL){
			        l->head = NULL;
				        free(l->head);
					        return NULL;
						    }
		    else{
			            Node * p = l->head;
				            l->head=p->next;
					            Data * d = p->data;
						            free(p);
							            p=NULL;
								            l->head->prev=NULL;
									            return d;
										        }
}

Data peekQueuelist(struct queuelist *){
	    if(l->head==NULL)
		            return -1;
	        else{
			        Node * p=l->head;
				        return p;
					    }
}

void clearQueuelist(struct queuelist *){
	    while(l->head==NULL || l->tail==NULL){
		            l->head=l->tail=NULL;
			            free(l->head);
				            free(l->tail);
					            l->head=l->head->next;
						            l->tail=l->tail->prev;
							            free(l);
								        }
}
void * deleteQueuelist(struct queuelist *){
	    free(l);
}
List * newQueuevector(){
	    
}
void pushQueuevector(struct queuevector * v, Data){
	    int full=current_size;
	        v->current_size;
		    return insertVector(,,)
}
List * newQueuevector(){
	    Queuevector *v=malloc(sizeof(Queuevector));
	        
	        v->data=NULL;
		    v->max_size=0;
		        v->current_size=0;
			    v->push= &pusgQueuevector;
			        v->pop=&popQueuevector;
				    v->peek=&peekQueuevector;
				        v->clear=&clearQueuevector;
					    v->delete=&deleteQueuevector;
					        return v;
}
void pushQueuevector(struct queuevector *qv, Data d){
	    return insertVector(sv->data,0,d);
}
Data popQueuevector(struct queuevector * qv){
	    Data d=qv->data[current_size];
	        return removeVector(sv->data,sv->data->current_size)
}
Data peekQueuevector(struct queuevector * qv){
	    data d=v->data[v->current_size-1]
		        return d;
}
void clearQueuevector(struct queuevector *qv);
while(qv->current_size==-1){
	    popQueuevector(qv);
}
return qv;
}
void * deleteQueuevector(struct queuevector *){
	    free(qv);
}

