#include <stdio.h>
#define MAXSIZE 1000
#define FILTER 80

int get_line(char line[], int lim);

int main()
{
	int len;
	char current[MAXSIZE];

	while ((len = get_line(current, MAXSIZE)) != 0)
		if (len > FILTER)
			printf("%s\n", current);

	return 0;
}

int get_line(char s[], int lim)
{
	int i, c;
	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
		s[i] = c;
	}
	if (i == 0)
		return i;
	else if (c == '\n') {
		s[i] = c;
		++i;
		s[i] = '\0';
	} else {
		s[lim-2] = '\n';
		++i;
		s[lim-1] = '\0';
		for (; c != '\n' && ((c = getchar()) != EOF); ++i);
	}


	return i;
}


