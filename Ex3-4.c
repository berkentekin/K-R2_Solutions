#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main(void)
{
	int d = -376;
	char digs[1000];
	itoa(d, digs);
	printf("%s\n", digs);
	return 0;
}

void reverse(char s[])
{
	int i, j;
	char tmp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
/* Convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0) /* Record sign */
		n = -n;     /* Make n positive */
	i = 0;
	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0';

	} while ((n /= 10) > 0);
	s[i] = '\0';
	reverse(s);
	if (sign < 0)
		printf("-");
}
