#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);
void reverse_comma(char s[]);

int main()
{
	char str[] = "Hello!";
	reverse_comma(str);
	printf("%s", str);
	return 0;
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void reverse_comma(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i], s[i] = s[j], s[j] = c;
	}
}
