#include "list_stack.h"

Stack* stack;
int n = 0;
void init()
{
	stack->data = '\0';
	stack->next = NULL;
	n = 0;
}
void push(char  data)
{
	if (is_full()) {
		//printf("full.\n");
		return;
	}
	if (is_empty()) {
		stack = make_stack(data);
		n++;
		return;
	}
	Stack* new_stack = make_stack(data);
	new_stack->next = stack;
	stack = new_stack;
	n++;
}

Stack * make_stack(char  data)
{
	Stack* new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->data = data;
	new_stack->next = NULL;
	return new_stack;
}

char pop()
{
	if(is_empty()){
		//printf("is_empty.\n");
		return 0;
	}
	char box = stack->data;
	Stack* new_stack = stack->next;
	free(stack);	stack = NULL;
	stack = new_stack;
	n--;
	return box;
}

char peek() {
	if (is_empty()) {
		//printf("empty.\n");
		return 0;
	}
	return stack->data;
}

int is_full() {
	return n == MAX;
}

int is_empty() {
	return stack == NULL;
}

int read_line(FILE* fp, char* buf, int limit) {
	int ch, i = 0;

	while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
		if (i < limit - 1) {
			buf[i++] = ch;
		}
	}
	buf[i] = '\0';
	return i;
}

void show_stack()
{
	if (is_empty()) {
		printf("empty.\n");
		return;
	}
	Stack* ptr_stack = stack;
	while (ptr_stack != NULL)
	{
		printf("%c\t", ptr_stack->data);
		ptr_stack = ptr_stack->next;
	}
	printf("\n");
}

void clear_stack()
{	

	while (stack != NULL) {
		Stack* p = stack->next;
		free(stack);	stack = NULL;
		stack = p;
	}
}

void process_command()
{
	while (1) {
		char buf[100];
		printf("$ ");

		if (read_line(stdin, buf, 100) <= 0)
			continue;
		char* cmd1;
		char* cmd2;
		cmd1 = strtok(buf, " ");
		if (cmd1 == NULL) {
			printf("invalid argument.\n");
			continue;
		}
		if (!strcmp(cmd1, "pop")) {
			char ch = pop();
			if (ch)
				printf("pop %c\n", ch);
			
		}
		else if (!strcmp(cmd1, "push")) {
			cmd2 = strtok(NULL, " ");
			if (cmd2 == NULL) {
				printf("invalid argument.\n");
				continue;
			}
			push(cmd2[0]);
		}
		else if (!strcmp(cmd1, "peek")) {
			char ch = peek();
			if (ch)
				printf("%c\n", ch);
		}
		else if (!strcmp(cmd1, "list")) {
			show_stack();
		}
		else if (!strcmp(cmd1, "exit")) {
			clear_stack();
			break;
		}
		else {
			printf("invalid argument.\n");
			continue;
		}
	}
}