#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define POSITIVE '0' /* signal that a positive number was found */
#define NEGATIVE '1' /* signal that a negative number was found */
#define MAXVAL 100 /* max depth of val stack */
#define BUFSIZE 100


int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
void swap(void);
void dup(void);
void clear(void);
void print_stack(void);
double double_modulo(double d1, double d2);
int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE]; /* Buffer for ungetch() */
int bufp = 0; /* next free position in buffer */



/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case POSITIVE:
			push(atof(s));
			break;
		case NEGATIVE:
			push(-atof(s));
			break;
		case 's':
			push(sin(pop()));
			break;
		case 'o':
			push(cos(pop()));
			break;
		case 't':
			push(tan(pop()));
			break;
		case 'e':
			push(exp(pop()));
			break;
		case 'x':
			swap();
			break;
		case 'd':
			dup();
			break;
		case 'p':
			print_stack();
			break;
		case 'c':
			clear();
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(double_modulo(pop(), op2));
			else
				printf("error: zero divisor (modulo)");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;

		}
	}
	return 0;
}

double double_modulo(double d1, double d2)
{
	return d1 - (int)(d1/d2) * d2;
}

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

int getch(void) /* Get a (possibly pushed-back) buffer */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getop(char s[])
{
	int i, c, min = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (c  == '-') {
		min = 1;
	}
	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* Not a number */
	i = 0;
	if (isdigit(c))/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	else if (c == '-' && isdigit(c = getch())) { /* collect integer part */
		min = 1;
		s[i] = c;
		while (isdigit(s[++i] = c = getch()))
			;
	}
	else {
		ungetch(c);
		return '-';
	}
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	if (min == 0)
		return POSITIVE;
	else
		return NEGATIVE;

}

void clear(void)
{
	sp = 0;
}

void print_stack(void)
{
	int i;
	for (i = 0; i < sp; i++)
		printf("%.2f ", val[i]);
	printf("\n");
}

void swap(void)
{
	double tmp;
	tmp = val[sp - 1];
	val[sp - 1] = val[sp - 2];
	val[sp - 2] = tmp;
}


void dup(void)
{
	int i, tmpsp = sp;
	for (i = 0; i < tmpsp; i++, sp++) {
		val[sp] = val[sp - tmpsp];
	}
}
