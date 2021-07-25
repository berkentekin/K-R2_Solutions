#include <stdio.h>
#define MAXSIZE 1000

void reverse(char line[]);
int get_line(char line[], int lim);

int main()
{
	int len;
	char line[MAXSIZE];
	while ((len = get_line(line, MAXSIZE)) != 0) {
		reverse(line);
		printf("%d %s",len, line);
	}

	return 0;
}

int get_line(char s[], int lim)
{
	int i, c;
	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
		s[i] = c;
	if (i > 0 && c == '\n') {
		s[i] = c;
		++i;
	}
	else if (i == 0) {
		s[i] = '\n';
		++i;

	}
	s[i] = '\0';
	i = i - 1;
	return i;
}

void reverse(char s[])
{
	int i, j;
	char tmp;
	for (i = 0; s[i] != '\n'; ++i);
	--i;
	for (j = 0; j <= i; ++j) {
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		--i;
	}
}
