#include <stdio.h>
#include <limits.h>
#include <float.h>

int log_2(long);

int main(void)
{
	printf("char\tMin: %d, Max: %d\n", CHAR_MIN, CHAR_MAX);
	printf("short\tMin: %d, Max: %d\n", SHRT_MIN, SHRT_MAX);
	printf("int\tMin: %d, Max: %d\n", INT_MIN, INT_MAX);
	printf("long\tMin: %ld, Max: %ld\n", LONG_MIN, LONG_MAX);
	printf("uchar\tMin: %d, Max: %d\n", 0, UCHAR_MAX);
	printf("ushort\tMin: %d, Max: %d\n", 0, USHRT_MAX);
	printf("uint\tMin: %d, Max: %u\n", 0, UINT_MAX);
	printf("ulong\tMin: %d, Max: %lu\n", 0, ULONG_MAX);
	printf("float\tMin: %.1f, Max: %.1f\n", FLT_MIN, FLT_MAX);
	return 0;
}

int log_2(long n)
{
	int i = 1;
	if (n == 1)
		return 0;
	if (n & 1)
		i = 2;
	for (; (n>>=1) != 0; i++);
	return i;
}


