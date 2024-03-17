#include "stackadt.h"

Stack operand_stack;


int eval(char * expr)
{
	char* token = strtok(expr, " ");
	operand_stack = create();
	while (token != NULL) {
		if (token[0] >= '0' && token[0] <= '9') {
			push(operand_stack, atoi(token));
		}
		else if (is_operator(token[0]) > -1) {
			int result = eval_op(token[0]);
			push(operand_stack, result);
		}
		else {
			handle_exception("Sytax Error: invaild character.");
		}
		token = strtok(NULL, " ");
	}
	if (is_empty(operand_stack)) {
		handle_exception("Sytax Error: empty stack(eval()).");
	}
	int answer = pop(operand_stack);
	if (!is_empty(operand_stack)) {
		handle_exception("Sytax Error: not empty stack(eval()).");
	}

	destroy(operand_stack);
	return answer;
}

int eval_op(char op)
{
	if (is_empty(operand_stack)) {
		handle_exception("Sytax Error: stack empty.");
	}
	int r_v, l_v;
	r_v = pop(operand_stack);
	if (is_empty(operand_stack)) {
		handle_exception("Sytax Error: stack empty.");
	}
	l_v = pop(operand_stack);
	
	switch (op) {
		case '+':
			return l_v + r_v;
		case '-':
			return l_v - r_v;
		case '*':
			return l_v * r_v;
		case '/':
			return l_v / r_v;
	}

	handle_exception("Sytax Error: invalid operator.");
}

void handle_exception(char*msg)
{
	printf("%s\n", msg);
	destroy(operand_stack);
	exit(1);
}

int is_operator(char ch)
{
	for (int i = 0; i < strlen(operator); i++) {
		if (ch == operator[i])
			return i;
	}
	return -1;
}

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
	/*if (is_empty(operand_stack)) {
		terminated("Error in destroy: stack is empty.");
		return;
	}*/
	free(s->contents);
	free(s);
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
	{
		terminated("Error in push(): stack is full.");
	}

	s->contents[s->top + 1] = item;
	s->top++;
}

Item peek(Stack s) 
{
	return s->contents[s->top];
}




static void terminated(const char* msg) {
	printf("terminated - %s\n", msg);
	exit(1);
}