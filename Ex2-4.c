#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

void squeeze(char s1[], char s2[]);

int main(void)
{
	int c, i;
	char s1[MAXLEN], s2[MAXLEN];
	for (i = 0; (c = getchar()) != '\n'; ++i) {
		s1[i] = c;
	}
	s1[i] = '\0';
	for (i = 0; (c = getchar()) != '\n'; ++i) {
		s2[i] = c;
	}
	s2[i] = '\0';
	squeeze(s1,s2);
	printf("%s\n", s1);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k, fl = 0;
	for (i = j = 0; s1[i] != '\0'; ++i) {
		fl = 0;
		for (k = 0; s2[k] != '\0'; k++) {
			if (s1[i] == s2[k]) {
				fl = 1;
				break;
			}
		}
		if (fl == 0)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}


