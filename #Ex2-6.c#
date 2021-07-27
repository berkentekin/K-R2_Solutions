#include <stdio.h>

#define uint unsigned int

uint setbits(uint x, int p, int n, int y);

int main(void)
{
	int x,y;
	x = 218, y = 170;
	printf("%u\n", setbits(x, 3, 3, y)); /* ==> 210 */
	return 0;
}

uint setbits(uint x, int p, int n, int y)
{
	uint bitmask = ~(~0 << n);
	return (x & ~(bitmask << p)) | ((y & bitmask) << p);
}
