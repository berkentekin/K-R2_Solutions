#include <stdio.h>
#define MAXLINE 1000

int max; /* max length seen so far*/
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */

int get_line(void);
void copy(void);

int main()
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = get_line()))
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

int get_line(void)
{
	int i, c;
	extern char line[]; /* No need to rewrite size for extern arrays */

	for (i = 0; i < MAXLINE - 1
			&& (c=getchar()) != EOF
			&& c != '\n'; ++i)
		line[i] = c;
	line[i] = '\n';
	line[i+1] = '\0';
	return i;
}

void copy(void)
{
	int i;
	extern char line[], longest[];
	for (i = 0; (longest[i] = line[i]) != '\0'; ++i);
}


