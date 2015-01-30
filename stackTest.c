#include <stdio.h>
#include "stack.h"
#include "expr_assert.h"

void test_createStack_create_a_stack(){
	Stack s1;
	s1 = createStack();
	assertEqual((int)s1.data,(int)NULL);
	assertEqual((int)s1.next,(int)NULL);
	assertEqual(s1.size,-1);
};

