#include <stdio.h>
#include <ctype.h>

double atof_e(char s[]);

int main(void)
{
	char num[] = "123.45e-2";
	printf("%f", atof_e(num));
	return 0;
}

double atof_e(char s[])
{
	double val, power;
	int i, sign, esign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'E' || s[i] == 'e')
		i++;
	esign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (esign == -1)
		for (; isdigit(s[i]) && s[i] > '0'; s[i]--) {
			power *= 10;
		}
	else
		for (; isdigit(s[i]) && s[i] > '0'; s[i]--) {
			power /= 10;
		}

	return sign * (val / power);
}

