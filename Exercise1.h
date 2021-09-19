#ifndef EXERCISE1_H
#define EXERCISE1_H

#include "CircularArrayQ.h"

/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list){
	int i,cnt=0;
	for(i = Q.front; i != Q.rear+1; i++,cnt++){
		if(i+1==MAX){
			i=0;
		}
	}
	
	return cnt;
}

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list){
	int i,cnt=0;
	PersonLinkedList P=NULL,temp;
	Person pers;
	for(i = Q.front; i != Q.rear+1; i++){
		if(i+1==MAX){
			i=0;
		}
		
		if(list.data[i].sex=='F' || list.data[i].sex=='f'){
			pers=front(list);
			if(dequeue(*list,pers)){
				temp=(PersonLinkedList)malloc(sizeof(PersonNode));
		
				if(temp!=NULL){
					temp->elem=front(list);
					temp->next=P;
					P=temp;
				}
			}	
		}
		
	}
	
	return P;
}

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
	
}

#endif
