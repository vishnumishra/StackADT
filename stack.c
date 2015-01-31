#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack createStack(){
	LinkedList *list = calloc(sizeof(LinkedList),1);
	Stack s = {list,&list->tail};
	return s;
}

int push(Stack s,void* data){
	Node *n1;
	int result;
	if(!data) return -1;
	n1 = create_node(data);
	result=add_to_list(s.list, n1);
	return s.list->count;
}

void * pop(Stack s){
	Node *result;
	result =  deleteTail(s.list, s.list->count-1);
	return (result==NULL)?NULL:result->data;
};
