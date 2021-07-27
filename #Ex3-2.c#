#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void escape(char to[], char from[]);
void escape_rev(char to[], char from[]);
int get_str(char line[], int lim);

int main(void)
{
	char line[MAXLEN], esc[MAXLEN], new[MAXLEN];
	get_str(line, MAXLEN);
	escape(esc, line);
	escape_rev(new, esc);
	printf("\nline:\n%s\nesc:\n%s\n\nnew:\n%s\n",line, esc, new);
	if (!strcmp(line, new))
		printf("Line is preserved.\n");
	else
		printf("Line is NOT preserved.\n");
	return 0;
}

int get_str(char line[], int lim)
{
	int i, c;
	for (i = 0; i < (lim-1) && (c = getchar()) != EOF; i++)
		line[i] = c;
	line[i] = '\0';
	return i;
}

void escape(char to[], char from[])
{
	int i, j;
	for (i=j=0; from[i] != '\0'; i++) {
		switch (from[i]) {
		case '\n':
			to[j++] = '\\';
			to[j++] = 'n';
			break;
		case '\t':
			to[j++] = '\\';
			to[j++] = 't';
			break;
		default:
			to[j++] = from[i];
		}
	}
	to[j] = '\0';
}

void escape_rev(char to[], char from[])
{
	int i, j;
	for (i=j=0; from[i] != '\0'; i++, j++) {
		if (from[i] == '\\')
			switch (from[++i]) {
			case 'n':
				to[j] = '\n';
				break;
			case 't':
				to[j] = '\t';
				break;
			default:
				to[j] = from[--i];
				break;
			}
		else
			to[j] = from[i];
	}
	to[j] = '\0';
}
