#include <stdio.h>
#include "stack.h"

Stack createStack(void){
	Stack s1 ;
	s1.data = NULL;
	s1.next = NULL;
	s1.size  = -1;
	return s1;
};



