#include "stackadt.h"

Stack create()
{
	Stack new_stack = (Stack)malloc(sizeof(struct stack_type));
	if (new_stack == NULL) {
		terminated("Error in create(): stack malloc fail.");
	}

	new_stack->contents = (Item*)malloc(sizeof(Item) * INIT_CAPACITY);
	if (new_stack->contents == NULL) {
		free(new_stack);
		terminated("Error in create(): stack->contents malloc fail.");
	}

	new_stack->size = INIT_CAPACITY;
	new_stack->top = -1;
	return new_stack;
}

void destroy(Stack s) 
{
	printf("Enter desroy()\n");
	if (is_empty(s)) {
		terminated("Error in destroy: stack is empty.");
		return;
	}
	free(s->contents); 
	free(s);	
}


void make_empty(Stack s)
{
	s->top = -1;
}

bool is_empty(Stack s)
{
	return s->top == -1;
}

bool is_full(Stack s) 
{
	return s->top == s->size;
}

Item pop(Stack s)
{
	if (is_empty(s)) {
		destroy(s);
		terminated("Error in pop(): stack is empty.");
	}
	Item tmp = s->contents[s->top];
	s->top--;
	return tmp;
}

void push(Stack s, Item item) 
{
	if (is_full(s)) 
		reallocate(s);

	s->contents[s->top + 1] = item;
	s->top++;
}

void reallocate(Stack s)
{
	Item* new_item = (Item*)malloc(sizeof(Item) * (s->size + 10));
	if (new_item == NULL) {
		destroy(s);
		terminated("Error in reallocate(): malloc fail.");
	}
	for (int i = 0; i < s->size; i++) {
		new_item[i] = s->contents[i];
	}
	free(s->contents); s->contents = NULL;
	s->contents = new_item;
	s->size += 10;
}

Item peek(Stack s)
{
	if (is_empty(s)) {
		destroy(s);
		terminated("Error in peek(): stack is empty.");
	}
	return s->contents[s->top];
}

void show_stack(Stack s)
{
	for (int i = s->top; i >= 0; i--) {
		printf("%d   ", s->contents[i]);
	}
	printf("\n");
}

static void terminated(const char* msg) {
	printf("%s\n", msg);
	exit(1);
}