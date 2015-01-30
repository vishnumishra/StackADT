typedef struct Stack{
	void* data;
	struct Stack *next;
	int size; 
}Stack;

Stack createStack(void);

