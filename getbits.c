#include <stdio.h>

#define uint unsigned

uint getbits(uint x, int p, int n);

int main(void)
{
	printf("%d\n", getbits(077, 4, 3));
	return 0;
}

uint getbits(uint x, int p, int n)
{
	return (x >> (p+1-n)) & ~(1 << n);
}


