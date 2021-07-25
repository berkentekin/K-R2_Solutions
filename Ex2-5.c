#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int any(char s1[], char s2[]);

int main(void)
{
	int c, i, loc;
	char s1[MAXLEN], s2[MAXLEN];
	for (i = 0; (c = getchar()) != '\n'; ++i)
		s1[i] = c;
	s1[i] = '\0';
	for (i = 0; (c = getchar()) != '\n'; ++i)
		s2[i] = c;
	s2[i] = '\0';
	loc = any(s1, s2);
	printf("%d\n", loc);
	return 0;
}

int any(char s[], char find[])
{
	int i, j;
	for (i = 0; s[i] != '\0'; ++i) {
		for (j = 0; find[j] != '\0' && s[i] != find[j]; ++j);
		if (find[j] != '\0')
			return i;
	}
	return -1;
}


