#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[], int min_width);

int main(void)
{
	int d = -376, w = 10;
	char digs[1000];
	itoa(d, digs, w);
	printf("%s\n", digs);
	return 0;
}

void reverse(char s[])
{
	int i, j;
	int tmp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
/* Convert n to characters in s */
void itoa(int n, char s[], int w)
{
	int i, j, sign;
	if ((sign = n) < 0) /* Record sign */
		n = -n;     /* Make n positive */
	i = 0;
	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0';

	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	for (; i < w; i++) {
		for (j = strlen(s) - 1; j >= 0; j--)
			s[j+1] = s[j];
		s[0] = ' ';
	}
}
