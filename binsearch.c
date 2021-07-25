#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n);

int main(void)
{
	int x, v[10000], i;
	x = 3212;
	for (i = 1; i <= 10000; ++i)
		v[i-1] = 2*i;
	printf("%d\n", binsearch(x, v, 10000));
	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
	/* no match */
}

/*int binsearch(int x, int v[], int n) [> v[] must be in increasing order <]*/
/*{*/
	/*int low, mid, high;*/

	/*low = 0;*/
	/*high = n - 1;*/
	/*while (low <= high) {*/
		/*mid = (low+high)/2;*/
		/*if (x < v[mid])*/
			/*high = mid + 1;*/
		/*else if (x > v[mid])*/
			/*low = mid + 1;*/
		/*else [> found match <]*/
			/*return mid;*/
	/*}*/
	/*return -1; [> no match <]*/

/*}*/

