typedef struct stack Stack;
typedef struct node *node_ptr;

typedef struct node{
	void* data;
	node_ptr link ;
}Node;

struct stack{
	node_ptr top;
	int count;
};

Stack createStack(void);
int push(Stack*,void*);
