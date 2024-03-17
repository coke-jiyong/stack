#ifndef STACKADT_H
#define STACKADT_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <vld.h>
#include <string.h>
#include <stdbool.h>

#define INIT_CAPACITY 100

typedef int Item;

static char operator[] = "+-*/()";
static int  operator_value[] = { 1,1,2,2,-1,-1 };

struct stack_type {
	Item* contents;
	int top;
	int size;
};

typedef struct stack_type* Stack;

static void terminated(const char* msg);
Stack create();
void destroy(Stack s);

Item peek(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
Item pop(Stack s);
void push(Stack s, Item item);
void reallocate(Stack s);
int is_operator(char ch);
int eval(char* expr);
void handle_exception(char*);
int eval_op(char op);
#endif