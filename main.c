//#include "stack.h"
#include "list_stack.h"

char* parenthesis1 = "({[";
char* parenthesis2 = ")}]";
int is_parenthesis1(int ch);
int is_parenthesis2(int ch);
int check_paren(char,char);
void stack_handle(char* buf);
int main()
{
	//process_command();

	while (1)
	{
		//init();
		char buf[100] = { 0, };
		printf("$ ");
		scanf("%s", buf);
		if (!strcmp(buf, "exit")) {
			clear_stack();
			break;
		}
		stack_handle(buf);
		
		if (!is_empty()) {
			printf("false.\n");
			show_stack();
		}
		else
			printf("ture.\n");
		
		clear_stack();
	}
}
void stack_handle(char * buf)
{
	int _parenthesis1, _parenthesis2;
	for (int i = 0; i < strlen(buf); i++) {
		_parenthesis1 = is_parenthesis1(buf[i]);
		if (_parenthesis1 >= 0) {
			push(buf[i]);
			continue;
		}

		_parenthesis2 = is_parenthesis2(buf[i]);
		if (_parenthesis2 >= 0) {
			push(buf[i]);
		}
		else {
			continue;
		}

		char ch = pop();
		if (check_paren(peek(), ch)) {
			pop();
		}
		else {
			push(buf[i]);
		}
	}
	
}

int check_paren(char paren1, char paren2) 
{
	//printf("check_paren : %c, %c\n", paren1, paren2);
	return is_parenthesis1(paren1) == is_parenthesis2(paren2);
}

int is_parenthesis1(int ch) {
	for (int i = 0; i < 3; i++) {
		if (parenthesis1[i] == ch) {
			return i ;
		}
	}

	return -1;
}

int is_parenthesis2(int ch) {
	for (int i = 0; i < 3; i++) {
		if (parenthesis2[i] == ch) {
			return i ;
		}
	}

	return -1;
}