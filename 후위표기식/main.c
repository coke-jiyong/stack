#include "stackadt.h"
int read_line(FILE* fp, char* str, int limit)
{
	int ch, i = 0;
	while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
		if(i < limit -1)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int main()
{
	
	char s[INIT_CAPACITY];
	printf("input postfix expression : ");
	if (read_line(stdin, s, INIT_CAPACITY) <= 0) {
		printf("input error.\n");
		return 0;
	}
	printf("result : %d\n", eval(s));
	destroy();
	return 0;
}