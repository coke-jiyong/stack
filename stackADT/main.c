#include "stackadt.h"

int main()
{
	Stack a = create();
	Stack b = create();

	push(a, 1);
	push(a, 2);
	push(a, 3);
	printf("pop(a) : %d\n", pop(a));
	printf("peek(a) : %d\n",peek(a));
	printf("is_full() : %d\n", is_full(a));
	push(b, 7);
	push(b, 8);
	push(b, 9);
	printf("pop(b) : %d\n", pop(b));
	printf("peek(b) : %d\n", peek(b));
	printf("is_full() : %d\n", is_full(b));
	show_stack(a);
	show_stack(b);
	

	destroy(a);
	destroy(b);
	return 0;
}