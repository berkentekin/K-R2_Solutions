#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 100 /* max depth of val stack */

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full can't push%g\n", f);
}

/* pop: pop and return top val from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}


