#include "expr_assert.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Student *creatStudent(int id,float eng_score,char* name){
	Student *std = malloc(sizeof(Student));
	std->id = id;
	std->eng_score = eng_score;
	std->name = name;
	return std;
}

LinkedList createListOf3(){
	Node *n1,*n2,*n3;
	LinkedList list = createList();
	Student *std1,*std2,*std3;

	std1 = creatStudent(2,40.5,"badOne");
	std2 = creatStudent(3,98.0,"goodOne");
	std3 = creatStudent(4,02.5,"cheee...");

	n1 = create_node(std1);
	n2 = create_node(std2);
	n3 = create_node(std3);

	add_to_list(&list,n1);
	add_to_list(&list,n2);
	add_to_list(&list,n3);
	return list;
};

void test_creatStack_creat_null_stack(){
	
	Stack s = createStack();
	assert(s.list!=NULL);
	assert(*(s.top)==NULL);
}

void test_push_push_the_data_on_stack(){
	int data=1,count;
	Stack s = createStack();
	count = push(s,&data);
	assertEqual(count, 1);
	assert((*(s.top))->data==&data);
}


void test_createStack_create_a_stack(){
	Stack s1;
	s1 = createStack();
	assert(*s1.top==NULL);
};

void test_push_push_the_data_onto_stack(){
	int data = 23,result;
	Stack s1 = createStack();
	result = push(s1,&data);
	assertEqual(result,1);
}

void test_push_push_the_data_onto_stack_02(){
	int data[] = {23,2,3,4},result;
	Stack s1 = createStack();
	push(s1,&data[0]);
	push(s1,&data[1]);
	push(s1,&data[2]);
	result = push(s1,&data[3]);
	assertEqual(result,4);
}

void test_push_push_the_data_onto_stack_03(){
	int data[] = {23,2,45},result;
	Stack s1 = createStack();
	push(s1,&data[0]);
	push(s1,&data[1]);
	result = push(s1,&data[2]);
	assertEqual(result,3);
	assertEqual(*(int*)(*s1.top)->data,45);
}

void test_push_push_the_data_onto_stack_04(){
	Student *std1,*std2,*std3;
	Stack s = createStack();
	int result;
	std1 = creatStudent(2,40.5,"badOne");
	std2 = creatStudent(3,98.0,"goodOne");
	std3 = creatStudent(4,02.5,"cheee...");

	push(s,std1);
	push(s,std2);
	result = push(s,std3);
	assertEqual(result, 3);
}

void test_push_push_the_data_onto_stack_05(){
	Student *std1,*std2,*std3;
	Stack s = createStack();
	Student* result;
	std1 = creatStudent(2,40.5,"badOne");
	std2 = creatStudent(3,98.0,"goodOne");
	std3 = creatStudent(4,02.5,"cheee...");

	push(s,std1);
	push(s,std2);
	push(s,std3);
	result = pop(s);
	assert((result)->eng_score == 2.5 );
}

void test_push_push_the_data_onto_stack_06(){
	Student *std1,*std2,*std3;
	Stack s = createStack();
	Student* result;
	std1 = creatStudent(2,40.5,"badOne");
	std2 = creatStudent(3,98.0,"goodOne");
	std3 = creatStudent(4,02.5,"cheee...");

	push(s,std1);
	push(s,std2);
	push(s,std3);
	pop(s);
	result = pop(s);

	assert((result)->name == "goodOne" );
}


void test_pop_return_NULL_if_stack_is_empty(){
	Student *std1,*std2,*std3;
	Stack s = createStack();
	int* result;
	std1 = creatStudent(2,40.5,"badOne");
	std2 = creatStudent(3,98.0,"goodOne");

	push(s,std1);
	push(s,std2);
	pop(s);
	pop(s);
	result = pop(s);
	assert( result == NULL );
}

void test_pop_pop_the_top_element_of_stack(){
	int data[] = {23,2,45};
	node_ptr result;
	Stack s1 = createStack();
	push(s1,&data[0]);
	push(s1,&data[1]);
	push(s1,&data[2]);
	result = pop(s1);
	assertEqual(*(int*)result, 45);
}

void test_stack_gives_data_15_at_index_2(){
	Stack stack = createStack();
	int data[] = {12,13,15,16},count,index,i;
	for(i=0;i<4;i++){
		count = push(stack,&data[i]);
	}
	index = indexOf(*stack.list,&data[2]);
	assertEqual(count,4);
	assertEqual(index,2);
	assertEqual(*(int*)(*stack.top)->data,data[3]);
};



