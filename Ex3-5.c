#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main(void)
{
	int d = -376;
	int b = 8;
	char digs[1000];
	itob(d, digs, b);
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
void itob(int n, char s[], int b)
{
	int i, sign, base_trans;
	if ((sign = n) < 0) /* Record sign */
		n = -n;     /* Make n positive */
	i = 0;
	do { /* generate digits in reverse order */
		base_trans = n % b;
		if (base_trans > 9)
			s[i++] = 'A' + base_trans - 10;
		else
			s[i++] = base_trans + '0';

	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
