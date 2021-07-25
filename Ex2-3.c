#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int htoi(char line[]);

int main(void)
{
	char hx[] = "0xFF";
	printf("%d\n", htoi(hx));
	return 0;
}

int htoi(char s[])
{
	int i, res = 0;
	char let;
	for (i = 2; (let = s[i]) != '\0'; ++i) {
		switch (let) {
		case 'A': res = 16 * res + 10; break;
		case 'B': res = 16 * res + 11; break;
		case 'C': res = 16 * res + 12; break;
		case 'D': res = 16 * res + 13; break;
		case 'E': res = 16 * res + 14; break;
		case 'F': res = 16 * res + 15; break;
		default: res = 16 * res + (let - '0'); break;
		}
	}
	return res;
}


