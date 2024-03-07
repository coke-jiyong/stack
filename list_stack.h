#pragma once
#ifndef LIST_STACK_H
#define STACK_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <vld.h>
#include <string.h>
//stack with list
#define MAX 100
struct STACK {
	char data;
	struct STACK* next;
}typedef Stack;


void init();
void push(char data);
Stack* make_stack(char data);
char pop();
char peek();
int is_empty();
int is_full();
int read_line(FILE*, char*, int);
void process_command();
void show_stack();
void clear_stack();
#endif