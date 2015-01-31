#include <stdio.h>
#include "stack.h"
#include "expr_assert.h"

void test_createStack_create_a_stack(){
	Stack s1;
	s1 = createStack();
	assertEqual((int)s1.top,(int)NULL);
	assertEqual(s1.count,0);
};

void test_push_push_the_data_onto_stack(){
	int data = 23,result;
	Stack s1 = createStack();
	result = push(&s1,&data);
	assertEqual(result,1);
}

void test_push_push_the_data_onto_stack_02(){
	int data[] = {23,2,3,4},result;
	Stack s1 = createStack();
	push(&s1,&data[0]);
	push(&s1,&data[1]);
	push(&s1,&data[2]);
	result = push(&s1,&data[3]);
	assertEqual(result,4);
}

void test_push_push_the_data_onto_stack_03(){
	int data[] = {23,2,45},result;
	Stack s1 = createStack();
	push(&s1,&data[0]);
	push(&s1,&data[1]);
	result = push(&s1,&data[2]);
	assertEqual(result,3);
	printf("%p\n",(node_ptr)s1.top);
	assertEqual(*(int*)(s1.top)->data,45);
}

// Stack getStackOf3(,){

// };

// void test_pop_pop_the_top_element_of_stack(){
// 	int data[] = {23,2,45},result;
// 	Stack s1 = createStack();
// 	push(&s1,&data[0]);
// 	push(&s1,&data[1]);
// 	push(&s1,&data[2]);

// }





