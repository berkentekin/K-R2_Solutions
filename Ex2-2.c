#include <stdio.h>

int main(void)
{
	int i, c, lim = 1000;
	for (i = 0; i < lim - 1; ++i) {
		if ((c = getchar()) == '\n')
			break;
		else if (c == EOF)
			break;
	}
	return 0;
}


