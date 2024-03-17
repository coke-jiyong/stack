#include "stackadt.h"
#include "makePostfix.h"


int make_postfitx(char* infix, char* buf)
{
	int res, i = 0;
	int len = 0;
	int open_bracket = 0;
	Stack stack = create();
	char* item = strtok(infix, " ");
	while (item != NULL) {
		if (item[0] >= '0' && item[0] <= '9') {
			for (int j = 0; j < strlen(item); j++) {
				len += sprintf(buf + len, "%c", item[j]);
			}
			len += sprintf(buf + len, " ");
		}
		else if ((res = is_operator(item[0])) >= -1) {
			if (is_empty(stack) || item[0] == '(') { // (가 나오면 ) 가 나올때까지 푸시
				push(stack, item[0]);
			}
			else {
				if (is_bignum(stack, res)) {
					push(stack, item[0]);
				}
				else{
					while (!is_bignum(stack, res) && !is_empty(stack)) {
						Item ch = pop(stack);
						if (ch == '(')
							break;
						len += sprintf(buf + len, "%c ", ch);
					}
					if (item[0] != ')') {
						push(stack, item[0]);
					}
				}
			}
		}
		else{
			handle_exception("Syntax Error: invalid character encountered. ");
		}
		item = strtok(NULL, " ");
	}

	while (!is_empty(stack)) {
		len += sprintf(buf + len, "%c ", pop(stack));
	}
	destroy(stack);
	return len;
}


bool is_bignum(Stack s , int index) 
{	
	if (operator_value[index] > operator_value[is_operator(peek(s))])
		return true;
	return false;
}