#include <stdio.h>

#define uint unsigned int

uint inverse(uint x, int p, int n);

int main(void)
{
	uint x = 31;
	printf("%u\n", inverse(x, 3, 2)); /* ==> 7 */
	return 0;
}

uint inverse(uint x, int p, int n)
{
	int bitmask = ~(~0 << n);
	return x ^ (bitmask << p);

}


