#include <stdio.h>
#define MAXSIZE 1000

int parse_line(char line[], int lim);

int main()
{
	int len;
	char line[MAXSIZE];
	while ((len = parse_line(line, MAXSIZE)) != 0)
		printf("%d %s", len, line);
	return 0;
}

int parse_line(char s[], int lim)
{
	int i, c;
	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
		s[i] = c;
	if (i == 0) {
		s[i] = '\0';
		return i;
	} else if (c == '\n') {
		for (; s[i] == ' ' || s[i] == '\t'; --i);
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}

	return i;
}


