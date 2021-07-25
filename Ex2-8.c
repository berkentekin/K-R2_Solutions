#include <stdio.h>

#define uint unsigned int

uint rightrot(uint x, int n);

int main(void)
{
	printf("%u\n", rightrot(21, 3)); /* ==> 2684354562 */
	return 0;
}

uint rightrot(uint x, int n)
{
	while (n-- > 0) {
		if ((x & 1) == 1)
			x = (x >> 1) | ~(~0U >> 1);
		else
			x >>= 1;
	}
	return x;
}

