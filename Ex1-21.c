#include <stdio.h>

#define TABSTOP 8
#define MAXLEN 1000

int get_line_entab(char line[], int lim);
void print_replace_seqs(char line[]);

int main(void)
{
	char line[MAXLEN];
	int len;
	while ((len = get_line_entab(line, MAXLEN)) != 0)
		print_replace_seqs(line);

	return 0;
}

int get_line_entab(char s[], int lim)
{
	int i, c, space;
	space = 0;
	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
		 s[i] = c;
		 if (c == ' ') {
			 ++space;
			 if (space == TABSTOP) {
				 i -= TABSTOP - 1;
				 s[i] = '\t';
				 space = 0;
			}
		 }
		 else
			 space = 0;
	}
	if (c == '\n') {
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

void print_replace_seqs(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == ' ')
			printf("/spc/");
		else if (s[i] == '\t')
			printf("\\t");
		else
			putchar(s[i]);
	}
}



