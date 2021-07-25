#include <stdio.h>

#define TABSTOP 8
#define MAXLEN 1000

int get_line_detab(char line[], int lim);
void print_replace_seqs(char line[]);

int main()
{
	char line[MAXLEN];
	int len;
	while ((len = get_line_detab(line, MAXLEN)) != 0) {
		print_replace_seqs(line);

	}
	return 0;
}

int get_line_detab(char line[], int lim)
{
	int i, space, c;
	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n';) {
		if (c == '\t')
			for (space = 0; space < TABSTOP; ++space) {
				line[i] = ' ';
				++i;
			}
		else {
			line[i] = c;
			++i;
		}
	}
	line[i] = '\n';
	++i;
	line[i] = '\0';
	return i-1;
}

void print_replace_seqs(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\t')
			printf("\\t");
		else if (s[i] == ' ')
			printf("/spc/");
		else
			putchar(s[i]);
	}
}
