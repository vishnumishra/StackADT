#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack createStack(void){
	Stack s1 ;
	// s1.count = malloc(sizeof(int));
	// s1.top  = malloc(sizeof(Node));
	s1.count = 0;
	s1.top = NULL;
	return s1;
};

int push(Stack *s,void* data){
	node_ptr newNode = malloc(sizeof(Node));
	newNode->data = data;	
	newNode->link= s->top;
	(s->top) = newNode;
	s->count++;
	return s->count;
	// (*(int*)s.count)++;
	// return *(int*)s.count;
};

// int pop(Stack *s){
// 	node_ptr newNode = malloc(sizeof(Node));
// 	(newNode)->link= s->top;
// 	s->top = newNode;
// 	s->count++;
// 	return s->count;
// };


