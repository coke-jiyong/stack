//#include "stack.h"
//#define MAX 100
//
//char stack[MAX];
//int top = -1;
//
//void push(char ch)
//{
//	if (is_full()) {
//		printf("full.\n");
//		return;
//	}
//	top++;
//	stack[top] = ch;
//}
//
//char pop()
//{
//	if (is_empty()) {
//		printf("empty.\n");
//		return 0;
//	}
//	char tmp = stack[top];
//	top--;
//	return tmp;
//}
//
//char peek()
//{
//	if (is_empty()) {
//		printf("empty.\n");
//		return 0;
//	}
//	return stack[top];
//}
//
//int is_full()
//{
//	return top == MAX - 1;
//}
//int is_empty()
//{
//	return top == -1;
//}
//
//void show_stack()
//{
//	if (is_empty()) {
//		printf("empty.\n");
//		return;
//	}
//	
//
//	for (int i = 0; i < top+1; i++) {
//		printf("%c\t", stack[i]);
//	}
//	printf("\n");
//}
//
//void process_command()
//{
//	while (1) {
//		char buf[10];
//		printf("$ ");
//
//		if (read_line(stdin, buf, 10) <= 0)
//			continue;
//		char* cmd1, * cmd2;
//		cmd1 = strtok(buf, " ");
//		if (cmd1 == NULL) {
//			printf("invalid argument.\n");
//			continue;
//		}
//		if (!strcmp(cmd1, "pop")) {
//			char ch = pop();
//			if (ch)
//				printf("pop %c\n", ch);
//		}
//		else if (!strcmp(cmd1, "push")) {
//			cmd2 = strtok(NULL, " ");
//			if (cmd2 == NULL) {
//				printf("invalid argument.\n");
//				continue;
//			}
//			push(cmd2[0]);
//		}
//		else if (!strcmp(cmd1, "peek")) {
//			char ch = peek();
//			if (ch)
//				printf("%c\n", ch);
//		}
//		else if (!strcmp(cmd1, "list")) {
//			show_stack();
//		}
//		else if (!strcmp(cmd1, "exit")) {
//			break;
//		}
//		else {
//			printf("invalid argument.\n");
//			continue;
//		}
//	}
//}
//
//int read_line(FILE* fp, char* buf, int limit) {
//	int ch, i = 0;
//
//	while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
//		if (i < limit - 1) {
//			buf[i++] = ch;
//		}
//	}
//	buf[i] = '\0';
//	return i;
//}