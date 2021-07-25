#include <stdio.h>
#include <ctype.h> /* for isspace() and isdigit() */

#define MAXLEN 1000

int atoi(char s[]);
void get_str(char line[], int lim);

int main(void)
{
	char num[MAXLEN];
	get_str(num, MAXLEN);
	printf("%d\n", atoi(num));
	return 0;
}

void get_str(char line[], int lim)
{
	int c, i;
	for (i = 0; i < (lim-1) && (c = getchar()) != '\0' && c != '\n'; i++)
		line[i] = c;
	line[i] = '\0';
}

int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') /* skip sign */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;

}
